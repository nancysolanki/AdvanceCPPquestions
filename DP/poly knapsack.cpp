
int solve(vector<int>& weights, vector<int>& values, int capacity) 
{
   int n=values.size();
   if(n==0)
   {
       return 0;
   }
  int dp[capacity+1];
  for(int i=0;i<=capacity;i++)
  {
      dp[i]=0;
  }
  for(int i=0;i<=capacity;i++)
  {
      for(int j=0;j<n;j++)
      {
          if(weights[j]<=i)
          {
              dp[i]=max(dp[i],dp[i-weights[j]]+values[j]);
          }

      }
  }return dp[capacity];
}
