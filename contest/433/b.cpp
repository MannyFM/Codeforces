
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, a[maxn], b[maxn];
ll s1[maxn], s2[maxn];
int m, l, r, q;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	for (int i = 1; i <= n; i++)
		s1[i] = s1[i - 1] + a[i],
		s2[i] = s2[i - 1] + b[i];
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &q, &l, &r);
		if (q == 1)
			printf("%I64d\n", s1[r] - s1[l - 1]);
		if (q == 2)
			printf("%I64d\n", s2[r] - s2[l - 1]);
	}
}