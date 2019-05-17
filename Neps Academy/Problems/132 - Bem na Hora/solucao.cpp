#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x)
{
	int root = sqrt(x);

	for(int i = 2; i <= root; i++)
		if(!(x % i)) return false;
	return true;
}

int main(int argc, char** argv)
{

	int N;

	cin >> N;

	while(!is_prime(N)) N--;

	cout << N << endl;

	return 0;
}
