 /*FOR EXAMPLE : A = [   [1, 3, 5],
                         [2, 6, 9],
                         [3, 6, 9]   ]
Output 1:
    5
Explanation 1:
    A = [1, 2, 3, 3, 5, 6, 6, 9, 9]
    Median is 5. So, we return 5.*/

int Solution::findMedian(vector<vector<int> > &A) 
{
    vector<int>a;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            a.push_back(A[i][j]);
        }
    }
    int ans;
 int n=a.size();
 sort(a.begin(),a.end());
 if(n%2==0){
     ans=(a[n/2]+a[n/2 -1])/2;
 }
 else{
    ans=a[n/2];
 }
 return ans;
}
