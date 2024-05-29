int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
	int sum=0, maxSum=0;
	for(int i=0; i<accountsSize; i++){
		sum=0;
		for(int j=0; j<*accountsColSize; j++){
			sum += accounts[i][j];
		}
		maxSum=(maxSum>=sum)?maxSum:sum;
	}
	return maxSum;
}
