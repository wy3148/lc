// https : //leetcode.com/problems/number-of-islands/description/

// Given a 2d grid map of '1' s(land) and '0' s(water), count the number of islands.An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.You may assume all four edges of the grid are all surrounded by water.

//                                                                                                                                                                              Example 1 :

//     Input : 11110 11010 11000 00000

//     Output : 1 Example 2 :

//     Input : 11000 11000 00100 00011

//     Output : 3

class Solution
{
  public:
    void dfs(vector<vector<bool>> &visited, vector<vector<char>> &grid, int x, int y)
    {

        int m = grid.size();
        int n = grid[0].size();

        if (y + 1 < n && grid[x][y + 1] == '1' && visited[x][y + 1] == false)
        {
            visited[x][y + 1] = true;
            dfs(visited, grid, x, y + 1);
        }

        if (x + 1 < m && grid[x + 1][y] == '1' && visited[x + 1][y] == false)
        {
            visited[x + 1][y] = true;
            dfs(visited, grid, x + 1, y);
        }

        if (y - 1 >= 0 && grid[x][y - 1] == '1' && visited[x][y - 1] == false)
        {
            visited[x][y - 1] = true;
            dfs(visited, grid, x, y - 1);
        }

        if (x - 1 >= 0 && grid[x - 1][y] == '1' && visited[x - 1][y] == false)
        {
            visited[x - 1][y] = true;
            dfs(visited, grid, x - 1, y);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int res = 0;
        int m = grid.size();

        if (m == 0)
            return res;
        int n = grid[0].size();

        //m *n array of array
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1' && visited[i][j] == false)
                {
                    res++;
                    visited[i][j] == true;
                    dfs(visited, grid, i, j);
                }
            }
        }

        return res;
    }
};

//bfs
class Solution
{
  public:
    void bfs(vector<vector<char>> &grid, int i, int j)
    {

        int m = grid.size();
        int n = grid[0].size();
    std:
        queue<pair<int, int>> q;
        q.push(pair<int, int>(i, j));

        while (!q.empty())
        {

            auto cur = q.front();
            q.pop();
            int x = cur.first;
            int y = cur.second;

            if (x - 1 >= 0 && grid[x - 1][y] == '1')
            {
                q.push(pair<int, int>(x - 1, y));
                grid[x - 1][y] = '0';
            }

            if (x + 1 < m && grid[x + 1][y] == '1')
            {
                q.push(pair<int, int>(x + 1, y));
                grid[x + 1][y] = '0';
            }

            if (y - 1 >= 0 && grid[x][y - 1] == '1')
            {
                q.push(pair<int, int>(x, y - 1));
                grid[x][y - 1] = '0';
            }

            if (y + 1 < n && grid[x][y + 1] == '1')
            {
                q.push(pair<int, int>(x, y + 1));
                grid[x][y + 1] = '0';
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {

        int m = grid.size();

        if (m == 0)
            return 0;

        int n = grid[0].size();
        int res = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '0';
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }
};
