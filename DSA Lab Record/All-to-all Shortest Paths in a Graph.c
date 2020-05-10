#include<stdio.h>
#define min(x, y) (((x) > (y)) ? (y) : (x))
#define V 4
#define INF 99999

void printGraph(int graph[V][V]);
void floydWarshall(int graph[V][V]);

void floydWarshall(int graph[V][V]) {
    int i, j, k;
    for(k = 0; k < V; k++) {
        for(j = 0; j < V; j++) {
            for(i = 0; i < V; i++) {
                graph[i][j] =  min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }
    printGraph(graph);
}

void printGraph(int graph[V][V]) {
    printf("All to All shortest paths matrix \n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (graph[i][j] == INF) {
                printf(" INF ");
            }
            else {
                printf("  %d  ", graph[i][j]);
            }
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = { {0,   5,  INF, 10}, 
                        {INF, 0,   3, INF}, 
                        {INF, INF, 0,   1}, 
                        {INF, INF, INF, 0} 
                      }; 
    floydWarshall(graph);
}