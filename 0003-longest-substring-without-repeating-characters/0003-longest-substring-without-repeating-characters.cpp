class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0; 
        int maxLength = 0; 
        map<char, int> mp;
        for (int end = 0; end < s.size(); end++) {
            if (mp.find(s[end]) != mp.end() && mp[s[end]] >= start) {
                start = mp[s[end]] + 1;
            }
        mp[s[end]] = end; 
        maxLength = max(maxLength, end - start + 1); 
        }
        return maxLength; 
    }
};