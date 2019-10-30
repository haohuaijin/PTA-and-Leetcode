int lengthOfLongestSubstring(char * s){
    int count = 1;
    int index;
    int max = 1;
    int book[66] = {0};
    int lenght = strlen(s);
    for(int i=0;i<lenght-1;i++){
        count = 1;
        memset(book,0,sizeof(int)*66);
        book[abs(s[i]-'a')] = 1;
        index = i + 1;
        while(1){
            if(!book[abs(s[i]-'a')]){
                book[abs(s[i]-'a')] = 1;
                count++;
            } else break;
            if(count > max){
                max = count;
            }
            index++;
            if(index > lenght) break;
        }
    }
    return max;
}