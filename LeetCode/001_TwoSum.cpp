class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto itr=nums.begin();itr!=nums.end();itr++)
            mp[*itr] = (itr-nums.begin());
        for(int i=0;i<nums.size();++i){
            int find = target - nums[i];
            if(mp.find(find) != mp.end()){
                if(mp[find] != i){
                    ans.push_back(i), ans.push_back(mp[find]);
                    break;
                }
            }
        }
        return ans;
    }
};
