// Represent a graph of flight paths between cities, where the cost of an edge is the time or fuel used for the journey.
// Use adjacency list or matrix representation and check if the graph is connected. Justify the storage representation
// used.
// (Flight Path Graph)
#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>

using namespace std;

// Graph class using adjacency list representation
class Graph {
private:
    unordered_map<string, list<pair<string, int>>> adjList;

public:
    // Add a flight (edge) between two cities with cost (time/fuel)
    void addFlight(const string& cityA, const string& cityB, int cost) {
        adjList[cityA].push_back({cityB, cost});
        adjList[cityB].push_back({cityA, cost});
    }

    // Perform BFS to check if all nodes are reachable from a starting node
    bool isConnected() {
        unordered_map<string, bool> visited;
        if (adjList.empty()) return true; // empty graph is trivially connected
        
        // Get the first node to start BFS
        string startCity = adjList.begin()->first;

        // BFS
        queue<string> q;
        q.push(startCity);
        visited[startCity] = true;

        while (!q.empty()) {
            string city = q.front();
            q.pop();

            // Explore neighbors
            for (auto neighbor : adjList[city]) {
                if (!visited[neighbor.first]) {
                    visited[neighbor.first] = true;
                    q.push(neighbor.first);
                }
            }
        }

        // If all cities are visited, the graph is connected
        return visited.size() == adjList.size();
    }

    // Print the graph (adjacency list representation)
    void printGraph() {
        for (auto& pair : adjList) {
            cout << pair.first << " -> ";
            for (auto& neighbor : pair.second) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g;

    int n;
    cout << "Enter the number of flights: ";
    cin >> n;

    // Taking input for flights between cities
    for (int i = 0; i < n; ++i) {
        string cityA, cityB;
        int cost;
        cout << "Enter flight details (CityA CityB Cost): ";
        cin >> cityA >> cityB >> cost;
        g.addFlight(cityA, cityB, cost);
    }

    // Check if the graph is connected
    if (g.isConnected()) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }

    // Optionally, print the graph
    cout << "\nGraph (Adjacency List Representation):\n";
    g.printGraph();

    return 0;
}

// OR 
// #include <iostream>
// #include <vector>
// #include <map>
// #include <queue>

// using namespace std;

// // Function to check whether the graph is connected using Breadth First Search (BFS)
// bool isConnected(vector<vector<pair<int, int>>>& graph, int startNode) {
//     vector<bool> visited(graph.size(), false);
//     queue<int> queue;
//     queue.push(startNode);
//     visited[startNode] = true;

//     while (!queue.empty()) {
//         int currentNode = queue.front();
//         queue.pop();

//         for (auto neighbor : graph[currentNode]) {
//             int neighborNode = neighbor.first;
//             if (!visited[neighborNode]) {
//                 queue.push(neighborNode);
//                 visited[neighborNode] = true;
//             }
//         }
//     }

//     for (bool nodeVisited : visited) {
//         if (!nodeVisited) {
//             return false;
//         }
//     }

//     return true;
// }

// int main() {
//     // Map of airports or cities
//     map<string, int> airports;
//     airports["A"] = 0;
//     airports["B"] = 1;
//     airports["C"] = 2;
//     airports["D"] = 3;
//     airports["E"] = 4;

//     // Creating an adjacency list
//     vector<vector<pair<int, int>>> adjacencyList(5);

//     // Adding flight paths between cities (edges in the graph)
//     adjacencyList[airports["A"]].push_back({airports["B"], 1});
//     adjacencyList[airports["B"]].push_back({airports["C"], 2});
//     adjacencyList[airports["C"]].push_back({airports["D"], 3});
//     adjacencyList[airports["D"]].push_back({airports["E"], 4});
//     adjacencyList[airports["E"]].push_back({airports["A"], 5});

//     // Checking whether the graph is connected or not
//     bool connected = isConnected(adjacencyList, airports["A"]);

//     if (connected) {
//         cout << "The graph is connected." << endl;
//     } else {
//         cout << "The graph is not connected." << endl;
//     }

//     return 0;
// }

