int findNumbers(int* nums, int numsSize) {
    int count=0, temp=0, sum=0;
    for(int i=0; i<numsSize; i++){
        count=0;
        temp=nums[i];
        while(temp!=0){
            temp=temp / 10;
            count++;
        }
        if(count%2==0){
            sum++;
        }
    }
    return sum;
}
