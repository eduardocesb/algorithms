//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  if(a*3 + b < d*3 + e){
  	cout << "F\n";
  }else if(a*3 + b > d*3 + e){
  	cout << "C\n";
  }else if(c > f){
  	cout << "C\n";
  }else if(c < f){
  	cout << "F\n";
  }else{
  	cout << "=\n";
  }
}