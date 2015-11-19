
#include <bits/stdc++.h>

using namespace std;

int const maxn = int(1e4) + 12;
int n;
char s[maxn], t[maxn];

void shift(int l, int r, int k)
{
    int len = r - l + 1;
    k %= len;
    for (int i = 0; i < len; i++)
        t[i] = s[l + (i - k + len) % len];
    for (int i = 0; i < len; i++)
        s[l + i] = t[i];
}

int main()
{
    scanf("%s", s);
    int m, l, r, x;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &l, &r, &x);
        l--, r--;
        shift(l, r, x);
    }
    puts(s);
}