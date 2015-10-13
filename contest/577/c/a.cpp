
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

int n;
bool pr[maxn];
vector <int> prs;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	memset(pr, 1, sizeof(pr));
	pr[0] = pr[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		if (!pr[i])
			continue;
		prs.pb(i);
		for (int j = i * i; j <= n; j += i)
			pr[j] = 0;
	}
	vector <int> v;
	for (int x : prs)
	{
		int y = x;
		while (y <= n)
		{
			v.pb(y);
			y *= x;
		}
	}
	printf("%d\n", v.size());
	for (int i : v)
		printf("%d ", i);
}
