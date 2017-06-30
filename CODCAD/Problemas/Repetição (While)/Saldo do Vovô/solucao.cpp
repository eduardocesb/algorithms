//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int x, s, r = 0;
  cin >> x >> s;
  r = s;
  int y;
  for (int i = 0; i < x; ++i)
  {
  	cin >> y;
  	s += y;
  	if(r > s){
  		r = s;
  	}
  }
  cout << r << endl;
  return 0;
}