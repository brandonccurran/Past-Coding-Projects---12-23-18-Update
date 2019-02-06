import json

def query(filename, qs):
	tree = []
	with open(filename, 'r') as f:
		tree = json.load(f)
	i = 0
	for q in qs:
		yield tree[qs[i][0]][qs[i][1]]
		i = i + 1