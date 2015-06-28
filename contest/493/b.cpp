
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
#define fn "a"
#define f first
#define s second

int n, a[maxn];
vector <int> v[2];
ll sum[2];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		v[a[i] < 0].pb(abs(a[i]));
		sum[a[i] < 0] += abs(a[i]);
	}
	int win = -1;
	if (sum[0] != sum[1])
	{
		puts(sum[0] > sum[1] ? "first" : "second");
		return 0;
	}
	for (int i = 0; i < int(v[0].size()); i++)
	{
		if (i >= int(v[1].size()))
		{
			win = 1;
			break;
		}
		if (v[0][i] == v[1][i])
			continue;
		win = (v[0][i] < v[1][i]) + 1;
		break;
	}
	if (win == -1)
	{
		if (v[0].size() != v[1].size())
			win = 2;
		else
			win = (a[n - 1] < 0) + 1;
	}
	puts(win == 1 ? "first" : "second");
}