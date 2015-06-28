
#include <bits/stdc++.h>

using namespace std;

struct node
{
	int x, y;
};

node O, a, b;

int main()
{
	scanf("%d%d", &O.x, &O.y);
	int val = abs(O.x) + abs(O.y);
	a.x = 0, a.y = val;
	if (O.y < 0)
		a.y *= -1;
	b.y = 0, b.x = val;
	if (O.x < 0)
		b.x *= -1;
	if (a.x > b.x)
		swap(a, b);
	printf("%d %d %d %d", a.x, a.y, b.x, b.y);
	
}