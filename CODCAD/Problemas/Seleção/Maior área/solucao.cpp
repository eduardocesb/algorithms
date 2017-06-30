//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if((a*b) == (c*d)){
    cout << "Empate\n";
  }else if((a*b) < (c*d)){
      cout << "Segundo\n";
  }else{
      cout << "Primeiro\n";
  }
}