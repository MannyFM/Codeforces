
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int const maxn = int(1e5 + 12);
int const maxb = int(1e6 + 12);
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
#define dist(l, r) (r - l + 1)
//#define fn ""

int n, a[maxn];
int cnt[maxb], head[maxb], tail[maxb];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
	{
		if (!head[a[i]])
			head[a[i]] = i;
		cnt[a[i]]++;
		tail[a[i]] = i;
	}
	int j = 1;
	for (int i = 1; i <= n; i++)
		if (cnt[a[i]] > cnt[a[j]] || (cnt[a[i]] == cnt[a[j]] && (dist(head[a[i]], tail[a[i]]) < dist(head[a[j]], tail[a[j]]))))
			j = i;
	printf("%d %d\n", head[a[j]], tail[a[j]]);
}
