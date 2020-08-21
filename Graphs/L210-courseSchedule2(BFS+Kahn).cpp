#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[9];
         
        for(int i=0;i<prerequisites.size();i++){
            
                graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
        }
        
        vector<int> indegree(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            for(int v:graph[i]){
                indegree[v]++;
            }
        }
        
        vector<int> topologicalSort;
        
        queue<int> que;
        
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                que.push(i);
            }
        }
        
        
        
        //cout << que.size() << endl;
        while(que.size()!=0){
            int size = que.size();
            while(size-->0){
                int rvtx = que.front();
                que.pop();
                
                topologicalSort.push_back(rvtx);
                
                for(int v:graph[rvtx]){
                    indegree[v]--;
                    if(indegree[v]==0){
                        que.push(v);
                    }
                }
            }
        }
        
        //cout << topologicalSort.size() ;
        
        
        if(topologicalSort.size()!=numCourses){
            vector<int> blank;
            return blank;
        }
        
        return topologicalSort;
    }
};