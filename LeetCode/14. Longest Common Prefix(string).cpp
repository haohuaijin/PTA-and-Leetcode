char * longestCommonPrefix(char ** strs, int strsSize){
    int i = 0;
    if(strsSize == 0) return ""; //要考虑strsSize为0的情况
    while(1){ //控制列
        for(int j=0;j<strsSize;j++){ //控制行
            if(strs[0][i] != strs[j][i] || strs[j][i] == '\0'){
                strs[0][i] = '\0';
                return strs[0];
            }
        }
        i++;
    }
    return NULL;
}