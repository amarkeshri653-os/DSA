class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int m=mat.size();
        int n=mat[0].size();
        int low=0;
        int high=(m*n -1);
        while(low<=high){
            int mid=(low + high)/2 ;
            int row= mid / n;
            int col=mid % n;
            if(mat[row][col]==tar){
                return true;
            }
            else if(mat[row][col]<tar){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return false;
    }
};