/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int *map=(int*)malloc((numsSize+1)* sizeof(int)); // plus zero
    int *retArr=(int*)malloc((numsSize+1)* sizeof(int)); // plus zero
    memset(map, 0, (numsSize+1)* sizeof(int));
    memset(retArr, 0, (numsSize+1)* sizeof(int));
    int j=0;


    /* Create a map with nums */
    for(int i=0; i<numsSize; i++){
        map[nums[i]]+=1;
    }

    /* Check the map, if the zero means what it lack of */
    for(int i=1; i<=numsSize; i++){
        if(map[i]==0){
            retArr[j]=i;
            j++;
        }
    }
    *returnSize = j;
    free(map);
    return retArr;
}
