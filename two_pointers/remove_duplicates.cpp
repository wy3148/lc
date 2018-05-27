//https://www.lintcode.com/problem/remove-duplicates-from-sorted-array-ii/description

// Description
// Follow up for "Remove Duplicates":
// What if duplicates are allowed at most twice?

// For example,
// Given sorted array A = [1,1,1,2,2,3],
// Your function should return length = 5, and A is now [1,1,2,2,3].

class Solution
{
  public:
    /**
     * @param A: a list of integers
     * @return : return an integer
     */
    int removeDuplicates(vector<int> &nums)
    {
    // write your code here
    std:
        map<int, int> count;
        vector<int> s;

        for (auto v : nums)
        {
            if (count[v] == 0)
            {
                s.push_back(v);
            }
            count[v]++;
        }

        int i = 0;
        for (auto v : s)
        {
            if (count[v] >= 2)
            {
                nums[i] = nums[i + 1] = v;
                i += 2;
            }
            else
            {
                nums[i] = v;
                i++;
            }
        }
        return i;
    }
};