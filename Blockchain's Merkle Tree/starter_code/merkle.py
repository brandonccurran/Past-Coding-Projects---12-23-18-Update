# Starter code for assignment 1
# UMass CS461/661 Spring 2019

import json, math
from doublehash import doublehash

leaves = []
with open('leaves.json', 'r') as f:
    leaves = json.load(f)

merkleTree = []
#########################
## Your code goes here ##
#########################

# to find depth of merkle tree:
depth  = int(math.log(len(leaves), 2))

h_leaves = []
num_leaves = []
for i in range(depth+1):

    # puts all leaves' hashes into first array in tree
    if i == 0:
        for j in leaves:
            h_leaves.append(doublehash(j))
        merkleTree.append(h_leaves)
        num_leaves = len(h_leaves)


    else:
        temp_array = []
        counter = 0

        # dictates how many entries belong in each array (each array is half as long as its predecessor)
        num_leaves = num_leaves/2
        for k in range(int(num_leaves)):

            # set vars for the two hashes we will concatenate
            left_hash = merkleTree[i-1][counter]
            right_hash = merkleTree[i-1][counter+1]

            # we pad the first value, and concatenate with the second
            cat_hash = (left_hash << 256) ^ right_hash

            temp_array.append(doublehash(cat_hash))

            counter += 2
        merkleTree.append(temp_array)


# write the tree to a file
with open('tree.json', 'w') as f:
    f.write(json.dumps(merkleTree, indent=2))