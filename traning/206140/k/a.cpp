
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

string s;
set	<int> ab, ba;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	cin >> s;
	for (int i = 0; i + 1 < (int)s.size(); i++)
	{
		if (s[i] == 'A' && s[i + 1] == 'B')
			ab.insert(i);
		if (s[i] == 'B' && s[i + 1] == 'A')
			ba.insert(i);
	}
	for (int i : ab)
	{
		auto it  = ba.upper_bound(i + 1);
		if (it != ba.end())
		{
			puts("YES");
			return 0;
		}
	}
	for (int i : ba)
	{
		auto it  = ab.upper_bound(i + 1);
		if (it != ab.end())
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
}

