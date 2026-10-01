class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1, high = INT_MIN;
        int res = high;
        for(int pile : piles) high = max(pile, high);
        while(low <= high){
            int spd = low + (high - low) / 2;
            int hrs = 0;
            for (int pile : piles) {
                hrs += (pile + spd - 1LL) / spd;
            }
            if(hrs > h){
                low = spd + 1;
            }
            else{
                res = spd;
                high = spd - 1;
            }
        }
        return res;
    }
};
