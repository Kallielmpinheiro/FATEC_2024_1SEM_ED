#include <iostream>
#include <string>

using namespace std;

struct nts{
	float notas;
	float notas2;
	float media;
};

struct estudant{
	string nome;
	int idade;
	nts Ntsmd;
}; 

string recebe_name();
int recebe_idade();
float recebe_notas();
float rcb_notas2();
float calc_media(float nota1,float nota2);


int main(int argc, char** argv) {
	
	int y = 1;
	int *ptr = &y;
	estudant *cadast_estudant = new estudant [*ptr];
	
	for(int i = 0;i < *ptr;i++){
		cadast_estudant[i].nome = recebe_name();
		cadast_estudant[i].idade = recebe_idade();
		cadast_estudant[i].Ntsmd.notas = recebe_notas();
		cadast_estudant[i].Ntsmd.notas2 = rcb_notas2();
		cadast_estudant[i].Ntsmd.media= calc_media(cadast_estudant[i].Ntsmd.notas,cadast_estudant[i].Ntsmd.notas2);
	} 
	
	for(int i = 0;i < *ptr;i++){
		cout << "SEU NOME É = " << cadast_estudant[i].nome << endl;
		cout << "SUA IDADE É = " << cadast_estudant[i].idade << endl;
		cout << "SUA PRIMEIRA NOTA É = " << cadast_estudant[i].Ntsmd.notas << endl;
		cout << "SUA SEGUNDA NOTA É = " << cadast_estudant[i].Ntsmd.notas2 << endl;
		cout << "SUA MÉDIA FINAL É = " << cadast_estudant[i].Ntsmd.media << endl;
	}
	
	
	delete[] cadast_estudant;
	return 0;
}

string recebe_name(){
	string nm;
	cout << "Informe seu nome : " << endl;
	cin >> nm;
	return nm;
}

int recebe_idade(){
	int idd;
	cout << "Informe sua idade :" << endl;
	cin >> idd;
	return idd;
}

float recebe_notas(){
	float nt1;
	cout << "Informe a sua nota : " << endl;
	cin >> nt1;
	return nt1;
}

float calc_media(float nota1,float nota2){
	 return (nota1 + nota2) / 2;
}

float rcb_notas2(){
	float nt2;
	cout << "Informe a sua nota : " << endl;
	cin >> nt2;
	return nt2;
}




