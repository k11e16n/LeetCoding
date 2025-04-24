// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1, right = n, mid = 0;

    while(left < right){
        mid = left + (right - left)/2;
        if(isBadVersion(mid)){
            right = mid;
        }else{
            left = mid + 1;
        }
    }

    return left;
}
