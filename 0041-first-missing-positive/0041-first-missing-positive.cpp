class Solution {
public:
    int firstMissingPositive(vector<int>& nums) { 
        sort(nums.begin(), nums.end());
        
        int idx = 0; 
        
        while (idx < nums.size() && nums[idx] <= 0) {
            idx++; 
        }

        int counter = 1;  

        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] > counter) {
                return counter; 
            }
            if (nums[i] == counter) {
                counter++; 
            }
        }
        return counter; 
    }
};
