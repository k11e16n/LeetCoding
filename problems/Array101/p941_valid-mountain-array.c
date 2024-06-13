bool validMountainArray(int* arr, int arrSize){
    int i=1, j=0, peak=-1;

    if(arrSize<3){
        return false;
    }

    while(i<arrSize){
        if(peak==-1 && arr[i-1]>=arr[i]){
            peak=i-1;
            if(peak==0){
                return false;
            }
        }
        if(peak!=-1 && arr[i-1]<=arr[i]){
            return false;
        }
        i++;
    }
    if(peak==-1){
        return false;
    }
    return true;
}
