 //Since each row is sorted, we can use Binary Search to count of 1s in each row.
 // We find the index of first instance of 1 in each row.
 //The count of 1s will be equal to total number of columns minus the index of first 1.
class Solution{
public:
   int binary(int si,int ei,vector<int> arr,int n)
   {   
       
       if(si<=ei)
       {
           int mid=si+(ei-si)/2;
           if((mid == 0 or arr[mid-1]==0) and arr[mid]==1)
           {  
               return mid;
           }
          else if (arr[mid]==0 )
           {
             return   binary(mid+1,ei,arr,n);
           }
           
         else  return binary(si,mid-1,arr,n);
       }   
       
       return -1;
       
   }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) 
	{   int si=0;
	    int max=0;
	    int ei=n-1;
	    int index=0;
	    for(int i=0;i<n;i++)
	    {
	        int first=binary(si,ei,arr[i],n);
	        if (first!=-1 and m-first> max)
	        {
	            max=m-first;
	            index=i;
	        }
	    }
	    return index;
	    
	    
	  
	 
	}

};
