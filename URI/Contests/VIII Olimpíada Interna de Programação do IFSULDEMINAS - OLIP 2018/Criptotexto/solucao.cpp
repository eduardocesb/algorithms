#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char** argv)
{
	optimize;
	stack<char> p;
	string x;
	int N;

	cin >> N;

	while(N--)
	{
		cin >> x;
for(auto c : x)
			if(c >= 'a' && c <= 'z')
				p.push(c);
		while(!p.empty())
			cout << p.top(), p.pop();
		cout << endl;
	}

	return 0;
}
