/*XOR works by setting the bits which are set in either of one of the given numbers (0 ^ 1 = 1, 1 ^ 0 = 1) and finally taking out the common bits 
present in both numbers (1 ^ 1 = 0).*/
vector Solution::grayCode(int A) {
vector ans;
long long x = pow(2 , A) , i;
for(i=0 ; i < x ; i++)
{
int j = i/2;
ans.push_back(i^j);
}
return ans;
}
