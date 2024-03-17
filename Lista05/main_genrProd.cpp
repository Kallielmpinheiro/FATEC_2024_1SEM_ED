#include <iostream>
#include <string>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;

struct product{
string nome;
float preco;
float qtdestq;
};

string recebe_nome();
float recebe_preco();
float recebe_qtdestq();

int main(int argc, char** argv) {

int eslha;

do{
	cout << " -- É POSSIVEL CADASTRAR ATE 10 PRODUTOS P/VEZ -- " << endl;
	cout << "QUANTOS PRODUTOS DESEJA CADASTRAR : ";
	cout << endl;
	cin >> eslha;	
	
	if(eslha>10 || eslha < 0){
		cout << "I N V A L I D O ! " << endl;
	}
}while(eslha>10 || eslha < 0);


int *ptr = &eslha;
product *products = new product[*ptr];	

for(int i = 0;i < *ptr;i++){
	products[i].nome = recebe_nome();
	products[i].preco = recebe_preco();
	products[i].qtdestq = recebe_qtdestq();
	cout << endl;
}

for(int i = 0;i < *ptr;i++){
	cout << "NOME DO PRODUTO = " << products[i].nome << endl;
	cout << "PRECO DO PRODUTO = " << products[i].preco << endl;
	cout << "QUANTIDADE DO PRODUTO DISPONIVEL EM ESTOQUE = " << products[i].qtdestq << endl;
	cout << endl;
}
	delete[] products;
	return 0;
}

string recebe_nome(){
string nm;
cout << "Informe o produto: ";
cin >> nm;
return nm;
}
float recebe_preco(){
float price;
cout << "Informe o preco referente ao produto : ";
cin >> price;
return price;
}
float recebe_qtdestq(){	
float estq;
cout << "Informe a quantidade de itens que a em estoque: ";
cin >> estq;
return estq;	
}
