/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define METHOD 2

#if METHOD == 1 /* Force myself using binary search */
int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

bool BS(int* nums, int numsSize, int target){
    int left = 0, right = numsSize - 1, mid = 0;
    while(left <= right){
        mid = left + (right - left)/2;
        if( nums[mid] == target){
            return true;
        }else if( nums[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return false;
}

#define MAXV 1000
int* de_duplicated(int* nums, int* numsSize){
    int retSize = 0;
    bool map[MAXV+1] = {0};
    for(int i = 0; i < (*numsSize); i++){
        if(!map[nums[i]]){
            map[nums[i]] = true;
            retSize++;
        }
    }
    nums = realloc(nums, retSize * sizeof(int));
    int j = 0;
    for(int i = 0; i <= MAXV; i++){
        if(map[i]){
            nums[j++] = i;
        }
    }
    *numsSize = retSize;
    return nums;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    /* Sort one array */
    qsort(nums1, nums1Size, sizeof(int), compare);

    /* search another array and compare by sorted array */
    int *ans_arr = NULL;
    *returnSize = 0;
    for(int i = 0; i < nums2Size; i++){
        if( BS(nums1, nums1Size, nums2[i]) ){
            (*returnSize)++;
            ans_arr = realloc(ans_arr, (*returnSize)*sizeof(int));
            ans_arr[*returnSize-1] = nums2[i];
        }
    }
    
    /* remove duplicated in ans_arr*/
    ans_arr = de_duplicated(ans_arr, returnSize);
    return ans_arr;
}
#endif

#if METHOD == 2 /* Better method, using bitmap, no order */
#define MAXV 1001
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    /* Create a bitmap using */
    bool map[MAXV] = {false};
    int *retArr = malloc( ((nums1Size>=nums2Size)?nums1Size:nums2Size) * sizeof(int));
    *returnSize = 0;
    for(int i = 0; i<nums1Size; i++){
        map[nums1[i]] = true;
    }

    /* Check another arr, if common then add to arr*/
    for(int i = 0; i<nums2Size; i++){
        if(map[nums2[i]]){
            retArr[(*returnSize)++]=nums2[i];
            map[nums2[i]] = false;
        }
    }

    /* recycle unuse space, realloc guarantee the value */
    retArr = realloc(retArr, (*returnSize) * sizeof(int));
    return retArr;
}
#endif
