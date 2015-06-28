
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
//#define fn "a"
#define F first
#define S second

string s = "CODEFORCES";
string t;

string substr(int l, int r)
{
	return t.substr(l, r - l + 1);
}

bool calc()
{
	if (s.size() > t.size())
		return 0;
	if (s.size() == t.size())
		return s == t;
	int n = int(t.size());
	for (int l = 0; l < n; l++)
	for (int r = l; r < n; r++)
	{
		string S = substr(0, l - 1) + substr(r + 1, n - 1);
		if (S == s)
			return 1;
	}
	return 0;
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	cin >> t;
	puts(calc() ? "YES" : "NO");
}
