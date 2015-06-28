
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define inf (int)(1e9 + 7)
#define maxn (int)(5e3 + 12)

int n, a[maxn];
vector <int> t[5];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]), t[a[i]].pb(i + 1);
	int sz = min(min(t[1].size(), t[2].size()), t[3].size());
	printf("%d\n", sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d %d %d\n", t[1][i], t[2][i], t[3][i]);
	}
}