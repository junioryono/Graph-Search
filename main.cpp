#include <iostream>
#include <list>

using namespace std;

class Graph {
    /*
    struct edge {
        int adj_vtx;
        list<int> *next;
    };
    */
    private:
	    int V;
	    list<int> *adj;
	    void DFSUtil(int v, bool visited[]);

    public:
	    Graph(int V);
	    void addEdge(int v, int w);
	    void BFS(int s);
	    void DFS(int v);
        bool hasCycle();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::BFS(int s) {
	bool *visited = new bool[V];
    visited[s] = true;
	for (int i = 0; i < V; i++) visited[i] = false;

	list<int> queue;
	queue.push_back(s);

	list<int>::iterator i;
	while (!queue.empty()) {
		s = queue.front();
		cout << " -> " << s;
		queue.pop_front();

		for (i = adj[s].begin(); i != adj[s].end(); ++i) 
			if (!visited[*i]) {
				visited[*i] = true;
				queue.push_back(*i);
			}
	}
}

void Graph::DFSUtil(int v, bool visited[]) {
	visited[v] = true;
	cout << " -> " << v;
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i) if (!visited[*i]) DFSUtil(*i, visited);
}

void Graph::DFS(int s) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++) visited[i] = false;
	DFSUtil(s, visited);
}

bool Graph::hasCycle() {
    bool *visited = new bool[V];
    int i;
    for (i = 0; i < V; i++){};
    if (i == this->V) return true;
    else return false;
}

int main() {
	Graph graph(4);
	graph.addEdge(0, 2);
	graph.addEdge(0, 2);
	graph.addEdge(2, 2);
	graph.addEdge(2, 3);
	graph.addEdge(2, 3);
	graph.addEdge(3, 3);

	cout << "BFT:" << endl;
	graph.BFS(2);
	cout << endl;

    cout << "DFT:" << endl;
	graph.DFS(2);
	cout << endl;

    cout << "Has Cycle:" << endl;
	cout << graph.hasCycle();
	cout << endl;

	return 0;
}