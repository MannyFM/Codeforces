#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fname ""

typedef long long LL;

const int N = 202000;
const int mod = 1e9 + 7;
const int inf = 2e9;
const LL infl = 2e18;
int n;
int d[N], a[N];

int main() {
	#ifdef LOCAL
		freopen(fname".in", "r", stdin);
		freopen(fname".out", "w", stdout);
	#endif
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		d[i] = inf;
	}
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	int ans;
	for(int i = 0; i < n; ++i)  {
		int j = upper_bound (d, d + n, a[i]) - d;
		d[j] = a[i];
		ans = max(ans, j);
	}
	cout << n - ans;
	return 0;
}