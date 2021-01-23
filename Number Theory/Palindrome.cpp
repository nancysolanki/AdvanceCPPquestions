//YT LINK- https://www.youtube.com/watch?v=UPdSViixmDs
// last digits of the no. are poped and added to the front of the ans

bool isPalindrome(int x) 
{


if( x < 0 ) return false;
    
    int result = 0;
    int num = x;
    
    while( num > 0 )
    {
        result = result * 10 + num % 10;
        
        if( result > x ) return false;
        
        num = num / 10;
    }
    
    if( result == x ) return true;
    
    else return false;
}
