//  the relationship between the bits of x and x-1. So as in x-1, the rightmost 1 and bits right to it are flipped, then by performing x&(x-1), and storing it in x, 
//will reduce x to a number containing number of ones(in its binary form) less than the previous state of x, thus increasing the value of count in each iteration.


class Solution {
public:
vector<int> countBits(int num)
{   int count=0;

    vector<int>ans;
    for(int i=0;i<=num;i++)
    {
        count=0;
        for(int j=i;j>0;)
        {
            j=j&(j-1);
            count++;
        }
         ans.push_back(count);
    }
 return ans;

}
};
