//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int n, y, x = 0, r;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
  	cin >> y;
  	x += y;
  	if(x >= 1000000){
  		r = i + 1;
  		break;
  	}
  }
  cout << r << endl;
  return 0;
}