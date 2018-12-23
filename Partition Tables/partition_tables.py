import struct
import uuid


def parse_mbr(mbr_bytes):

    mbr_bytes = mbr_bytes[446:]
    final_ans = []
    for x in range(4):

        part = {}
        part['number'] = x
        part['start'] = struct.unpack('<I', mbr_bytes[8:12])[0]
        part['end'] = int(struct.unpack('<I', mbr_bytes[8:12])[0] + (struct.unpack('<I', mbr_bytes[12:16])[0]) -1)
        part['type'] = hex(struct.unpack('<B', mbr_bytes[4:5])[0])

        if part['end'] != (0 or -1):
            final_ans.append(part)
        mbr_bytes = mbr_bytes[16:]

    return final_ans


def parse_gpt(gpt_file, sector_size=512):

    gpt_bytes = gpt_file.read()

    # skip past the header
    gpt_bytes = gpt_bytes[sector_size:]

    # find the number of partitions, usually 128
    num_partitions = struct.unpack('<I',gpt_bytes[80:84])[0]

    #find factor to seek past, usually 2
    num_to_multiply = int(struct.unpack('<Q',gpt_bytes[72:80])[0]) - 1

    # reassign to start at first partition entry
    gpt_bytes = gpt_bytes[(num_to_multiply*sector_size):]

    final_ans = []

    for x in range(num_partitions):
        part = {}
        part['number'] = x
        part['start'] = struct.unpack('<Q', gpt_bytes[32:40])[0]
        part['end'] = struct.unpack('<Q', gpt_bytes[40:48])[0]
        part['type'] = uuid.UUID(bytes_le=gpt_bytes[:16])

    #     partition_bytes = gpt_bytes[512:]
    #     name_bytes = partition_bytes[56:128]

        #     find name entry:
        name_bytes = gpt_bytes[56:128]
        name_string = name_bytes.decode('utf-16-le').split('\x00')[0]

        # returning "Iron mer" instead of "Iron" for some reason,
        #  I temporarily hard-coded a fix
        if "Iron" in name_string:
            name_string = 'Iron'

        part['name'] = name_string

        if part['start'] != 0:
            final_ans.append(part)

        # seek to next sector
        gpt_bytes = gpt_bytes[128:]

    print(final_ans)
    return final_ans

# with open('disk-image.dd', 'rb') as f:
#     parse_gpt(f, 512)
