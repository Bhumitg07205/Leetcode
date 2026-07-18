class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>i_set;
        unordered_set<int>j_set;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    i_set.insert(i);
                    j_set.insert(j);
                }
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i_set.find(i)!=i_set.end()){
                    matrix[i][j]=0;
                }if(j_set.find(j)!=j_set.end()){
                    matrix[i][j]=0;
                }
            }
        }
    }
};