
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

int n, k, a[maxn];

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= 2 * n + 1; i++)
		scanf("%d", a + i);
	for (int i = 2; i <= 2 * n + 1; i += 2)
	{
		if (a[i] - 1 > a[i - 1] && a[i] - 1 > a[i + 1])
		{
			k--;
			a[i]--;
			if (!k)
				break;
		}
	}
	for (int i = 1; i <= 2 * n + 1; i++)
		printf("%d ", a[i]);
}