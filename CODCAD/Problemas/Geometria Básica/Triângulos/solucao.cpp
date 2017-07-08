#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int A, B, C;
	cin >> A >> B >> C;
	if(A + B <= C || A + C <= B || B + C <= A || A < max(B - C, C - B) || B < max(A - C, C - A) || C < max(A - B, B - A)){
		cout << 'n' << endl;
	}else if((A * A) + (B * B) == (C * C) || (A * A) + (C * C) == (B * B) || (B * B) + (C * C) == (A * A)){
		cout << 'r' << endl;
	}else if((A * A) + (B * B) < (C * C) || (A * A) + (C * C) <= (B * B) || (B * B) + (C * C) <= (A * A)){
		cout << 'o' << endl;
	}else{
		cout << 'a' << endl;
	}
	return 0;
}