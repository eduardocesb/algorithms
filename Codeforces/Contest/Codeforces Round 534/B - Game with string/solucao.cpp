#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

int main(int argc, char** argv)
{
	optimize;

	string S;

	cin >> S;

	int r = 0;

	stack<char> pilha;

	for(auto x : S)
		if(!pilha.empty() && pilha.top() == x) pilha.pop(), r++;
		else pilha.push(x);

	cout << (r & 1 ? "Yes" : "No") << endl;

	return 0;
}
