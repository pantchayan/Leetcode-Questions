#include <vector>
#include <queue>
 using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int N = matrix.size();
        
        if(N==0) return 0;
        
        int M = matrix[0].size();
        
        if(N==0 && M==1) return 1;
        
        vector<vector<int>> indegree(N,vector<int>(M,0));
        
        calcIndegree(matrix,indegree);
        
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        queue<int> que;
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(indegree[i][j]==0){
                    que.push(i*M + j);
                }
            }
        }
        
        vector<int> ans;
        int level = 0;
        
        while(que.size()!=0){
            int size = que.size();
            while(size-->0){
                int rvtx = que.front();
                que.pop();
                
                int i = rvtx/M;
                int j = rvtx%M;
                
                ans.push_back(matrix[i][j]);
                
                for(int k=0;k<4;k++){
                    int r = i+dir[k][0];
                    int c = j+dir[k][1];
                    
                    if(r>=0 && c>=0 && r<N && c<M){
                        if(matrix[i][j]<matrix[r][c]){
                            indegree[r][c]--;
                            if(indegree[r][c]==0){
                                que.push(r*M +c);
                            }
                        }
                    }
                }
            }
            level++;
        }
        
        return level;
        
        
    }
    
    void calcIndegree(vector<vector<int>>& matrix, vector<vector<int>>& indegree){
        int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        int N = matrix.size();
        int M = matrix[0].size();
        
        
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                for(int k=0;k<4;k++){
                    int r = i + dir[k][0];
                    int c = j + dir[k][1];
                    
                    if(r>=0 && c>=0 && r<N && c<M){
                        if(matrix[r][c] > matrix[i][j]){
                            indegree[r][c]++;
                        }
                    }
                    
                }
            }
        }
        
        
    }
};