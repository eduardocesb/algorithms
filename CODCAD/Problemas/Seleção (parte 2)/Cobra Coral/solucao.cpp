//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  
  if(a == c || b == d){
  	cout << 'V' << endl;
  }else{
  	cout << 'F' << endl;
  }
}