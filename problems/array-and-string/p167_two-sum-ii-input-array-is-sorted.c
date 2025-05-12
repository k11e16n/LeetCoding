/**
 * Note: The returned array must be malloced, assume caller calls free().
*/
#define METHOD 1
#if METHOD == 1 // BS
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    *returnSize = 2; // Because exactly one solution
    int* ans = malloc(2 * sizeof(int));
    for (int i = 0; i < numbersSize; i++) {
        int complement = target - numbers[i];
        // 在 [i+1..numbersSize-1] 用二分找 complement
        int left = i + 1, right = numbersSize - 1;
        while (left <= right) { // Template I
            int mid = left + (right - left) / 2;
            if (numbers[mid] == complement) {
                ans[0] = i + 1;  // 题目要求 1-based 索引
                ans[1] = mid + 1;
                return ans;
            } else if (numbers[mid] < complement) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    // 一定能找到，不会走到这里
    return NULL;
}
#endif

#if METHOD == 2 // Two pointer
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    int index_1 = 0, index_2 = numbersSize - 1;

    while (index_1 < index_2) {
        if (numbers[index_1] + numbers[index_2] == target) {
            int* retArr = malloc(2 * sizeof(int));
            *returnSize = 2;
            retArr[0] = ++index_1;
            retArr[1] = ++index_2;
            return retArr;
        }else if (numbers[index_1] + numbers[index_2] > target) {
            index_2--;
        } else if (numbers[index_1] + numbers[index_2] < target) {
            index_1++;
        }
    }
    *returnSize = 0;
    return NULL;
}
#endif
