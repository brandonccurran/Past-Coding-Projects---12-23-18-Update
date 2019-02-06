import json, math
from doublehash import doublehash
from oracle import query

with open('test.json', 'r') as f:
	d = json.load(f)
	root = d['root']
	candidate = d['candidate']
	index = d['index']

tree = []
with open("tree.json", 'r') as f:
		tree = json.load(f)

member = False

#########################
## Your code goes here ##
#########################

member = (tree[0][index] == doublehash(candidate))


with open('test_result.json', 'w') as f:
	f.write(json.dumps(member))