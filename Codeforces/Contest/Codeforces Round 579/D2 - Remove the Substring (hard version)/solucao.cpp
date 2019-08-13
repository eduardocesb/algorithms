#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)
#define pii pair<int, int>
#define ll long long
#define MAXN 200020

using namespace std;

int ida[MAXN], vinda[MAXN], preffix[MAXN], suffix[MAXN];

int main(int argc, char const *argv[])
{
	optimize;

	string A, B;

	cin >> A >> B;

	int tam = A.length(), tam1 = B.length(), pos = 0;

	for(int i = 0; i < tam; i++)
	{
		if(A[i] == B[pos])
		{
			ida[i] = 1;
			pos++;
		}
	}

	pos--;

	int y = 1;

	for(int i = tam - 1; i >=0; i--)
	{
		if(A[i] == B[pos])
		{
			vinda[y++] = i;
			pos--;
		}
	}

	vinda[0] = tam;

	preffix[0] = ida[0];

	for(int i = 1; i < tam; i++)
		preffix[i] = ida[i] + preffix[i - 1];


	int r = vinda[tam1];

	for(int i = 0; i < tam; i++)
		r = max(r, vinda[tam1 - preffix[i]] - i - 1);

	cout << r << endl;
	
	return 0;
}