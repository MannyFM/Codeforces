
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
//#define fn "c"
#define F first
#define S second

int a, b, ans;
int A, B;

int main()
{
	#ifdef fn
		freopen(fn".in", "r", stdin);
		freopen(fn".out", "w", stdout);
	#endif
	scanf("%d%d", &a, &b);
	for (int cnt1 = 0; cnt1 <= a / 2; cnt1++)
	{
		A = a - cnt1 * 2;
		B = b - cnt1;
		if (B < 0 || A < 0)
			continue;
		int cnt2 = min(A, B / 2);
		ans = max(ans, cnt1 + cnt2);
	}
	for (int cnt2 = 0; cnt2 <= b / 2; cnt2++)
	{
		B = b - cnt2 * 2;
		A = a - cnt2;
		if (B < 0 || A < 0)
			continue;
		int cnt1 = min(A / 2, B);
		ans = max(ans, cnt1 + cnt2);
	}
	printf("%d", ans);
}