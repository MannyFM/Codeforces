
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
#define fn "bank"

struct pig
{
	ll t, a, b, id;
	pig()
	{
		t = a = b = id = 0;
	}
	pig(int i)
	{
		scanf(I64 I64 I64, &t, &a, &b);
		id = i;
	}
	void out()
	{
		printf("t:" I64 " a:" I64 " b:" I64 " id:" I64 "\n", t, a, b, id);
	}
};

bool operator < (pig a, pig b)
{
	return a.id < b.id;
}

deque <pair <ll, pig>> little[11];
int n, m;
ll ans[maxn];
vector <pig> v;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		v.pb(pig(i + 1));
	for (int i = 1; i <= m; i++)
		little[i].pb(mp(0, pig()));
	for (int i = 0; i < n; i++)
	{
		int j = 1;
		for (int k = 2; k <= m; k++)
			if (little[k].back().F < little[j].back().F)
				j = k;
		//printf("j:%d in:%d out:%d ", j, little[j].back().F, max(little[j].back().F, v[i].t) + v[i].a);
		little[j].pb(mp(max(little[j].back().F, v[i].t) + v[i].a, v[i]));
		//v[i].out();
	}
	//puts("\nBIG");

	for (int k = 1; k <= m; k++)
		little[k].pop_front();
	ll big = 0;
	for (int i = 0; i < n; i++)
	{
		int j = 1;
		for (int k = 2; k <= m; k++)
		{
			if (little[k].empty())
				continue;
			if ((little[j].empty()) || (little[k].front().F < little[j].front().F)
			|| (little[k].front().F == little[j].front().F && little[k].front().S.id < little[j].front().S.id))
				j = k;
		}
		auto x = little[j].front();
		ll T = max(x.F, big) + x.S.b;
		//printf("j:%d in:%d out:%d ", j, little[j].front().F, T);
		//x.S.out();
		ans[x.S.id] = T;
		big = T;
		little[j].pop_front();
	}
	for (int i = 1; i <= n; i++)
		printf(I64 "\n", ans[i]);
}
