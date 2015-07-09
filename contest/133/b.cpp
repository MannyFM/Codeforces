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
int const mod = 1000003;
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
//#define fn ""

map <char, int> m;
string s;
int ans;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	m['>'] = 8;
	m['<'] = 9;
	m['+'] = 10;
	m['-'] = 11;
	m['.'] = 12;
	m[','] = 13;
	m['['] = 14;
	m[']'] = 15;
	cin >> s;
	for (int i = 0; i < int(s.length()); i++)
		ans = (ans * 16 + m[s[i]]) % mod;
	printf("%d", ans);
}
