#define ll long long int
int Solution::pow(int x, int n, int d) 
{  int base=x;
   int expo=n;
   int m=d;
    if(m==1) return 0;
    ll ans=1,y=base%m;
    while(expo>0){
        if(expo&1)
         ans=((ans)*y)%m;
        y=(y*y)%m;
        if(y<0) y+=m;
        expo=expo>>1;
    }
    if(ans<0){
        ans=(m-abs(ans)%m);
        return ans;
    }
    return ans%m;
}

