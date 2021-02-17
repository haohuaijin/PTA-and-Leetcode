/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (42.26%)
 * Likes:    473
 * Dislikes: 0
 * Total Accepted:    88.1K
 * Total Submissions: 208.5K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 * 
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 * 
 * 示例:
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * 运行你的函数后，矩阵变为：
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * 解释:
 * 
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 * 
 */

// @lc code=start
// DFS 从两边开始搜索
// 从边界的元素以及和边界元素相接的元素不被填充为'X'，我得到一个思路，就是可以从边界上开始
// 深度优先搜索，对搜索到的元素'O'进行标记成'A'，最后遍历整个数组，那些没有被标记成'A'的'O'就是会被填充
// 成'X'的元素，最后将'A'恢复成'O'。
// 为什么会想到这个思路呢？ 因为如果直接遍历整个数组进行DFS的话，会使得将一些和边界相连的'O'标记成'A'的
// 过程比较麻烦（我没写出来)，然后突然灵光一闪，想到可以从边界进行dfs。
/*
class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c){
        int m = board.size(); // row
        int n = board[0].size(); //col

        board[r][c] = 'A';
        if(r - 1 >= 0 && board[r-1][c] == 'O')  dfs(board, r-1, c);
        if(r + 1 < m  && board[r+1][c] == 'O')  dfs(board, r+1, c);
        if(c - 1 >= 0 && board[r][c-1] == 'O')  dfs(board, r, c-1);
        if(c + 1 < n  && board[r][c+1] == 'O')  dfs(board, r, c+1);

    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(!m) return;
        int n = board[0].size();
        
        for(int c = 0; c < n; ++c){
            if(board[0][c] == 'O') dfs(board, 0, c);
            if(board[m-1][c] == 'O') dfs(board, m-1, c);
        }
        for(int r = 1; r < m-1; ++r){
            if(board[r][0] == 'O') dfs(board, r, 0);
            if(board[r][n-1] == 'O') dfs(board, r, n-1);
        }

        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(board[r][c] == 'O')        board[r][c] = 'X';
                else if(board[r][c] == 'A')   board[r][c] = 'O';
            }
        } 
    }
};
*/
// BFS 也是从边界开始
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if(!m) return;
        int n = board[0].size();

        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                bool isEdge = ((r == 0) || (r == m-1) || (c == 0) || (c == n-1));//通过一个变量来指示边界
                if(isEdge && (board[r][c] == 'O')){
                    queue<pair<int, int>> q;
                    q.push({r, c});
                    board[r][c] = 'A';
                    while(!q.empty()){
                        auto t = q.front(); q.pop(); // queue的头是front
                        int x = t.first, y = t.second;
                        
                        if(x - 1 >= 0 && board[x-1][y] == 'O') { q.push({x-1, y}); board[x-1][y] = 'A'; }  
                        if(x + 1 < m  && board[x+1][y] == 'O') { q.push({x+1, y}); board[x+1][y] = 'A'; }  
                        if(y - 1 >= 0 && board[x][y-1] == 'O') { q.push({x, y-1}); board[x][y-1] = 'A'; }  
                        if(y + 1 < n  && board[x][y+1] == 'O') { q.push({x, y+1}); board[x][y+1] = 'A'; }  
                    }
                }
            }
        } 
        for(int r = 0; r < m; ++r){
            for(int c = 0; c < n; ++c){
                if(board[r][c] == 'O')       board[r][c] = 'X';
                else if(board[r][c] == 'A')  board[r][c] = 'O';
            }
        } 
    }
};
// @lc code=end