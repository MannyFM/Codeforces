
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e3 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int n, m;
int cnt[maxn];
int s;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		cnt[a]++;
		cnt[b]++;
	}
	for (int i = 1; i <= n; i++)
		if (!cnt[i])
		{
			s = i;
			break;
		}
	printf("%d\n", n - 1);
	for (int i = 1; i <= n; i++)
		if (i != s)
			printf("%d %d\n", i, s);
}