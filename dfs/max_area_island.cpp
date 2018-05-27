
// 695. Max Area of Island
// DescriptionHintsSubmissionsDiscussSolution
// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

// Example 1:
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
// Example 2:
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
// Note: The length of each dimension in the given grid does not exceed 50.

class Solution {
public:
    void dfs(vector<vector<int>>& grid,vector<vector<bool>>& visited,int i, int j, int& cur){
        if (i + 1 < grid.size() && grid[i+1][j] == 1 && visited[i+1][j] == false){
            visited[i+1][j] = true;
            cur++;
            dfs(grid,visited,i+1,j,cur);
        }
        
        if (i - 1 >= 0 && grid[i-1][j] == 1 && visited[i-1][j] == false){
            visited[i-1][j] = true;
            cur++;
            dfs(grid,visited,i-1,j,cur);
        }
 
        if (j+1 < grid[0].size() && grid[i][j+1] == 1 && visited[i][j+1] == false){
            visited[i][j+1] = true;
            cur++;
            dfs(grid,visited,i,j+1,cur);
        }
        
        if (j-1 >= 0 && grid[i][j-1] == 1 && visited[i][j-1] == false){
            visited[i][j-1] = true;
            cur++;
            dfs(grid,visited,i,j-1,cur);
        }   
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;        
        int m = grid.size();
        
        if ( m == 0) return res;
        int n = grid[0].size();
        
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        
        for (int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                if (grid[i][j] == 1 && visited[i][j] == false){
                    int c = 1;
                    visited[i][j] = true;
                    dfs(grid,visited,i,j,c);
                    res = max(res,c);
                }
            }
        }
        return res;
    }
};
