//https://www.youtube.com/watch?v=cOFAmaMBVps&t=44s
// you can have a basic idea on how to approach this problem through this YT link
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {  int res=0;
      vector<int>f(32,0);
    
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<32;j++)
            {
                if(nums[i]&(1<<j))
                {
                    f[j]++;
                }
            }
        }
        for(int i=0;i<32;i++)
        {
            if(f[i]%3==1)
            {
                res=res+(1<<i);
            }
        }
     return res;
    }
};
