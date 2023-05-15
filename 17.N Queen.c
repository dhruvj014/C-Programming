#include <stdio.h>
#define N 4

int board[N][N];

// Function to check if a queen can be placed at board[row][col]
int isSafe(int row, int col) {
    int i, j;

    // Check if there is a queen in the same row
    for (i = 0; i < col; i++) {
        if (board[row][i] == 1)
            return 0;
    }

    // Check upper diagonal on the left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    // Check lower diagonal on the left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j] == 1)
            return 0;
    }

    return 1;
}

// Function to solve the N-Queens problem using backtracking
int solveNQueens(int col) {
    // Base case: If all queens are placed, return true
    if (col >= N)
        return 1;
    // Try placing a queen in each row of the current column
    for (int row = 0; row < N; row++) {
        // Check if the queen can be placed at board[row][col]
        if (isSafe(row, col)) {
            // Place the queen at board[row][col]
            board[row][col] = 1;

            // Recursively place the rest of the queens
            if (solveNQueens(col + 1))
                return 1;

            // If placing the queen at board[row][col] doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }
    // If no queen can be placed in the current column, return false
    return 0;
}
// Function to print the N-Queens solution
void printSolution() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the board with all 0s
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = 0;
        }
    }

    // Solve the N-Queens problem
    if (solveNQueens(0)) {
        printf("Solution:\n");
        printSolution();
    } else {
        printf("No solution found!\n");
    }

    return 0;
}
