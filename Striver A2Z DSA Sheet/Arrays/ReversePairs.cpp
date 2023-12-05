// Problelm Link: https://leetcode.com/problems/reverse-pairs/

class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high) {
        vector<int> temp; 
        int left = low;      
        int right = mid + 1;   
        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left]);
                left++;
            }
            else {
                temp.push_back(nums[right]);
                right++;
            }
        }
        while (left <= mid) {
            temp.push_back(nums[left]);
            left++;
        }
        while (right <= high) {
            temp.push_back(nums[right]);
            right++;
        }
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }

    int countPairs(vector<int> &nums, int low, int mid, int high) {
        int right = mid + 1;
        int pairs = 0;
        for (int i = low; i <= mid; i++) {
            while (right <= high && (long long)nums[i] > (long long)2 * (long long)nums[right]) right++;
            pairs += (right - (mid + 1));
        }
        return pairs;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        int pairs = 0;
        if(low >= high) return pairs;
        int mid = (low + high) / 2;
        pairs += mergeSort(nums, low, mid);
        pairs += mergeSort(nums , mid + 1, high);
        pairs += countPairs(nums, low , mid , high);
        merge(nums, low , mid , high);

        return pairs;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};