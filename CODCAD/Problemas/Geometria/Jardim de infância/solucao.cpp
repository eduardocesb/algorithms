#include <bits/stdc++.h>
#define ponto pair<int, int>
#define X first
#define Y second
#define RETO 0
#define AGUDO 1
#define OBTUSO -1

using namespace std;

ponto P1, P2, P3, P4, P5, P6, P7;

long long int comprimento(ponto a, ponto b){
	return pow(a.X - b.X, 2) + pow(a.Y - b.Y, 2);
}

int angulo(ponto a, ponto b, ponto c){
	if(comprimento(a, b) + comprimento(b, c) == comprimento(a, c))
		return RETO;
	else if(comprimento(a, b) + comprimento(b, c) > comprimento(a, c))
		return AGUDO;
	else
		return OBTUSO;
}

bool forma_reta(ponto a, ponto b, ponto c){
	return ((c.X * b.Y) + (a.X * c.Y) + (a.Y * b.X)) - ((a.X * b.Y) + (a.Y * c.X) + (b.X * c.Y)) == 0;
}

bool check1(){
	return angulo(P2, P1, P3) == AGUDO;
}

bool check2(){
	return comprimento(P1, P2) == comprimento(P1, P3);
}

bool check3(){
	return forma_reta(P2, P4, P5) && forma_reta(P4, P5, P3);
}

bool check4(){
	return comprimento(P2, P4) == comprimento(P5, P3);
}

bool check5(){
	return comprimento(P2, P3) > comprimento(P4, P5);
}

bool check6(){
	return angulo(P2, P4, P6) == RETO && angulo(P3, P5, P7) == RETO;
}

bool check7(){
	return comprimento(P4, P6) == comprimento(P5, P7);
}

bool check8(){
	return comprimento(P1, P6) > comprimento(P1, P4);
}
bool forma_pinheiro(){
	return (check1() && check2() && check3() && check4() && check5() && check6() && check7() && check8());
}

int main(int argc, char const *argv[])
{

	cin >> P1.X >> P1.Y;
	cin >> P2.X >> P2.Y;
	cin >> P3.X >> P3.Y;
	cin >> P4.X >> P4.Y;
	cin >> P5.X >> P5.Y;
	cin >> P6.X >> P6.Y;
	cin >> P7.X >> P7.Y;
	cout << (forma_pinheiro() ? 'S' : 'N') << endl;
	return 0;
}