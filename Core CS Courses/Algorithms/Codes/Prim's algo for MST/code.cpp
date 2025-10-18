#include <iostream>

using namespace std;

const int MAX = 100;
const int INF = 1e9;


int findMinKeyVertex(int key[], bool mstSet[], int vertices) {
    int minKey = INF;
    int minIndex = -1;

    for (int v = 0; v < vertices; ++v) {
        if (!mstSet[v] && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}


void printMST(int parent[], int graph[MAX][MAX], int vertices) {
    cout << "Edge   Weight" << endl;
    for (int i = 1; i < vertices; ++i) {
        cout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << endl;
    }
}


void primMST(int graph[MAX][MAX], int vertices) {
    int parent[MAX];
    int key[MAX];
    bool mstSet[MAX];


    key[0] = 0;


    for (int count = 0; count < vertices - 1; ++count) {
        int u = findMinKeyVertex(key, mstSet, vertices);
        mstSet[u] = true;


        for (int v = 0; v < vertices; ++v) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }


    printMST(parent, graph, vertices);
}

int main() {
    int vertices;
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    int graph[MAX][MAX];

    cout << "Enter the adjacency matrix for the graph:" << endl;
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cin >> graph[i][j];
        }
    }


    primMST(graph, vertices);

    return 0;
}

