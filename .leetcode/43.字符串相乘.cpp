/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (41.05%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    38.8K
 * Total Submissions: 94.1K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start
class Solution {
public:
/*
    //大体思路：手写乘法模拟计算
    string multiply(string num1, string num2) {
        int f = 0, s = 0,i = 0;
        int carry = 0;
        string res,mid;
        if(num1[0] == '0' || num2[0] == '0') return "0";
        while(!num2.empty()){
            carry = 0;
            f = num2[num2.size()-1] - '0';
            num2.pop_back();
            for(int j=0; j<i; j++) mid += '0'; //添加零
            
            for(int k = num1.size()-1; k >= 0; k--){
                s = num1[k] - '0';
                mid += to_string((carry + s * f) % 10);
                carry = (carry + s * f)/10;
            }
            
            if(carry != 0) mid += to_string(carry);

            reverse(mid.begin(), mid.end());

            AddString(res, mid);
            mid.clear();
            i++;
        }
        return res;
    }
    void AddString(string &res, string &mid){
        int f, s, carry = 0;
        string tmp;
        while(!res.empty() || !mid.empty()){
            f = 0; s = 0;
            if(!res.empty()){
                f = res[res.size()-1] - '0';
                res.pop_back();
            }
            if(!mid.empty()){
                s = mid[mid.size()-1] - '0';
                mid.pop_back();
            }
            if(f + s + carry >= 10){
                tmp += to_string((f+s+carry)%10);
                carry = (f+s+carry)/10;
            } else {
                tmp += to_string(f+s+carry);
                carry = 0; //注意这里
            }
        }
        if(carry != 0) tmp += to_string(carry);
        res = tmp;
        tmp.clear();
        reverse(res.begin(), res.end());
    }*/
    //竖式乘法
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        string res(n1+n2, '0');
        for(int i=n1-1; i>=0; i--){
            for(int j=n2-1; j>=0; j--){
                int tmp = (res[i+j+1]-'0') + (num1[i]-'0')*(num2[j]-'0');
                res[i+j+1] = tmp%10 + '0'; //余数
                res[i+j] += tmp/10; //进位
            }
        }
        //去除前面多余的0
        for(int i=0; i<n1+n2; i++){
            if(res[i] != '0')
                return res.substr(i);
        }
        return "0";
    }
};
// @lc code=end

