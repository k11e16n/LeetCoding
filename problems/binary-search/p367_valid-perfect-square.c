bool isPerfectSquare(int num) {
    int left = 0, right = num;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        uint64_t sq = (uint64_t)mid * mid;       // 用 64 位防溢位
        if (sq == (uint64_t)num) {
            return true;
        } else if (sq < (uint64_t)num) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}
