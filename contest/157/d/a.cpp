
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define maxn (int)(1e5 + 12)

int n, a[maxn], m;
int cnt[2][maxn];
//1 - a[i] = killer, 0 - a[i] = !killer
int c[2];
int cnt_killer = 0;
int IsKiller[maxn];
//1 - killer, 0 - !killer
string s[maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		cnt[a[i] > 0][abs(a[i])]++;
		c[a[i] > 0]++;
	}
	/*
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", cnt[0][i], cnt[1][i]);
	*/
	for (int i = 1; i <= n; i++)
	{
		//i = killer
		int now = cnt[1][i] + c[0] - cnt[0][i];
		if (now == m)
			cnt_killer++, IsKiller[i] = 1;
		/*
		if (now == m)
			printf("%d may be killer\n", i);
		*/
	}
	int ok = cnt_killer == 1;
	//printf("%d %d\n", cnt_killer, ok);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] > 0)
		{
			if (IsKiller[a[i]])
			{
				if (ok)
				{
					s[i] = "Truth";
				}
				else
					s[i] = "Not defined";
			}
			else
				s[i] = "Lie";
		}
		else
		{
			if (!IsKiller[-a[i]])
				s[i] = "Truth";
			else
			{
				if (ok)
					s[i] = "Lie";
				else
					s[i] = "Not defined";
			}
		}
	}
	for (int i = 1; i <= n; i++)
		cout << s[i] << '\n';
}
