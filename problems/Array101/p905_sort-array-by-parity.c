/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    int i=0, j=numsSize-1, temp=0;
    *returnSize=numsSize;

    while(i<j){
        if(nums[i]%2==0){
            i++;
        }else if(nums[j]%2!=0){
            j--;
        }else{
            temp=nums[i];
            nums[i]=nums[j];
            nums[j]=temp;
        }
    }
    return nums;
}
