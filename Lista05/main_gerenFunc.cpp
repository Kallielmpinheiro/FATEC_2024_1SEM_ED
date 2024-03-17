#include <iostream>
#include <string>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct func{
	string nome;
	string cargo;
	int idade;
	int numero;
	float salario;
};

string recebe_nome();
string recebe_cargo();
int recebe_idade();
int recebe_numero();
float recebe_salario();

int main(int argc, char** argv) {
	
	int esclha;
	cout << " BEM VINDO ! " << endl ;
	cout << " Quantos funcionarios deseja cadastrar ? " << endl;
	cin >> esclha;
	cout << endl;
	
	int *ptr = &esclha;
	
	func *cadastFunc = new func[*ptr];
	
	for(int i = 0;i < *ptr;i++){
		cout << "Funcionario - " << i+1 << " : " << endl;
		cadastFunc[i].nome = recebe_nome();
		cadastFunc[i].cargo = recebe_cargo();
		cadastFunc[i].idade = recebe_idade();
		cadastFunc[i].numero = recebe_numero();
		cadastFunc[i].salario = recebe_salario();
		cout << endl;
	}
	
	for(int i = 0;i < *ptr;i++){
		cout << "NOME = " << cadastFunc[i].nome <<endl;
		cout << "CARGO = " << cadastFunc[i].cargo <<endl;
		cout << "IDADE = " << cadastFunc[i].idade <<endl;
		cout << "NUMERO = " << cadastFunc[i].numero <<endl;
		cout << "SALARIO = " << cadastFunc[i].salario <<endl;
		cout << endl;
	}
	
	delete[] cadastFunc;
	return 0;
}

string recebe_nome(){
	string nm;
	cout << "Informe o nome do funcionario : ";
	cin.ignore();
	getline(cin,nm);
	
	if(nm.empty()){
		cout << "INSIRA A INFORMAÇÃO ! "<<endl;
		return recebe_nome();
	}
	return nm;
}
string recebe_cargo(){
	string crg;
	cout << "Informe o cargo do funcionario : ";
	cin.ignore();
	getline(cin,crg);
	
	if(crg.empty()){
		cout << "INSIRA A INFORMAÇÃO ! "<<endl;
		return recebe_cargo();
	}
	return crg;
}
int recebe_idade(){
	int idd;
	cout << "Informe a idade do funcionario : ";
	cin >> idd;
	return idd;
}
int recebe_numero(){
	int nid;
	cout << "Informe o numero de indentificação do funcionario : ";
	cin >> nid;
	return nid;
}
float recebe_salario(){
	float slr;
	cout << "Informe o salario do funcionario : ";
	cin >> slr;
	return slr;
}

