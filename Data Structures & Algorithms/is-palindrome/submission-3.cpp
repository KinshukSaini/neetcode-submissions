class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int l = 0, r = n - 1;

        while(l <= r){
            char left = tolower(s[l]);
            char right = tolower(s[r]);
            if(left < '0' || (left > '9' && left < 'a') || left > 'z') {
                l++;
                continue;
            }
            if(right < '0' || (right > '9' && right < 'a') || right > 'z'){
                r--;
                continue;
            }
            
            if(left != right) return false;
            
            l++, r--;
        }
        return true;
    }
};
