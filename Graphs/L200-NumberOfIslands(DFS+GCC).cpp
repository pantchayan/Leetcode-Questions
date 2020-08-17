#include <vector>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0) return 0;
        
        int tr = grid.size();
        int tc = grid[0].size();
        
        int count = 0;
        for(int i=0;i<tr;i++){
            for(int j=0;j<tc;j++){
                if(grid[i][j]=='1'){
                    count++ ;
                    dfs_numsIslands(i,j,tr,tc,grid);
                }
            }
        }
        
        return count;
    }
    
    
    void dfs_numsIslands(int r,int c,int tr,int tc,vector<vector<char>>& grid){
        if(grid[r][c]== '0'){
            return;
        }
        
        
        //DFS body 
        grid[r][c] = '0';
        
        if(c+1 < tc){
            dfs_numsIslands(r,c+1,tr,tc,grid);
        }
        if(r+1 < tr){
            dfs_numsIslands(r+1,c,tr,tc,grid);
        }
        if(c-1 >= 0){
            dfs_numsIslands(r,c-1,tr,tc,grid);
        }
        if(r-1 >= 0){
            dfs_numsIslands(r-1,c,tr,tc,grid);
        }
        
        
        
    }
    
    
};