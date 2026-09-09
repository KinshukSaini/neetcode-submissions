class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> mpp;
        while(true){
            if(n == 1) return true;
            mpp[n] = 1;
            int sum = 0;
            int temp = n;
            while(temp){
                int a = temp % 10;
                sum += a * a;
                temp /= 10;
            }
            n = sum;
            if(mpp[n]) return false;
        }
        return true;
    }
};
