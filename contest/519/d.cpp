
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e5 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "d"
#define F first
#define S second

int const sz = int('z' - 'a' + 1);

int cost[sz + 1];
ll ans;
ll sum[maxn];
map <ll, int> cnt[sz + 1];
char buf[maxn];
int a[maxn];


int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	for (int i = 0; i < sz; i++)
		scanf("%d", cost + i);
	scanf("%s", buf + 1);
	int n = int(strlen(buf + 1));
	for (int i = 1; i <= n; i++)
		a[i] = buf[i] - 'a';
	
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + cost[a[i]];
	
	for (int i = 1; i <= n; i++)
	{
		//printf("%c %I64d %d\n", a[i] + 'a', sum[i - 1], cnt[a[i]][sum[i - 1]]);
		ans += cnt[a[i]][sum[i - 1]];
		cnt[a[i]][sum[i]]++;
	}
	printf("%I64d", ans);

}