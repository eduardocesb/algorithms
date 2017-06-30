#include <iostream>

using namespace std;

int main(){
  char X;
  int n, r = 0;
  cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> X;
		if(X == 'P' || X == 'C'){
			r += 2;
		}else if(X == 'A'){
			r++;
		}
	}

	cout << r << endl;
  return 0;
}