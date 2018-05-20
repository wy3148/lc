//https://leetcode.com/problems/friend-circles/description/

// There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

// Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

// Example 1:
// Input: 
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2
// Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
// The 2nd student himself is in a friend circle. So return 2.
// Example 2:
// Input: 
// [[1,1,0],
//  [1,1,1],
//  [0,1,1]]
// Output: 1
// Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
// so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
// Note:
// N is in range [1,200].
// M[i][i] = 1 for all students.
// If M[i][j] = 1, then M[j][i] = 1.

class Solution
{
  public:
    void dfs(vector<vector<int>> &M, vector<vector<bool>> &visited, int i, int j)
    {
        for (int p = 0; p < M.size(); p++)
        {
            if (M[j][p] == 1 && visited[j][p] == false)
            {
                visited[j][p] = true;
                if (p != i && p != j)
                {
                    dfs(M, visited, j, p);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>> &M)
    {

        int n = M.size();
        int res = 0;

        if (n == 0)
            return 0;

        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int i = 0; i < n; i++)
        {

            for (int j = 0; j < n; j++)
            {

                if (M[i][j] == 1 && visited[i][j] == false)
                {
                    res++;
                    dfs(M, visited, i, j);
                }
            }
        }

        return res;
    }
};

//use queue as bfs solution
class Solution
{
  public:
    int findCircleNum(vector<vector<int>> &M)
    {

        std::queue<int> q;
        int n = M.size();
        int res = 0;

        //each persion
        vector<bool> visited(n, false);

        for (int i = 0; i < n; i++)
        {
            if (visited[i])
                continue;

            q.push(i);

            //i->j friend, push j in the queue

            while (!q.empty())
            {

                auto front = q.front();
                q.pop();

                //each element in the queue since they are in the same friend circle
                //tag them as visited = true
                visited[front] = true;

                for (int j = 0; j < n; j++)
                {
                    if (M[front][j] == 1 && visited[j] == false && front != j)
                    {
                        q.push(j);
                    }
                }
            }

            res++;
        }

        return res;
    }
};