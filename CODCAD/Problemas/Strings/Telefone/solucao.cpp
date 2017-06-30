#include <iostream>
#include <cctype>

using namespace std;

char troca(char x){
	if(x == 'A' || x == 'B' || x == 'C'){
		return '2';
	}else if(x == 'D' || x == 'E' || x == 'F'){
		return '3';
	}else if(x == 'G' || x == 'H' || x == 'I'){
		return '4';
	}else if(x == 'J' || x == 'K' || x == 'L'){
		return '5';
	}else if(x == 'M' || x == 'N' || x == 'O'){
		return '6';
	}else if(x == 'P' || x == 'Q' || x == 'R' || x == 'S'){
		return '7';
	}else if(x == 'T' || x == 'U' || x == 'V'){
		return '8';
	}else if(x == 'W' || x == 'X' || x == 'Y' || x == 'Z'){
		return '9';
	}
}	

int main(int argc, char const *argv[])
{
	string num;
	cin >> num;
	int tam = num.length();
	for (int i = 0; i < tam; ++i)
	{
		if(num[i] == '-'){
			continue;
		}else if(isdigit(num[i])){
			continue;
		}else{
			num[i] = troca(num[i]);
		}
	}

	cout << num << endl;
	return 0;
}