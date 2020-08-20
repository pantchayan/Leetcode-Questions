#include <vector>
#include <queue>
 using namespace std;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid.size()==0){
            return 0;
        }
        if(grid[0][0]==1){
            return -1;
        }
        
        
        queue<pair<int,int>> que;
        
        int N = grid.size();
        
        
            
        int level = 1;
        
        que.push({0,0});
        
        grid[0][0] = 1;
        
        int dir[8][2] = {{-1, -1}, {-1, 0}, {0, -1}, {-1, 1}, {1, -1}, {0, 1}, {1, 0}, {1, 1}};
        
        while(que.size()!=0){
            int size = que.size();
            while(size-->0){
                pair rvtx = que.front();
                que.pop();
                int i = rvtx.first;
                int j = rvtx.second;
                if(i==N-1 && j==N-1){
                    return level;
                }
                for(int k=0;k<8;k++){
                
                    int l = i + dir[k][0];
                    int m = j + dir[k][1];
                    
                    if(l>=0 && m >=0 && l<N && m < N){
                        if(grid[l][m]==0){
                            que.push({l,m});
                            grid[l][m] = 1;
                        }
                    }
                }
            }
            level++;
        }
        
        return -1;
        
    }
};