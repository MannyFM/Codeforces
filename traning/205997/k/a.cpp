
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
int m, l, r, k;

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	cin >> s >> m;
	int n = (int)s.length();
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &l, &r, &k);
		l--, r--;
		k %= r - l + 1;
//		cout << s.substr(0, l) << " " << s.substr(r - k + 1, k) << " " << s.substr(l, r - l - k + 1) << " " << s.substr(r + 1, n - r) << '\n';
		s = s.substr(0, l) + s.substr(r - k + 1, k) + s.substr(l, r - l - k + 1) + s.substr(r + 1, n - r);
//		cout << s << '\n';
	}
	cout << s;
}

