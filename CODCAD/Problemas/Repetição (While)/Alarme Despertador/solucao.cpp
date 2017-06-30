//Codigo de exemplo
#include<iostream>

using namespace std;

int main(){
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  while(a != 0 || b != 0 || c != 0 || d != 0){
  	int r = 0;
  	if(a > c || (a == c && b > d)){
  		r += ((24 - a) + c) * 60;
  	}else{
  		r += (c - a) * 60;
  	}
  	r += d - b;
  	cout << r << endl;
  	cin >> a >> b >> c >> d;
  }
  return 0;
}