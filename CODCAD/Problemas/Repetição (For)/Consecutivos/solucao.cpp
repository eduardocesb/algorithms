//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int n, x, r = 0, ant, max = 0;
  cin >> n;
  for (int i = 0; i < n; ++i)
  {
  	cin >> x;
  	if(i == 0 || x == ant){
  		r++;
  	}else{
  		r = 1;
  	}
  	ant = x;
  	if(max < r){
  		max = r;
  	}
  }
  cout << max << endl;
  return 0;
}