
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
#define fn "c"
#define f first
#define s second
#define sqr(x) ((x) * (x))

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

int n, x[maxn], y[maxn], a[maxn], b[maxn];

void change(int i)
{
	int new_x = y[i] - b[i] + a[i];
	int new_y = a[i] + b[i] - x[i];
	x[i] = new_x;
	y[i] = new_y;
}

bool check(int i)
{
	for (int t = 0; t < 4; t++)
		for (int tt = t + 1; tt < 4; tt++)
			if (x[i + t] == x[i + tt] && y[i + t] == y[i + tt])
				return 0;
	ll d1 = sqr(x[i] - x[i + 1] + 0ll) + sqr(y[i] - y[i + 1] + 0ll);
	ll d2 = sqr(x[i] - x[i + 2] + 0ll) + sqr(y[i] - y[i + 2] + 0ll);
	ll d3 = sqr(x[i] - x[i + 3] + 0ll) + sqr(y[i] - y[i + 3] + 0ll);
	if (d1 == d2 && d2 == d3)
		return 0;
	if (d1 != d2 && d2 != d3)
		return 0;
	if (d1 == d2 && d3 < d1)
		return 0;
	if (d1 == d3 && d2 < d1)
		return 0;
	if (d3 == d2 && d1 < d2)
		return 0;
	
}

int calc(int i)
{
	int ans = inf;
	for (int i1 = 0; i1 < 4; i1++)
	{
		change(i);
		for (int i2 = 0; i2 < 4; i2++)
		{
			change(i + 1);
			for (int i3 = 0; i3 < 4; i3++)
			{
				change(i + 2);
				for (int i4 = 0; i4 < 4; i4++)
				{
					change(i + 3);
					if (check(i))
						ans = min(ans, (i1 + 1) % 4 + (i2 + 1) % 4 + (i2 + 1) % 4 + (i2 + 1) % 4);
				}
			}
		}
	}
	if (ans == inf)
		return -1;
	return ans;
}

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d", x + i, y + i, a + i, b + i);
	for (int i = 0; i < n; i += 4)
		printf("%d\n", calc(i));
}