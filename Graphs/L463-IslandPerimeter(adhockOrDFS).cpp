#include <vector>
using namespace std;

class Solution {
public:
    int perimeter = 0;
    int islandPerimeter(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        
        int tr = grid.size();
        int tc = grid[0].size();
        int total1s = 0;
        int commonReg = 0;
        
        
        for(int i=0;i<tr;i++){
            for(int j=0;j<tc;j++){
                if(grid[i][j]==1){
                    total1s ++ ;
                    
                    if(j+1<tc && grid[i][j+1]==1){
                        commonReg++;
                    }
                    if(i+1<tr && grid[i+1][j]==1){
                        commonReg++;
                    }
                }
            }
        }
        return total1s*4 - commonReg*2;
    }
    
    
    
    
};