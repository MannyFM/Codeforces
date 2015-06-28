
#include <bits/stdc++.h>

using namespace std;

int n, k, l, c, d, p, nl, np;

int main()
{
	scanf("%d%d%d%d%d%d%d%d", &n, &k, &l, &c, &d, &p, &nl, &np);
	printf("%d", min((k * l) / (n * nl), min((c * d) / n, (p / np) / n)));
}