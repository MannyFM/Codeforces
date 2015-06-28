
#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;
typedef unsigned long long ull;
typedef map <int, int> mii;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn int(1e6 + 12)
#define maxb int(2e6 + 12)
#define inf int(1e9 + 7)
#define linf ll(1e18 + 12)
#define eps 1e-7
#define mp make_pair
#define pb push_back
//#define fn "a"
#define F first
#define S second

char s[maxn];
int n;
vector <int> l, r;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%s", s);
	n = int(strlen(s));
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'r')
			r.pb(i + 1);
		else            
			l.pb(i + 1);
	}
	reverse(begin(l), end(l));
	for (auto i : r)
		printf("%d\n", i);
	for (auto i : l)
		printf("%d\n", i);
}