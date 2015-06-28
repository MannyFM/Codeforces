
#include <bits/stdc++.h>

using namespace std;

#define sqr(x) ((x) * (x))

double r, xa, ya, xb, yb;

int main()
{
	cin >> r >> xa >> ya >> xb >> yb;
	double d = (sqr(xa - xb) + sqr(ya - yb)) + .0;
	d = sqrt(d);
	int ans = d / (2.0 * r);
	if (abs(ans * (2.0 * r) - d) >= 1e-9)
		ans++;
	printf("%d", ans);	
}