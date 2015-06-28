
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
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

const int sz = 'z' - 'a' + 1;

int cnt[sz];
int n, ans = 0;
char s[2 * maxn];

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= 2 * n - 2; i += 2)
	{
		cnt[s[i] - 'a']++;
		if (!cnt[s[i + 1] - 'A'])
		{
			ans++;
		}
		else
			cnt[s[i + 1] - 'A']--;
	}
	printf("%d", ans);
}
