/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include<iostream>
#include<list>
#include<vector>

using namespace std;
class MaxQueue
{
private:
    list<int> m_list;

public:
    MaxQueue(){}
    virtual ~MaxQueue(){}

    // push方法
    void push(int n) {
        while (!m_list.empty() && m_list.back() < n)
        {
            // 删除队尾元素
            m_list.pop_back();
        }

        m_list.push_back(n);
        
    }

    // pop方法
    void pop(int n) {
        if (m_list.front() == n)
        {
            m_list.pop_front();
        }
        
    }

    // max方法
    int max() {
        return m_list.front();
    }
};


// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MaxQueue tmpQueue;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (i < k - 1)
            {
                tmpQueue.push(nums[i]);
            } else {
                // 添加最后一个元素
                tmpQueue.push(nums[i]);
                // 获取最大值
                res.push_back(tmpQueue.max());
                // 删除第一个元素
                tmpQueue.pop(nums[i - k + 1]);
            }
            
        }
        
        return res;
    }
};
// @lc code=end

