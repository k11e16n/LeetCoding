/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if(digitsSize == 0){
        return NULL;
    }
    bool carry = true;
    for(int i = digitsSize - 1; i >= 0; i-- ){
        if(carry){
           digits[i]++;
           carry = false;
        }
        if(digits[i] == 10){
            digits[i] = 0;
            carry = true;
        }
    }
    if(carry){
        int *new_array = malloc( (digitsSize+1) * sizeof(int) );
        memcpy(new_array+1, digits, digitsSize * sizeof(int) );
        new_array[0] = 1;
        *returnSize = digitsSize + 1;
        return new_array;
    }

    *returnSize = digitsSize;
    return digits;
}
