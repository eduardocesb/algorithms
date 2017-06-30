//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int x;
  cin >> x;
  int r = 0;
  while(x != 0){
    if(r < x){
      r = x;
    }
    cin >> x;
  }
  cout << r << endl;
  return 0;
}