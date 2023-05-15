#include <stdio.h>
#include <limits.h>

#define INF INT_MAX
#define N 4

int tsp(int graph[][N], int mask, int pos, int dp[][N]) {
    if (mask == (1 << N) - 1) {
        return graph[pos][0]; // Return to the starting node
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int minCost = INF;
    for (int i = 0; i < N; i++) {
        if ((mask & (1 << i)) == 0) {
            int newCost = graph[pos][i] + tsp(graph, mask | (1 << i), i, dp);
            if (newCost < minCost) {
                minCost = newCost;
            }
        }
    }

    dp[mask][pos] = minCost;
    return minCost;
}

int main() {
    int graph[N][N] = {
        {0, 10, 15, 20},
        {5, 0, 9, 10},
        {6, 13, 0, 12},
        {8, 8, 9, 0}
    };

    int dp[1 << N][N];
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }

    int minCost = tsp(graph, 1, 0, dp);
    printf("Minimum cost for TSP: %d\n", minCost);

    return 0;
}
