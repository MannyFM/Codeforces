
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(4e3 + 12);
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

int n, d[maxn], v[maxn], p[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	vector <int> pa;
	for (int i = 1; i <= n; i++)
		scanf("%d%d%d", v + i, d + i, p + i);
	for (int i = 1; i <= n; i++)
	{
		if (p[i] < 0)
		{
			for (int j = i + 1; j <= n; j++)
			{
				p[j] -= d[i];
				if (p[j] < 0)
					p[j] = -1;
			}
			continue;
		}
		int cnt = v[i];
		for (int j = i + 1; j <= n && cnt; j++)
			if (p[j] >= 0)
			{
				p[j] -= cnt--;
				if (p[j] < 0)
					p[j] = -1;
			}
		pa.pb(i);
	}
	printf("%d\n", pa.size());
	for (int i : pa)
		printf("%d ", i);
}
