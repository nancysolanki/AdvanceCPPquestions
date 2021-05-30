
void bfs(vector<int>adj[], int v , int s)  //s is the starting index
{
  bool visited[v+1];
  for(int i=0;i<v;i++)
  {
    visited[i]=false;
  }
  queue<int>q;
  visited[s]=true;
  q.push(s);
  while(!q.empty())
  {
    int curr=q.front();
    q.pop();
    cout<<curr<<" ";
    
    for(int i:adj[curr])
    {
      if(visited[i]==false)
      {
        visited[i]=true;
        q.push(i);
      }
    }
  }
  
}
