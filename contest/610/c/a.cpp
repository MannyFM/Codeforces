
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

string rev(string x)
{
	string s;
	for (int i = 0; i < int(x.size()); i++)
		s.pb(1 - (x[i] - '0') + '0');
	return s;
}

vector <string> rec(int k)
{
	if (k == 0)
		return {"1"};
	auto v = rec(k - 1);
	int n = v.size();
	for (int i = 0; i < n; i++)
		v.pb(v[i]);
	for (int i = 0; i < n; i++)
		v[i] += v[i];
	for (int i = n; i < 2 * n; i++)
		v[i] += rev(v[i]);
//	for (int i = 0; i < int(v.size()); i++)
//	{
//		puts(v[i].c_str());
//	}
	return v;
}

int main()
{
	#ifdef fn
		freopen(fn ".in", "r", stdin);
		freopen(fn ".out", "w", stdout);
	#endif
	int k;
	scanf("%d", &k);
	auto v = rec(k);
	for (int i = 0; i < int(v.size()); i++)
	{
		for (char x : v[i])
			printf("%c", x == '1' ? '+' : '*');
		puts("");
	}
}

