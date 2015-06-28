
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define f first
#define s second

template<typename T>
T min(T a, T b, T c)
{
	return min(a, min(b, c));
}

template<typename T>
T max(T a, T b, T c)
{
	return max(a, max(b, c));
}

int t, a, b, k;

ll d[maxn];
ll f[maxn];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &t, &k);
	d[0] = f[0] = 1;
	for (int i = 1; i <= maxn; i++)
	{
		d[i] = d[i - 1];
		if (i >= k)
			d[i] = (d[i] + d[i - k]) % inf;
	}
	for (int i = 1; i <= maxn; i++)
		f[i] = (f[i - 1] + d[i]) % inf;
	while(t--)
	{
		scanf("%d%d", &a, &b);
		printf("%I64d\n", (f[b] - f[a - 1] + inf) % inf);
	}

}