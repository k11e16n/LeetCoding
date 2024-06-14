int thirdMax(int* nums, int numsSize) {

    // using one array to store first three number
    // Using LONG because it is bigger than int in 64 bit memory
    long rank[3]={LONG_MIN, LONG_MIN, LONG_MIN};
    for(int i=0; i<numsSize; i++){
        if(rank[0]==nums[i] || rank[1]==nums[i] || rank[2]==nums[i]) {
            continue;
        }

        if(nums[i]>rank[0]){
            rank[2]=rank[1];
            rank[1]=rank[0];
            rank[0]=nums[i];
        }else if(nums[i]>rank[1]){
            rank[2]=rank[1];
            rank[1]=nums[i];
        }else if(nums[i]>rank[2]){
            rank[2]=nums[i];
        }
    }

    return (rank[2]==LONG_MIN)?rank[0]:rank[2];
}
