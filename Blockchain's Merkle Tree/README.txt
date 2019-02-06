Your task is to construct a Merkle Tree from a given set of leaf nodes in merkle.py, which reads in
leaves.json and outputs the variable merkleTree to a file tree.json.

We have provided an example solution that might help you test your program: solution tree.json.
merkleTree[0] should be an array of the hashes of the leaves. merkleTree[i][j] should be the hash of the
concatenation of merkleTree[i - 1][j * 2] and merkleTree[i - 1][j * 2 + 1], and so on.
The hash function you use is doublehash(), which takes a 512 bit number and outputs 256 bit number.

For example,
doublehash(0) == 112873800299245400418399412847166129871615482632478404544220642288268866287330
doublehash(1) == 55234876095934119651006768611382564447113638146482495072641080355973059660226.
You should not have to use any external libraries.




--------------------------------

All credit for starter code (all files except for implementation of merkle.py) to Brian Levine

https://www.cics.umass.edu/faculty/directory/levine_brian