class Solution {
public:
    bool isAnagram(string s, string t) {
        int m = s.size(), n = t.size();
        if(m != n) return false;
        map<char, int> mpp1;
        map<char, int> mpp2;

        for(char c : s) mpp1[c]++;
        for(char c : t) mpp2[c]++;
        for(auto [c, f] : mpp1){
            if(mpp2[c] != f) return false;
        }
        return true;
    }
};
