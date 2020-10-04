#include <iostream>
#include <cstdio>


using namespace std;


long long int fatorial(int x){
	if(x == 0 || x == 1){
		return 1;
	}
	
	return x * fatorial(x-1);
}

int main(){
	int n,m;
	while(scanf("%d %d", &n, &m) != EOF){
		cout << fatorial(n) + fatorial(m) << endl;
	}
	
}
