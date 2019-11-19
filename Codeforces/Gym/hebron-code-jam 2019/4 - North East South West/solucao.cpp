#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;

	int N;

	cin >> N;

	string op;

	int r = 0;

	for(int i = 0; i < N; i++)
	{
		cin >> op;

		if(op == "left")
			r--;
		else if(op == "right")
			r++;
		else
			r += 2;

		if(r > 3)
			r -= 4;

		if(r < 0)
			r += 4;
	}

	string a[] = {"north", "east", "south", "west"};

	cout << a[r] << endl;

	return 0;
}