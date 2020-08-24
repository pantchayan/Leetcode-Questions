#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
        unordered_map<int,vector<int>> map;
        
        int numRoutes = routes.size();
        
        for(int i=0;i<numRoutes;i++){
            for(int ele : routes[i]){
                map[ele].push_back(i);
            }
        }
        
        unordered_set <int> busStands;
        vector<bool> visRoutes(numRoutes,false);
            
        queue<int> que;
        
        que.push(S);
        int level = 0;
        while(que.size()!=0){
            int size = que.size();
            while(size-->0){
                int curr = que.front();
                que.pop();
                if(curr == T){
                    return level;
                }
                
                
                for(int r: map[curr]){
                    if(!visRoutes[r]){
                        for(int bs : routes[r]){
                            if (busStands.find(bs) == busStands.end()) {
                                que.push(bs);
                                busStands.insert(bs);
                            } 
                        } 
                        visRoutes[r] = true;
                    }
                }
                
                
            }
            level++;
        }
        
        return -1;
        
    }
};