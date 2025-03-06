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
                printf("res1 is %d\n", res);
                if(prev == x)
                {
                    return false;
                }
                return true;
            }
            else if(res - pow(3, x)> 0)
            {
                printf("res2 is %d, x is %d\n", res, x);
                x++;
                
            }
            else if(res - pow(3, x) < 0)
            {
                
                //printf("res3 is %d, x is %d\n", res, x);
                res = res - pow(3,x-1);
                printf("res3 is %d, x is %d\n", res, x);
                if(prev == x -1)
                {
                    return false;
                }
                prev = x-1;
                x = 0;
                if(res < 0)
                {
                    printf("res4 is %d\n", res);
                    return false;
                }
                
            }

        }
    }
};