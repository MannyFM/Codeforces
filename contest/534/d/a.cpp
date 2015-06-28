
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(2e5 + 12);
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

int n;
vector <int> ans, v[maxn];
int cur = 0;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		v[x].pb(i);
	}
	for (int i = 1; i <= n; i++)
	{
		while (v[cur].empty())
		{
			cur -= 3;
			if (cur < 0)
			{
				puts("Impossible");
				return 0;
			}
		}
		ans.pb(v[cur].back());
		v[cur].pop_back();
		cur++;
	}
	puts("Possible");
	for (int i : ans)
		printf("%d ", i);
}
