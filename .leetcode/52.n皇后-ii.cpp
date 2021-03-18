/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (82.19%)
 * Likes:    239
 * Dislikes: 0
 * Total Accepted:    57.3K
 * Total Submissions: 69.7K
 * Testcase Example:  '4'
 *
 * n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：n = 4
 * 输出：2
 * 解释：如上图所示，4 皇后问题存在两个不同的解法。
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：n = 1
 * 输出：1
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * 皇后彼此不能相互攻击，也就是说：任何两个皇后都不能处于同一条横行、纵行或斜线上。
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution{
public:
    int N;
    int queenPos[10];
    int totalNQueens(int n){
        int ret = 0;
        N = n;
        NQueens(ret, 0);
        return ret;
    }
    void NQueens(int &ret, int k){
        int i;
        if(k == N){
            ret += 1;
            return;
        }
        for(i=0; i<N; i++){
            int m;
            for(m=0; m<k; m++){
                if((queenPos[m] == i) || (abs(k-m) == abs(i-queenPos[m])))
                    break;
            }
            if(m == k){
                queenPos[k] = i;
                NQueens(ret, k+1);
            }
        }
    }
};
// @lc code=end
