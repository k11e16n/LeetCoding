
int map[50] = {0};

int fib(int n){
  if (n < 2) {
    return n;
  } else {
    map[n-1] = (map[n-1] == 0)?fib(n-1):map[n-1];
    map[n-2] = (map[n-2] == 0)?fib(n-2):map[n-2];
    return map[n-1]+map[n-2];
  }
}
