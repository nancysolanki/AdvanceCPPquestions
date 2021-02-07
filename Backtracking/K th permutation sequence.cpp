/*We can use next_permutation that modifies a string so that it stores lexicographically next permutation.
*/
string Solution::getPermutation(int A, int B) 
{  
    vector<int> v;
for(int i=1;i<=A;i++)v.push_back(i);

do{
    B--;
}while(next_permutation(v.begin(),v.end()) && B!=1);

string s="";
for(int i: v){
    s = s +  to_string(i); 
}
return s;
}
