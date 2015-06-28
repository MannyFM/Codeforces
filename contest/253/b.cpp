
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n, c[maxn], a[maxn], sz;
map <int, int> d;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	/*
	for (int i = 0; i < n; i++)	
		printf("%d ", a[i]);
	puts("");
	*/
	int ans = n - 1;
	for (int l = 0; l < n; l++)
	{
		int L = l - 1, R = n;
		while (R - L > 1)
		{
			//printf("%d %d\n", L, R);
			int mid = (L + R) >> 1;
			if (a[mid] > 2 * a[l])
			{
				R = mid;
			}
			else
			{
				L = mid;
			}
		}
		//printf("%d %d %d  %d %d\n", l, L, R, a[l], a[L]);
		ans = min(ans, n - (L - l + 1));
	}

	printf("%d", ans);
}