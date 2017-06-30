#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b , c;
	cin >> a >> b >> c;
	if(a == b){
		cout << 'S' << endl;
	}else if(a == c){
		cout << 'S' << endl;
	}else if(b == c){
		cout << 'S' << endl;
	}else if(a == (b + c)){
		cout << 'S' << endl;
	}else if(a == (b - c)){
		cout << 'S' << endl;
	}else if(a == (c - b)){
		cout << 'S' << endl;
	}else if(b == (a + c)){
		cout << 'S' << endl;
	}else if(b == (a - c)){
		cout << 'S' << endl;
	}else if(b == (c - a)){
		cout << 'S' << endl;
	}else if(c == (a + b)){
		cout << 'S' << endl;
	}else if(c == (a - b)){
		cout << 'S' << endl;
	}else if(c == (b - a)){
		cout << 'S' << endl;
	}else{
		cout << 'N' << endl;
	}
}