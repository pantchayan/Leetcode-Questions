#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        
        int N = graph.size();
        
        if(N==1 && graph[0].size()==1){
            return false;
        }
        
        
        vector<int> vis(N,-1); // Red : 0, Green : 1 , Nothing : -1
        
        for(int i=0;i<N;i++){
            if(vis[i]==-1){
                bool ans = bipartiteBFS(i,vis,graph);
                if(!ans){
                    return ans;
                }
            }
        }
        
        return true;
    }
    
    
    bool bipartiteBFS(int src, vector<int> &vis,vector<vector<int>>& graph){
        
        queue<pair<int,int>> que;
        
        que.push({src,0}); // Source --> Red
        
        while(que.size()!=0){
            int size = que.size();
            while(size-->0){
                pair<int, int> rvtx = que.front();
                que.pop();
                
                 //Check to detect a cycle
            if(vis[rvtx.first]!=-1){

                //Check to detect an odd cycle
                if(vis[rvtx.first]!=rvtx.second){
                    return false;
                }
                continue;

            }
                
                vis[rvtx.first] = rvtx.second;
                
                for(int v:graph[rvtx.first]){
                    if(vis[v]==-1){
                        que.push({v, (rvtx.second+1)%2});
                        
                    }
                }
                
            }
        }
        
        
        return true;
    }
    
    
    
    
};