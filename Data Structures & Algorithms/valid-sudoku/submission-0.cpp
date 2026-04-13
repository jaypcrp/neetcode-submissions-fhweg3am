class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // vector<vector<int>> count;
        for(int i=0; i<9;i++)
    {
        unordered_map<char,int> row_count;
        unordered_map<char,int> col_count;
        
        for(int j=0;j<9;j++)
        {
            // Row check
            if(board[i][j] != '.') {
                row_count[board[i][j]]++;
                if(row_count[board[i][j]] > 1) {
                    cout << "Wrong";
                    return false;
                }
            }
            
            // Column check
            if(board[j][i] != '.') {
                col_count[board[j][i]]++;
                if(col_count[board[j][i]] > 1) {
                    cout << "Wrong";
                    return false;
                }
            }
            
        }
    }
    
    for(int row = 0; row < 9; row += 3)
{
    for(int col = 0; col < 9; col += 3)
    {
        unordered_map<char,int> square_count;

        for(int i = 0; i < 3; i++)
        {
            for(int j = 0; j < 3; j++)
            {
                char val = board[row + i][col + j];

                if(val != '.')
                {
                    square_count[val]++;
                    if(square_count[val] > 1)
                    {
                        cout << "Wrong";
                        return false;
                    }
                }
            }
        }
    }
}
    return true;
    }
};
