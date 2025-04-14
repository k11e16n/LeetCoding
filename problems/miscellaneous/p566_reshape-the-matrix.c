/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    /* Check legal first */
    if((matSize*(*matColSize)) != (r*c)){
        printf("illegal!\n");
        *returnSize = matSize;
        *returnColumnSizes = matColSize;
        return mat;
    }

    /* alloc return arr memory */
    int **ret_arr = (int**)malloc( r * sizeof(int *));
    *returnColumnSizes = (int*) malloc( r * sizeof(int *));
    for(int i = 0; i < r; i++){
        ret_arr[i] = (int*)malloc( c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    /* Apply number */
    int position = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            ret_arr[i][j] = mat[position/(*matColSize)][position%(*matColSize)];
            //printf("[DBG]ret_arr[%d][%d] = %d\n", i, j, ret_arr[i][j]);
            position++;
        }
    }
    *returnSize = r;

    return ret_arr;
}
