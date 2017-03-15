#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	unsigned long long n, m, x, r = 0, ant = 0;
	bool deu_certo = true;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> x;
		if(min(x, m - x) >= ant){
			ant = min(x, m - x);
			r+= min(x, m - x);
		}else if(max(x, m - x) >= ant){
			ant = max(x, m - x);
			r+= max(x, m - x);
		}else{
			deu_certo = false;
		}
	}

	if(deu_certo){
		cout << r << endl;
	}else{
		cout << -1 << endl;
	}
	return 0;
}