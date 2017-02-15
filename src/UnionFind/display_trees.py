import networkx as nx
import matplotlib.pyplot as plt 


def parse_data(data_file):
	pass


def display_tree(parsed_data):
	
	G = nx.Graph()
	pos = nx.spring_layout(G)

	nx.draw_networkx_nodes(G, pos, nodelist=parsed_data['nodelist'])
	nx.draw_networkx_edges(G, pos, edgelist=parsed_data['edgelist'])
	nx.draw_networkx_labels(G, pos, labels=parsed_data['nodelist'])

	plt.show()



DATA_FILE = ""
display_tree(parse_data(DATA_FILE))