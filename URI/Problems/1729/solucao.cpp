#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	double D;
	cin >> N >> D;
	int T;
	while(scanf("%d", &T) != EOF){
		bool deu_certo = true;
		int hr = 0, mr = 0, sr = 0;
		for (int i = 0; i < N; i++)
		{
			string c;
			cin >> c;
			double h, m, s;
			h = c[0] - '0';
			m = (10*(c[2] - '0')) + (c[3] - '0');
			s = (10*(c[5] - '0')) + (c[6] - '0');

			if(h < 0){
				deu_certo = false;
			}else{
				hr += h;
				mr += m;
				sr += s;
			}
		}




		double tempo;
		tempo = (hr*60)+ mr + (sr/60.0);
		if(T < 10){
			cout << "  " << T << ": ";
		}else if(T < 100){
			cout << " " << T << ": ";
		}else{
			cout << T <<": ";
		}
		if(deu_certo){
			int M;
			double S;
			M = tempo/D;
			S = tempo/D;
			S -= M;
			S *= 60;
			if((S - (int(S))) > 0.5){
				S = int(S)+1;
			}else{
				S = int(S);
			}

			if(S == 60){
				M++;
				cout << M <<":00 min/km" << endl;
			}else if(S < 10){
				cout << M << ":0" << S << " min/km" << endl;
			}else{
				cout << M << ":" << S << " min/km" << endl;
			}
		}else{
			cout << "-" << endl;
		}
	}
	return 0;
}