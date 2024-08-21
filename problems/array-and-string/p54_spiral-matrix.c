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
