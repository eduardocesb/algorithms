#include <iostream>
#include <cstdio>

using  namespace std;

int main(int argc, char const *argv[])
{
	char c;
	int n = 0;
	while(true){
		scanf("%c", &c);
		if(c == '\n'){
			break;
		}

		if(c == ' '){
			cout << c;
		}else if(n){
			cout << c;
			n--;
		}else{
			n++;
		}
	}
	cout << endl;
	return 0;
}