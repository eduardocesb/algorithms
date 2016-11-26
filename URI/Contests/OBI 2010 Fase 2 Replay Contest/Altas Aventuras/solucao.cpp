#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N, K; 
	cin >> N >> K;
	int r = 0;

	while(N > 1){
		if(N%2 == 0){
			N = N/2;
		}else{
			N = (N+1)/2;
		}
		r++;
	}
	cout << r << endl;
	return 0;
}