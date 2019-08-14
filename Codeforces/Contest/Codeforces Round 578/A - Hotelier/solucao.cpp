#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

bool salas[10];

int main(int argc, char** argv)
{
	optimize;

	int N;

	cin >> N;

	char x;

	for(int i = 0; i < N; i++)
	{
		cin >> x;

		if(x == 'L')
		{
			for(int j = 0; j < 10; j++)
				if(!salas[j])
				{
					salas[j] = true;
					break;
				}
		}
		else if(x == 'R')
		{
			for(int j = 9; j >= 0; j--)
				if(!salas[j])
				{
					salas[j] = true;
					break;
				}
		}
		else
			salas[x - '0'] = false;
	}
	
	for(int i = 0; i < 10; i++)
		cout << salas[i];
	cout << endl;

	return 0;
}
