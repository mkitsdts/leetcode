#include <iostream>
#include <cmath>
using namespace std;

class Solution
{
public:
    static int reverse(int x)
    {
        bool is = false;
        if (x == 0)
        {
            return 0;
        }
        else if (x < 0)
        {
            is = true;
            if (x < -1 * INT_MAX)
            {
                return 0;
            }
            x *= -1;
        }
        int result = 0;
        int i = 1;
        while (x > 0)
        {
            if (INT_MAX / 10 > result)
            {
                result *= 10;
                result += x % 10;
                ++i;
                x /= 10;
            }
            else
            {
                if (INT_MAX / 10 == result)
                {
                    if (x <= 7)
                    {
                        result *= 10;
                        result += x;
                        break;
                    }
                }
                return 0;
            }
        }
        if (is)
        {
            return result * -1;
        }
        return result;
    }
};

int main()
{
    cout << Solution::reverse(123) << endl;
    cout << Solution::reverse(-123) << endl;
    cout << Solution::reverse(120) << endl;
    cout << Solution::reverse(0) << endl;
    cout << Solution::reverse(1534236469) << endl;
    cout << Solution::reverse(-2147483648) << endl;
    return 0;
}