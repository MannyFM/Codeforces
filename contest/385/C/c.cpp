
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e7 + 10)
#define inf (int)(1e9 + 7)

int n, m, x, l, r;
int c[maxn], cnt[maxn];
long long s[maxn];
bool us[maxn];

int main()
{
    freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        cnt[x]++;
    }

    us[0] = us[1] = 1;
    for(int i = 2; i <= maxn - 10; i++)
        if (!us[i])
        {
            c[i] += cnt[i];
            for(int j = i + i; j <= maxn - 10; j += i)
            {
                us[j] = 1;
                c[i] += cnt[j];
            }
        }
    for(int i = 2; i <= maxn - 10; i++)
        s[i] = s[i - 1] + c[i];
    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &l, &r);
		r = min(r, 10000000);
		l = min(l, 10000001);
        printf("%I64d\n", s[r] - s[l - 1]);
    }
}
