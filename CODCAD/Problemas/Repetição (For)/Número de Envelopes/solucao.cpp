//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int n, x, r = 0;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
  	cin >> x;
  	if(x < r || i == 0){
  		r = x;
  	}
  }
  cout << r << endl;
  return 0;
}