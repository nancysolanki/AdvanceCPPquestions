// Approach: 
// For a Strongly Connected Graph, each vertex must have an in-degree and an out-degree of at least 1. Therefore, in order to make a graph strongly connected, each vertex must have an incoming edge and an outgoing edge. The maximum number of incoming edges and the outgoing edges required to make the graph strongly connected is the minimum edges required to make it strongly connected. 
// Follow the steps below to solve the problem: 

//     Find the count of in-degrees and out-degrees of each vertex of the graph, using DFS.
//     If the in-degree or out-degree of a vertex is greater than 1, then consider it as only 1.
//     Count the total in-degree and out-degree of the given graph.
//     The minimum number of edges required to make the graph strongly connected is then given by max(N-totalIndegree, N-totalOutdegree).
//     Print the count of minimum edges as the result.
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<int> adj[], int* vis, int* inDeg,
		int* outDeg)
{

	vis[u] = 1;


	// Traversing adjacent nodes
	for (auto v : adj[u])
	{
		// Mark out-degree as 1
		outDeg[u] = 1;
		// Mark in-degree as 1
		inDeg[v] = 1;

		// If not visited
		if (vis[v] == 0)
		{
			// DFS Traversal on
			// adjacent vertex
			dfs(v, adj, vis, inDeg, outDeg);
		}
	}
}

// Function to return minimum number
// of edges required to make the graph
// strongly connected
int findMinimumEdges(int source[], int N, int M, int dest[])
{
	// For Adjacency List
	vector<int> adj[N + 1];

	// Create the Adjacency List
	for (int i = 0; i < M; i++)
	{
		adj].push_back(dest[i]);
	}

	// Initialize the in-degree array
	int inDeg[N + 1] = { 0 };

	// Initialize the out-degree array
	int outDeg[N + 1] = { 0 };

	// Initialize the visited array
	int vis[N + 1] = { 0 };

	// Perform DFS to count in-degrees
	// and out-degreess
	dfs(1, adj, vis, inDeg, outDeg);

	// To store the result
	int minEdges = 0;

	// To store total count of in-degree
	// and out-degree
	int totalIndegree = 0;
	int totalOutdegree = 0;

	// Find total in-degree
	// and out-degree
	for (int i = 1; i <= N; i++)
	{
		if (inDeg[i] == 1)
			totalIndegree++;
		if (outDeg[i] == 1)
			totalOutdegree++;
	}

	// Calculate the minimum
	// edges required
	minEdges = max(N - totalIndegree, N - totalOutdegree);

	// Return the minimum edges
	return minEdges;
}


int main()
{
	int N = 5, M = 5;

	int source[] = { 1, 3, 1, 3, 4 };
	int destination[] = { 2, 2, 3, 4, 5 };

	// Function call
	cout << findMinimumEdges(source, N, M, destination);
	return 0;
}

