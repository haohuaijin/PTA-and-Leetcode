#include <iostream>
#include <vector>
#include <string>
using namespace std;

void getNext(const string& str, vector<int>& next){
    next[0] = -1;
    int i = 0, j = -1;
    int len = str.size();
    while(i < len){
        if(j == -1 || str[i] == str[j]){
            ++i; ++j;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int KMP(string haystack, string needle) {
    int i = 0, j = 0;
    int len1 = haystack.size(), len2 = needle.size();
    if(len2 == 0) return 0;
    vector<int> next(len2+1);
    getNext(needle, next);

    while(i < len1 && j < len2){
        if(j == -1 || haystack[i] == needle[j]){
            ++i; ++j;
        } else {
            j = next[j];
        }
    }

    if(j == len2) 
        return i - j;
    else    
        return -1;
}

int main(){
    string s1 = "ababababc";
    string s2 = "abc";
    vector<int> next(s2.size());
    int index = KMP(s1, s2);
    cout << s1.substr(index, s2.size() - index) << endl;
    return 0;
}