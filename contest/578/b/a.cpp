
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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
#define next MyLittleNext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
//#define fn ""

/*
typedef vector <char> vi;

bool greater(vi x, vi y)
{
	if (x.size() != y.size())
		return x.size() > y.size();
	for (int i = 0; i < int(x.size()); i++)
		if (x[i] != y[i])
			return x[i];
	return false;
}

vi getv(int x)
{
	vi y;
	while (x > 0)
		y.pb(x & 1), x >>= 1;
	reverse(all(y));
	return y;
}
*/

ll pre[maxn], suff[maxn], a[maxn];
int n, k, x;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d%d", &n, &k, &x);
	for (int i = 1; i <= n; i++)
		scanf(I64, a + i);
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] | a[i];
	for (int i = n; i > 0; i--)
		suff[i] = suff[i + 1] | a[i];
	printf(I64 "\n", pre[n]);
	for (int t = 1; t <= k; t++)
	{
		ll j = 1;
		ll best = ((a[j] * x) | suff[j + 1]);
		for (int i = 2; i <= n; i++)
		{
			ll cur = a[i] * x;
			if ((pre[i - 1] | cur | suff[i + 1]) > best)
			{
				best = pre[i - 1] | cur | suff[i + 1];
				j = i;
			}
		}
		a[j] *= x;
		for (int i = 1; i <= n; i++)
			pre[i] = pre[i - 1] | a[i];
		for (int i = n; i > 0; i--)
			suff[i] = suff[i + 1] | a[i];
		for (int i = 1; i < 15; i++)
			printf(I64 " ", a[i]);
		puts("");
	}
	printf(I64, pre[n]);
}
