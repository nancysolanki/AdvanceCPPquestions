
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {  //nancy you have to watch kadane algo videos when revising
        int maxcurr,maxg;
        maxcurr=maxg=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            maxcurr=max(nums[i],maxcurr+nums[i]);
            if(maxcurr>maxg)
            {
                maxg=maxcurr;
            }
        }
        return maxg;
        
    }
};
