
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
#define fn "disease"
#define NO {puts("Incorrect"); exit(0);}

int n, m;
set <int> pos, neg, net;
int a[110][10100], res[10100];

void relax()
{
	for (int i = 1; i <= m; i++)
	{
		int cnt = 0;
		bool cur = 0;
		for (int j = 1; j <= n; j++)
		{
			if (a[j][i])
			{
				if (net.count(j))
					cnt++;
				if (pos.count(j))
					cur |= 1;
			}
		}
		if (!cnt)
			continue;
		if (!res[i])
		{
			for (int j = 1; j <= n; j++)
			{
				if (a[j][i] && net.count(j))
				{
					net.erase(j);
					neg.insert(j);
					//printf("%d:net->neg\n", j);
					relax();
				}
			}
			continue;
		}
		if (cnt == 1 && !cur)
		{
			for (int j = 1; j <= n; j++)
				if (a[j][i] && net.count(j))
				{
					net.erase(j);
					pos.insert(j);
					//printf("%d:net->pos\n", j);
					relax();
				}
		}
	}
}

void check()
{
	for (int i = 1; i <= m; i++)
	{
		bool ok = 0;
		for (int j = 1; j <= n; j++)
		{
			if (a[j][i] && (pos.count(j) || net.count(j)))
				ok |= 1;
		}
		if (res[i] != ok)
			NO;
	}
}

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
			scanf("%d", &a[j][i]);
		scanf("%d", res + i);
	}
	for (int i = 1; i <= n; i++)
		net.insert(i);
	relax();
	/*
	printf("%d ", neg.size());
	for (int x : neg)
		printf("%d ", x);
	puts("");
	printf("%d ", pos.size());
	for (int x : pos)
		printf("%d ", x);
	puts("");
	printf("%d ", net.size());
	for (int x : net)
		printf("%d ", x);
	puts("");
	*/
	check();
	printf("%d ", neg.size());
	for (int x : neg)
		printf("%d ", x);
	puts("");
	printf("%d ", pos.size());
	for (int x : pos)
		printf("%d ", x);
	puts("");
	printf("%d ", net.size());
	for (int x : net)
		printf("%d ", x);
	puts("");
	
}
