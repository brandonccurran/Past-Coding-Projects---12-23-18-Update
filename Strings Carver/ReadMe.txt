"strings" generally extracts and prints on a separate line each sequence of n or more printable ASCII values from its input — the exact behavior various depending upon the version of strings you have. On the EdLab, strings is GNU strings.

GNU strings takes an optional argument -n min-len, indicating the value of n. It also takes an optional argument -e encoding, indicating the encoding that should be checked. s is essentially UTF-8 printable ASCII; b and l are essentially big- and little-endian UTF-16 printable ASCII.

You’re going to implement strings in Python, treating the Unicode code points between U+20 and U+7E, inclusive, as printable. Just like in strings, each string of the required length (or greater) will be printed to standard out on its own line.

For simplicity’s sake: Assume all UTF-16 strings are even-byte aligned. That is, you should assume they start on offsets (from the start of the file) that are divisible by two. In practice this is not the case, but allowing odd- and even-aligned strings leads to ambiguities that make autograding a hassle. Be aware that a real strings implementation needs to scan byte-by-byte, but for this assignment, yours does not.

Note you do not need to use your own encoder and decoder from earlier in this assignment; you may use Python built-ins to determine if a given byte (or pair of bytes, in the case of UTF-16) represents a character of interest.






All credit for starter code and project documentation belongs to Marc Liberatore
https://people.cs.umass.edu/~liberato/home/