#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int N = edges.size();
        vector<int> size(N+1,1);
        vector<int> par(N+1,0);
        
        vector<int> ans;
        for(int i=1;i<=N;i++){
            par[i] = i;
            //size[i] = 1;
        }
        
        for(vector<int> pair:edges){
            //cout << pair[0]<<" "<<pair[1];
            int l1 = findPar(pair[0],par);
            int l2 = findPar(pair[1],par);
            
            if(l1==l2){
                return pair;
                
            }
            else{
                mergeSet(l1,l2,size,par);
                
            }
        }
        
        return ans;
    }
    
    int findPar(int vtx,vector<int> &par){
        if(par[vtx]==vtx) return vtx;
        vtx = findPar(par[vtx],par);
        return vtx;
    }
    
    void mergeSet(int l1,int l2,vector<int> &size,vector<int> &par){
        
        if(size[l1]<size[l2]){
            par[l1] = l2;
            size[l2]+=size[l1];
        }
        else{
            par[l2] = l1;
            size[l1]+=size[l2];
        }
    
    }
    
    
    
};