#define METHOD 1
#define INF 100001

#if METHOD == 1 /* O(n log(n)), think of binary search */

int minSubArrayLen(int target, int* nums, int numsSize) {
    /* prepare a presum array where
     * prefix[0] = 0
     * prefix[i] = sum of nums[0 .. i-1]
     */
    int *presum = malloc((numsSize + 1)*sizeof(int));
    memset(presum, 0, (numsSize + 1)*sizeof(int));
    for(int i = 1; i<=numsSize; i++){
        presum[i] = presum[i-1] + nums[i-1];
    }

    /* for each presum[i], find a smallest presum[j]
     * so that presum[j] - presum[i] >= target
     * Why:
     * the question is find a minimal sum(nums[i]+...+nums[j-1]) >= target
     * presum[j] - presum[i] >= target  ===> nums[j-1]+...+nums[i] >= target
     * so just search each i,j pair and minimal length is the answer.
     */

    /* for each i in presum, find a j >= target
     * and presum is ascending, so we can use Binary search
     */
     int min = INF, left = 0, right = numsSize;
    for(int i = 0; i<numsSize; i++){
        left = i;
        right = numsSize;

        // binary search: find first j s.t. presum[j] >= presum[i] + target
        while(left < right){
            int mid = left + (right - left)/2;
            if( (presum[mid] - presum[i]) >= target ){
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        if( (presum[left] - presum[i]) >= target ){
            if((left - i) < min){
                min = left - i;
            }
        }
    }
    free(presum);
    return (min == INF)?0:min;
}
#endif

#if METHOD == 2
int minSubArrayLen(int target, int* nums, int numsSize) {
    int l_pos = 0, r_pos = 0, count = 0, sum = 0, min = NaN;

    while( r_pos < numsSize ){
        /* Move right */
        sum += nums[r_pos];

        /* until we found greater than target */
        while( sum >= target ){
            /* we update min if needed */
            if( (r_pos - l_pos + 1)  < min){
                min = (r_pos - l_pos + 1);
            }
            /* Move left */
            sum -= nums[l_pos++];
        }
        r_pos++;
    }

    return (min==INF)?0:min;
}
#endif
