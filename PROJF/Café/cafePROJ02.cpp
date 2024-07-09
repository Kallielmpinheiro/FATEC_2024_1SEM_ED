#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Pagamentos
{
    int mes;
    int ano;
    float valor;
};

typedef struct Alunos
{
    int id;
    string nomeCompleto;
    int anoIngresso;
    int semestre;
    string curso;
    Pagamentos *Pag;
} Alns;

struct Node
{
    Alns Aluno;
    Node *next;
};

struct Lista
{
    int tamanho = 0;
    int ultimoID = 0;
    Node *inicio = NULL;
};

int gerarID();
void criarAluno(Lista *List, string nomeCompleto, string curso, int anoIngresso, int semestre);
void editarAlunos(Lista *List, int id, string newNome, string newCurso, int anoIngresso, int semestre);
void verParticipantes();
void cadastrarContribuicao(Lista *List, int id, int ano, int mes, float valor);
void verContribuicao();
void menu(Lista *List);
void liberarLista(Lista *List);
void carregarDds(Lista *List);
void carregarPag(Lista *List);

int main()
{
    Lista lista;
    carregarDds(&lista);
    carregarPag(&lista);
    menu(&lista);
    liberarLista(&lista);
    return 0;
}

int gerarID()
{
    int id = 0;

    ifstream contador("contador_id.txt"); // leitura
    if (contador.is_open())
    {
        contador >> id; // extrair dados do objeto
        contador.close();
    }
    else
    {
        cout << "Erro: o ID não foi encontrado." << endl;
    }

    ofstream contadorIN("contador_id.txt"); // gravacao
    if (contadorIN.is_open())
    {
        contadorIN << ++id;
        contadorIN.close();
    }
    else
    {
        cout << "Erro: Não foi possível escrever o ID no arquivo." << endl;
    }

    return id;
}

void criarAluno(Lista *List, string nomeCompleto, string curso, int anoIngresso, int semestre)
{
    if (curso != "SI" && curso != "si" && curso != "GE" && curso != "ge" && curso != "DSM" && curso != "dsm")
    {
        cout << "Insira um curso válido da unidade (SI, GE, ou DSM)." << endl;
        return;
    }

    int id = gerarID();
    Node *newNode = new Node;
    newNode->Aluno.id = id;
    newNode->Aluno.nomeCompleto = nomeCompleto;
    newNode->Aluno.curso = curso;
    newNode->Aluno.anoIngresso = anoIngresso;
    newNode->Aluno.semestre = semestre;
    newNode->Aluno.Pag = new Pagamentos{0, 0, 0};
    newNode->next = List->inicio;
    List->inicio = newNode;
    List->tamanho++;

    ofstream ppts("participantes.txt", ios::app);
    if (!ppts.is_open())
    {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }
    ppts << id << " " << nomeCompleto << " " << curso << " " << anoIngresso << " " << semestre << endl;
    // outFile << id << " | Nome: " << nomeCompleto << " | Curso: " << curso << " | Ano de Ingresso: " << anoIngresso << " | Semestre: " << semestre << endl;
    ppts.close();

    string courseFileName = "contribuentes.txt";
    ofstream outFile_course(courseFileName, ios::app);
    if (!outFile_course.is_open())
    {
        cout << "Erro ao abrir o arquivo de contribuintes do curso." << endl;
        return;
    }
    // outFile_course << id << " | Nome Completo: " << nomeCompleto << " | Ano de Ingresso: " << anoIngresso << endl;
    outFile_course << id << " " << nomeCompleto << " " << anoIngresso << endl;

    outFile_course.close();

    string courseFileName2 = "contribuentes_" + curso + ".txt";
    ofstream outFile_course2(courseFileName2, ios::app);
    if (!outFile_course2.is_open())
    {
        cout << "Erro ao abrir o arquivo de contribuintes do curso." << endl;
        return;
    }
    outFile_course2 << id << " " << nomeCompleto << " " << anoIngresso << endl;
    // outFile_course2 << id << " | Nome Completo: " << nomeCompleto << " | Ano de Ingresso: " << anoIngresso << endl;
    outFile_course2.close();
}

void editarAlunos(Lista *List, int id, string newNome, string newCurso, int anoIngresso, int semestre)
{
    if (newCurso != "SI" && newCurso != "si" && newCurso != "GE" && newCurso != "ge" && newCurso != "DSM" && newCurso != "dsm")
    {
        cout << "Insira um curso válido da unidade (SI, GE, ou DSM)." << endl;
        return;
    }
    Node *search = List->inicio;
    string cursoAntigo;
    float valorAntigo;

    while (search != NULL)
    {
        if (search->Aluno.id == id)
        {
            cursoAntigo = search->Aluno.curso;
            valorAntigo = search->Aluno.Pag->valor;
            search->Aluno.nomeCompleto = newNome;
            search->Aluno.curso = newCurso;
            search->Aluno.anoIngresso = anoIngresso;
            search->Aluno.semestre = semestre;

            ofstream ppt("participantes.txt");
            if (!ppt.is_open())
            {
                cout << "Erro ao abrir o arquivo." << endl;
                return;
            }

            Node *search = List->inicio;
            while (search != NULL)
            {
                ppt << search->Aluno.id << " " << search->Aluno.nomeCompleto << " " << search->Aluno.curso << " " << search->Aluno.anoIngresso << " " << search->Aluno.semestre << endl;
                search = search->next;
            }
            ppt.close();

            string cursoAntgFN = "contribuentes_" + cursoAntigo + ".txt";
            ifstream inFile_old(cursoAntgFN);
            ofstream tempFile("temp.txt"); // arquivo temporário para escrita

            string line;
            while (getline(inFile_old, line))
            {
                if (line.find(to_string(id)) == string::npos) // copiar as linhas que não contêm o ID do aluno para o arquivo temporário, filtrando assim o aluno que deve ser removido.
                {                                             // procurar a ocorrência do ID do aluno
                    tempFile << line << endl;
                }
            }

            inFile_old.close();
            tempFile.close();
            remove(cursoAntgFN.c_str());
            rename("temp.txt", cursoAntgFN.c_str()); // usado para fornecer o nome do arquivo

            string newCourseFileName = "contribuentes_" + newCurso + ".txt";
            ofstream outFile_new(newCourseFileName, ios::app);
            if (!outFile_new.is_open())
            {
                cout << "Erro ao abrir o arquivo de contribuintes do novo curso." << endl;
                return;
            }
            outFile_new << id << " " << newNome << " " << anoIngresso << " " << valorAntigo << endl;
            // outFile_new << id << " | Nome: " << newNome << " | Ano de Ingresso: " << anoIngresso << " | Valor Antigo: " << valorAntigo << endl;
            outFile_new.close();

            break;
        }
        search = search->next;
    }

    if (search == NULL)
    {
        cout << "O Aluno portador do ID: " << id << " não foi localizado na lista." << endl;
    }
}

void verParticipantes()
{
    ifstream dbase("participantes.txt");
    string dados;
    while (getline(dbase, dados))
    {
        cout << dados << endl;
    }
    dbase.close();
}

void cadastrarContribuicao(Lista *List, int id, int ano, int mes, float valor)
{
    Node *search = List->inicio;
    while (search != NULL)
    {
        if (search->Aluno.id == id)
        {
            Pagamentos *pag = new Pagamentos{mes, ano, valor};
            if (search->Aluno.Pag)
            {
                delete search->Aluno.Pag;
            }
            search->Aluno.Pag = pag;

            ofstream outFile("contribuentes.txt", ios::app);
            if (!outFile.is_open())
            {
                cout << "Erro ao abrir o arquivo." << endl;
                return;
            }
            // outFile << "ID: " << id << " | Ano: " << ano << " | Mês: " << mes << " | Valor: " << valor << endl;
            outFile << id << " " << ano << " " << mes << " " << valor << endl;
            outFile.close();

            string courseFileName = "contribuentes_" + search->Aluno.curso + ".txt";
            ofstream outFile_course(courseFileName, ios::app);
            if (!outFile_course.is_open())
            {
                cout << "Erro ao abrir o arquivo de contribuintes do curso." << endl;
                return;
            }
            outFile_course << id << " " << ano << " " << mes << " " << valor << endl;
            // outFile_course << "ID: " << id << " | Ano: " << ano << " | Mês: " << mes << " | Valor: " << valor << endl;
            outFile_course.close();

            return;
        }
        search = search->next;
    }
    cout << "O Aluno portador do id: " << id << " não foi localizado na lista." << endl;
}

void verContribuicao()
{
    cout << "Escolha o arquivo de contribuição que deseja visualizar:\n";
    cout << "1. Geral\n";
    cout << "2. Apenas DSM\n";
    cout << "3. Apenas GE\n";
    cout << "4. Apenas SI\n";

    int escolha;
    cin >> escolha;

    string nomeArquivo;
    switch (escolha)
    {
    case 1:
        nomeArquivo = "contribuentes.txt";
        break;
    case 2:
        nomeArquivo = "contribuentes_dsm.txt";
        break;
    case 3:
        nomeArquivo = "contribuentes_ge.txt";
        break;
    case 4:
        nomeArquivo = "contribuentes_si.txt";
        break;
    default:
        cout << "Opção inválida." << endl;
        return;
    }

    ifstream dbase(nomeArquivo);
    if (!dbase.is_open())
    {
        cerr << "Erro ao abrir o arquivo." << endl;
        return;
    }

    string dados;
    while (getline(dbase, dados))
    {
        cout << "Contribuição: " << dados << endl;
    }
    dbase.close();
}

void liberarLista(Lista *List)
{
    Node *search = List->inicio;
    while (search != NULL)
    {
        Node *next = search->next;
        if (search->Aluno.Pag)
        {
            delete search->Aluno.Pag;
        }
        delete search;
        search = next;
    }
    List->inicio = NULL;
}
void carregarDds(Lista *List)
{
    ifstream Infile("participantes.txt");
    if (!Infile.is_open())
    {
        cout << "Erro ao abrir o arquivo de participantes." << endl;
        return;
    }

    int id, anoIngresso, semestre;
    string nomeCompleto, curso;
    while (Infile >> id >> ws && getline(Infile, nomeCompleto, ' ') && getline(Infile, curso, ' ') && Infile >> anoIngresso >> semestre)
    {
        Node *newNode = new Node;
        newNode->Aluno.id = id;
        newNode->Aluno.nomeCompleto = nomeCompleto;
        newNode->Aluno.curso = curso;
        newNode->Aluno.anoIngresso = anoIngresso;
        newNode->Aluno.semestre = semestre;
        newNode->Aluno.Pag = new Pagamentos{0, 0, 0};
        newNode->next = List->inicio;
        List->inicio = newNode;
        List->tamanho++;
    }
    Infile.close();
}

void carregarPag(Lista *List)
{
    ifstream inFile;

    string filenames[] = {"contribuentes.txt", "contribuentes_DSM.txt", "contribuentes_SI.txt", "contribuentes_GE.txt"};

    for (string &filename : filenames)
    {
        inFile.open(filename);
        if (!inFile.is_open())
        {
            cout << "Erro ao abrir o arquivo " << filename << endl;
            continue;
        }

        int id, ano, mes;
        float valor;
        while (inFile >> id >> ano >> mes >> valor)
        {
            Node *search = List->inicio;
            while (search != NULL)
            {
                if (search->Aluno.id == id)
                {
                    Pagamentos *pag = new Pagamentos{mes, ano, valor};
                    if (search->Aluno.Pag)
                    {
                        delete search->Aluno.Pag;
                    }
                    search->Aluno.Pag = pag;
                    break;
                }
                search = search->next;
            }
        }
        inFile.close();
    }
}

void menu(Lista *List)
{
    int escolha;

    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Criar Aluno\n";
        cout << "2. Editar Aluno\n";
        cout << "3. Ver Participantes\n";
        cout << "4. Cadastrar Contribuição\n";
        cout << "5. Ver Contribuições\n";
        cout << "6. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> escolha;

        switch (escolha)
        {
        case 1:
        {
            int anoIngresso, semestre;
            string nomeCompleto, curso;
            cin.ignore();
            cout << "Digite o nome completo do aluno: ";
            getline(cin, nomeCompleto);
            cout << "Digite o curso do aluno: ";
            getline(cin, curso);
            cout << "Digite o ano de ingresso: ";
            cin >> anoIngresso;
            cout << "Digite o semestre atual: ";
            cin >> semestre;
            criarAluno(List, nomeCompleto, curso, anoIngresso, semestre);
            break;
        }

        case 2:
        {
            int id, anoIngresso, semestre;
            string newNome, newCurso;
            cout << "Digite o ID do aluno a ser editado: ";
            cin >> id;
            cin.ignore();
            cout << "Digite o novo nome do aluno: ";
            getline(cin, newNome);
            cout << "Digite o novo curso do aluno: ";
            getline(cin, newCurso);
            cout << "Digite o novo ano de ingresso: ";
            cin >> anoIngresso;
            cout << "Digite o novo semestre: ";
            cin >> semestre;
            editarAlunos(List, id, newNome, newCurso, anoIngresso, semestre);
            break;
        }
        case 3:
            verParticipantes();
            break;
        case 4:
        {
            int id, ano, mes;
            float valor;
            cout << "Digite o ID do aluno para cadastrar a contribuição: ";
            cin >> id;
            cout << "Digite o ano da contribuição: ";
            cin >> ano;
            if (ano > 2024)
            {
                cout << "Insira um ano valido" << endl;
                continue;
            }
            cout << "Digite o mês da contribuição: ";
            cin >> mes;
            if (mes > 12 || mes < 1)
            {
                cout << "Insira um mês valido" << endl;
                continue;
            }
            cout << "Digite o valor da contribuição: ";
            cin >> valor;
            if (valor <= 0)
            {
                cout << "Digite um valor valido" << endl;
                continue;
            }
            cadastrarContribuicao(List, id, ano, mes, valor);
            break;
        }
        case 5:
            verContribuicao();
            break;
        case 6:
            cout << "Saindo..." << endl;
            break;
        default:
            cout << "Opção inválida. Tente novamente." << endl;
            break;
        }
        cin.clear();
    } while (escolha != 6);
}