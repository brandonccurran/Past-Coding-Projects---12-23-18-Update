

import argparse


def print_strings(file_obj, encoding, min_len):

    temp_string = ""
    while True:
        # read in the bytes
        if encoding == 's':
            bytes = file_obj.read(1)
        else:
            bytes = file_obj.read(2)

        # end of file; print strings if applicable
        if not bytes:
            if len(temp_string) >= min_len:
                print(temp_string)
            break

        # add to string buffer if its readable

        # utf8
        if encoding == 's':
            if 0x20<=bytes[0]<=0x7e:
                temp_string += bytes.decode()
            else:
                if len(temp_string) >= min_len:
                    print(temp_string)
                temp_string = ""

        # utf16le
        elif encoding == 'l':
            if 0x20 <= int.from_bytes(bytes, byteorder='little') <= 0x7e:
                temp_string += bytes.decode('utf-16-le')
            else:
                if len(temp_string) >= min_len:
                    print(temp_string)
                temp_string = ""


        # utf16be
        elif encoding == 'b':
            if 0x20<= int.from_bytes(bytes, byteorder='big') <= 0x7e:
                temp_string += bytes.decode('utf-16-be')
            else:
                if len(temp_string) >= min_len:
                    print(temp_string)
                temp_string = ""





def main():
    parser = argparse.ArgumentParser(description='Print the printable strings from a file.')
    parser.add_argument('filename')
    parser.add_argument('-n', metavar='min-len', type=int, default=4,
                        help='Print sequences of characters that are at least min-len characters long')
    parser.add_argument('-e', metavar='encoding', choices=('s', 'l', 'b'), default='s',
                        help='Select the character encoding of the strings that are to be found. ' +
                             'Possible values for encoding are: s = UTF-8, b = big-endian UTF-16, ' +
                             'l = little endian UTF-16.')
    args = parser.parse_args()

    with open(args.filename, 'rb') as f:
        print_strings(f, args.e, args.n)

if __name__ == '__main__':
    main()