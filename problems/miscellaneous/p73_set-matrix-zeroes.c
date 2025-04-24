void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    
    /* Create a col store col zero information. */
    bool *col_chk = (bool *)malloc( *matrixColSize * sizeof(bool));
    memset(col_chk, 1, *matrixColSize * sizeof(bool)); /* just set to non-zero value*/
    bool resetRow = 0;

    for(int r = 0; r < matrixSize; r++){
        for(int c = 0; c < *matrixColSize; c++){
            if(matrix[r][c] == 0){
                /* Clear entire row later */
                resetRow = 1;
                /* Update col_chk table */
                col_chk[c] = 0;
            }
        }
        if(resetRow){
            memset(matrix[r], 0, (*matrixColSize) * sizeof(int) );
            resetRow = 0;
        }
    }
    /* Finally we clean up for all col to zero if needed */
    for(int i = 0; i < (*matrixColSize); i++){
        if(col_chk[i] == 0){
            for(int j = 0; j < matrixSize; j++){
                matrix[j][i] = 0;
            }
        }
    }
}

/* Solution on internet which is also trivial*/
#include <stdio.h>
#include <stdlib.h>

void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int rowZero = 0, colZero = 0;

    // First pass: Identify which rows and columns need to be zeroed
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize[i]; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;

                if (i == 0) rowZero = 1;
                if (j == 0) colZero = 1;
            }
        }
    }

    // Second pass: Zero out non-first rows and columns based on markers
    for (int i = 1; i < matrixSize; i++) {
        for (int j = 1; j < matrixColSize[i]; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out the first row if needed
    if (rowZero) {
        for (int j = 0; j < matrixColSize[0]; j++) {
            matrix[0][j] = 0;
        }
    }

    // Zero out the first column if needed
    if (colZero) {
        for (int i = 0; i < matrixSize; i++) {
            matrix[i][0] = 0;
        }
    }
}
