
vector<int> Solution::sieve(int A) 
{
    bool prime[A+1];
    vector<int> ans;
    for(int i=0;i<=A;i++)
    {
        prime[i]=true;
    }
    prime[0]=false;
    prime[1]= false;
    for(int i=2;i<=A;i++)
    {
        if(prime[i]==true)
        {
            for(int j=i+i;j<=A;j=j+i)
            {
                prime[j]=false;
            }
        }
        
    }
    for(int i=2;i<=A;i++)
    {
        if(prime[i]==true)
        {
            ans.push_back(i);
        }
    }
    return ans;
}
