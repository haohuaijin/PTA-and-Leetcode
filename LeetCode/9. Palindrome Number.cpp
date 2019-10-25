bool isPalindrome(int x){
    //用数组记录位数，比较
    /*int count = 0;
    int a[100] = {0};
    int num = x;
    int flag = 1;
    if(x < 0) return false;
    else {
        while(num != 0) {
            a[count++] = num%10;
            num /= 10; 
        }
        for(int i=0;i<count/2;i++){
            if(a[i] != a[count-i-1]) flag = 0;
        }
        if(flag) return true;
        else return false;
    }*/
    //反转后面的数字
    if(x < 0 || x%10 == 0 && x != 0) return false;
    int reverse = 0;
    while(x > reverse){
        reverse = reverse*10 + x%10;
        x /= 10;
    }
    return x == reverse || x == reverse/10;
}