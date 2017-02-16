import networkx as nx
import matplotlib.pyplot as plt 


def parse_data(data_file_path):
	nodes_and_edges = dict()
	data_file = open(data_file_path, "r")
	N = data_file.readline()
	nodes_and_edges['nodelist'] = list(range(0, int(N)))
	edge_strings = [line.replace("\n", "").split("&") for line in data_file]
	nodes_and_edges['edgelist'] = [(int(es[0]), int(es[1])) for es in edge_strings]
	data_file.close()
	return nodes_and_edges


def display_tree(parsed_data):
	G = nx.Graph()
	G.add_nodes_from(parsed_data['nodelist'])
	G.add_edges_from(parsed_data['edgelist'])
	pos = nx.spring_layout(G)
	nx.draw_networkx(G, pos=pos, with_labels=True)
	plt.show()



DATA_FILE = "src/UnionFind/displaytreetxt.txt"
display_tree(parse_data(DATA_FILE))