
/*The input can be stored in a long long int, here I use unsigned long long int for a larger range. We need to find k, for 1+k^1+k^2+k^3+...+k^d=n. The smallest possible 
base is k=2, with has the longest possible representation, i.e., largest d. So, to find the smallest base means to find the longest possible representation "11111....1" based 
on k. As n<=10^18, so n<(1<<62). We iterate the length of the representation from 62 to 2 (2 can always be valid, with base=n-1), and check whether a given length can be valid.

For a given length d, we use binary search to check whether there is a base k which satisfies 1+k^1+k^2+...k^d=n. The left limit is 1, and the right limit is pow(n,1/d)+1, 
i.e., the d th square root of n. The code is shown below.*/


class Solution {
public:
    string smallestGoodBase(string n) {
    unsigned long long tn=(unsigned long long)stoll(n);
    unsigned long long x=1;
    for (int i=62;i>=1;i--) {
        if ((x<<i)<tn) {
            unsigned long long cur=mysolve(tn,i);
            if (cur!=0) return to_string(cur);
        }
    }
    return to_string(tn-1);
    }
    
unsigned long long mysolve(unsigned long long n,int d) {
    double tn=(double) n;
    unsigned long long right=(unsigned long long)(pow(tn,1.0/d)+1);
    unsigned long long left=1;
    while (left<=right){
        unsigned long long mid=left+(right-left)/2;
        unsigned long long sum=1,cur=1;
        for (int i=1;i<=d;i++) {
            cur*=mid;
            sum+=cur;
        }
        if (sum==n) return mid;
        if (sum>n) right=mid-1;
        else left=mid+1;
    }
    return 0;
}

};
