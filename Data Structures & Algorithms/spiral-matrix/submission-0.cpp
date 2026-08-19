class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();

        int sX = 0, sY = 0, eX = n - 1, eY = m - 1;
        int turn = 0;
        while(sX <= eX && sY <= eY){
            int t = turn % 4;
            if(t == 0){
                for(int i = sX; i <= eX; i++){
                    res.push_back(matrix[sY][i]);
                }
                sY++;
            }
            else if(t == 1){
                for(int j = sY; j <= eY; j++){
                    res.push_back(matrix[j][eX]);
                }
                eX--;
            }
            else if(t == 2){
                for(int i = eX; i >= sX; i--){
                    res.push_back(matrix[eY][i]);
                }
                eY--;
            }
            else{
                for(int j = eY; j >= sY; j--){
                    res.push_back(matrix[j][sX]);
                }
                sX++;
            }
            turn++;
        }   
        return res;
    }
};
