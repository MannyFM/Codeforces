
#include <bits/stdc++.h>

using namespace std;

int n, a[1020], l, r, score[2];
bool fl;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	l = 0, r = n - 1;
	while (l < r)
	{
		if (a[l] > a[r])
			score[fl] += a[l++];
		else
			score[fl] += a[r--];
		fl = !fl;
	}
	if (l == r)
	{
		score[fl] += a[l];
	}
	printf("%d %d", score[0], score[1]);
}