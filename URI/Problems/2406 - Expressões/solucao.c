#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXN 100100

char pilha[MAXN];
int tam;

void push(char x)
{
	pilha[tam++] = x;
}

bool empty()
{
	return !tam;
}

char pop()
{
	if(empty())
		return ' ';
	return pilha[--tam];
}


bool abre(char x)
{
	return (x == '(' || x == '{' || x == '[');
}

bool fecha(char x, char y)
{
	if(y == '(') return x == ')';
	if(y == '[') return x == ']';
	if(y == '{') return x == '}';
	return x == ' ';
}

int main(int argc, char** argv)
{
	int N, i;
	scanf("%d", &N);

	while(N--)
	{
		tam = 0;
		bool ok = true;
		fflush(stdin);

		char linha[MAXN];

		scanf("%s", linha);
		int sz = strlen(linha);

		for(i = 0; i < sz; i++)
			if(abre(linha[i]))
				push(linha[i]);
			else
				ok *= fecha(linha[i], pop());

		printf("%c\n", (ok && empty() ? 'S' : 'N'));
	}

	return 0;
}
