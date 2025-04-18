/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    *returnSize = matrixSize * *matrixColSize;
    int *ret_arr = malloc( *returnSize * sizeof(int));
    int i = 0, direction = 0, m = 0, n = 0;
    int limit_top = 0, limit_right = *matrixColSize - 1, limit_bottom = matrixSize - 1, limit_left = 0;
    while( i < (matrixSize * *matrixColSize) ){
        /* ⭢ */
        if( direction == 0){
            /* Check boundary */
            if( n < limit_right ){
                ret_arr[i] = matrix[m][n++];
            }else{
                ret_arr[i] = matrix[m][n];
                m++;
                limit_top++;
                /* Change direction */
                direction = (direction + 1) % 4 ;
            }

        /* ⭣ */
        }else if (direction == 1){
            /* Check boundary */
            if( m < limit_bottom ){
                ret_arr[i] = matrix[m++][n];
            }else{
                ret_arr[i] = matrix[m][n];
                n--;
                limit_right--;
                /* Change direction */
                direction = (direction + 1) % 4 ;
            }
        /* ⭠ */
        }else if (direction == 2){
            /* Check boundary */
            if( n > limit_left ){
                ret_arr[i] = matrix[m][n--];
            }else{
                ret_arr[i] = matrix[m][n];
                m--;
                limit_bottom--;
                /* Change direction */
                direction = (direction + 1) % 4 ;
            }
        /* ⭡ */
        }else if (direction == 3){
            if( m > limit_top ){
                ret_arr[i] = matrix[m--][n];
            }else{
                ret_arr[i] = matrix[m][n];
                n++;
                limit_left++;
                /* Change direction */
                direction = (direction + 1) % 4 ;
            }
        }

        /* Check end condition */
        i++;
    }
    return ret_arr;
}




/* Recursive method from Internet */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 /**
  Refer the solution on the internet. Using dr, dc to know which direction to go
  dr, dc
  0   1   -> row fixed, go through all col from left to right
  1   0   -> go through all raw from top to bottom, col fixed
  0   -1  -> row fixed, go through all col from right to left
  -1  0   -> go through all raw from bottom to top, col fixed

  and we use r,c to record current position.
 */
void spiral(int **matrix, int m, int n, int **result, int *result_iter, int r, int c, int dr, int dc){
    if(m == 0 || n == 0)
        return;

    for(int i = 0; i < n; i++){
        /* Only go through first line. */
        r = r + dr;
        c = c + dc;
        (*result)[(*result_iter)++] = matrix[r][c];
    }

    spiral(matrix, n, (m-1), result, result_iter, r, c, dc, -dr);
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {

    *returnSize = matrixSize * matrixColSize[0];
    int *result_arr = (int *)malloc( *returnSize * sizeof(int));
    int result_iter = 0;

    spiral( matrix, matrixSize, *matrixColSize, &result_arr, &result_iter, 0, -1, 0, 1);
    return result_arr;
}
