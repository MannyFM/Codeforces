
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define mp make_pair
#define pb push_back
#define fn "collect"
#define LOCAL

int n, a[maxn];
int m, b[maxn];

bool find(int x)
{
	int l = 0, r = n + 1;
	int mid = (l + r) >> 1;
	while (r - l > 1)
	{
		mid = (l + r) >> 1;
		if (a[mid] < x)
			l = mid;
		else
			r = mid;
	}
	mid = (l + r) >> 1;
	return a[r] == x;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", b + i);
		puts (find(b[i]) ? "YES" : "NO");
	}
}