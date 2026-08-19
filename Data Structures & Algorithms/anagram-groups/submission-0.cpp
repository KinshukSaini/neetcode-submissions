class Solution {
public:
    bool is_anna(int i, int j, vector<int>& vis, vector<string>& strs){
        string s = strs[i];
        string t = strs[j];
        map<char, int> mpp1;
        map<char, int> mpp2;
        int n = s.size();
        int m = t.size();
        if(n != m) return false;

        for(int i = 0; i < n; i++){
            mpp1[s[i]]++;
            mpp2[t[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(mpp1[s[i]] != mpp2[s[i]]) return false;
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<int> vis(n, 0);
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            vector<string> arr;
            arr.push_back(strs[i]);
            vis[i] = 1;
            for(int j = i + 1; j < n; j++){
                if(vis[j]) continue;
                if(is_anna(i, j, vis, strs)){
                    arr.push_back(strs[j]);
                    vis[j] = 1;
                }
            }
            ans.push_back(arr);
        }
        return ans;
    }
};
