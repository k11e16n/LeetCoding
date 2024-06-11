/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *Result = malloc( numsSize * sizeof(int) );
    int min=0;
    *returnSize = numsSize;

    while(i<=j){
        /* Make it positive */
        if ( nums[i]<0 ){
            nums[i] = nums[i]*-1;
        }
        if ( nums[j]<0 ){
            nums[j] = nums[j]*-1;
        }

        /* Put the biggest back */
        if ( nums[i] < nums[j]){
            Result[k] = nums[j]*nums[j];
            j--;
        }else{
            Result[k]=nums[i]*nums[i];
            i++;
        }
        k--;
    }

    return Result;
}
