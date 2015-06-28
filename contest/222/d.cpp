
#include <bits/stdc++.h>

using namespace std;

#define maxn int(1e5 + 12)

int n, a[maxn], b[maxn], x;
int cnt[maxn], suf[maxn];

int main()
{
	scanf("%d%d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d%d", a + i, b + i);
	for (int i = 0; i < n; i++)
		cnt[b[i]]++;
	for (int i = maxn - 2; i >= 0; i--)
		suf[i] = suf[i + 1] + cnt[i];
	for (int i = 0; i < n; i++)
	{
		
	}
}