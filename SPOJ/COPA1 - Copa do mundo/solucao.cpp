#include <iostream>

using namespace std;

int main(){
	char oitavas[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P'};
	char quartas[8];
	char semi[4];
	char fim[2];
	int j = 0;
	for(int i=0;i<16;i+=2){
		int j1,j2;
		cin >> j1 >> j2;
		if(j1 > j2){
			quartas[j] = oitavas[i];
		}else{
			quartas[j] = oitavas[i+1];
		}
		j++;
	}
	j=0;
	for(int i=0;i<8;i+=2){
		int j1,j2;
		cin >> j1 >> j2;
		if(j1 > j2){
			semi[j] = quartas[i];
		}else{
			semi[j] = quartas[i+1];
		}
		j++;
	}
	j=0;
	for(int i=0;i<4;i+=2){
		int j1,j2;
		cin >> j1 >> j2;
		if(j1 > j2){
			fim[j] = semi[i];
		}else{
			fim[j] = semi[i+1];
		}
		j++;
	}
	
	int j1,j2;
	cin >> j1 >> j2;
	if(j1 > j2){
		cout << fim[0] << endl;
	}else{
		cout << fim[1] << endl;
	}
	return 0;
}
