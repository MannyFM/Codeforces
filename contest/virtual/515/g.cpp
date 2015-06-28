
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

int f[12];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	f[0] = f[1] = 1;
	for (int t = 1; t <= 10; t++)
		f[t] = f[t - 1] * t, printf("%d ", f[t]);
	puts("");
	for (int t = 3; t <= 10; t++)
	{
		for (int k = 2; k < t; k++)
		{
			for (int q = 1; q <= 10; q++)
			{
				if (f[t] / f[k] == f[q])
				{
					printf("%d != %d * %d\n", t, k, q);
				}
			}
		}
	}
}