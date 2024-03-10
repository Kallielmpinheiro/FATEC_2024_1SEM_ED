//Desenvolva uma aplicação para cadastrar cliente em loja.
//Crie uma estrutura para cadastro ( nome, endereço, cidade, estado)
//Crie uma estrutura para parcelas (data, local).
//É previsto 12 parcelas.

#include <iostream>
#include <string>

using namespace std;

struct estdlc{
	string data;
	string local;
	int quant_parc;
	float valor;
}; 

struct cadastro{
	string nome;
	string endereco;
	string cidade;
	string estado;
	estdlc seila;
};

string recebe_nome();
string recebe_endereco();
string recebe_cidade();
string recebe_estado();
string recebe_data();
string recebe_local();
float recebe_quant_parc();
float recebe_valor();


int main() {
	
	const int NumCAD = 1;
	
	cadastro vetor_cadastro[NumCAD];
	
	for(int x = 0; x < NumCAD;x++){
		vetor_cadastro[x].nome = recebe_nome();
		vetor_cadastro[x].endereco = recebe_endereco();
		vetor_cadastro[x].cidade = recebe_cidade();
		vetor_cadastro[x].estado = recebe_estado();
		vetor_cadastro[x].seila.data = recebe_data();
		vetor_cadastro[x].seila.local = recebe_local();
		vetor_cadastro[x].seila.quant_parc = recebe_quant_parc();
		vetor_cadastro[x].seila.valor = recebe_valor();
		
		}
	
	for(int x = 0;x < NumCAD;x++){
		cout << "Nome = " << vetor_cadastro[x].nome << endl;
		cout << "Endereço = " << vetor_cadastro[x].endereco << endl;
		cout <<	"Cidade = " << vetor_cadastro[x].cidade << endl;
		cout << "Estado = " << vetor_cadastro[x].estado << endl;
		cout <<	"Data = " << vetor_cadastro[x].seila.data << endl;
		cout <<	"Local = " << vetor_cadastro[x].seila.local << endl;
		cout << "Valor = " << vetor_cadastro[x].seila.valor <<endl;
		cout << "Quantidade de parcelas = " << vetor_cadastro[x].seila.quant_parc << endl;
		cout << "Valor da parcela = " << (vetor_cadastro[x].seila.valor / vetor_cadastro[x].seila.quant_parc) << endl;
    
	}
	return 0;
}

string recebe_nome() {
	string n;
	cout << "Informe seu nome - ";
	cin >> n;
	return n;
}
string recebe_endereco() {
	string end;
	cout << "Informe o endereço (BAIRRO, RUA, NUMERO) - ";
	cin >> end;
	return end;
}
string recebe_cidade(){
	string cid;
	cout << "Informe a cidade - ";
	cin >> cid;
	return cid;
}
string recebe_estado(){
	string est;
	cout << "Informe o estado - ";
	cin >> est;
	return est;
}
string recebe_local(){
	string lc;
	cout << "Informe o local - ";
	cin >> lc;
	return lc;
}
string recebe_data(){
	string dt;
	cout << "Informe a data - ";
	cin >> dt;
	return dt;
}
float recebe_valor(){
	float  vlr;
	cout  <<"VALOR DESEJADO DE CREDITO : ";
	cin >> vlr;
	return vlr;
}
float recebe_quant_parc(){
	int qtd;
	do{
		cout << "INFORME A QTD DE PARCELAS : ";
		cin >> qtd;
		
		if (qtd > 12){
			cout << "QUANTIDADE SUPERA AS DISPONIVEIS ! " << endl;
		}
	}while(qtd > 12);
	return qtd;}
