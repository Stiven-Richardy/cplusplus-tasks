/*
IFSP - CAMPUS CUBATÃO
TURMA: ADS 371 - LINGUAGEM DE PROGRAMAÇÃO
INTEGRANTES:
-> Stiven Richardy Silva Rodrigues
-> Guilherme Mendes de Sousa

EXERCICIO 3: À partir de uma lista de nomes disponível em um arquivo TXT, transforma-los em nomes no formato agenda telefônica. 
Exemplo: José Antonio Santos Silva => Silva, José Antonio Santos
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
			
			string capturar = nome.substr(sobrenome, tamanho) + ", ";
			nome.erase(sobrenome, tamanho);
			
   		    cout << nome.insert(0, capturar) << endl;
		}
		
		arquivo.close();
	}	
	else
	{
		cout << "O arquivo nomes.txt não existe na pasta atual.";
	}
	
	return 0;
}
