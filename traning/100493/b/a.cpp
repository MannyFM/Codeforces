
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
#define fn "basketball"

string s;
int n, m, last;
map <string, int> pts;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cin >> s;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d:%d", &x, &y);
		cin >> s;
		pts[s] += x + y - last;
		last = x + y;
	}
	string ans = pts.begin() -> F;
	for (auto x : pts)
		if (x.S > pts[ans])
			ans = x.F;
	cout << ans << " " << pts[ans];
}
