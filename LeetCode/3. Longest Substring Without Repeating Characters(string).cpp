/**
 * 暴力法，时间比较大 
 */
int lengthOfLongestSubstring(char * s){
    int count = 1;
    int index;
    int max = 1;
    int book[150] = {0}; 
    int lenght = strlen(s);
    if(!strcmp(s,"")) return 0;
    for(int i=0;i<lenght-1;i++){
        count = 1;
        memset(book,0,sizeof(int)*150);
        book[s[i]-' '] = 1;
        index = i + 1;
        while(!book[s[index]-' ']){
            book[s[index]-' '] = 1;
            index++;
            count++;
            if(index >= lenght) break;
        }
        if(count > max) max = count;
    }
    return max;
}