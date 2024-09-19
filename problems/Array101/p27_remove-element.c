int removeElement(int* nums, int numsSize, int val) {
    int i=0, j=numsSize-1, count=0;

    while(i<=j){
        if(nums[i] == val){
            while(i<j && nums[j]==val){
                count++;
                j--;
            }

            nums[i]=nums[j];
            count++;
            j--;
        }
        i++;
    }

    return numsSize-count;
}

/* A better method on the internet
int removeElement(int* nums, int numsSize, int val) {
    int k=0;
    int i;
    for (i =0 ; i < numsSize ; i++) {
        if(nums[i] != val) {
            nums[k++] = nums[i];
        }
    }
    return k;
}
*/
