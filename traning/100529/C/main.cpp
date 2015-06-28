
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)
#define maxn (int)(1e5 + 12)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define fn "dunes"

int n, m, q;
int l[maxn], r[maxn], x[maxn];
long long ans;

int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    	scanf("%d%d%d", &l[i], &r[i], &x[i]);
    while (m--)
    {
    	ans = 0ll;
    	scanf("%d", &q);
    	for (int i = 0; i < n; i++)
    		if (l[i] <= q && q <= r[i])
    			ans += (q - l[i]) & 1 ? -x[i] : x[i];
    	printf("%I64d\n", ans);
    }
}
