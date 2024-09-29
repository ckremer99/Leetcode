class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string common_prefix = strs[0]; 
        for (int i = 1; i < strs.size(); i++) {
            int char_count = 0; 
            while(char_count < common_prefix.size()) {
                if (strs[i][char_count] != common_prefix[char_count]) {
                    common_prefix = common_prefix.substr(0, char_count);
                    break;
                }
                char_count++; 
            }
        }
        return common_prefix; 
    }
};