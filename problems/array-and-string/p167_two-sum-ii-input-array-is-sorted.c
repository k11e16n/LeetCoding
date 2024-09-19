/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
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
