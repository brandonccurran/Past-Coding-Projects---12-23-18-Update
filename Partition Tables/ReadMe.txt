The Master Boot Record (MBR) is a legacy format for partition tables on consumer PCs; it lives on in the first sector of many (most?) removable USB drives (“thumb drives”). It’s a simple format (if you ignore extended partitions) that’s easy to parse, and you’re going to do so in this assignment.

The GUID Partition Table (GPT) is the new standard for partitioning fixed disks on PCs, defined as part of the Unified Extensible Firmware Interface standard. It’s more complicated than an MBR, but should be fairly straightforward to parse, especially for survivors of the Exif parsing assignment.




What to do

Implement a parse_mbr() function, which when passed a valid MBR containing only primary partitions (represented as a sequence of 512 bytes) returns a list of entries. There should be one item in the list for each non-empty entry in the MBR (consider entries with an entry type of non-zero as non-empty). The list should be in the same order as the partition entries in the MBR. Each item in the list should be a dictionary, and the dictionary should have the following keys and values:

number: the partition table entry number, starting at 0
start: the first sector of the partition
end: the last sector of the partition
type: the partition type, represented as string in hexadecimal format (for example, "0x06")


Next, implement a parse_gpt() function, which takes two parameters. The first parameter is an open file-like object that starts at the protective MBR of a GPT and ends on or after the last possible entry in the table. The second optional parameter is the sector size in bytes, defaulting to 512. parse_gpt() should return a list of entries. There should be one item in the list for each non-empty entry in the GPT. The list should be in the same order as the partition entries in the MBR. Each item in the list should be a dictionary, and the dictionary should have the following keys and values:

number: the partition table entry number, starting at 0
start: the first sector of the partition
end: the last sector of the partition
type: the 16-byte GUID as a UUID object (pass the bytes to the uuid.UUID() constructor as the bytes_le argument)
name: the name of the partition, as a string, not a bytes sequence; assume the UTF-16LE name in the entry ends at the first NUL codepoint (U+0000) and trim it accordingly


In both functions, you may assume the input is valid. We will not test your code on invalid inputs.



**** STARTER CODE ****




import struct
import uuid


def parse_mbr(mbr_bytes):
    return []


def parse_gpt(gpt_file, sector_size=512):
    return []



All credit for starter code and project documentation belongs to Marc Liberatore
https://people.cs.umass.edu/~liberato/home/