#include <iomanip>
#include <iostream>

using namespace std;

int main(){
  char O;
  double a, b;
  cin >> O >> a >> b;
  cout << fixed << setprecision(2);
  if(O == 'D'){
  	cout << a / b << endl;
  }else{
  	cout << a * b << endl;
  }
  return 0;
}