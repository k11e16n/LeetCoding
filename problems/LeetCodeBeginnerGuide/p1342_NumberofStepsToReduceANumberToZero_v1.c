int numberOfSteps(int num) {
	int i =  num, count = 0;
	while(num!=0){
			if( num % 2 == 0){
					num = num / 2;
			}else{
					num -= 1;
			}
			count++;
	}
	return count;
}
