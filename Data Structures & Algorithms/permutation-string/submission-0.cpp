class Solution {
public:
    bool checkInclusion(string s1, string s2){
        int m = s1.size(), n = s2.size();
        if(m > n) return false;
        vector<int> mpp1(26, 0);
        for(char c : s1) mpp1[c - 'a']++;

        int l = 0, r = m - 1;
        vector<int> mpp2(26, 0);
        for(int i = l; i <= r; i++) mpp2[s2[i] - 'a']++;

        while(r < n){
            if(mpp1 == mpp2) return true;
            mpp2[s2[l] - 'a']--;
            l++, r++;
            if(r == n) return false;
            mpp2[s2[r] - 'a']++;            
        }
        return false;
    }
};
