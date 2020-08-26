#include <vector>
#include <queue>
 using namespace std;
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        
        vector<int> par;
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i!=j && M[i][j]==1){
                    int l1 = findPar(i,par);
                    int l2 = findPar(j,par);  
                    if(l1==l2){
                        continue;
                    }
                    else{
                        count++;
                        par[l1]= l2;
                    }
                }
            }
        }
        
        
        return n-count;
        
        
        
        
    }
        int findPar(int vtx,vector<int> &par){
            if(par[vtx]==vtx)return vtx;
            return vtx = findPar(par[vtx],par);
        }
};