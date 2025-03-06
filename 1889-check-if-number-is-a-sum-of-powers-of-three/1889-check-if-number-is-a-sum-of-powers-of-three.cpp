#include <cmath>

class Solution {
public:
    bool checkPowersOfThree(int n) 
    {
        int x = 0;
        int res = n;
        int aux = 0;
        int prev = -1;
        
        while(true)
        {
            if(res - pow(3,x) == 0)
            {
                if(prev == x)
                {
                    return false;
                }
                return true;
            }
            else if(res - pow(3, x)> 0)
            {
                x++;
                
            }
            else if(res - pow(3, x) < 0)
            {
                res = res - pow(3,x-1);
                if(prev == x -1)
                {
                    return false;
                }
                prev = x-1;
                x = 0;
                if(res < 0)
                {
                    return false;
                }
                
            }

        }
    }
};