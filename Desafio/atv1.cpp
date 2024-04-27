#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char **argv)
{
    string texto;
    FILE *outFile;

    if ((outFile = fopen("arquivo2.txt", "a")) == NULL)
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    do
    {
        cout << "Insira as informacoes : ";
        getline(cin, texto);

        if (texto == "0")
        {
            cout << "Encerrando o programa." << endl;
            break;
        }

        fprintf(outFile, "%s\n", texto.c_str());

    } while (true);

    fclose(outFile); 

    if (texto == "0")
    {
        outFile = fopen("arquivo2.txt", "r");
        if (outFile == NULL)
        {
            cout << "Erro ao abrir o arquivo para leitura." << endl;
            return 1;
        }

        char line[100];
        printf("Conteúdo do arquivo:\n");
        while (fgets(line, sizeof(line), outFile) != NULL)
        {
            printf("%s", line);
        }

        fclose(outFile);
    }

    return 0;
}
