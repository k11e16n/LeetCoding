/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *Result = malloc( numsSize * sizeof(int) );
    int min=0;
    *returnSize = numsSize;

    for(int i=0; i<numsSize; i++){
        min=nums[i]*nums[i];
        for(int j=i; j<numsSize; j++ ){
            if(min>=Result[j]){
                min=Result[j];
                Result[j]=Result[i];
                Result[i]=min;
            }
        }
    }

    return Result;
}
