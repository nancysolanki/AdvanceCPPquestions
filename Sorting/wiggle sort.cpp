
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        sort(nums.begin(),nums.end());
        int j=n-1;
        for(int i=1;i<n;i=i+2)
        {
            ans[i]=nums[j];
            j--;
        }
        for(int i=0;i<n;i=i+2)
        {
            ans[i]=nums[j];
            j--;
        }
        nums=ans;

        
    }
};
