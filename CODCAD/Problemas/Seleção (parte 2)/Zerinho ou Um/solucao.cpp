//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  if(a != b && a != c){
  	cout << "A" << endl;
  }else if(b != a && b != c){
  	cout << "B" << endl;
  }else if(c != a && c != b){
  	cout << "C" << endl;
  }else{
  	cout << "*" << endl;
  }
}