/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** construct2DArray(int* original, int originalSize, int m, int n, int* returnSize, int** returnColumnSizes) {
    int **ret_arr = NULL;
    if(m*n != originalSize){
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    /* Allocate for m*n array */
    ret_arr = (int **)malloc( m * sizeof(int *) );
    *returnColumnSizes = (int *) malloc( m * sizeof(int) );
    for(int i = 0; i < m; i++){
        ret_arr[i] = (int *)malloc( n * sizeof(int));
        (*returnColumnSizes)[i] = n;
    }

    /* insert the number */
    for(int i = 0; i < originalSize; i++){
        ret_arr[i/n][i%n] = original[i];
        //printf("ret_arr[%d][%d] = original[%d]:%d\n", i/n, i%n, i, original[i]);
    }

    *returnSize = m;

    return ret_arr;
}
