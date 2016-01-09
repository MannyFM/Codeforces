
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

int n, p, q;
string s;
int X = -1, Y = -1;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	cin >> n >> p >> q >> s;
	for (int x = 0; x * 1ll * p <= n; x++)
	{
		int y = (n - (x * p)) / q;
		if (y >= 0 && y * q + x * p == n)
		{
			X = x, Y = y;
			break;
		}
	}
	if (X == -1)
	{
		puts("-1");
		return 0;
	}
	printf("%d\n", X + Y);
	int pos = 0;
	for (int i = 0; i < X; i++)
	{
		puts(s.substr(pos, p).c_str());
		pos += p;
	}
	for (int i = 0; i < Y; i++)
	{
		puts(s.substr(pos, q).c_str());
		pos += q;
	}
}

