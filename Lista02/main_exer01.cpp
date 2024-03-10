#include <iostream>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

	struct carros{
	string placa;
	string ano;
	string marca; 
	
	};
	
	struct revisoes{	
	string data;
	string local;
	}; 
	
	string recebe_placa();
	string recebe_ano();
	string recebe_marca();
	string recebe_data();
	string recebe_local();

int main(int argc, char** argv) {


carros cad_car[1];
revisoes cad_rev[1];
	
for(int x= 0 ;x < 1;x++){
cad_car[x].placa = recebe_placa();
cad_car[x].ano = recebe_ano();
cad_car[x].marca = recebe_marca();
	
};

int rv;
cout << "Quantas revisoes foram feitas ? : ";
cin >> rv;

for(int x = 0;x < rv; x++){
cad_rev[x].data = recebe_data();
cad_rev[x].local = recebe_local();

};


for (int x = 0;x < 1;x++){
	cout << "Placa - " << cad_car[x].placa << endl;
	cout << "Ano - " << cad_car[x].ano << endl;
	cout << "Marca - " << cad_car[x].marca << endl;
}

for(int x = 0;x < rv;x++){
	cout << "Data - " << cad_rev[x].data << endl;
	cout << "Local -" << cad_rev[x].local << endl;
}

	return 0;
}


string recebe_placa(){
	string plc;
	cout << "Informe a placa do veiculo :  ";
	cin >> plc;
	return plc;
}
string recebe_ano(){
	string an;
	cout << "Informe o ano do veiculo : ";
	cin >> an;
	return an;
}
string recebe_marca(){
	string mrc;
	cout << "Informe a marca do veiculo : ";
	cin >> mrc;
	return mrc;
}
string recebe_data(){
	string rcbd;
	cout << "Informe a data que foi feita a revisão : ";
	cin >> rcbd;
	return rcbd;
}
string recebe_local(){
	string rcloc;
	cout << "Informe o local que foi realizado a revisão : ";
	cin >> rcloc;
	return rcloc;
}
