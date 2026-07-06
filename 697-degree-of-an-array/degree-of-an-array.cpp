class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> first;
        unordered_map<int, int> last;

        for (int i = 0; i < nums.size(); i++){
            if(first.find(nums[i]) == first.end())
            first[nums[i]] = i;
            last [nums[i]] = i;
            freq[nums[i]]++;
        }
        int degree = 0;
        int ans = nums.size();

        for (auto &it: freq){
            degree = max(degree, it.second);
        }
        for (auto &it : freq){
            if (it.second == degree){
                ans = min (ans, last[it.first] - first[it.first] + 1);
            }
        }
        return ans;
    }
};