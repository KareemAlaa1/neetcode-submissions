class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] ={0};
        int cols[9] ={0};
        int sqrs[9] ={0};

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')continue;
                int value = board[i][j]-'1';
                if((rows[i] & (1 << (value-1))) || (cols[j] & (1 << (value-1))) ||
                (sqrs[i/3 *3 +j/3] & (1 << (value-1))) ) return false;

                rows[i] |= (1 << (value-1));
                cols[j] |= (1 << (value-1));
                sqrs[i/3 *3 +j/3] |= (1 << (value-1));
            } 
        }
        return true;
    }
};
