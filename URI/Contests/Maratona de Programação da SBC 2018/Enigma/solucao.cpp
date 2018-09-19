#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	string a, b;

	cin >> a >> b;

	int r = 0, tam1 = a.length(), tam2 = b.length();

	for(int i = 0; i <= tam1 - tam2; i++)
	{
		bool ok = true;
		for(int j = 0; j < tam2; j++)
			if(a[i + j] == b[j])
			{
				ok = false;
				break;
			}
		r += ok;
	}

	printf("%d\n", r);

	return 0;
}
