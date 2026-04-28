class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size()*matrix[0].size()-1;
        int mid = 0;

        while(l<=r){
            mid = l + (r-l)/2;
            if(matrix[mid/matrix[0].size()][mid%matrix[0].size()]>target){
                r = mid-1;
            }else if (matrix[mid/matrix[0].size()][mid%matrix[0].size()]<target){
                l = mid+1;
            }else{
                return true;
            }
        }
        return false;
    }
};
