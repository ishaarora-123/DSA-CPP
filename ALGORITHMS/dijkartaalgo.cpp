#include <iostream>
#include <limits.h>
using namespace std;
int const V = 5;
int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX;
    int min_index;
    for (int i = 0 ; i < V ; i ++) {
        if(sptSet[i] == false && dist[i] <= min) {
            min = dist[i]; min_index = i;
        }
    }
    return min_index;
}
void dijkstra(int graph[V][V], int source) {
    int dist[V];
    bool sptSet[V];
    for (int i  = 0; i < V ; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[source] = 0;
    //sptSet[source] = true;
    for (int i = 0 ; i < V-1 ; i ++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (int j = 0 ; j < V ; j++) {
            if ((graph[u][j] != 0 )&& (sptSet[j] == false) && ((dist[u] + graph[u][j]) < dist[j])) {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }


    for (int i = 0 ; i < V ; i ++) {
        cout << i <<"  "<< dist[i]<< endl;
    }
}
int main() {
    int graph[V][V] = {{0,2,0,6,0},
                        {2,0,3,8,5},
                        {0,3,0,0,7},
                        {6,8,0,0,9},
                        {0,5,7,9,0}};
    dijkstra(graph,0);
    return 0;
}