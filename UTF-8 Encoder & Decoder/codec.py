def encode(codepoint):

    # 1 byte
    if codepoint < 128:
        return bytes([codepoint])

    # 2 bytes
    if 128 <= codepoint <= 2047:

        # place the first 5 bits from codepoint in byte1, after 110
        byte1 = 0b11000000

        # isolate the five bits we want
        mask1 = 0b11111000000

        temp1 = (codepoint & mask1) >> 6
        # OR them together
        ans1 = byte1 | temp1

        byte2 = 0b10000000
        mask2 = 0b00000111111
        temp2 = codepoint & mask2
        ans2 = byte2 | temp2

        return bytes([ans1, ans2])


    # 3 bytes
    if 2048 <= codepoint <= 65535:
        # byte1
        byte1 = 0b11100000
        mask1 = 0b1111000000000000
        temp1 = (codepoint & mask1) >> 12
        ans1 = byte1 | temp1

    #     byte2
        byte2 = 0b10000000
        temp2 = codepoint
        mask2 = 0b0000111111000000
        temp2 = (temp2 & mask2) >> 6
        ans2 = byte2 | temp2

    #     byte3
        byte3 = 0b10000000
        mask3 = 0b0000000000111111
        temp3 = codepoint & mask3
        ans3 = byte3 | temp3

        return bytes([ans1, ans2, ans3])


    # 4 bytes
    if codepoint >= 65536:

#         byte1
        byte1 = 0b11110000
        mask1 = 0b111000000000000000000
        temp1 = (codepoint & mask1) >> 18
        ans1 = byte1 | temp1

#   byte2
        byte2 = 0b10000000
        mask2 = 0b000111111000000000000
        temp2 = (codepoint & mask2) >> 12
        ans2 = byte2 | temp2

#         byte3
        byte3 = 0b10000000
        mask3 = 0b000000000111111000000
        temp3 = (codepoint & mask3) >> 6
        ans3 = byte3 | temp3

#         byte4
        byte4 = 0b10000000
        mask4 = 0b000000000000000111111
        temp4 = codepoint & mask4
        ans4 = byte4 | temp4

        return bytes([ans1,ans2,ans3,ans4])







def decode(bytes_object):

#     1byte
    if len(bytes_object) == 1:
        return bytes_object[0]

#     2bytes
    if len(bytes_object) == 2:

        temp1 = (bytes_object[0])
        ans1 = (0b00011111 & temp1) << 6

        temp2 = bytes_object[1]
        ans2 = (0b00111111 & temp2)

        final = ans1 | ans2
        return final


    if len(bytes_object) == 3:

        temp1 = bytes_object[0]
        ans1 = (0b00001111 & temp1) << 12

        temp2 = bytes_object[1]
        ans2 = (0b00111111 & temp2) << 6

        temp3 = bytes_object[2]
        ans3 = (0b00111111 & temp3)

        final = ans1 | ans2 | ans3
        return final

    if len(bytes_object) == 4:

        temp1 = bytes_object[0]
        ans1 = (0b00000111 & temp1) << 18

        temp2 = bytes_object[1]
        ans2 = (0b00111111 & temp2) << 12

        temp3 = bytes_object[2]
        ans3 = (0b00111111 & temp3) << 6

        temp4 = bytes_object[3]
        ans4 = (0b00111111 & temp4)

        final = ans1 | ans2 | ans3 | ans4
        return final

def main():
    # print("actual")
    print(encode(1000000))
    # print(bin(2000))
    b = b'\xf3\xb4\x89\x80'
    print(ord(b.decode()))
    print(decode(b))


if __name__ == '__main__':
    main()

