

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
  public:
  bool ispossible(int arr[], int n , int k , int ans2)
  {
      int st=1;
      int pages=0;
      for(int i=0;i<n;i++)
      {
          if(pages+arr[i]> ans2)
          {
              pages=arr[i];
              st++;
              if(st>k)
              {
                  return false;
              }
          }
          else
          {
              pages=pages+arr[i];
          }
      } return true;
  }
    int findPages(int arr[], int n, int m) 
    {  int ei,si=0;
       int t =0;
       for(int i=0;i<n;i++)
       {
           t=t+arr[i];
           si=max(si,arr[i]);
       }
       ei=t;
       
       int ans=si;
       while(si<=ei)
       {
           int mid=(si+ei)/2;
           if(ispossible(arr, n , m , mid))
           {   ans=mid;
               ei=mid-1; 
           }
           else {si=mid+1;}
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends
