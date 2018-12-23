We’re going to do a clean-room implementation of the BSD hexdump utility, which is installed as /usr/bin/hexdump on the EdLab (and on OS X, and on most Linux distributions). In particular, you are going to write a Python program named hexdump.py that reproduces the effect of invoking hexdump -Cv filename, which writes a hexdump of the contents of the given filename in Canonical, verbose format to standard output. In other words, entering at the command line:

hexdump -Cv filename

and

python3.5 hexdump.py filename

should result in identical behavior for valid input files. What is that behavior? To quote the manual page (accessible by typing man hexdump at the command line), it should “display the input offset in hexadecimal, followed by sixteen space-separated, two column, hexadecimal bytes, followed by the same sixteen bytes in %_p format enclosed in '|' characters.”



For example:

00000000  ff d8 ff e0 00 10 4a 46  49 46 00 01 01 00 00 01  |......JFIF......|
00000010  00 01 00 00 ff db 00 43  00 07 07 09 09 09 09 09  |.......C........|
00000020  09 09 09 09 09 09 09 09  09 09 09 09 09 09 09 09  |................|
...
(many omitted lines)
...
0002d690  12 93 b3 e7 8e 86 62 f5  0a 25 4e 4b f0 7a d0 24  |......b..%NK.z.$|
0002d6a0  df 58 22 1a 3b 37 c5 16  92 a3 c4 b1 68 f7 69 64  |.X".;7......h.id|
0002d6b0  bc 10 7c d1 0d 02 da 5f  07 ea c0 1f ff d9        |..|...._......|
0002d6be




For any readable file, your program must produce the correct output and exit without error. Your program need not handle exceptional cases related to a missing filename argument or an un-open-able file; do not bother catching the exceptions.





All credit for starter code and project documentation belongs to Marc Liberatore
https://people.cs.umass.edu/~liberato/home/