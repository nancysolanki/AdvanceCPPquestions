/*XOR works by setting the bits which are set in either of one of the given numbers (0 ^ 1 = 1, 1 ^ 0 = 1) and finally taking out the common bits 
present in both numbers (1 ^ 1 = 0).
 
Given decimal number n with bits positions I (I+1) (I+2) … numbered from left to right
Its Gray code is I (I^(I+1)) ((I+1)^(I+2)) …
Notice each bit is xoring with previous bit
(so if we take a number and right shift it we will bring previous bit position for given bit in current number)
Gray code equivalent hence is for n = n^(n/2)*/
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
