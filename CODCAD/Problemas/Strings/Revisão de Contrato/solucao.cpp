#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	string num;
	cin >> N >> num;
	while(N != 0 || num != "0"){
		int tam = num.length();
		for (int i = 0; i < tam; ++i)
		{
			if(num[i] == '0' + N){
				num.erase(num.begin() + i);
				i--;
				tam--;
			}
		}
		tam = num.length();
		bool achou = false;
		for (int i = 0; i < tam; ++i)
		{
			if(!achou && num[i] == '0'){
				continue;
			}
			cout << num[i];
			achou = true;
		}
		if(!achou){
			cout << 0;
		}
		cout << endl;
		cin >> N >> num;
	}
	return 0;
}