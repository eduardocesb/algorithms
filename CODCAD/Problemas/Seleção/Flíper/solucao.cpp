//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  if(a == 0){
      cout << "C\n";
  }else{
      if(b == 0){
          cout << "B\n";
      }else{
          cout << "A\n";
      }
  }
}