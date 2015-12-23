
#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;
int f1, f2;

int main()
{
    scanf("%d%d%d%d", &a, &b, &c, &d);
    f1 = max(3ll * a / 10, a - (a * 1ll * c) / 250);
    f2 = max(3ll * b / 10, b - (b * 1ll * d) / 250);
    if (f1 > f2)
        puts("Misha");
    else
    if (f1 < f2)
        puts("Vasya");
    else
        puts("Tie");
}
