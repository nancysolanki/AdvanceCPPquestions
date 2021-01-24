class Solution {
public:
    bool isHappy(int n) {
while (true) {
        
        long sum = 0;
        
        while (n != 0) {
            
            int lastDigit = n % 10;
            n /= 10;
            sum += lastDigit * lastDigit;
        }
        
        if (1 <= sum && sum <= 9) {
            
            if (sum == 1 || sum == 7) return true;
            else return false;
        }
        else n = sum;
    }
  }
};
