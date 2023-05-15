#include<stdio.h>
#define V 4

void djikstra(int graph[V][V], int src)
{
    int dist[V];
    int sol[V];

    for(int i=0;i<V;i++){
        dist[i] = 999999;
        sol[i] = 0;
    }
    dist[src] = 0;
    for (int i=0;i<V-1;i++)
    {
        int u = minDistance(dist,sol);
        sol[u]=1;

        for(int j=0;j<V;j++)
        {
            if(sol[j]==0 && graph[i][j] != 0 && dist[i] != 999999 && dist[i]+graph[i][j]<dist[j]){
                dist[j] = dist[i]+graph[i][j];
            }
        }
    }
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int minDistance(int dist[V],int sol[V])
{
    int min=999999,min_ind;
    for(int v=0;v<V;v++)
    {
        if(sol[v]==0 && dist[v]<=min){
            min = dist[v];
            min_ind = v;
        }
    }
    return min_ind;
}
int main()
{
    int graph[V][V] = {
        {0,1,3,0},
        {0, 0, 1, 10},
        {0, 0, 0, 4},
        {0, 0, 0, 0}
    };

    djikstra(graph, 0);

    return 0;
}
