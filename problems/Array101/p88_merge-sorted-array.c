void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int *retArr=malloc(nums1Size * sizeof(int));
    int i=0, j=0, k=0;

    while(k<nums1Size){
        if(m==0 && n !=0 ){
            retArr[k]=nums2[j];
            j++;
        }else if (m!=0 && n == 0){
            retArr[k]=nums1[i];
            i++;
        }else{ /* both not zero */
            if(i<m && j<n){
                if(nums1[i]>nums2[j]){
                    retArr[k]=nums2[j];
                    j++;
                }else{
                    retArr[k]=nums1[i];
                    i++;
                }
            }else if(i>=m){
                retArr[k]=nums2[j];
                j++;
            }else{ //j>n
                retArr[k]=nums1[i];
                i++;
            }
        }
        k++;
    }

    for(int i=0; i<nums1Size; i++){
        nums1[i]=retArr[i];
    }
    free(retArr);
}
