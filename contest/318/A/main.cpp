
#include <bits/stdc++.h>

using namespace std;

long long n, k, t;

int main()
{
    scanf("%I64d%I64d", &n, &k);
    // 9 8
    // 1 3 5 7 9 2 4 6 8
    // 1 3 5 7 9 2 4 6 8 10
    //
    if (k <= (n + 1) / 2)
    {
        t = k * 2 - 1;
    }
    else
    {
        k -= (n + 1) / 2;
        t = k * 2;
    }
        printf("%I64d", t);
}