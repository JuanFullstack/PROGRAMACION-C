#include <stdio.h>

#define ROWS 3
#define COLS 3

void transposeMatrix(int matrix[ROWS][COLS], int transposed[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
}

void displayMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[ROWS][COLS] = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};
    int transposed[COLS][ROWS];

    printf("Matriz original:\n");
    displayMatrix(matrix);

    transposeMatrix(matrix, transposed);

    printf("\nMatriz transpuesta:\n");
    displayMatrix(transposed);

    return 0;
}
