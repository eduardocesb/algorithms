//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int n, x, r = 0, ant = 0;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
  	cin >> x;
  	if(i == 0){
  		ant = x - 10;
  	}

  	if(x >= ant + 10){
  		r += 10;
  	}else{
  		r += x - ant;
  	}

  	ant = x;
  }
  cout << r << endl;
  return 0;
}