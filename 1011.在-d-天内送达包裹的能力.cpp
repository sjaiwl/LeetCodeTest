/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int getSum(vector<int>& weights) {
        int sum = 0;
        for (auto i : weights)
        {
            sum += i;
        }

        return sum;
    }

    bool canFinish(vector<int>& weights, int mid, int D) {
        int i = 0;
        for(int day = 0; day < D; ++day) {
            int max = mid;
            while ((max -= weights[i]) >=0)
            {
                i++;
                if (i == weights.size()) {
                    return true;
                }
            }
        }
        return false;
    }

    int shipWithinDays(vector<int>& weights, int D) {
        auto maxNum = max_element(weights.begin(), weights.end());
        // 二分查找左边界
        int left = *maxNum;
        int right = getSum(weights) + 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (canFinish(weights, mid, D)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
// @lc code=end

