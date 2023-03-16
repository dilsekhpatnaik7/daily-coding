// Problem Link: https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-all-four-sum-numbers

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                int low = j + 1, high = n - 1, sum3 = target - nums[i] - nums[j];
                while(low < high) {
                    if(nums[low] + nums[high] < sum3) low++;
                    else if(nums[low] + nums[high] > sum3) high--;
                    else if(nums[low] + nums[high] == sum3) {
                        ans.push_back({nums[i], nums[j], nums[low], nums[high]});
                        
                        while(low < high && nums[low] == nums[low + 1]) low++;
                        while(low < high && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;

                    }
                }
                while(j + 1 < n - 2 && nums[j + 1] == nums[j]) ++j;;
            }
            while(i + 1 < n - 3 && nums[i + 1] == nums[i]) ++i;
        }
        return ans;
    }
};