#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int N = grid.size();
        int M = grid[0].size();
        
        if(N==0){
            return 0;
        }
        if(N==1 && M==1){
            if(grid[0][0]==0){
                return 0;
            }
        }
        
        
        
        int level = 0;
        
        queue<int> que;
        
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(grid[i][j]==2){
                    que.push(i*M +j);
                }
            }
        }
        
        while(que.size()!=0){
            int size = que.size();
            while(size -- >0){
                
                int vtx = que.front();
                que.pop();
                
                
                int i = vtx/M;
                int j = vtx%M;
                
                for(int k=0;k<4;k++){
                    int r = i + dir[k][0];
                    int c = j + dir[k][1];
                    
                    if(r>=0 && c>=0 && r<N && c<M){
                        if(grid[r][c]==1){
                            grid[r][c] = 2;
                            
                            que.push(r*M +c);
                        }
                    }
                }
            }
            level++ ;
        }
        
        for(vector<int> arr: grid){
            for(int o:arr){
                if(o==1){
                    return -1;
                }
            }
        }
        
        return level-1;
    }
};