/**
 *等学会KMP，用KMP重写
 **/
int strStr(char * haystack, char * needle){
    int count = 0;
    if(strlen(needle) == 0) return 0;
    while(*haystack){
        char *a = haystack;
        char *b = needle;
        while(*a == *b){
            *a++;
            *b++;
            if(*b == '\0') return count;
        }
        haystack++;
        count++;
    }
    return -1;
}