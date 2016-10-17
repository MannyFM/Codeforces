
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

double a, b, c, D, x;

int main() {
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				cout << "R";
			else 
				cout << "No solution";
		} else {
			cout << -c / b;
		}
		return 0;
	}
	D = b * b - 4 * a * c;
	if (D < 0) {
		cout << "No solution";
	}
	if (D == 0) {
		double x = - b / (2 * a);
		cout << x;
	}
	if (D > 0) {
		D = sqrt(D);
		double x = (- b + D) / (2 * a);
		cout << x << " ";
		x = (-b - D) / (2 * a);
		cout << x;
	}
}
