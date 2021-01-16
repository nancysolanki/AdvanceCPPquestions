// I have used property of XOR a^a=0 and a^0=a

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
         int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans=ans^nums[i];
        }
        return ans;
    }
};

