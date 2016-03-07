
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
//#define fn ""

template <typename T>
bool umax(T & a, T b)
{
	return a < b ? (a = b, 1) : 0;
}

template <typename T>
bool umin(T & a, T b)
{
	return a > b ? (a = b, 1) : 0;
}

int n, m;
vector <pii> v;

bool cor(int x, int y)
{
	return 0 <= x && x <= n && 0 <= y && y <= m;
}

void around(int x, int y)
{
	for (int i = -2; i <= 2; i++)
		for (int j = -2; j <= 2; j++)
			if (cor(x + i, y + j))
				v.emplace_back(mp(x + i, y + j));
}

typedef long double ld;

ld dist(const pii & a, const pii & b)
{
	return sqrt(ld(a.F - b.F) * (a.F - b.F) + ld(a.S - b.S) * (a.S - b.S));
}

pii a[4];
ld ans;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	around(0, 0);
	around(n, 0);
	around(0, m);
	around(n, m);
	sort(all(v));
	v.erase(unique(all(v)), end(v));
	int N = (int)v.size(); 
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
	for (int k = 0; k < N; k++)
	for (int l = 0; l < N; l++)
	{
		if (i == j || i == k || i == l || j == k || j == l || k == l)
			continue;
		if (umax(ans, dist(v[i], v[j]) + dist(v[j], v[k]) + dist(v[k], v[l])))
			a[0] = v[i], a[1] = v[j], a[2] = v[k], a[3] = v[l];
	}
	for (int i = 0; i < 4; i++)
		printf("%d %d\n", a[i].F, a[i].S);
}

