//https://leetcode.com/problems/most-profit-assigning-work/description/
class Solution
{
  public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int ans = 0;
        int m = 0;

        //priority queue, top element has lowest difficulty value
        auto cmp = [](pair<int, int> &l1, pair<int, int> &l2) { return l1.first > l2.first; };
        std::priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> q(cmp);

        for (int i = 0; i < difficulty.size(); i++)
        {
            q.push(pair<int, int>(difficulty[i], profit[i]));
        }

        sort(worker.begin(), worker.end());

        for (auto curWorker : worker)
        {
            while (q.size() > 0)
            {
                auto t = q.top();
                if (curWorker >= t.first)
                {
                    m = max(m, t.second); //m always is the last avaible profit
                    q.pop();
                }
                else
                {
                    break;
                }
            }
            ans += m;
        }
        return ans;
    }
};