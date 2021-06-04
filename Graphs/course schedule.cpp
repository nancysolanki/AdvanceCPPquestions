/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] 
indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.*/

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    { vector<int> adj[numCourses];
    vector<int> indegree(numCourses);
    
    for(int i=0;i<prerequisites.size();i++)
    {
        adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        indegree[prerequisites[i][1]]++;
    }
    
    queue<int> q;
    for(int i=0; i<numCourses; i++){
        if(indegree[i]==0) 
            q.push(i);
    }
    
    int c = q.size();
    while(!q.empty()){
        int x= q.front();
        q.pop();
        for(auto y:adj[x]){
            indegree[y]--;
            if(indegree[y]==0){
                q.push(y);
                c++;
            }
        }
    }
    if(c!=numCourses) return false;
    return true;
    }
};
