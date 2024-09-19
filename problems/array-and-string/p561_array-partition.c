#define METHOD 1

#if METHOD == 1
int min( int a, int b){
    return (a<b)?a:b;
}

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    
    /* sort the array */
    qsort(nums, numsSize, sizeof(int), compare);
    
    /* swap sort too slow
    int min = 0, i = 0, j = 0;
    for(i = 0; i < numsSize ; i++){
        min = i;
        for(j = i; j < numsSize ; j++){
            if(nums[j] < nums[min]){
                min = j;
            }
        }
        swap(&nums[i], &nums[min]);
    }
    */

    /* sum each pair */
    int sum = 0;
    for(int k = 0; k < numsSize;  k += 2){
        sum += nums[k];
    }

    return sum;
}
#endif

#if METHOD == 2
/* Internet idea
 * Using hash map to sort
 * */
int arrayPairSum(int* nums, int numsSize)
{
    uint16_t pos = 0;
    int32_t sum = 0;
    int32_t val1 = 0;
    int32_t val2 = 0;
    uint16_t map[20001] = {};

    for(uint16_t i = 0; i < numsSize; ++i)
    {
        ++map[nums[i] + 10000];
    }

    for(int16_t i = 0; i < 20001; ++i)
    {
        while(map[i]--)
        {
            if(pos % 2)
            {
                val2 = (i - 10000);
                sum += (val1 < val2 ? val1 : val2);
            }
            else
            {
                val1 = (i - 10000);
            }

            ++pos;
        }
    }

    return sum;
}
#endif
