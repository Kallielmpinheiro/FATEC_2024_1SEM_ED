#include <iostream>
#include <string>

using namespace std;

struct revisoes {  
    string data;
    string local;
};

struct carros {
    string placa;
    string ano;
    string marca; 
    revisoes *rev; 
    int num_revisoes; 
};

string recebe_placa();
string recebe_ano();
string recebe_marca();
string recebe_data();
string recebe_local();

int main(int argc, char** argv) {
    int y;
    cout << "---- DESEJA CADASTRAR QUANTOS VEICULOS --- ";
    cin >> y;

    carros *cad_car = new carros[y];

    for(int x = 0; x < y; x++) {
        cad_car[x].placa = recebe_placa();
        cad_car[x].ano = recebe_ano();
        cad_car[x].marca = recebe_marca();

        cout << "Quantas revisoes foram feitas para o carro " << x+1 << "? : ";
        cin >> cad_car[x].num_revisoes;

        cad_car[x].rev = new revisoes[cad_car[x].num_revisoes];

        for(int i = 0; i < cad_car[x].num_revisoes; i++) {
            cad_car[x].rev[i].data = recebe_data();
            cad_car[x].rev[i].local = recebe_local();
        }
    }

    for (int x = 0; x < y; x++) {
        cout << "Placa - " << cad_car[x].placa << endl;
        cout << "Ano - " << cad_car[x].ano << endl;
        cout << "Marca - " << cad_car[x].marca << endl;

        cout << "Revisoes para o carro " << x+1 << ":" << endl;
        for(int i = 0; i < cad_car[x].num_revisoes; i++) {
            cout << "  Data - " << cad_car[x].rev[i].data << endl;
            cout << "  Local - " << cad_car[x].rev[i].local << endl;
        }

        delete[] cad_car[x].rev; 
    }

    delete[] cad_car; 
    return 0;
}


string recebe_placa() {
    string plc;
    cout << "Informe a placa do veiculo :  ";
    cin >> plc;
    return plc;
}

string recebe_ano() {
    string an;
    cout << "Informe o ano do veiculo : ";
    cin >> an;
    return an;
}

string recebe_marca() {
    string mrc;
    cout << "Informe a marca do veiculo : ";
    cin >> mrc;
    return mrc;
}

string recebe_data() {
    string rcbd;
    cout << "Informe a data que foi feita a revisao : ";
    cin >> rcbd;
    return rcbd;
}

string recebe_local() {
    string rcloc;
    cout << "Informe o local que foi realizado a revisao : ";
    cin >> rcloc;
    return rcloc;
}

