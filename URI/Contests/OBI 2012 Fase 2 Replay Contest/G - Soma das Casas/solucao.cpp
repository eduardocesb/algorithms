#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	map<int, bool> existe;
	for (int i = 0; i < N; ++i)
	{
		int x;
		cin >> x;
		existe[x] = true;
	}
	int k;
	cin >> k;
	map<int, bool>::iterator it;
	for(it = existe.begin(); it!= existe.end(); it++){
		int n1 = it->first;
		int diferenca = k - n1;
		if(existe[diferenca] == true){
			cout << n1 << " " << diferenca << endl;
			break;
		}
	}
	return 0;
}