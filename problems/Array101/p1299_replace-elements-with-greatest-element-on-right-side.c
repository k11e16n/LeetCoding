/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* replaceElements(int* arr, int arrSize, int* returnSize) {
    int max=-1, temp=0;;
    *returnSize = arrSize;

    for(int i=arrSize-1; i>=0; i--){
        temp=arr[i];
        arr[i]=max;
        if(temp>max){
            max=temp;
        }
    }
    return arr; 
}
