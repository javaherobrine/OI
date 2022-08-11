#include<bits/stdc++.h>
using namespace std;
//if target-nums[i]==nums[j],nums[i]+nums[j]==target,i,j should be returned
//URL:https://leetcode.cn/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>map{};
        vector<int>result;
        for(int i=0;i<nums.size();i++){
        	map.insert({target-nums[i],i});//put numbers and their indexes
        }
        for(int i=0;i<nums.size();i++){
        	try{
        		int j=map.at(nums[i]);
        		if(j==i){//if j==i,the elements are the same.
        			continue;
        		}else{//or they are different
        			result.push_back(j);//add j
        			result.push_back(i);//add i
        			return result;//return the result
        		}
        	}catch(exception& e){//if nums[i]+nums[j]!=target,the circulation should be executed again
        		continue;
        	}
        }
        return result;//can also return nullptr
    }
};
