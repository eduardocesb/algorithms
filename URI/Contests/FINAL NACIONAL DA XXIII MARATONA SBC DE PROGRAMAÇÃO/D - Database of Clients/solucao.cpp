#include <bits/stdc++.h>
#define pii pair<string, string>

using namespace std;

int main(int argc, char** argv)
{
	int N;

	cin >> N;

	map<pii, bool> idx;

	for(int i = 0; i < N; i++)
	{
		string a, l1 = "", l2 = "";
		cin >> a;

		int j = 0, tam = a.length();


		while(j < tam)
		{
			if(a[j] == '@' || a[j] == '+') break;
			if(a[j] != '.')
				l1 += a[j];
			j++;
		}

		while(j < tam && a[j] != '@') j++;

		j++;

		while(j < tam)
			l2 += a[j++];

		idx[pii(l1, l2)] = true;
	}

	int r = idx.size();

	cout << r << endl;

	return 0;
}
