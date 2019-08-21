#include <bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL)

using namespace std;

string sum(string a, string b)
{
	string r = "";

	int tam1 = a.length(), tam2 = b.length();

	if(tam1 < tam2) return sum(b, a);

	while(tam2 < tam1)
	{
		tam2++;
		b = "0" + b;
	}

	int vai = 0;

	while(tam1 && tam2)
	{
		int x = a[--tam1] - '0';
		int y = b[--tam2] - '0';

		int z = x + y + vai;

		vai = 0;

		if(z > 9)
		{
			vai = 1;
			z %= 10;
		}

		r += '0' + z;
	}

	if(vai)
		r += "1";

	reverse(r.begin(), r.end());

	return r;
}

string menor(string a, string b)
{
	if((int)a.length() != (int)b.length()) return (int)a.length() < (int)b.length() ? a : b;
	int i = 0;
	while(a[i] == b[i])i++;
	return a[i] < b[i] ? a : b;
}

int main(int argc, char** argv)
{
	optimize;
	
	int N;
	string S;

	cin >> N >> S;

	int i = (N + 1) / 2;

	string resp = S;

	while(i)
	{
		if(S[i] == '0' && S[N - i] == '0')
		{
			i--;
			continue;
		}

		if(S[i] != '0' && S[N - i] != '0')
		{
			string a = sum(S.substr(0, i), S.substr(i, N - i));
			string b = sum(S.substr(0, N - i), S.substr(N - i, i));
			resp = menor(a, b);
			break;
		}
		else if(S[i] != '0')
		{
			resp = sum(S.substr(0, i), S.substr(i, N - i));
			break;
		}
		else if(S[N - i] != '0')
		{
			resp = sum(S.substr(0, N - i), S.substr(N - i, i));
			break;
		}

		i--;
	}

	cout << resp << endl;

	return 0;
}
