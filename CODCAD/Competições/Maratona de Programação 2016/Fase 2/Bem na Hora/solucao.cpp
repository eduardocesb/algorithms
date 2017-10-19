#include <bits/stdc++.h>

using namespace std;

bool prime(int x){
	int root = sqrt(x);
	for (int i = 2; i <= root; ++i)
		if(x % i == 0) return false;
	return true;
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	for(int i = N; i > 0; i--)
		if(prime(i)){
			cout << i << endl;
			break;
		}
	return 0;
}