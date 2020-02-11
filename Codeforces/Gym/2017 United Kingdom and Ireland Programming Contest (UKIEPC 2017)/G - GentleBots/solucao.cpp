#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define INF 2000000000
#define pii pair<int, int>
#define ll long long
#define MAXN 100100
#define MAXP 1000000
#define MAXL 23

using namespace std;

struct Ponto
{
	int X, Y, Z, D;

	Ponto(int x = 0, int y = 0, int z = 0, int d = 0) : X(x), Y(y), Z(z), D(d) {}

	bool operator == (const Ponto &a) const { return X == a.X && Y == a.Y && Z == a.Z;}
	bool operator != (const Ponto &a) const { return X != a.X || Y != a.Y || Z != a.Z;}
	Ponto operator + (const Ponto &a) const {return Ponto(X + a.X, Y + a.Y, Z + a.Z, D);}

	void print()
	{
		cout << X << " " << Y << " " << Z << " " << D << endl;
	}
};

vector<pair<Ponto, Ponto> > ans;
Ponto I1, I2, F1, F2;

bool bateu(Ponto P1, Ponto P2)
{
	return P1 == P2;
}

bool acabou()
{
	return I1 == F1 && I2 == F2;
}

void anda(Ponto &I)
{
	if(I.D == 1) I = I + Ponto(-1, 0, 0);
	if(I.D == 2) I = I + Ponto(0, 1, 0);
	if(I.D == 3) I = I + Ponto(1, 0, 0);
	if(I.D == 4) I = I + Ponto(0, -1, 0);
	if(I.D == 5) I = I + Ponto(0, 0, 1);
	if(I.D == 6) I = I + Ponto(0, 0, -1);
}

bool v(Ponto I, Ponto F, int x)
{
	if(x == 0) return I == F;
	if(x == 1) return I.X > F.X;
	if(x == 2) return I.Y < F.Y;
	if(x == 3) return I.X < F.X;
	if(x == 4) return I.Y > F.Y;
	if(x == 5) return I.Z < F.Z;
	if(x == 6) return I.Z > F.Z;
}

void muda_direcao(Ponto &I, Ponto &F)
{
	int nums[] = {0, 1, 2, 3, 4, 5, 6};

	random_shuffle(nums, nums + 7);

	for(int i = 0; i < 7; i++)
		if(v(I, F, nums[i]))
		{
			I.D = nums[i];
			return;
		}
}

void desvia(Ponto &I1, Ponto &F1, Ponto &I2, Ponto &F2, bool inv = false)
{
	if(I2.D)
	{
		if(I1.D == 1 && (I2.D != 3)) return;
		if(I1.D == 2 && (I2.D != 4)) return;
		if(I1.D == 3 && (I2.D != 1)) return;
		if(I1.D == 4 && (I2.D != 2)) return;
		if(I1.D == 5 && (I2.D != 6)) return;
		if(I1.D == 6 && (I2.D != 5)) return;
	}

	//PROBLEMA NO X
	if(I1.D == 1 || I1.D == 3)
	{
		int num = rand() % 19;

		if(num & 1)
		{
			if(I1.Y >= MAXP - 5)
				I1.D = 4;
			else I1.D = 2;
		}
		else
		{
			if(I1.Z >= MAXP - 5)
				I1.D = 6;
			else I1.D = 5;
		}
	}

	//PROBLEMA NO Y
	else if(I1.D == 2 || I1.D == 4)
	{
		int num = rand() % 13;

		if(num & 1)
		{		
			if(I1.Z >= MAXP - 5)
				I1.D = 6;
			else I1.D = 5;
		}
		else
		{
			if(I1.X >= MAXP - 5)
				I1.D = 1;
			else I1.D = 3;
		}
	}

	//PROBLEMA NO Z
	else if(I1.D == 5 || I1.D == 6)
	{
		int num = rand() % 7;

		if(num & 1)
		{	
			if(I1.X >= MAXP - 5)
				I1.D = 1;
			else I1.D = 3;
		}
		else
		{
			if(I1.Y >= MAXP - 5)
				I1.D = 4;
			else I1.D = 2;
		}
	}

	if(inv)
		ans.emplace_back(I2, I1);
	else
		ans.emplace_back(I1, I2);

	anda(I1);


	if(inv)
		ans.emplace_back(I2, I1);
	else
		ans.emplace_back(I1, I2);
}

void solve()
{
	Ponto aux;

	ans.emplace_back(I1, I2);

	while(!acabou())
	{
		muda_direcao(I1, F1);
		muda_direcao(I2, F2);

		aux = I1;
		anda(aux);
		if(bateu(aux, I2)) desvia(I1, F1, I2, F2, false);
		else I1 = aux;

		aux = I2;
		anda(aux);
		if(bateu(aux, I1)) desvia(I2, F2, I1, F1, true);
		else I2 = aux;

		ans.emplace_back(I1, I2);
	}

	pair<Ponto, Ponto> ult;

	int sum = 0;
	bool check = true;

	for(int i = 0; i < (int)ans.size(); i++)
	{
		auto r = ans[i];

		if(r == ult) continue;

		sum++;

		if(i)
		{
			check *= ((abs(r.first.X - ult.first.X) + abs(r.first.Y - ult.first.Y) + abs(r.first.Z - ult.first.Z)) < 2);
			check *= ((abs(r.second.X - ult.second.X) + abs(r.second.Y - ult.second.Y) + abs(r.second.Z - ult.second.Z)) < 2);
		}

		check *= abs(r.first.X) <= MAXP;
		check *= abs(r.first.Y) <= MAXP;
		check *= abs(r.first.Z) <= MAXP;
		check *= abs(r.second.X) <= MAXP;
		check *= abs(r.second.Y) <= MAXP;
		check *= abs(r.second.Z) <= MAXP;
		check *= r.first != r.second;

		ult = r;

		cout << "(" << r.first.X << " " << r.first.Y << " " << r.first.Z << ") (" << r.second.X << " " << r.second.Y << " " << r.second.Z << ")" << endl;
	}

	cout << (!check || sum > 7000 ? "DEU MERDA KCT\n" : "") ;
}

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	optimize;

	cin >> I1.X >> I1.Y >> I1.Z;
	cin >> F1.X >> F1.Y >> F1.Z;
	
	cin >> I2.X >> I2.Y >> I2.Z;
	cin >> F2.X >> F2.Y >> F2.Z;

	solve();

	return 0;
}