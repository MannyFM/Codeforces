
#include <bits/stdc++.h>

using namespace std;

#define inf (int)(1e9 + 7)
#define maxn (int)(1e3 + 12)
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define pii pair <int, int>
#define ll long long

int n, m, ans;
int left, right, us[maxn];
int a[maxn][maxn];
char c;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
		cin >> c, a[i][j] = (int)(c - 'a');
	for (int k = 0; k < max(n, m); k++)
	{
		bool fl = 0;
		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (us[j])
					continue;
				if (a[i - 1][j] > a[i][j])
				{
					us[j] = 1;
					fl = 1;
				}
				if (a[i - 1][j] < a[i][j])
				{
					break;
				}
			}
		}
		if (!fl)
			break;
	}
	for (int i = 0; i < m; i++)
		ans += us[i];
	cout << ans;
	/*
	for (int i = 0; i < m; i++)
		cout << us[i] << " ";
	*/
}