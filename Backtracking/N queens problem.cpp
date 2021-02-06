 //base case many 
     //n==0
     // print
     //for loop 
            //isvalid
     //place queen n-1
     //call next row
     //if size==end
     
     //remove queen
     //call on next position


class Solution {
public:
   
  vector<vector<string>> solveNQueens(int n) 
    {  vector<vector<string>> result;
        vector<string> temp(n, string(n, '.'));
        solveNQueens(result, temp, 0, n);
        return result;
    }
    void solveNQueens(vector<vector<string>> &result, vector<string> &temp, int cur_row, int left) {
        // goal : we have no queens left, all queens are put in a proper pos
        if(cur_row == temp.size()) {
            if(left == 0) {
                result.push_back(temp);
            }
            return;
        }
        // constrain, before modifying we should make sure this is a valid input
        for(int col = 0; col < temp.size(); ++col) {
            if(helper(temp, cur_row, col)) {
                temp[cur_row][col] = 'Q';
                solveNQueens(result, temp, cur_row+1, left-1);
                temp[cur_row][col] = '.';
            }
        }
        // no possible solution
        return;
    }
    bool helper(vector<string> &temp, int row, int col) {
        // check row
        for(int i = 0; i < row; ++i) {
            if(temp[i][col] == 'Q') {
                return false;
            }
        }
        // check col
        for(int i = 0; i < col; ++i) {
            if(temp[row][i] == 'Q') {
                return false;
            }
        }
        // check main diagnoal
        int r = row-1, c = col-1;
        while(r >= 0 && c >= 0) {
            if(temp[r--][c--] == 'Q') return false;
        }
        // check auxiliary diag
        r = row-1, c = col+1;
        while(r >= 0 && c < temp.size()) {
            if(temp[r--][c++] == 'Q') return false;
        }
        return true;
    }
     
     
     
     
     
     
    
       
    
};
