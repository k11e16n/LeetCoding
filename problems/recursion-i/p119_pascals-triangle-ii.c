/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define METHOD 2

/* recursive */
#if METHOD == 1
int* getRow(int rowIndex, int* returnSize) {
    
    /* rowIndex equals size of array */
    int *ret = malloc( (rowIndex+1) * sizeof(int));
    *returnSize = rowIndex+1;

    /* Set base case for 0 and 1*/
    if(rowIndex == 0){
        ret[0] = 1;
    }else if(rowIndex == 1){
        ret[0] = 1;
        ret[1] = 1;
    }else{
        /* Get previous index to generate current index */
        int *retPrev = malloc( (rowIndex) * sizeof(int));
        int size = 0;
        retPrev=getRow(rowIndex-1, &size);

        /* Skip first and last node since it is 1 */
        ret[0]=1;
        ret[rowIndex]=1;

        /* Build up the index array */
        for(int i=1; i<rowIndex; i++){
            ret[i]=retPrev[i-1]+retPrev[i];
        }
        free(retPrev);
    }
    return ret;
}
#endif

/* two pointer method */
#if METHOD == 2
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex+1;
    int *ret = malloc( *returnSize * sizeof(int));
    
    for (int i = 0; i <= rowIndex; i++) {
        ret[i] = 1; 
        /* Node: must be start from back, otherwise the infromation will be lost */
        for (int j = i - 1; j > 0; j--) {
            ret[j] = ret[j] + ret[j - 1];
        }
    }
    return ret;
}
#endif

