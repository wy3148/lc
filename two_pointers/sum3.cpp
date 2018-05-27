//https://leetcode.com/problems/3sum/description/

// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0 ? Find all unique triplets in the array which gives the sum of zero.

// Note
// :

// The solution set must not contain duplicate triplets.

// Example :

// Given array nums = [ -1, 0, 1, 2, -1, -4 ],

// A solution set is :
// [
// [ -1, 0, 1 ],
// [ -1, -1, 2 ]
// ]

class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;

        int len = nums.size();
        if (len < 3)
        {
            return res;
        }

        sort(nums.begin(), nums.end());
        for (int i = 0; i < len; i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int begin = i + 1, end = len - 1;
            while (begin < end)
            {
                int sum = nums[i] + nums[begin] + nums[end];
                if (sum == 0)
                {
                    vector<int> t;
                    t.push_back(nums[i]);
                    t.push_back(nums[begin]);
                    t.push_back(nums[end]);
                    res.push_back(t);
                    begin++;
                    end--;
                    while (begin < end && nums[begin] == nums[begin - 1])
                        begin++;
                    while (begin < end && nums[end] == nums[end + 1])
                        end--;
                }
                else if (sum > 0)
                {
                    end--;
                }
                else
                    begin++;
            }
        }
        return res;
    }
};
