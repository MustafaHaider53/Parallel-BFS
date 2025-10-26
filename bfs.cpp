#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <chrono>   // For timing
#include <iomanip>  // For setting output precision
using namespace std;

class Graph {
    int V;
    list<int> *l;


public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // For undirected graph
    }

    void printGraph() {
        for (int i = 0; i < V; i++) {
            cout << i << " -> ";
            for (int v : l[i]) {
                cout << v << ", ";
            }
            cout << endl;
        }
    }

    void bfs(){
        // --- Start Timer ---
        auto start_time = chrono::high_resolution_clock::now();

        queue<int> Q;
        vector<bool> vis(V, false);
        Q.push(0);
        vis[0] = true;

        while(Q.size() > 0){
            int u = Q.front();
            Q.pop();
            cout << u << " ";
            for(int v : l[u]){
                if(!vis[v]){
                    vis[v] = true;
                    Q.push(v);
                }
            }
        }
        cout << endl; // Newline after traversal

        // --- Stop Timer ---
        auto end_time = chrono::high_resolution_clock::now();
        
        // Calculate and print the total duration
        chrono::duration<double> duration = end_time - start_time;
        
        cout << "BFS execution time: " << fixed 
             << setprecision(8) << duration.count() << " seconds" << endl;

    }
};

int main() {
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    cout << "BFS Traversal starting from vertex 0:" << endl;
    g.bfs(); // This will now print the traversal AND the time

    cout << "\nGraph Adjacency List:" << endl;
    g.printGraph();

    return 0;
}

