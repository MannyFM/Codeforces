
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
#define fn "f"

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

int n, s;
map <ll, ll> a, b;
vector <pll> A, B;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++)
	{
		char c;
		int x, y;
		scanf(" %c%d%d", &c, &x, &y);
		if (c == 'S')
			a[x] += y;
		else
			b[-x] += y;
	}
	int cnt = min(s, (int)a.size());
	for (int i = 1; i <= cnt; i++)
	{
		auto it = a.begin();
		A.pb(*it);
		a.erase(it);
	}
	reverse(all(A));
	for (auto it : A)
		printf("S " I64 " " I64 "\n", it.F, it.S);
	cnt = min(s, (int)b.size());
	for (int i = 1; i <= cnt; i++)
	{
		auto it = b.begin();
		printf("B " I64 " " I64 "\n", - it -> F, it -> S);
		b.erase(it);
	}
}

