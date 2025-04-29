/*
IFSP - CAMPUS CUBATÃO
TURMA: ADS 371 - LINGUAGEM DE PROGRAMAÇÃO
INTEGRANTES:
-> Stiven Richardy Silva Rodrigues
-> Guilherme Mendes de Sousa

EXERCICIO 4: À partir de uma lista de nomes disponível em um arquivo TXT, transforma-los em nomes no formato citação bibliográfica. 
Exemplo: José Antonio Santos Silva => SILVA, José A. S.
*/

#include <iostream>
#include <fstream>
#include <locale.h>

using namespace std;

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "");
	
	ifstream arquivo("nomes.txt");
	string nome;
	
	if (arquivo.is_open())
	{
		while (!arquivo.eof())
		{
			getline(arquivo, nome);
			
			int tamanho = nome.size();
			int sobrenome = nome.rfind(' ');
			string sobrenomeTxt = nome.substr(sobrenome, tamanho) + ", ";
			string restoNome = nome.substr(0, sobrenome);
			string *partsNome;
			partsNome = new string[5];
			int indiceEspaco = restoNome.find(' ');
            int qntEspaco = 0;
            partsNome[qntEspaco] = restoNome.substr(0, indiceEspaco);
            qntEspaco++;
            
			for (int ii = indiceEspaco+1; ii < restoNome.length(); ii++) {
				if (restoNome[ii] == ' '){
					partsNome[qntEspaco] = restoNome.substr(indiceEspaco + 1, (ii - (indiceEspaco + 1)));
					indiceEspaco = ii;
					qntEspaco++;
				}
			}
			partsNome[qntEspaco] = restoNome.substr(indiceEspaco+1, restoNome.length() - indiceEspaco);
			qntEspaco++;
			string sobrenomeFinal ="";
			for (int ii = 0; ii < sobrenomeTxt.length(); ii++){
				sobrenomeFinal += toupper(sobrenomeTxt[ii]);
			}
			string nomeReferencia = sobrenomeFinal + partsNome[0] + " ";
			for (int ii = 1; ii < qntEspaco; ii++){
				string aux = partsNome[ii];
				partsNome[ii] = aux[0];
				partsNome[ii] += ". ";
				nomeReferencia += partsNome[ii];
			}
			nome.erase();
			
   		    cout << nome.insert(0, nomeReferencia) << endl;
		}
		
		arquivo.close();
	}	
	else
	{
		cout << "O arquivo nomes.txt não existe na pasta atual.";
	}
	return 0;
}
