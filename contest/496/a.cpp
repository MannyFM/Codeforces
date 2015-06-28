
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)
#define maxn (int)(1e5 + 12)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair <int, int>
#define ll long long

int n, a[200], ans = inf;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i + 1 < n; i++)
	{
		int now = -inf;
		for (int j = 1; j < n; j++)
			if (j == i)
				now = max(now, a[j + 1] - a[j - 1]), j++;
			else
				now = max(now, a[j] - a[j - 1]);
		ans = min(now, ans);
	}
	printf("%d", ans);
}