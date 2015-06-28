
#include <bits/stdc++.h>

using namespace std;

int n, s;
int a[200], sum;

int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	for (int i = 0; i < n - 1; i++)
		sum += a[i];
	puts(sum <= s ? "YES" : "NO");
}
