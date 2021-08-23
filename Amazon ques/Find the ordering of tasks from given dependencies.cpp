// consider this problem as a graph (related to topological sorting) problem.
//   All tasks are nodes of the graph and if task u is a prerequisite of task v, we will add a directed edge from node u to node v. Now, this problem is equivalent to finding a topological 
// ordering of nodes/tasks (using topological sorting) in the graph represented by prerequisites. If there is a cycle in the graph, then it is not possible to finish all tasks (because in 
// that case there is no any topological order of tasks). Both BFS and DFS can be used for topological sorting to solve it.

// Since pair is inconvenient for the implementation of graph algorithms, we first transform it to a graph. If task u is a prerequisite of task v, we will add a directed edge from node 
// u to node v.

// Topological Sorting using BFS
// Here we use Kahn’s algorithm for topological sorting. BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to do so, there must be 
// a cycle in the graph and we return false. Otherwise we have found one. We set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of all its neighbors by 1.
//  This process will be repeated for n (number of nodes) times.




// CPP program to find order to process tasks
// so that all tasks can be finished. This program
// mainly uses Kahn's algorithm.
#include <bits/stdc++.h>
using namespace std;

// Returns adjacency list representation of graph from
// given set of pairs.
vector<unordered_set<int> > make_graph(int numTasks,
			vector<pair<int, int> >& prerequisites)
{
	vector<unordered_set<int> > graph(numTasks);
	for (auto pre : prerequisites)
		graph[pre.second].insert(pre.first);
	return graph;
}

// Computes in-degree of every vertex
vector<int> compute_indegree(vector<unordered_set<int> >& graph)
{
	vector<int> degrees(graph.size(), 0);
	for (auto neighbors : graph)
		for (int neigh : neighbors)
			degrees[neigh]++;
	return degrees;
}

// main function for topological sorting
vector<int> findOrder(int numTasks,
		vector<pair<int, int> >& prerequisites)
{
	// Create an adjacency list
	vector<unordered_set<int> > graph =
			make_graph(numTasks, prerequisites);

	// Find vertices of zero degree
	vector<int> degrees = compute_indegree(graph);
	queue<int> zeros;
	for (int i = 0; i < numTasks; i++)
		if (!degrees[i])
			zeros.push(i);

	// Find vertices in topological order
	// starting with vertices of 0 degree
	// and reducing degrees of adjacent.
	vector<int> toposort;
	for (int i = 0; i < numTasks; i++) {
		if (zeros.empty())
			return {};
		int zero = zeros.front();
		zeros.pop();
		toposort.push_back(zero);
		for (int neigh : graph[zero]) {
			if (!--degrees[neigh])
				zeros.push(neigh);
		}
	}
	return toposort;
}

// Driver code
int main()
{
	int numTasks = 4;
	vector<pair<int, int> > prerequisites;

	// for prerequisites: [[1, 0], [2, 1], [3, 2]]

	prerequisites.push_back(make_pair(1, 0));
	prerequisites.push_back(make_pair(2, 1));
	prerequisites.push_back(make_pair(3, 2));
	vector<int> v = findOrder(numTasks, prerequisites);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}
