#include <iostream>
#include <stack>
#include <cstdio>

using namespace std;

char inverso(char x){
	if(x == ')')
		return '(';
	if(x == '}')
		return '{';
	if(x == ']')
		return '[';
}

int main(int argc, char const *argv[])
{
	int T;
	char x = ' ';
	cin >> T;
	scanf("%c", &x);
	for (int i = 0; i < T; ++i)
	{
		scanf("%c", &x);
		stack<char> pilha;
		bool deu_certo = true;
		while(x != '\n'){
			if(x == '(' || x == '{' || x == '[')
				pilha.push(x);
			else{
				if(pilha.empty() || pilha.top() != inverso(x))
					deu_certo = false;
				else
					pilha.pop();
			}
			scanf("%c", &x);
		}
		if(deu_certo && pilha.empty())
			cout << 'S' << endl;
		else
			cout << 'N' << endl;
	}
	return 0;
}