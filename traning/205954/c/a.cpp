
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

vector <pii> v;
int n, m, a[maxn], b[maxn];

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", a + i);
		v.pb({a[i], 0});
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", b + i);
		v.pb({b[i], 1});
	}
	int f = 3 * n, s = 3 * m;
	int F = f, S = s;
	sort(all(v));
	for (int i = 0; i < int(v.size()); )
	{
		int j = i;
		while (j < int(v.size()) && v[i].F == v[j].F)
		{
			if (v[j].S)
				s--;
			else
				f--;	
			j++;
		}
		if (f - s > F - S || (f - s == F - s && f > F))
		{
			F = f;
			S = s;
		}
		i = j;
	}
	printf("%d:%d", F, S);
}

