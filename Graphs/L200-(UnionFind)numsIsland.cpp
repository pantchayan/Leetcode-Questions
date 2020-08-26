#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // Union Find method
        
        if(grid.size()==0) return 0;
        
        int N = grid.size();
        int M = grid[0].size();
        
        vector<int> par;
        
        for(int i=0;i<N*M;i++){
            par.push_back(i);
        }
        
        int numOfOnes = 0;
        int mergeCount = 0;
        int dir[2][2] = {{1,0},{0,1}};
        int count = 0;
        for(int i=0;i<N*M;i++){
            int r = i/M;
            int c = i%M;
            
            if(grid[r][c]=='1'){
                numOfOnes++;
                for(int k=0;k<2;k++){
                    int x = r + dir[k][0];
                    int y = c + dir[k][1];
                
                    if(x>=0 && y>=0 && x<N && y<M && grid[x][y]=='1'){
                        int j = x*M + y;
                        int l1 = findPar(i,par);
                        int l2 = findPar(j,par);
                        
                        if(l1!=l2){
                            par[l2] = l1;
                            mergeCount++;
                        }
                
                    }
                }
            }
            
        }
        
        // for(int i=0;i<par.size();i++){
        //     if(par[i]==i && grid[i/M][i%M]=='1'){
        //         count++;
        //     }
        // }

        return numOfOnes-mergeCount;
    }
    
    int findPar(int vtx,vector<int> &par){
        if(par[vtx]==vtx) return vtx;
        return vtx = findPar(par[vtx],par);
    }
};