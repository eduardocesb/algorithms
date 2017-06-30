#include <iostream>

using namespace std;

int main(){
  int m, a, b;
  char O;
  cin >> m >> a >> O >> b;
  if(O == '*'){
  	a *= b;
  }else{
  	a += b;
  }

  if(a > m){
  	cout << "OVERFLOW\n";
  }else{
  	cout << "OK\n";
  }
  return 0;
}