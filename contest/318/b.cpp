#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e6 + 12);
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

vector <int> KMP(string s)
{
	int n = int(s.length());
	vector <int> p(n, 0);
	for (int i = 1; i < n; i++)
	{
		int j = p[i - 1];
		while (j > 0 && s[j] != s[i])
			j = p[j - 1];
		if (s[i] == s[j])
			j++;
		p[i] = j;
	}
	return p;
}

string s, h, m;
ll ans;
vector <int> pos;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	cin >> s;
	vector <int> a, b;
	h = "heavy#" + s;
	m = "metal#" + s;
	a = KMP(m);
	b = KMP(h);
	for (int i = 0; i < int(h.length()); i++)
		if (a[i] == 5)
			pos.pb(i);
	int uk = 0;
	for (int i = 0; i < int(m.length()); i++)
	{
		if (b[i] == 5)
		{
			while (uk < int(pos.size()) && pos[uk] < i)
				uk++;
			ans += pos.size() - uk;
			//printf("%d %d %d\n", i - 6, uk, uk < int(pos.size()) ? pos[uk] - 6 : -1);
		}
	}
	printf(I64, ans);
}
