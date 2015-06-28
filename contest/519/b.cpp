
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

int n;
multiset <int> s1, s2;
int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d", &n);
	int a;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		s1.insert(a);
	}
	for (int i = 1; i <= n - 1; i++)
	{
		scanf("%d", &a);
		s1.erase(s1.find(a));
		s2.insert(a);
	}
	for (int i = 1; i <= n - 2; i++)
	{
		scanf("%d", &a);
		s2.erase(s2.find(a));
	}
	printf("%d\n%d", *s1.begin(), *s2.begin());
}