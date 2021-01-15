
class Solution {
public:
    int trap(vector<int>& height)
    {  
        int n=height.size();
        if(n==0)
        {
            return 0;
        }
        int total=0;
        int l[n];
        l[0]=height[0];
        int r[n];
        r[n-1]=height[n-1];
      
        for(int i=1;i<n;i++)
        {
              l[i]=max(l[i-1],height[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
               r[i]=max(height[i],r[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            total =total+min(l[i],r[i])-height[i];
        }
        return total;
    }
};
