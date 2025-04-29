/*
IFSP - CAMPUS CUBATÃO
ADS 371 - 28/01/2025
NOMES:
- STIVEN RICHARDY SILVA RODRIGUES
- GUILHERME MENDES DE SOUSA
*/
#include <iostream>
#include <locale.h>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <regex>
#include <string.h>

using namespace std;

#define TAM 3

struct nascProps {
	int dia;
	int mes;
	int ano;
};

class Data {
	private:
		int dia;
		int mes;
		int ano;
		
	public:	
		Data(int dia, int mes, int ano) {
			this->dia = dia;
			this->mes = mes;
			this->ano = ano;
		}
		
		Data() {
			this->dia = 0;
			this->mes = 0;
			this->ano = 0;
		}
		
		void setDia(int dia) {
			this->dia = dia;
		}
		
		void setMes(int mes) {
			this->mes = mes;
		}
		
		void setAno(int ano) {
			this->ano = ano;
		}
		
		int getDia() {
			return this->dia;
		}
		
		int getMes() {
			return this->mes;
		}
		
		int getAno() {
			return this->ano;
		}
		
		string getData() { 
			string sdia = to_string(this->dia);
			string smes = to_string(this->mes);
			string sano = to_string(this->ano);
			
			return sdia.insert(0, 2-sdia.size(), '0') + "/" + 
		           smes.insert(0, 2-smes.size(), '0') + "/" +
		           sano.insert(0, 4-sano.size(), '0');
        }
        
		Data* dia_seguinte() {
			Data *ds = new Data(this->dia, this->mes, this->ano);
			int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
			
			if (ds->ano%4 == 0)
			{
				diasNoMes[1]++;
			}
			
			ds->dia++;
			if(ds->dia > diasNoMes[ds->mes-1])
			{
				ds->dia = 1;
				ds->mes++;
				if (ds->mes > 12)
				{
					ds->mes = 1;
					ds->ano++;
				}
			}
			return ds;
		}
		
		bool valida(tm* dataAtual) {
			int diasNoMes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		
			if (this->mes < 1 || this->mes > 12 || this->dia < 1 || this->ano < 1) {
				return false;
			}
		
			if ((this->ano % 4 == 0 && this->ano % 100 != 0) || (this->ano % 400 == 0)) {
				diasNoMes[1] = 29;
			}
		
			if (this->dia > diasNoMes[this->mes - 1]) {
				return false;
			}
		
			int anoAtual = dataAtual->tm_year + 1900;
			int mesAtual = dataAtual->tm_mon + 1;
			int diaAtual = dataAtual->tm_mday;
		
			if (this->ano > anoAtual) return false;
			if (this->ano == anoAtual && this->mes > mesAtual) return false;
			if (this->ano == anoAtual && this->mes == mesAtual && this->dia > diaAtual) return false;
		
			return true;
		}
};

class Contato {
	private:
		string email;
		string nome;
		string telefone;
		Data* dtnasc;

	public:
		Contato(string email, string nome, string telefone, Data* nasc) {
			this->email = email;
			this->nome = nome;
			this->telefone = telefone;
			this->dtnasc = nasc;
		}
		
		Contato() {
			this->email = "";
			this->nome = "";
			this->telefone = "";
			this->dtnasc = new Data(12,12,12);
		}
		
		string getEmail() {
			return this->email;
		}
		
		void setEmail(string email) {
			this->email = email;
		}
		
		string getNome() {
			return this->nome;
		}
		
		void setNome(string nome) {
			this->nome = nome;
		}
		
		string getTelefone() {
			return this->telefone;
		}
		
		void setTelefone(string telefone) {
			this->telefone = telefone;
		}
		
		string getDtNasc() {	
			return this->dtnasc->getData();
		}
		
		void setDtNasc(Data* dtnasc) {
			this->dtnasc = dtnasc;
		}
		
		int Idade() {
    		time_t t = time(0);
    		tm* agora = localtime(&t);

    		int diaAtual = agora->tm_mday;
    		int mesAtual = agora->tm_mon + 1;
    		int anoAtual = agora->tm_year + 1900;

    		int idade = anoAtual - this->dtnasc->getAno();

    		if (mesAtual < this->dtnasc->getMes() || 
       	   	   (mesAtual == this->dtnasc->getMes() && diaAtual < this->dtnasc->getDia())) {
        		idade--;
    		}

    		return idade;
		}
		
		void mostraContato() {	
			cout << "--------------------------------------------" << endl <<
            "| Nome: " << this->getNome() << endl <<
			"| Email: " << this->getEmail() << endl <<
			"| Telefone " << this->getTelefone() << endl <<
			"| Idade: " << this->Idade() << " anos." << endl <<
			"--------------------------------------------" << endl;
		}
};

string nomeBib(string nome) {
    int tamanho = nome.size();
    int sobrenomePos = nome.rfind(' ');

    if (sobrenomePos == string::npos) {
		return nome;
	}

    string sobrenomeTxt = nome.substr(sobrenomePos + 1);
    string restoNome = nome.substr(0, sobrenomePos);

    string partsNome[10];
    int qntPartes = 0;

    size_t inicio = 0;
    while (true) {
        size_t espaco = restoNome.find(' ', inicio);
        if (espaco == string::npos) {
            partsNome[qntPartes++] = restoNome.substr(inicio);
            break;
        } else {
            partsNome[qntPartes++] = restoNome.substr(inicio, espaco - inicio);
            inicio = espaco + 1;
        }
    }

    string sobrenomeFinal = "";
    for (char c : sobrenomeTxt) {
        sobrenomeFinal += toupper(c);
    }

    string nomeReferencia = sobrenomeFinal + ", " + partsNome[0] + " ";

    for (int i = 1; i < qntPartes; ++i) {
        nomeReferencia += toupper(partsNome[i][0]);
        nomeReferencia += ". ";
    }

    return nomeReferencia;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "");
	
	int totalIdade = 0;
	double media;
	Contato** listaContatos = new Contato*[TAM];
	
	for (int ii = 0; ii < TAM; ++ii) {
		string email;
		string nome;
		string telefone;
		nascProps data;
		Data* nasc;
		bool valid;
		
		cout << "============================================" << endl
	 	 	 <<	"            CADASTRO DE CONTATOS" << endl
       	 	 << "============================================" << endl;
		
		do {
			valid = true;
			cout << "| Informe o " << (ii+1) << "º nome: ";
			getline(cin, nome);
			
			if (nome.find(' ') == string::npos) {
				cout << "| Nome inválido. Tente novamente." << endl;
				valid = false;
			}
		} while (!valid);
		
		do {
			valid = true;
			cout << "| Informe o " << (ii+1) << "º e-mail: ";
			getline(cin, email);
			
			if (email.find('@') == string::npos) {
				cout << "| E-mail inválido. Tente novamente." << endl;
				valid = false;
			}
		} while (!valid);
		
		do {
			valid = true;
			cout << "| Informe o " << (ii+1) << "º Telefone (Formato: [(XX)XXXXX-XXXX)]: ";
			getline(cin, telefone);
			regex padrao_tel("^\\(\\d{2}\\)\\d{5}-\\d{4}$");

			if (!regex_match(telefone, padrao_tel)) {
				cout << "| Telefone inválido. Tente novamente." << endl;
				valid = false;
			}
		} while (!valid);
		
		do {
			valid = true;
			
			time_t t = time(0);
    		tm* agora = localtime(&t);
			
			cout << "Informe a " << (ii+1) << "º data de nascimento:" << endl;
			cout << "- Informe o dia: ";
			cin >> data.dia;
			cout << "- Informe o mês: ";
			cin >> data.mes;
			cout << "- Informe o ano: ";
			cin >> data.ano;
		
			nasc = new Data(data.dia, data.mes, data.ano);
			
			if (!nasc->valida(agora)) {
				cout << "| Data inválida. Tente novamente." << endl;
				valid = false;
				delete nasc;
			}
		} while (!valid);
				
		cout << "| " << (ii+1) <<"º Contato cadastrado com sucesso." << endl 
 	 	 	 << "| Pressione qualquer tecla para continuar..." << endl 
   	    	 << "--------------------------------------------" << endl;
    	_getch();
		system("cls");
		
		nasc = new Data(data.dia, data.mes, data.ano);
		listaContatos[ii] = new Contato(email, nome, telefone, nasc);
		totalIdade += listaContatos[ii]->Idade(); 
	}

	cout << "============================================" << endl
	 	 <<	"            RELAÇÃO DE CONTATOS" << endl
       	 << "============================================" << endl;
		
	for (int ii = 0; ii<TAM; ii++) {
		cout << "---------------------------------------" << endl << "Contato " << (ii+1) << endl;
		listaContatos[ii]->mostraContato();
	}
	
	cout << "| Pressione qualquer tecla para continuar..." << endl 
          << "--------------------------------------------" << endl;
 	_getch();
	system("cls");
	
	cout << "============================================" << endl
	 	 <<	"                  ROTINAS" << endl
       	 << "============================================" << endl;
	
	media = totalIdade / TAM;
	cout << "| A média de idades é: " << media << endl 
		 << "--------------------------------------------" << endl
		 << "| Contatos mais velhos que a média: " << endl;
	for (int ii = 0; ii<TAM; ii++) {
		if (listaContatos[ii]->Idade() > media) {
			cout << "| - Nome: " << nomeBib(listaContatos[ii]->getNome()) << endl;
		}
	}
	
	int maioresDeIdade = 0;
	for ( int ii = 0; ii < TAM; ii++) {
		if (listaContatos[ii]->Idade() >= 18) {
			maioresDeIdade++;
		}
	}
	cout << "--------------------------------------------" << endl 
		 << "| Quantidade de contatos maiores de idade: " << maioresDeIdade << endl;
	
	int maiorIdade = 0;
	for (int ii = 0; ii < TAM; ++ii) {
		if (listaContatos[ii]->Idade() > maiorIdade) {
			maiorIdade = listaContatos[ii]->Idade();
		}
	}
	cout << "--------------------------------------------" << endl 
		 <<"| Contato(s) mais velho(s): " << endl;
	for(int ii = 0; ii < TAM; ++ii) {
		if (maiorIdade == listaContatos[ii]->Idade()) {
			cout << "| - Nome: " << nomeBib(listaContatos[ii]->getNome()) << endl
				 << "| - E-mail: " << listaContatos[ii]->getEmail() << endl
				 << "| - Telefone: " << listaContatos[ii]->getTelefone() << endl
				 << "--------------------------------------------" << endl;
		}
	}
	
	for (int ii = 0; ii < TAM; ++ii) {
        delete listaContatos[ii];
    }
	
	return 0;
}