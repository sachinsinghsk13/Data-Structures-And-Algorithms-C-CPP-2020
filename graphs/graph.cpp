#include <list>
#include <iostream>
using namespace std;

class graph {
	private:
		int total_nodes;
		list<int> *adj_list;
		void dfs_util(int index, bool visited[]);
	public:
		graph(int vertices);
		void add_edge(int vertex_u, int vertex_v);
		void bfs(int start);
		void dfs(int start);
};


graph::graph(int vertices) {
	this->total_nodes = vertices;
	adj_list = new list<int>[total_nodes];
}

void graph::add_edge(int u, int v) {
	adj_list[u].push_back(v); // because its a digraph
}

void graph::bfs(int begin_vertex) {
	bool *visisted = new bool[total_nodes];
	for (int i = 0; i < total_nodes; i++)
		visisted[i] = false;
	
	visisted[begin_vertex] = true;
	list<int> q;
	q.push_back(begin_vertex);

	while (!q.empty()) {
		begin_vertex = q.front();
		cout << begin_vertex << " ";
		q.pop_front();
		list<int>::iterator it;
		for (it = adj_list[begin_vertex].begin(); it != adj_list[begin_vertex].end(); ++it) {
			if (!visisted[*it]) {
				visisted[*it] = true;
				q.push_back(*it);
			}
		}
	}
}

void graph::dfs(int start) {
	bool *visited = new bool[total_nodes];
	for (int i = 0; i < total_nodes; i++)
		visited[i] = false;
	dfs_util(start, visited);
}

void graph::dfs_util(int index, bool visited[]) {
	visited[index] = true;
	cout << index << " ";
	for (list<int>::iterator it = adj_list[index].begin(); it != adj_list[index].end(); ++it)
		if (!visited[*it])
			dfs_util(*it, visited);
}