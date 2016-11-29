#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	char x;
	scanf("%c",&x);
	while(x != '\n'){
		
		if(x == 'A' || x == 'B' || x == 'C'){
			cout << '2';
		}else if(x == 'D' || x == 'E' || x == 'F'){
			cout << '3';
		}else if(x == 'G' || x == 'H' || x == 'I'){
			cout << '4';
		}else if(x == 'J' || x == 'K' || x == 'L'){
			cout << '5';
		}else if(x == 'M' || x == 'N' || x == 'O'){
			cout << '6';
		}else if(x == 'P' || x == 'Q' || x == 'R' || x == 'S'){
			cout << '7';
		}else if(x == 'T' || x == 'U' || x == 'V'){
			cout << '8';
		}else if(x == 'W' || x == 'X' || x == 'Y' || x == 'Z'){
			cout << '9';
		}else{
			cout << x;
		}
		
		scanf("%c",&x);
	}
	cout << endl;
	
	return 0;
}
