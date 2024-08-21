i/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize) {
    
    /* i is for control total times 
     * m, n is edge node position
     * position_m, position_n is current node position
     * bias is for calculate the position while reverse
    */
    int i = 0, m = 0, n = 0, position_m = 0, position_n = 0, bias = 0;
    *returnSize = (matSize * *matColSize);
    int * ret_arr = malloc( *returnSize * sizeof(int));

    /* I expect ↙ as normal, so ↗ means need to change */
    bool change = true;

    /* Total runs mxn times */
    while( i < (matSize * *matColSize) ){
        
        /* we store the value */
        if( change ){ /* ↗ */
            /* if ↗ then we add bias to store with reverse sequence */
            ret_arr[i+bias] = mat[position_m][position_n];
            /* i+1 and bias -1, so total -2 */
            bias -= 2;
        }else{
            /* if ↙ we process with normal way */
            ret_arr[i] = mat[position_m][position_n];
        }

        /* Update m or n only when touch the edge which edge means top row or right column */
        if(position_m == matSize - 1 || position_n == 0 ){
            if( n != *matColSize - 1 ){
                n++;
                /* bias update when n less than row size */
                bias = (n > matSize-1)?matSize-1:n;
            }else if ( m != matSize - 1){
                m++;
                /* bias update when m less than col size */
                bias = (m < matSize-*matColSize)?*matColSize-1:matSize - m - 1;
            }
            /* Update current note to edge node */
            position_m = m;
            position_n = n;
            change = !change;
        /* we goes ↙ if not edge */
        }else{
                position_m++;
                position_n--;
        }

        i++;
    }

    return ret_arr;
}
