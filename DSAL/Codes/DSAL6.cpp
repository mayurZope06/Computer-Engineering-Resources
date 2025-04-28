// Represent a graph using adjacency matrix/list to perform Depth-First Search (DFS) and adjacency list to perform
// Breadth-First Search (BFS). Use a map of the area around a college as the graph, identifying prominent landmarks
// as nodes.
// (Graph Representation Algorithm)
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Graph {
public:
  
    vector<vector<int>> adjMatrix;
    
    vector<vector<int>> adjList;
    int V; 
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0)); 
        adjList.resize(V); 
    }

    
    void addEdgeMatrix(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 
    }

    void addEdgeList(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    
    void DFSMatrix(int start, vector<bool>& visited) {
        stack<int> s;
        s.push(start);
        visited[start] = true;

        while (!s.empty()) {
            int node = s.top();
            s.pop();
            cout << "Visited: " << node << endl;

            for (int i = 0; i < V; i++) {
                if (adjMatrix[node][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    s.push(i);
                }
            }
        }
    }

    
    void BFSList(int start) {
        vector<bool> visited(V, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << "Visited: " << node << endl;

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    int V, E;
    cout << "Enter number of landmarks (nodes): ";
    cin >> V;

    Graph g(V);

    cout << "Enter number of connections (edges): ";
    cin >> E;

    cout << "Enter the connections between landmarks (pairs of integers):" << endl;
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdgeMatrix(u, v);  
        g.addEdgeList(u, v);    
    }

    int start;
    cout << "Enter starting node for DFS and BFS: ";
    cin >> start;

    cout << "\nPerforming DFS (using adjacency matrix):" << endl;
    vector<bool> visitedDFS(V, false);
    g.DFSMatrix(start, visitedDFS);

    cout << "\nPerforming BFS (using adjacency list):" << endl;
    g.BFSList(start);

    return 0;
}
