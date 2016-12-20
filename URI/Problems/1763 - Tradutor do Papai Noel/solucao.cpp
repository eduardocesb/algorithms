#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	map<string, string> traducao;

	traducao["brasil"] = "Feliz Natal!";
	traducao["alemanha"] = "Frohliche Weihnachten!";
	traducao["austria"] = "Frohe Weihnacht!";
	traducao["coreia"] = "Chuk Sung Tan!";
	traducao["espanha"] = "Feliz Navidad!";
	traducao["grecia"] = "Kala Christougena!";
	traducao["estados-unidos"] = "Merry Christmas!";
	traducao["inglaterra"] = "Merry Christmas!";
	traducao["australia"] = "Merry Christmas!";
	traducao["portugal"] = "Feliz Natal!";
	traducao["suecia"] = "God Jul!";
	traducao["turquia"] = "Mutlu Noeller";
	traducao["argentina"] = "Feliz Navidad!";
	traducao["chile"] = "Feliz Navidad!";
	traducao["mexico"] = "Feliz Navidad!";
	traducao["antardida"] = "Merry Christmas!";
	traducao["canada"] = "Merry Christmas!";
	traducao["irlanda"] = "Nollaig Shona Dhuit!";
	traducao["belgica"] = "Zalig Kerstfeest!";
	traducao["italia"] = "Buon Natale!";
	traducao["libia"] = "Buon Natale!";
	traducao["siria"] = "Milad Mubarak!";
	traducao["marrocos"] = "Milad Mubarak!";
	traducao["japao"] = "Merii Kurisumasu!";

	string palavra;
	while(cin >> palavra){
		if(traducao[palavra]!= ""){
			cout << traducao[palavra] << endl;
		}else{
			cout << "--- NOT FOUND ---" << endl;
		}
	}
	return 0;
}