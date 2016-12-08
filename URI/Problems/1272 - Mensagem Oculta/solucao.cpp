#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	char x;
	scanf("%c", &x);
	for (int i = 0; i < N; ++i)
	{
		scanf("%c", &x);
		bool imprime = true;
		while(x != '\n'){
			if(x != ' ' && imprime == true){
				cout << x;
				imprime = false;
			}
			if(x == ' '){
				imprime = true;
			}
			scanf("%c", &x);
		}
		cout << endl;
	}
	return 0;
}