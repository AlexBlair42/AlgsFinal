////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Alex Blair and Aleisha Smith
// 13 December 2018
// Advanced Algorithm and Design
// This is a program that implements Prims algorithm
// for minimmum spanning trees
// in C++
// Using code from https://codereview.stackexchange.com/questions/126617/implementation-of-prims-algorithm-in-c
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Include Directories
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


// Parameters are as follows, A------B, Weight
typedef pair<pair<int, int>, int> Edge; //a, b, weight



vector<Edge> prims(vector<vector<int>> graph, int total_nodes) {
	vector<int> unvisited;
	vector<int> visited;
	vector<Edge> result;

	//mark first as visited and mark the rest as unvisited
	for (int i = 1; i < total_nodes; i++)
		unvisited.push_back(i);
	// Push initial visited is 0 index
	visited.push_back(0);

	while (!unvisited.empty()) {

		vector<Edge> edges_with_weight;
		//put all edges (with their weight) from nodes that are in visited
		for (auto node : visited) {
			for (int sec_node = 0; sec_node < total_nodes; sec_node++) {
				if (graph[node][sec_node] > 0 && find(unvisited.begin(), unvisited.end(), sec_node) != unvisited.end()) {
					//add if there is connection and second node is not visited yet
					Edge edg = make_pair(make_pair(node, sec_node), graph[node][sec_node]);
					edges_with_weight.push_back(edg);
				}
			}
		}

		//find the shortest edge
		pair<pair<int, int>, int> the_shortest;
		the_shortest = edges_with_weight.front();
		for (auto i : edges_with_weight) {
			if (the_shortest.second > i.second)
				the_shortest = i;
		}

		//add the shortest path to the result
		result.push_back(the_shortest);

		//remove a node that the shortest edge leads to
		unvisited.erase(remove(unvisited.begin(), unvisited.end(), the_shortest.first.second), unvisited.end());

		//mark this node as visited
		visited.push_back(the_shortest.first.second);
	};
	return result;
}


int main() {
	/*
	vector<vector<int>> graph =
	{ {{0, 2, 0, 6, 0},
	  {2, 0, 3, 8, 5},
	  {0, 3, 0, 0, 7},
	  {6, 8, 0, 0, 9},
	  {0, 5, 7, 9, 0},
} };
	*/

	vector<vector<int>> graph =
	{ {{ 0,  3,  1,  2,  5,  9,  8,  6,  4,  1},    // 0
	   { 3,  0,  6,  1,  4,  5,  6,  4,  4,  5},    // 1
	   { 1,  6,  0,  6,  2,  1,  8,  2,  8,  1},    // 2
	   { 2,  1,  6,  0,  1,  4,  8,  9,  7,  0},    // 3
	   { 5,  4,  2,  1,  0,  4,  5,  8,  8,  2},    // 4
	   { 9,  5,  1,  4,  4,  0,  8,  7,  4,  4},    // 5
	   { 8,  6,  8,  8,  5,  8,  0,  6,  6,  3},    // 6
	   { 6,  4,  2,  9,  8,  7,  6,  0,  1,  1},    // 7
	   { 4,  4,  8,  7,  8,  4,  6,  1,  0,  7},    // 8
	   { 1,  5,  1,  0,  2,  4,  3,  1,  7,  0},    // 9
		} };
 

    // For different matrix sizes change integer param. so for mat 2 change 5 to 10.
	vector<Edge> result = prims(graph, 10);
	for (auto i : result) {
		cout << "Edge [ " << i.first.first << ", " << i.first.second << "], Weight: " << i.second << endl;
	}

	return 0;
}
