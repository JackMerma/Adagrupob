/** 
* @author      : Jackson Fernando Merma Portocarrero (jmermap@unsa.edu.pe)
* @filename    : maximal_square
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //dimensiones de la matriz
        int height=matrix.size();
        int width=matrix[0].size();
        
        int data[height+1][width+1];
        int ans=0;
        
        
        for(int i=0; i<=height; i++){
            for(int u=0; u<=width; u++){
                if(i==0||u==0){
                    data[i][u]=0;
                }else if(matrix[i-1][u-1] != '0'){
                    data[i][u]=min(data[i-1][u-1],min(data[i-1][u],data[i][u-1]))+1;
                    ans=max(ans,data[i][u]);
                }else{
                    data[i][u]=0;
                }
            }
        }
        
        return ans*ans;
    }
};