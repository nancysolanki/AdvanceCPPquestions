#include<vector>
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
          sort(nums.begin(),nums.end());
          int si,ei;
          vector<vector<int>> ans;
         si=0;
         ei=nums.size()-1;
       
            for (int i=0; i<nums.size(); i++)
            {
                 if ((i>0) && (nums[i]==nums[i-1]))
                  continue;
                 si=i+1;
         ei=nums.size()-1;
         while(si<ei)
         {   vector<int>res(3,0);
             
                 int sum=nums[i]+nums[si]+nums[ei];
                 if(sum>0)
                 {
                     ei--;
                 }
                 if(sum<0)
                 {
                     si++;
                     
                 }
                 if (sum==0)
                 {
                     res[0]=nums[i];
                     res[1]=nums[si];
                     res[2]=nums[ei];
                   ans.push_back(res);
                     while(si<ei and nums[si]==nums[si+1])si++;
                     while(si<ei and nums[ei]==nums[ei-1])ei--;
                     si++;ei--;
                 }
                
             } 
             
         }
        return ans;
    }
};
