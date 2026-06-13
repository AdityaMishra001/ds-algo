class Solution {
public:
    //2 approaches==>>
    //Bottom up
    //Top down

    //bottom up is easier as we do not need to check if vaild (2 pairs exists)
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows=triangle.size();
        
        
        for(int i=rows-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};