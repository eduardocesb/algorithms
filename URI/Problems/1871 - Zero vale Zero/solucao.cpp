#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long long N, M;
	cin >> N >> M;
	while(N != 0 || M != 0){
		unsigned long long res = N + M;
		stringstream str;
		str << res;
		string r = str.str();
		int tam = r.size();
		for (int i = 0; i < tam; ++i)
		{
			if(r[i] != '0'){
				cout << r[i];
			}
		}
		cout << endl;
		cin >> N >> M;
	}
	return 0;
}