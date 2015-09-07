
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

map <int, int> B, S;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	int n, p, q, s;
	char d;
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
	{
		scanf(" %c %d %d", &d, &p, &q);
		if (d == 'B')
			B[p] += q;
		else
			S[p] += q;
	}
	int i = 0;
	vector <pii> a, b;
	for (pii x : S)
	{
		if (i == s)
			break;
		a.pb(x);
		i++;
	}
	i = B.size();
	for (pii x : B)
	{
		if (i <= s)
			b.pb(x);
		i--;
	}
	reverse(all(a));
	reverse(all(b));
	for (auto x : a)
		printf("S %d %d\n", x.F, x.S);
	for (auto x : b)
		printf("B %d %d\n", x.F, x.S);
}
