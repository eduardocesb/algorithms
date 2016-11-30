#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

void triangulo(double base, double altura){
	double area = (base*altura)/2.0;
	printf("TRIANGULO: %.3f\n", area);
}

void circulo(double raio){
	double PI = 3.14159;
	double area = PI * pow(raio, 2);
	printf("CIRCULO: %.3f\n", area);
}

void trapezio(double base_menor,double base_maior,double altura){
	double area = (base_menor + base_maior) * altura / 2.0;
	printf("TRAPEZIO: %.3f\n", area);
}

void quadrado(double lado){
	double area = pow(lado, 2);
	printf("QUADRADO: %.3f\n", area);
}

void retangulo(double base, double altura){
	double area = base * altura;
	printf("RETANGULO: %.3f\n", area);
}

int main(int argc, char const *argv[])
{
	double A, B, C;
	cin >> A >> B >> C;
	triangulo(A, C);
	circulo(C);
	trapezio(A, B, C);
	quadrado(B);
	retangulo(A, B);

	return 0;
}