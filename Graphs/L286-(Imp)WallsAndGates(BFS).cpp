#include <vector>
#include <queue>
 using namespace std;
class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        if(rooms.size()==0){
            return;
        }
        if(rooms.size()==1){
            return;
        }
        
        
        
        int N = rooms.size();
        int M = rooms[0].size();
        
        
        queue<int> que;
        
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(rooms[i][j]==0){
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
                        if(rooms[r][c]>rooms[i][j]){
                            rooms[r][c] = rooms[i][j] +1;
                            
                            que.push(r*M +c);
                        }
                    }
                }
            }
            
        }
        
        
        
    }
};