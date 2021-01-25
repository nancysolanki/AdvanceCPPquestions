
int Solution::titleToNumber(string A) 
{
  int ans=0;
  for(int i=0;A[i]!='\0';i++)
  {
      ans=ans*26 +(A[i]-'A'+1);
  }
  return ans;
}
