
#include <bits/stdc++.h>

using namespace std;

int n, l, r;
int cnt[2][2];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &l, &r), cnt[0][l]++, cnt[1][r]++;
	printf("%d", min(cnt[0][0], cnt[0][1]) + min(cnt[1][0], cnt[1][1]));
}