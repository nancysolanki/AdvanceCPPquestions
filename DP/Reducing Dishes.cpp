//leetcode problem
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction)
    {  sort(satisfaction.begin(), satisfaction.end());
        int N=satisfaction.size();
        int sum=0, ans=0;
        for(int i=N-1; i>=0; --i) {
            if(satisfaction[i]+sum<0) {
                break;
            }
            sum+=satisfaction[i];
            ans+=sum;
            
        }
        return ans;
    

    }
};
