
#include <bits/stdc++.h>

using namespace std;

int mi = 10002, ma = -10002;
int n, a, ans;

int main()
{
    scanf("%d%d", &n, &a);
    mi = a, ma = a;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &a);
        if (a < mi)
        {
            ans++;
            mi = a;
        }
        if (a > ma)
        {
            ans++;
            ma = a;
        }
    }
    printf("%d", ans);
}
