#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	unordered_set<string> joias;

	string j;

	while((cin >> j)) joias.insert(j);

	cout << joias.size() << endl;
	return 0;
}