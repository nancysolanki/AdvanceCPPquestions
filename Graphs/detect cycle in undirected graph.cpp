// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;





class Solution 
{
    public:
bool helper(int V, vector<int>adj[],int si ,bool visited[])
{
    vector<int>p(V,-1);
    queue<int>q;
   
    visited[si]=true;
     q.push(si);
    while(!q.empty())
    {
       int curr=q.front();
       q.pop();
       for(auto j : adj[curr])
       {
           if(!visited[j])
           {
               visited[j]=true;
               q.push(j);
               p[j]=curr;
           }
           else if(p[curr]!=j)
           {
               return true;
           }
           
       }
    }
    return false;
    
    
}

	bool isCycle(int V, vector<int>adj[])
	{
	    vector<int>p;
	    bool visited[V];
	    for(int i=0;i<V;i++)
	    {
	        visited[i]=false;
	    }
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false and  helper(V,adj,i,visited))
	        {
	            return true;
	        }
	    }
	    return false;
	}
};

