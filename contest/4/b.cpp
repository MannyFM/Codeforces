
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 35
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, all;
int l[maxn], r[maxn];
int a[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &all);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &l[i], &r[i]);
	int now = 0;
	for (int i = 0; i < n; i++)
	{
		a[i] = l[i];
		now += a[i];
	}
	int delta = all - now;
	if (delta < 0)
	{
		puts("NO");
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		int add = min(delta, r[i] - l[i]);
		a[i] += add;
		delta -= add;
	}
	if (delta > 0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
}