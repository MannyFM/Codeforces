
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
#define fn "g"
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

int n, k;
int a[maxn];
ll ans, all;

void rec(int t)
{
	if (t == k)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++)
				if (a[i] > a[j])
					cnt++;
		ans += cnt;
		all++;
		return;
			
	}
	for (int l = 0; l < n; l++)
		for (int r = l; r < n; r++)
		{
			reverse(a + l, a + r + 1);
			rec(t + 1);
			reverse(a + l, a + r + 1);
		}
			
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	rec(0);
	double t = ans / (all + .0);
	printf("%0.12f", t);
}