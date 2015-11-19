
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
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
//#define fn

int n;
ll t[200][200][200];

ll get(int x, int y, int z)
{
	ll ans = 0ll;
	for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
		for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
			for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
				ans += t[i][j][k];
	return ans;
}

void upd(int x, int y, int z, int d)
{
	for (int i = x; i < n; i = (i | (i + 1)))
		for (int j = y; j < n; j = (j | (j + 1)))
			for (int k = z; k < n; k = (k | (k + 1)))
				t[i][j][k] += d;
}

ll get(int x, int y, int z, int x1, int y1, int z1)
{
	return get(x1, y1, z1)
		- get(x - 1, y1, z1)
		- get(x1, y - 1, z1)
		+ get(x - 1, y - 1, z1)
		- get(x1, y1, z - 1)
		+ get(x - 1, y1, z - 1)
		+ get(x1, y - 1, z - 1)
		- get(x - 1, y - 1, z - 1);
}

int T, x, y, z, x1, y1, z1, d;
int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	while (scanf("%d", &T) == 1)
	{
		if (T == 3)
			break;
		if (T == 2)
		{
			scanf("%d%d%d%d%d%d", &x, &y, &z, &x1, &y1, &z1);
			//x++, y++, z++, x1++, y1++, z1++;
			printf(I64 "\n", get(x, y, z, x1, y1, z1));
		}
		if (T == 1)
		{
			scanf("%d%d%d%d", &x, &y, &z, &d);
			upd(x, y, z, d);
		}
	}
}
