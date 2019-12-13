/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
/*
    int numTrees(int n) { //动态规划
        int G[n+1] = {0};
        G[0] = 1;
        G[1] = 1;
        for(int i=2; i<=n; i++){
            for(int j=1; j<=i; j++){
                G[i] += G[j-1]*G[i-j];
            }
        }
        return G[n];
    }*/
    int numTrees(int n) { //数学演绎 Catalan number
        /*
        long int C;
        C = 1;
        for(int i=0; i<n; i++){ //Catalan number
            C = C * 2 * (2*i + 1)/(i + 2);
        }*/
        long int G[n+1] = {1};
        for(int i=0; i<n; i++){
            G[i+1] = G[i]*2*(2*i+1)/(i+2);
        }
        return (int)G[n];
    }
};
// @lc code=end

