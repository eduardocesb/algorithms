#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cstring>
using namespace std;

int fatorial(int x){
	int fat[x+1];
	fat[1] = 1; 
	for(int i=2;i<=x;i++){
		fat[i] = fat[i-1] *i;
	}
	return fat[x];
}

int main(){
	
	int instacia = 1;
	int n;
	while(scanf("%i",&n)!=EOF){
		long r = fatorial(n);
		char res[11];
		for(int i=0;i<11;i++){
			res[i] = 0;
		}
		sprintf (res, "%d", r);
		
		cout << "Instancia " << instacia << endl << res << endl;
		instacia++;
	} 
	return 0;
}
