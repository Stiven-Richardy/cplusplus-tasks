/*
IFSP - CAMPUS CUBAT�O
TURMA: ADS 371 - LINGUAGEM DE PROGRAMA��O
INTEGRANTES:
-> Stiven Richardy Silva Rodrigues
-> Guilherme Mendes de Sousa

EXERCICIO 3: � partir de uma lista de nomes dispon�vel em um arquivo TXT, transforma-los em nomes no formato agenda telef�nica. 
Exemplo: Jos� Antonio Santos Silva => Silva, Jos� Antonio Santos
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
		cout << "O arquivo nomes.txt n�o existe na pasta atual.";
	}
	
	return 0;
}
