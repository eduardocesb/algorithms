//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int n, p, x;
  cin >> p >> n;
  for (int i = 0; i < n; ++i)
  {
  	cin >> x;
  	p += x;
  	if(p < 0){
  		p = 0;
  	}else if(p > 100){
  		p = 100;
  	}
  }
  cout << p << endl;
  return 0;
}