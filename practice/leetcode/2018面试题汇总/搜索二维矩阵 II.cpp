class Solution {
public:
    从右上角开始所有，这样的话左边都是比自己小的
    上面都是比自己大的
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0)
        {
            return false;
        }

        int row = 0;
        int col = matrix[0].size()-1;
        while(row<matrix.size()&&col>=0){
            if(matrix[row][col]==target)
                return true;
            if(matrix[row][col]<target)
            {
                ++row;
            }
            else
            {
                --col;
            }
        }
        return false;
    }
};
