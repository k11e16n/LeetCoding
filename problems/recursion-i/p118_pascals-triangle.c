/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    /* Size of Rows */
    *returnSize = numRows;

    /* Size of Cols
     * The sizes of the arrays are returned as *returnColumnSizes array.
     * Put each column size in this array.
     * The caller might use like this:
        for (int i = 0; j < returnColumnSizes[i]; j++) {...}
    */
    *returnColumnSizes = malloc(numRows * sizeof(int));

    /* Create the 2D array */
    int **retArr = malloc(numRows * sizeof(int*));

    for(int i = 0; i<numRows; i++){
        retArr[i] = malloc((i+1) * sizeof(int));
        (*returnColumnSizes)[i]=i+1;
        //printf("The %dth Col size is %d\n", i, i+1);
        for(int j = 0; j<=i; j++){
            if(j == i || j == 0){
                //printf("process [%d][%d]=1\n", i, j);
                retArr[i][j]=1;
            }else{
                retArr[i][j]=retArr[i-1][j-1] + retArr[i-1][j];
                //printf("process [%d][%d]=%d\n", i, j, retArr[i][j]);
            }
        }
    }
    return retArr;
}
