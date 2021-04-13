
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0, n = s.size();
        bool dp[n][n];
        memset(dp, false, sizeof dp);
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i == j) dp[i][j] = true;
                else if(i+1 == j && s[i] == s[j]) dp[i][j] = true;
                else{
                    dp[i][j] = s[i]==s[j] && dp[i+1][j-1];
                }
                if(dp[i][j]) count++;
            }
        }
        return count;
    }
};
