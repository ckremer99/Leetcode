class Solution {
public:
    bool canJump(vector<int>& nums) { 
        int ptr = 0; 
        int max_jump = 0;
        while(ptr < nums.size() - 1) {
            max_jump = max(nums[ptr], max_jump-1);
            if(max_jump == 0) {
                return false;
            }
            ptr++;
        }
        return true;
    }
};