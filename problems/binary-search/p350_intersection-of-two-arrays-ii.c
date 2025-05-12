/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define METHOD 1

#if METHOD == 1 // Force using Binary search for follow up 1 and 2
int cmp_int(const void *a, const void *b) {
    return (*(int*)a) - (*(int*)b);
}

int* intersect(int* nums1, int m, int* nums2, int n, int* returnSize) {
    // 1. 排序
    qsort(nums1, m, sizeof(int), cmp_int);
    qsort(nums2, n, sizeof(int), cmp_int);

    // 2. 把 A 設為較小的陣列
    int *A = nums1,  a = m;
    int *B = nums2,  b = n;
    if (m > n) { A = nums2; a = n; B = nums1; b = m; }

    int *res = malloc(a * sizeof(int));
    *returnSize = 0;

    // 3. 在 B 上維護一個起始搜尋位置 low
    int low = 0;
    for (int i = 0; i < a; i++) {
        int target = A[i];
        // 二分找左邊界
        int left = low, right = b - 1, pos = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (B[mid] < target) {
                left = mid + 1;
            } else {
                if (B[mid] == target) pos = mid;
                right = mid - 1;
            }
        }
        if (pos != -1) {
            res[(*returnSize)++] = target;
            low = pos + 1;  // 下一次從 pos+1 開始，不重複
        }
    }

    // 4. 回收空間
    if (*returnSize == 0) {
        free(res);
        return NULL;
    }
    int *tmp = realloc(res, (*returnSize) * sizeof(int));
    if (tmp) res = tmp;
    return res;
}
#endif

#if METHOD == 2 // using bitmap and this is for follow up 3
#define MAXV 1001
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    /* Create a bitmap using */
    int map[MAXV] = {0};
    int *retArr = malloc( ((nums1Size>=nums2Size)?nums1Size:nums2Size) * sizeof(int));
    *returnSize = 0;
    for(int i = 0; i<nums1Size; i++){
        map[nums1[i]]++;
    }

    for(int i = 0; i<nums2Size; i++){
        if(map[nums2[i]]){
            retArr[(*returnSize)++] = nums2[i];
            map[nums2[i]]--;
        }
    }

    /* recycle unuse space, realloc guarantee the value */
    retArr = realloc(retArr, (*returnSize) * sizeof(int));
    return retArr;
}
#endif
