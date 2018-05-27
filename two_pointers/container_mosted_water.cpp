//https://leetcode.com/problems/container-with-most-water/description/

class Solution
{
  public:
    int maxArea(vector<int> &height)
    {

        int start = 0;
        int end = height.size() - 1;
        int ans = 0;

        while (start < end)
        {
            //width * height = area, we start from the maximun value of width
            //the we move position either from start or from end.
            int minHeight = min(height[start], height[end]);
            //a1 , a3; width = 3 -1;
            ans = max(ans, (end - start) * minHeight);

            if (height[start] > height[end])
            {
                end--;
            }
            else
            {
                start++;
            }
        }
        return ans;
    }
};