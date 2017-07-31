#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
	long long int N;
	cin >> N;
	if(N '==' 0){
		cout << 'N' << endl;
		return 0;
	}
	double x = log2(N + 1);
	if(floor(x) == x){
		cout << 'S' << endl;
	}else{
		cout << 'N' << endl;
	}
	return 0;
}