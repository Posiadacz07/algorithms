int numberOfSteps(int num) {
    int result = 0;
    while(num != 0){
        if(num%2 == 0){
            result++;
            num /= 2;
        } else {
            result++;
            num -= 1;
        }
    }
    return result;
}