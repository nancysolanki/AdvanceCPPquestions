
class Solution {
public:
    int superEggDrop(int k, int n) {
           int dp[k+1][n+1];
        for(int i=0;i<=k;i++)
        {
            dp[i][1]=1;
            dp[i][0]=0;
        }
        for(int i=1;i<=n;i++)
            dp[1][i]=i;
        
        int res;
        for(int i=2;i<=k;i++)
        {
            for(int j=2;j<=n;j++)
            {
                dp[i][j]=INT_MAX;
                int l=1,r=j;
                while(l<=r)
                {
                    int m=l+(r-l)/2;
                    res=1+max(dp[i-1][m-1],dp[i][j-m]);
                    if(dp[i-1][m-1]<dp[i][j-m])
                        l=m+1;
                    else
                        r=m-1;
                    dp[i][j]=min(dp[i][j],res);
                }
                
            }
        }
        
        return dp[k][n];
    }
        
    
};
