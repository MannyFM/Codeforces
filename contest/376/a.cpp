
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

string s, l, r;
ll a, b;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	cin >> s;
	int k = int(s.find('^'));
	int n = int(s.size());
	l = s.substr(0, k);
	r = s.substr(k + 1, n - k - 1);
	reverse(l.begin(), l.end());
	for (int i = 0; i < int(l.size()); i++)
		if (l[i] != '=')
			a += (i + 1) * (l[i] - '0');
	for (int i = 0; i < int(r.size()); i++)
		if (r[i] != '=')
			b += (i + 1) * (r[i] - '0');
	if (a == b)
		puts("balance");
	else
		puts(a > b ? "left" : "right");
}