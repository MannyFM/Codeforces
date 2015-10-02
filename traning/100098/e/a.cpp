
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = 30 * 1000 + 15;
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
#define next MyLittlenext
//#define end MyLittleEnd
#define all(x) x.begin(), x.end()
#define fn "door"

int n, W;
pii a[maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &n, &W);
	scanf("%d%d", &a[0].F, &a[1].F);
	a[0].S = a[1].S = -1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i + 1].F);
		a[i + 1].S = i;
	}
	n += 2;
	sort(a, a + n);
	/*
	for (int i = 0; i < n; i++)
		printf("%d ", a[i].F);
	puts("");
	*/
	for (int ans = 0; ans <= n; ans++)
	{
		for (int i = 0; i < n - ans - 1; i++)
		{
			if (a[i + ans + 1].F - a[i].F >= W)
			{
				int cnt = ans;
				for (int j = 1; j <= ans; j++)
					if (a[i + j].S == -1)
						cnt--;
				printf("%d\n", cnt);
				for (int j = 1; j <= ans; j++)
					if (a[j + i].S != -1)
						printf("%d\n", a[j + i].S);
				return 0;
			}
		}
	}
	puts("-1");
}
