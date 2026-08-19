class Solution {
public:
    bool checkrow(vector<vector<char>>& board){
        for(auto r : board){
            map<char, int> mpp;
            for(auto n : r){
                if(n == '.') continue;
                if(mpp[n] != 0) return false;
                mpp[n]++;
            }
        }
        return true;
    }

    bool checkcol(vector<vector<char>>& board){
        for(int i = 0; i < 9; i++){
            map<char, int> mpp;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.') continue;
                if(mpp[board[j][i]] != 0) return false;
                mpp[board[j][i]]++;
            }
        }
        return true;
    }

    bool checkbox(vector<vector<char>>& board){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                map<char, int> mpp;
                for(int m = i * 3; m < (i + 1) * 3; m++){
                    for(int n = j * 3; n < (j + 1) * 3; n++){
                        if(board[m][n] == '.') continue;
                        if(mpp[board[m][n]] != 0) return false;
                        mpp[board[m][n]]++;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return checkrow(board) && checkcol(board) && checkbox(board);
    }
};
