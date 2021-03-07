/*Given two strings s0 and s1, return whether they are anagrams of each other.

Constraints

n ≤ 100,000 where n is the length of s0
m ≤ 100,000 where m is the length of s1*/


#include<unordered_map>
bool solve(string s0, string s1) 
{  unordered_map<int,int> m;
   unordered_map<int,int> n;
   if(s0.length()!=s1.length())
   {
       return false;
   }
   for(char i : s0)
   {
      m[i]++;

   }  
   for(char j: s1)
   {
       n[j]++;
   }
  if(n==m)
  {
      return true;
  }
  else return false;
}
