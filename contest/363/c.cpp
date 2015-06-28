
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 200000  + 12
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
#define fn "c"
#define F first
#define S second

char s[maxn];
char t[maxn];
int sz;

int main()
{
	#ifdef LOCAL
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s", s);
	t[sz++] = s[0];
	int n = int(strlen(s));
	for (int i = 1; i < n; i++)
	{
		if (sz > 1 && t[sz - 1] == t[sz - 2] && t[sz - 1] == s[i])
			continue;
		if (sz > 2 && t[sz - 2] == t[sz - 3] && t[sz - 1] == s[i])
			continue;
		t[sz++] = s[i];
	}
	puts(t);
}