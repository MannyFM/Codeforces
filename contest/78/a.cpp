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
//#define fn ""

string a;
int c[] = {5, 7, 5};
map <char, int> m;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	m['a'] = 1;
	m['e'] = 1;
	m['i'] = 1;
	m['o'] = 1;
	m['u'] = 1;
	for (int j = 0; j < 3; j++)
	{
		getline(cin, a);
		int cnt = 0;
		for (int i = 0; i < int(a.length()); i++)
			cnt += m[a[i]];
		if (cnt != c[j])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
}
