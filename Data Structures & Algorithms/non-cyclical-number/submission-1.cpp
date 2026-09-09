class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> s;
        while(true){
            s.insert(n);
            if(n == 1) return true;
            int sum = 0;
            int temp = n;
            while(temp){
                int a = temp % 10;
                sum += a * a;
                temp /= 10;
            }
            n = sum;
            if(s.find(sum) != s.end()) return false;
        }
        return true;
    }
};
