#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;

    cin >> N;

    string madeira;

    getline(cin, madeira);
    getline(cin, madeira);

    cout << fixed << setprecision(4);

    bool primeiro = true;

    while (N--) // Para cada caso de teste
    {
        map<string, int> frequencia;

        if(!primeiro)
            cout << endl;
        
        int qtd_total = 0;

        while (getline(cin, madeira) && (madeira != "")) // Ler as madeiras do caso de teste atual
        {
            qtd_total++;
            frequencia[madeira]++;
        }

        for (auto atual : frequencia) // Percorre todas as madeiras, em ordem lexicográfica
            cout << atual.first << " " << ((double)atual.second / qtd_total * 100.0) << endl;

        primeiro = false;
    }

    return 0;
}