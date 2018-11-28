#include <bits/stdc++.h>

using namespace std;

int mdc(int a, int b)
{
	return !b ? a : mdc(b, a % b);
}

int mmc(int a, int b)
{
	return (a * b) / mdc(a, b); 
}

int main(int argc, char** argv)
{
	int a, b;
	
	scanf("%d.%d", &a, &b);
	
	int n = 100 * a + b;
	int r = mmc(n, 36000) / n;
	
	cout << r << endl;
	
	return 0;
}