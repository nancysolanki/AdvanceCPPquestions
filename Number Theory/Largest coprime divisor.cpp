//X divides A i.e. A % X = 0
//X and B are co-prime i.e. gcd(X, B) = 1


int gcd(int a, int b) 
{ 
    
    if (a == 0 || b == 0) 
        return 0; 
  
    // base case 
    if (a == b) 
        return a; 
  
    // a is greater 
    if (a > b) 
        return gcd(a - b, b); 
    return gcd(a, b - a); 
} 
int Solution::cpFact(int x, int y) 
{
    while (gcd(x, y) != 1) { 
        x = x / gcd(x, y); 
    } 
    return x;
}
