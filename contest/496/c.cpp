
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

int n, m, a[200][200];
int us[200], ans, b[200];

int main()
{
	scanf("%d%d", &n, &m);
	char c;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> c, a[i][j] = (int)(c - 'a');
	for (int i = 1; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (us[j])
				continue;
			if (a[i][j] > a[i - 1][j])
				us[j] = 1;
			if (a[i][j] < a[i - 1][j])
				ans++;
		}
		for (int i = 0; i < m; i++)
			cout << us[i] << " ";
		puts("");
	}
	for (int i = 0; i < m; i++)
		cout << us[i] << " ";
	printf("%d", ans);
}