
#include <bits/stdc++.h>

using namespace std;

int a, b, n;

int main()
{
    scanf("%d%d%d", &a, &b, &n);
    while (1)
    {
        n -= __gcd(a, n);
        if (n < 0)
        {
            puts("1");
            return 0;
        }
        n -= __gcd(b, n);
        if (n < 0)
        {
            puts("0");
            return 0;
        }
    }
}
