//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int N, P;
  cin >> N >> P;
  int x, y, r = 0;
  for (int i = 0; i < N; ++i)
  {
  	cin >> x >> y;
  	if(x + y >= P){
  		r++;
  	}
  }

  cout << r << endl;
  return 0;
}