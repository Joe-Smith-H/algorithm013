/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include<vector>
#include<map>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        map<int,int>tmp_map;
        for (size_t i = 0; i < nums.size(); i++)
        {
            map<int,int>::iterator index = tmp_map.find(nums[i]);
            if (index != tmp_map.end())
            {
                res.push_back(index->second);
                res.push_back(i);
                break;
            }
            else
            {
                tmp_map[target - nums[i]] = i;
            }
        }
     return res;   
    }
};
// @lc code=end

