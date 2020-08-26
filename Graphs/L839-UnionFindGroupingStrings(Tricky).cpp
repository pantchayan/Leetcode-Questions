#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<int> par;
    
    
    int findPar(int vtx){
        if(par[vtx]==vtx) return vtx;
        
        return par[vtx] = findPar(par[vtx]);
    }
    
    bool isSimilar(string &A, string &B){
        
        //if(A==B) return true;
        int count = 0;
        for(int i=0;i<A.size();i++){
            if(A[i]!=B[i] && ++count>2)
                return false;
        }
        return true;
    }
    
    int numSimilarGroups(vector<string>& A) {
        int n = A.size();
        
        for(int i=0;i<n;i++){
            par.push_back(i);
        }
        
        int groups = n;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isSimilar(A[i],A[j])){
                    int l1 = findPar(i);
                    int l2 = findPar(j);
                    if(l1!=l2){
                        par[l1] = l2;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }
    
};