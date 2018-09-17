#include <bits/stdc++.h>
#define pii pair<int, int>

using namespace std;

int mdc(int a, int b)
{
	return !b ? a : mdc(b, a % b);
}

pii soma(int n1, int d1, int n2, int d2)
{
	pii r;
	r.first = (n1 * d2) + (n2 * d1);
	r.second = (d1 * d2);
	return r;
}

pii subtracao(int n1, int d1, int n2, int d2)
{
	pii r;
	r.first = (n1 * d2) - (n2 * d1);
	r.second = (d1 * d2);
	return r;
}

pii multiplicacao(int n1, int d1, int n2, int d2)
{
	pii r;
	r.first = (n1 * n2);
	r.second = (d1 * d2);
	return r;
}

pii divisao(int n1, int d1, int n2, int d2)
{
	pii r;
	r.first = (n1 * d2);
	r.second = (d1 * n2);
	return r;
}

void processa(int n1, int d1, int n2, int d2, string op)
{
	pii r;
	if(op == "+")
		r = soma(n1, d1, n2, d2);
	else if(op == "-")
		r = subtracao(n1, d1, n2, d2);
	else if(op == "*")
		r = multiplicacao(n1, d1, n2, d2);
	else
		r = divisao(n1, d1, n2, d2);

	bool negativo = r.first < 0;

	if(negativo)
		r.first *= -1;

	int MDC = mdc(r.first, r.second);

	printf("%s%d/%d = %s%d/%d\n", (negativo ? "-" : ""), r.first, r.second, (negativo ? "-" : ""), (r.first / MDC) , (r.second / MDC));
}


int main(int argc, char** argv)
{
	int n, n1, n2, d1, d2;

	string op, x;

	cin >> n;

	while(n--)
	{
		cin >> n1 >> x >> d1 >> op >> n2 >> x >> d2;
		processa(n1, d1, n2, d2, op);
	}

	return 0;
}
