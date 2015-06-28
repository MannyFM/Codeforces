
#include <bits/stdc++.h>

using namespace std;

#define maxn (int)(1e5 + 12)

int n, a[maxn], b[maxn], cnt;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i), b[i] = a[i];
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		cnt += (b[i] != a[i]);
	puts(cnt <= 2 ? "YES" : "NO");
}