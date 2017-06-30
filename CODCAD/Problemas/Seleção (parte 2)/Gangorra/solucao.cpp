//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  if(a * b == c * d){
  	cout << 0 << endl;
  }else if(a * b < c * d){
  	cout << 1 << endl;
  }else{
  	cout << -1 << endl;
  }
}