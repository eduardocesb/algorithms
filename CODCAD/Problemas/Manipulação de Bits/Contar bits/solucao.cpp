#include <bits/stdc++.h>

using namespace std;

int count_bits(long int N){
	int contador = 0;
	while(N != 0){
		contador++;
		N -= N&-N;
	}
	return contador;
}

int main(int argc, char const *argv[])
{
	long int N;
	cin >> N;
	cout << count_bits(N) << endl;
	return 0;
}
