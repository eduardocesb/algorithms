#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	unsigned int a, b;

	while((cin >> a >> b) && !cin.eof())
		cout << (unsigned int)(a ^ b) << endl;
	return 0;
}
