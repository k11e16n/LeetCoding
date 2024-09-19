#define METHOD 2

/* Using mod */
#if METHOD == 1
void rotate(int* nums, int numsSize, int k) {
    int *retArr = malloc(numsSize * sizeof(int));
    
    for(int i = 0; i < numsSize; i++){
        retArr[(i+k)%numsSize] = nums[i];
    }
    memcpy(nums, retArr, numsSize*sizeof(int));
    free(retArr);
}
#endif

/* takeout for loop */
#if METHOD == 2
void rotate(int* nums, int numsSize, int k) {

    int *retArr = malloc(numsSize * sizeof(int));
    int shiftSize = (k % numsSize);
    memcpy(retArr, nums + (numsSize - shiftSize) , shiftSize * sizeof(int));
    memcpy(retArr + shiftSize, nums, (numsSize - shiftSize) * sizeof(int));
    memcpy(nums, retArr, numsSize*sizeof(int));
    free(retArr);
}
#endif

/* using in-place O(1) 
   using reverse, from internet
*/
#if METHOD == 3
void reverse(int* nums, int start, int end) {
    int temp;
    for(int i = start, j = end; i < j; i++,j--){
        temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
void rotate(int* nums, int numsSize, int k) {
    reverse( nums, 0, numsSize - 1);
    reverse( nums, 0, (k%numsSize)-1);
    reverse( nums, k%numsSize, numsSize - 1);
}
#endif
