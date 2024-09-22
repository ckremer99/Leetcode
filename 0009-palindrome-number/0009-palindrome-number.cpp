#include <iostream>
#include <string> 

using namespace std; 


class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) return false; 
        int reversedHalf = 0; 
        while(reversedHalf < x) {
            reversedHalf = reversedHalf * 10 + x % 10; 
            x /= 10; 
        }

        return (x == reversedHalf || x == reversedHalf / 10); 
    }
};