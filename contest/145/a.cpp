
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
#define mp make_pair
#define pb push_back
#define F first
#define S second
//#define fn ""

string s, t;
int a[2], all;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif 
	cin >> s >> t;
	int n = int(s.size());
	for (int i = 0; i < n; i++)
	if (s[i] != t[i])
	{
		a[t[i] == '7']++;
		all++;
	}
	int ans = 0;
	int _swap = min(a[0], a[1]);
	ans += all - _swap;
	//printf("%d %d\n", _swap, all - 2 * _swap);
	printf("%d", ans);
}

