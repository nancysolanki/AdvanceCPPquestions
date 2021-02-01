//using binary search approach 


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
          int row = matrix.size();
        int col = matrix[0].size();
        int i = row-1,j =0;
        while(i>=0&&j<=col-1)
        {
            if(target>matrix[i][j])
            {
                j++;
            }
            else if(target<matrix[i][j])
            {
                i--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    
};
