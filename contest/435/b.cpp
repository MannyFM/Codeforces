
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(2e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

int a[20], n, k;
char s[20];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s%d", s + 1, &k);
	n = int(strlen(s + 1));
	for (int i = 1; i <= n; i++)
		a[i] = s[i] - '0';
	for (int i = 1; i <= n; i++)
	{
		int t = i;
		for (int j = i + 1; j <= n; j++)
			if (a[j] > a[t] && j - i <= k)
				t = j;
		while (t > i)
		{
			swap(a[t], a[t - 1]);
			k--;
			t--;
		}
	}
	for (int i = 1; i <= n; i++)
		printf("%d", a[i]);
}