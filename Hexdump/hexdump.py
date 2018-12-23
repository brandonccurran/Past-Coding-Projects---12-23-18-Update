import binascii
import sys


def hexdump(f):
    with open(f, "rb") as temp:
        bytes = temp.read(1)
        if not bytes:
            return
        temp.close()

    with open(f,"rb") as file:

        memory_count = 0
        print('{:08x}'.format(memory_count) + ' ', end=' ')
        final_str = []
        counter = 0

        while True:
            bytes = file.read(1)
            if not bytes:
                break
            for x in bytes:

                if counter == 16:
                    # ascii print
                    # bytes = file.read(16)
                    print(" |",end='')
                    print(''.join(final_str),end='')
                    print("|")

                    final_str = []
                    counter = 0

                    # new line begins
                    print('{:08x}'.format(memory_count), end='  ')

                elif counter == 8:
                    print(" ", end='')

                print(''.join(["%02x " % x]), end="")
                counter += 1
                memory_count += 1

                if hex(0x20) <= hex(x) <= hex(0x7e):
                    # this turns x into a readable hex val, ie "4e"
                    temp_hex = ''.join(["%02x " % x])

                #    this saves the ascii value
                    add_to_str = str(binascii.unhexlify(temp_hex.strip()))[2:]
                    final_str.append(add_to_str[:-1])

                else:
                    final_str.append('.')


        s= "   "
        num_spaces_needed = ((16-counter))

        if counter <= 8:
            print(s * num_spaces_needed + "  |" + ''.join(final_str) + "|")
        else:
            print(s * num_spaces_needed + " |" + ''.join(final_str) + "|")

        print('{:08x}'.format(memory_count))


hexdump(sys.argv[1])
# hexdump("filename.txt")