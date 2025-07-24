int climbStairs(int n) {
    int result = 0;
    if(n == 0 || n == 1){
        return 1;
    }

    int current = 1, prev = 1;
    for(int i = 1; i < n; i++){
        int tmp = current;
        current += prev;
        prev = tmp; 
    }
    return current;
}