
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 1000 + 12
#define inf int(1e9 + 7)
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second
#define NO {puts("0 0"); return 0;}

int n, p[maxn];
int l, r;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", p + i);
	for (int i = 1; i <= n; i++)
		if (p[i] != i)
		{
			l = i;
			r = p[i];
			break;
		}
	if (l == 0)
		NO;
	reverse(p + l, p + r + 1);
	for (int i = 1; i <= n; i++)
		if (p[i] != i)
			NO;
	printf("%d %d", l, r);
}
