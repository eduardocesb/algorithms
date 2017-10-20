#include <bits/stdc++.h>
#define optimize std::ios::sync_with_stdio(0); cin.tie(0)

using namespace std;

int main(int argc, char const *argv[])
{
	optimize;
	
	int N, x, y, x_, y_;

	cin >> N >> x >> y >> x_ >> y_;

	N /= 2;

	if(x <= N && x_ > N)
		cout << 'S' << endl;
	else if(x_ <= N && x > N)
		cout << 'S' << endl;
	else if(y <= N && y_ > N)
		cout << 'S' << endl;
	else if(y_ <= N && y > N)
		cout << 'S' << endl;
	else
		cout << 'N' << endl;

	return 0;
}