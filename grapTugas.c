#include <stdio.h>
#include <stdlib.h>

// Graph structure dengan adjacency matrix
struct Graph {
    int numVertices;
    int isDirected;
    int** adjMatrix;
};

// Buat graph dengan adjacency matrix
struct Graph* createGraph(int vertices, int directed) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->isDirected = directed;
    
    // Alokasi memory untuk adjacency matrix
    graph->adjMatrix = malloc(vertices * sizeof(int*));
    int i, j;
    for (i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = malloc(vertices * sizeof(int));
        // Inisialisasi semua nilai dengan 0
        for (j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
    
    return graph;
}

// Tambah edge
void addEdge(struct Graph* graph, int src, int dest) {
    // Tambah edge dari src ke dest
    graph->adjMatrix[src][dest] = 1;
    
    // Jika undirected, tambah edge dari dest ke src
    if (!graph->isDirected) {
        graph->adjMatrix[dest][src] = 1;
    }
}

// Print adjacency matrix
void printMatrix(struct Graph* graph) {
    int i, j;
    printf("Adjacency Matrix (%s):\n", 
           graph->isDirected ? "Directed" : "Undirected");
    
    // Print header
    printf("   ");
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    // Print matrix dengan row labels
    for (i = 0; i < graph->numVertices; i++) {
        printf("%d: ", i);
        for (j = 0; j < graph->numVertices; j++) {
            printf("%d ", graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // UNDIRECTED GRAPH
    printf("1. UNDIRECTED GRAPH:\n");
    struct Graph* undirected = createGraph(5, 0);
    
    addEdge(undirected, 0, 1);
    addEdge(undirected, 0, 4);
    addEdge(undirected, 1, 2);
    addEdge(undirected, 1, 3);
    addEdge(undirected, 1, 4);
    addEdge(undirected, 2, 3);
    addEdge(undirected, 3, 4);
    
    printMatrix(undirected);
    
    // DIRECTED GRAPH
    printf("\n2. DIRECTED GRAPH:\n");
    struct Graph* directed = createGraph(4, 1);
    
    addEdge(directed, 0, 1);
    addEdge(directed, 0, 2);
    addEdge(directed, 1, 2);
    addEdge(directed, 2, 0);
    addEdge(directed, 2, 3);
    addEdge(directed, 3, 3);
    
    printMatrix(directed);
    
    return 0;
}