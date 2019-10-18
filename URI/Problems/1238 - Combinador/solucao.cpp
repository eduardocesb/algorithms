#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[])
{

	int N;

	string a, b;

	scanf("%d", &N);

	while(N--)
	{
		cin >> a >> b;

		string r = "";


		for(int i = 0; i < (int)a.length(); i++)
		{
			r += a[i];

			if(i < (int)b.length()) r += b[i];
		}

		for(int i = (int)a.length(); i < (int)b.length(); i++)
			r += b[i];

		cout << r << endl;
	}

	return 0;
}