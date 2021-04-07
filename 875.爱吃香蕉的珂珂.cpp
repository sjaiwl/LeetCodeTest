/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int timeOf(int i, int mid) {
        if (i <= mid)
        {
            return 1;
        }

        return (i / mid) + ((i % mid) > 0 ? 1 : 0);
        
    }

    bool canFinish(vector<int>& piles, int mid, int h) {
        int time = 0;
        for (auto i : piles)
        {
            time += timeOf(i, mid);
        }
        
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        auto maxNum = max_element(piles.begin(), piles.end());
        // 二分查找左边界
        int left = 1;
        int right = *maxNum + 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (canFinish(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
        
    }
};
// @lc code=end

