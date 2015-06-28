
#include <bits/stdc++.h>

using namespace std;

int c[3], n, a;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a), c[i % 3] += a;
	int ans = max(c[0], max(c[1], c[2]));
	if (ans == c[0])
		puts("chest");
	if (ans == c[1])
		puts("biceps");
	if (ans == c[2])
		puts("back");
}