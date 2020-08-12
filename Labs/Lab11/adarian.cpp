#include <iostream>
#include <list>
#include <stack>
#include <vector>
#define ArrSize 200
using namespace std;

vector<int> id;
vector<int> counter;

class Graph
{
private:
	int vertices;
	list<int> *graph;
	vector<int> V;
	int count;
	int temp;

public:
	Graph(int);
	void addEdge(int, int);
	Graph transpose();
	void fill(int, bool *, stack<int> &);
	void DFS(int, bool *);
	void SCC();
	void printSCCID(vector<int>);
	void makeID(vector<int>);
};

/**
 * Graph
 * 
 * @param node int
*/
Graph::Graph(int node)
{
	this->vertices = node;
	graph = new list<int>[vertices];
	count = 0;
	temp = 0;
}

/**
 * addEdge
 * 
 * @param u int
 * @param v int
*/
void Graph::addEdge(int u, int v)
{
	graph[u].push_back(v);
}

/**
 * transpose
*/
Graph Graph::transpose()
{
	Graph g(vertices);

	for (auto i = 0; i < vertices; i++)
	{
		list<int>::iterator j;
		for (auto j = graph[i].begin(); j != graph[i].end(); j++)
			g.graph[*j].push_back(i);
	}
	return g;
}

/**
 * Fill
 * 
 * @param v integer
 * @param visited boolean
 * @param s stack<int>
*/
void Graph::fill(int v, bool *visited, stack<int> &s)
{
	visited[v] = true;
	list<int>::iterator i;

	for (auto i = graph[v].begin(); i != graph[v].end(); i++)
	{
		if (!visited[*i])
			fill(*i, visited, s);
	}

	s.push(v);
}

/**
 * DFS
 * 
 * @param v integer
 * @param visited boolean 
*/
void Graph::DFS(int v, bool *visited)
{
	count++;
	visited[v] = true;
	V.push_back(v);
	list<int>::iterator i;

	for (auto i = graph[v].begin(); i != graph[v].end(); i++)
	{
		if (!visited[*i])
			DFS(*i, visited);
	}

	if (temp == 0)
	{
		counter.push_back(count);
		temp++;
	}

	makeID(V);
	V.clear();
	count = 0;
	temp = 0;
}

/**
 * SCC
 * 
 * @desc Strongly Connected Components
*/
void Graph::SCC()
{
	stack<int> s;
	bool *visited = new bool[vertices];
	int v;
	Graph g = transpose();

	for (auto i = 0; i < vertices; i++)
		visited[i] = false;

	for (auto i = 0; i < vertices; i++)
	{
		if (visited[i] == false)
			fill(i, visited, s);
	}

	for (auto i = 0; i < vertices; i++)
		visited[i] = false;

	while (s.empty() == false)
	{
		v = s.top();
		s.pop();

		if (visited[v] == false)
		{
			g.DFS(v, visited);
			count++;
		}
	}

	printSCCID(id);
}

/**
 * printSCCID
 * 
 * @param id vector<int>
*/
void Graph::printSCCID(vector<int> id)
{
	int arr[ArrSize];
	auto w = true;
	auto x = 0;
	auto y = 0;
	auto z = 0;
	auto val;

	while (w)
	{
		val = id[y];
		z = counter[x];

		while (z > 0)
		{
			arr[id[y]] = val;
			y++;
			z--;
		}

		if (y == id.size())
			w = false;

		x++;
	}

	for (auto i = 0; i < id.size(); i++)
		cout << arr[i] << endl;
}

/**
 * makeID
 * 
 * @param V vector<int>
*/
void Graph::makeID(vector<int> V)
{
	auto temp = 0;
	auto j = 0;

	for (auto i = 1; i < V.size(); i++)
	{
		temp = V[i];
		j = i - 1;

		while (j >= 0 && V[j] > temp)
		{
			V[j + 1] = V[j];
			j--;
		}

		V[j + 1] = temp;
	}

	for (auto i = 0; i < V.size(); i++)
		id.push_back(V[i]);
}

int main()
{
	int vertice;
	int edge;
	int u, v;

	cin >> vertice;

	Graph g(vertice);

	cin >> edge;

	for (auto i = 0; i < edge; i++)
	{
		cin >> u;
		cin >> v;
		g.addEdge(u, v);
	}

	g.SCC();
	return 0;
}
