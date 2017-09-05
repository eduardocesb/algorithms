#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, c, d, root, num;
	int i;

	cin >> a >> b >> c >> d;

	int count = 0;

	root = (int) sqrt(c) + 1;

	int divi[root];

	for (int i = 1; i < root; ++i)
	{
		if(c % i != 0)
			continue;
		num = c / i;
		divi[count] = i;
		count++;
		divi[count] = num;
		count++;
	}

	sort(divi, divi + count);

	for (int i = 0; i < count; ++i)
	{
		if(divi[i] % a == 0 && divi[i] % b != 0 && d % divi[i] != 0){
			cout << divi[i] << endl;
			return 0;
		}
	}

	cout << -1 << endl;
	return 0;
}