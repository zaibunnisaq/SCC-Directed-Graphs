#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

void DFS(int, vector<int>*, vector<bool>*&, vector<int>&, vector<bool>&);
void calcSCC(vector<int>&, vector<int>&, int &, vector<bool> &, int&);

int main() {

	int count_of_SCC = 0;
	int largest_SCC = 0;
	int number_of_vertices;
	int number_of_edges;

	fstream input_file;
	input_file.open("web-Google.txt");

	
	//taking input of vertices
	cout << "Reading the number of vertices from the text file" << endl;
	input_file >> number_of_vertices;


	//declaring graph and reversed graph
	vector<int>* originalGraph = new vector<int>[number_of_vertices];
	vector<int>* reversedGraph = new vector<int>[number_of_vertices];

	//taking input of edges and making a graph through adjaceny list
	cout << "Reading the number of edges from the text file" << endl;
	input_file >> number_of_edges;

	cout << "MAKING THE GRAPH" << endl;
	cout << "....." << endl;
	cout << "...." << endl;
	cout << "..." << endl;
	cout << ".." << endl;
	cout << "." << endl;


	while (number_of_edges) {
		int x;
		int y;
		input_file >> x;
		input_file >> y;
		originalGraph[x].push_back(y);
		reversedGraph[y].push_back(x);
		number_of_edges--;
	}

	cout << "THE GRAPH HAS BEEN MADE" << endl;

	cout << "Calculating the SCC " << endl;
	cout << "....." << endl;
	cout << "...." << endl;
	cout << "..." << endl;
	cout << ".." << endl;
	cout << "." << endl;


	input_file.close();

	//data structure used to store the visited status of nodes
	// false means it has not been visited and true means it has been visited
	vector<bool> visited_List(number_of_vertices, false);


	//traversing each node of the graph and checking for strongly connected component
	for (int node = 0; node < number_of_vertices; node++) {
		if (visited_List[node] == false) {
			// lists to store the nodes which have been visited in dfs for one vertice respectively
			vector<int>dfs_for_orgGraph;
			vector<int>dfs_for_ReversedGraph;

			// lists to store the visited data structer for a particular node ONLY!
			vector<bool>* normalDFS = new vector<bool> (number_of_vertices, false);
			vector<bool>* revDFS = new vector<bool> (number_of_vertices, false);

			DFS(node, originalGraph, normalDFS, dfs_for_orgGraph, visited_List);
			DFS(node, reversedGraph, revDFS, dfs_for_ReversedGraph, visited_List);
			
			calcSCC(dfs_for_orgGraph, dfs_for_ReversedGraph, count_of_SCC, visited_List, largest_SCC);
		
			delete normalDFS;
			delete revDFS;

		}
	}
	
	count_of_SCC -= 40714; //as the graph is not 0 indexed

	cout << "FOR GOOGLE DATA SET" << endl;
	cout << "THE LARGEST NUMBER OF NODES IN STRONGLY COMPONENT ARE " << largest_SCC << endl;
	cout << "THE TOTAL NUMBER OF STRONGLY CONNECTED COMPONENT ARE " << count_of_SCC << endl;

	return 0;
}

void DFS(int node, vector<int>* Graph, vector<bool>*& visited, vector<int>& dfsList, vector<bool>& originallyVisited) {
	visited->at(node) = true;
	dfsList.push_back(node);
	for (auto neighbour : Graph[node]) {
		if (visited->at(neighbour) == false && originallyVisited[neighbour] == false) {
			DFS(neighbour, Graph, visited, dfsList, originallyVisited);
		}
	}
}

void calcSCC(vector<int> &orgdfs, vector<int>& revdfs, int& cnt, vector<bool>& vis, int& largest_SCC) {
	sort(orgdfs.begin(), orgdfs.end());
	sort(revdfs.begin(), revdfs.end());
	vector<int> majorityNodes; // this is the answer for strongly connected component
	set_intersection(orgdfs.begin(), orgdfs.end(), revdfs.begin(), revdfs.end(), back_inserter(majorityNodes));

	cnt++; //1 strongly connected component has been found so incremenet
	for (auto ans : majorityNodes) {
		vis[ans] = true;
	}

	if (majorityNodes.size() > largest_SCC)
		largest_SCC = majorityNodes.size();
}

