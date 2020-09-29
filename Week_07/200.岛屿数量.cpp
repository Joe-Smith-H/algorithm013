/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 *
 * https://leetcode-cn.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (50.07%)
 * Likes:    722
 * Dislikes: 0
 * Total Accepted:    145.3K
 * Total Submissions: 290K
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。
 * 
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ['1','1','1','1','0'],
 * ['1','1','0','1','0'],
 * ['1','1','0','0','0'],
 * ['0','0','0','0','0']
 * ]
 * 输出: 1
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ['1','1','0','0','0'],
 * ['1','1','0','0','0'],
 * ['0','0','1','0','0'],
 * ['0','0','0','1','1']
 * ]
 * 输出: 3
 * 解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
 * 
 * 
 */

// @lc code=start
#include<vector>
using namespace std;

class Solution {
public:
       
    int numIslands(vector<vector<char>>& grid) {
        int nrow = grid.size();
        if (nrow == 0) return 0;
        int ncol = grid[0].size();
        
        int count = 0;
        for (size_t i = 0; i < nrow; i++)
        {
            for (size_t j = 0; j < ncol; j++)
            {
                if (grid[i][j] == '1')
                {
                    count++;
                    dfs(grid, i, j);
                }
            }
            
        }
        return count;
        
    }

    void dfs(vector<vector<char>>&grid, int row, int col)
    {
        int nrow = grid.size();
        int ncol = grid[0].size();
        grid[row][col] = '0';
        if (row-1>=0 && grid[row-1][col] == '1') dfs(grid, row-1, col);
        if (row+1<nrow && grid[row+1][col] == '1') dfs(grid, row+1, col);
        if (col-1>=0 && grid[row][col-1] == '1') dfs(grid, row, col-1);
        if (col+1<ncol && grid[row][col+1] == '1') dfs(grid, row, col+1);
    }
};
// @lc code=end

