#include <iostream>
#include <cstring>

using namespace std;

class Graph {
private:
    int V;
    int** adjMatrix;

public:
    Graph(int vertices) : V(vertices) {

        adjMatrix = new int*[V];
        for (int i = 0; i < V; ++i)
            adjMatrix[i] = new int[V];


        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                adjMatrix[i][j] = 0;
    }

    ~Graph() {

        for (int i = 0; i < V; ++i)
            delete[] adjMatrix[i];
        delete[] adjMatrix;
    }


    void addEdge(int v, int w) {
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1;
    }

    void BFS(int start) {

        bool* visited = new bool[V];
        memset(visited, false, V);


        int* queue = new int[V];
        int front = 0, rear = 0;


        visited[start] = true;
        queue[rear++] = start;

        while (front < rear) {

            int current = queue[front++];
            cout << current << " ";


            for (int neighbor = 0; neighbor < V; ++neighbor) {
                if (adjMatrix[current][neighbor] && !visited[neighbor]) {
                    visited[neighbor] = true;
                    queue[rear++] = neighbor;
                }
            }
        }

        delete[] visited;
        delete[] queue;
    }


void DFSUtil(int v, bool visited[]) {

    visited[v] = true;
    cout << v << " ";


    for (int neighbor = 0; neighbor < V; ++neighbor) {
        if (adjMatrix[v][neighbor] && !visited[neighbor])
            DFSUtil(neighbor, visited);
    }
}


    void DFS(int start) {

        bool* visited = new bool[V];
        memset(visited, false, V);


        DFSUtil(start, visited);

        delete[] visited;
    }
};

int main() {

    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);


    cout << "BFS starting from vertex 0: ";
    g.BFS(0);
    cout << endl;


    cout << "DFS starting from vertex 0: ";
    g.DFS(0);
    cout << endl;

    return 0;
}
