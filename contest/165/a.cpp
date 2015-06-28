
#include <bits/stdc++.h>

using namespace std;

struct node
{
	int x, y;
};

node a[250];
int n, ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &a[i].x, &a[i].y);
	}
	for (int i = 0; i < n; i++)
	{
		bool l = 0, r = 0, u = 0, d = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j].x > a[i].x && a[j].y == a[i].y)
				r = 1;
			if (a[j].x < a[i].x && a[j].y == a[i].y)
				l = 1;
			if (a[j].x == a[i].x && a[j].y < a[i].y)
				d = 1;
			if (a[j].x == a[i].x && a[j].y > a[i].y)
				u = 1;
		}
		if (u && d && r && l)
			ans++;
	}
	printf("%d", ans);
}