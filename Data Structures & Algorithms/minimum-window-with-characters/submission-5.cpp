class Solution {
public:
    bool eq(const vector<int>& s, const vector<int>& t){
        for(int i = 0; i < 128; i++){
            if(t[i] == 0) continue;
            if(t[i] > s[i]) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if(m < n) return "";
        if(s == t) return t;
        int minLen = INT_MAX;
        string res = "";
        int start = -1;
        vector<int> mppS(128, 0);
        vector<int> mppT(128, 0);
        for(int i = 0; i < n; i++){
            mppT[(unsigned char)t[i]]++;
        }
        int l = 0, r = 0;
        mppS[(unsigned char)s[0]]++;
        while(r < m){
            if(eq(mppS, mppT)) while(eq(mppS, mppT)){
                if(minLen > r - l + 1){
                    minLen = r - l + 1;
                    start = l;
                }
                mppS[(unsigned char)s[l]]--;
                l++;
            }
            else{
                if(r == m - 1) break;
                r++;
                mppS[(unsigned char)s[r]]++;
            }

        }
        if(minLen == INT_MAX) return "";
        return s.substr(start, minLen);

    }
};