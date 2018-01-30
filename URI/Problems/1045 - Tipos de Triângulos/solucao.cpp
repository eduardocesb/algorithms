#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char const *argv[])
{
	//optimize;

	double A, B, C;

	cin >> A >> B >> C;

	if(A < B)
		swap(A, B);
	if(A < C)
		swap(A, C);
	if(B < C)
		swap(B, C);

	if(A >= B + C)
		puts("NAO FORMA TRIANGULO");
	else
	{
		if((A * A) == (B * B) + (C * C))
			puts("TRIANGULO RETANGULO");
		else if((A * A) > (B * B) + (C * C))
			puts("TRIANGULO OBTUSANGULO");
		else if((A * A) < (B * B) + (C * C))
			puts("TRIANGULO ACUTANGULO");
		
		if(A == B && B == C)
			puts("TRIANGULO EQUILATERO");
		else if(A == B || A == C || B == C)
			puts("TRIANGULO ISOSCELES");
	}

	return 0;
}