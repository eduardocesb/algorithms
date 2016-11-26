#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	map<int, bool> nums_jogados;
	int r = 0;
	for (int i = 0; i < 6; ++i)
	{
		int x;
		cin >> x;
		nums_jogados[x] = true;
	}

	for (int i = 0; i < 6; ++i)
	{
		int x;
		cin >> x;
		if(nums_jogados[x] == true){
			r++;
		}
	}

	if(r < 3){
		cout << "azar" << endl;
	}else if(r == 3){
		cout << "terno" << endl;
	}else if(r == 4){
		cout << "quadra" << endl;
	}else if(r == 5){
		cout << "quina" << endl;
	}else if(r == 6){
		cout << "sena" << endl;
	}
	return 0;
}