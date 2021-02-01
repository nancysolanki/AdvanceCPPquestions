/*We can view any given sequence in numsnums array as alternating ascending and descending sequences. By making use of this, and the fact that we can return any peak as the result, we can make use of Binary Search to find the required peak element.

In case of simple Binary Search, we work on a sorted sequence of numbers and try to find out the required number by reducing the search space at every step. In this case, 
we use a modification of this simple Binary Search to our advantage. We start off by finding the middle element, midmid from the given numsnums array.   If this element happens to be lying in a descending sequence of numbers. or a local falling slope(found by comparing nums[i]nums[i] to its right neighbour), 
it means that the peak will always lie towards the left of this element. Thus, we reduce the search space to the left of midmid(including itself) and perform the same process
on left subarray.

If the middle element, midmid lies in an ascending sequence of numbers, or a rising slope(found by comparing nums[i]nums[i] to its right neighbour), it obviously implies that
the peak lies towards the right of this element. Thus, we reduce the search space to the right of midmid and perform the same process on the right subarray.

In this way, we keep on reducing the search space till we eventually reach a state where only one element is remaining in the search space. This single element is the peak 
element.

To see how it works, let's consider the three cases discussed above again.*/


class Solution {
public:
    int helper(vector<int>& nums , int si , int ei)
    {
         if(si<=ei )
        {
            int mid=(si+ei)/2;
            if(nums[mid]>nums[mid+1] and nums[mid]>nums[mid-1] )
            {
                return mid;
            }
             else if(nums[mid]>nums[mid+1])
            {
                return helper(nums, si, mid);
            }
             else return helper(nums,mid+1,ei);
            
              
             
                
        }
        
       else return -1;
    }
  
    int findPeakElement(vector<int>& nums)
    {
      int si=0;
      int ei=nums.size()-1;
        if(nums.size()==1)return 0;
        if(nums[0] > nums[1])return 0;
        if((nums[0] < nums[1]) && nums.size()==2)return 1;
         if(nums[nums.size()-1]>nums[nums.size()-2])
                 return nums.size()-1;
        
        return helper(nums,si,ei);
        
    }
};
