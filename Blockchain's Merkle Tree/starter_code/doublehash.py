import struct
from hashlib import sha256

# takes a 512 bit number, val, as input
# returns the double-SHA256 hash of val as a 256 bit number
def doublehash(val):
	uints = [0] * 16
	index = 0
	while val:
		uints[index] = val & (2**32 - 1)
		index += 1
		val = val >> 32
	val = struct.pack('16I', *uints)
	uints = struct.unpack('8I', sha256(sha256(val).digest()).digest())
	val = 0
	for i in range(7, -1, -1):
		val = val << 32
		val += uints[i]
	return val