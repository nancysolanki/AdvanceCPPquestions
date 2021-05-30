void addedge(vector<int>adj[], int u , int v)
{
  adj[u].push_back[v];
  adj[v].push_back[u];
}
int main()
{
  int V=4;
  vector<int>adj[V];
  addedge(adj,0,1);
  addedge(adj,0,2);
  addedge(adj,1,2);
  addedge(adj,1,3);
  return 0;
}
//0--->1,2
//1--->0,2,3
//2--->0,1
//3--->1
