/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/*
 * Ken Note: Consider using bit operation to reduce the comparison
 */
char** fizzBuzz(int n, int* returnSize) {
    char** returnArray = NULL;
    returnArray = malloc( n * sizeof(char*) );
    *returnSize=n; /* I guess this is to tell the caller the number */

    for(int i=0; i<n; i++){
        returnArray[i] = malloc(9 * sizeof(char));
        if( (i+1)%3==0 && (i+1)%5==0 ){
                returnArray[i]="FizzBuzz";
        } else if( (i+1)%3 == 0 ){
                returnArray[i]="Fizz";
        } else if( (i+1)%5 == 0 ){
                returnArray[i]="Buzz";
        }else{
            sprintf(returnArray[i],"%d",i+1);
        }
    }
    return returnArray;
}
