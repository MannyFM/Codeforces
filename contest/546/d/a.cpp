#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 5000 * 1000 + 15;
int const maxb = int(2e6 + 12);
int const inf = int(1e9 + 7);
ll const linf = ll(1e18 + 12);
double const eps = 1e-7;
double const pi = acos(-1);
#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

int cnt[maxn];
int lp[maxn];
vector <int> pr;
ll sum[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	for (int i = 2; i < maxn; i++)
	{
		if (!lp[i])
		{
			lp[i] = i;
			cnt[i]++;
			pr.pb(i);
		}
		for (int j = 0; j < int(pr.size()) && pr[j] <= lp[i] && i * 1ll * pr[j] < maxn; j++)
		{
			lp[i * pr[j]] = pr[j];
			cnt[i * pr[j]] = cnt[i] + cnt[pr[j]];
		}
	}
	for (int i = 1; i < maxn; i++)
		sum[i] = sum[i - 1] + cnt[i];
	int n, a, b;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a, &b);
		printf(I64 "\n", sum[a] - sum[b]);
	}	
}
