
#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long l, r, a, b, c;
    cin >> l >> r;
    for(long long a = l; a <= r; a++)
    {
        for(long long b = a + 1; b <= r; b++)
        {
            for(long long c = b + 1; c <= r; c++)
            {

                //cout << a << " " << b << " " << c << " " << __gcd(a, b) << " " << __gcd(b, c) << " " << __gcd(a, c) << '\n';
                if (__gcd(a, b) == 1 && __gcd(b, c) == 1 && __gcd(a, c) != 1)
                {
                    cout << a << " " << b << " " << c;
                    return 0;
                }
            }
        }
    }
    cout << -1;
}
