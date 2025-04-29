/*
IFSP - CAMPUS CUBATÃO
TURMA: ADS 371 - LINGUAGEM DE PROGRAMAÇÃO
INTEGRANTES:
-> Stiven Richardy Silva Rodrigues
-> Guilherme Mendes de Sousa

EXERCICIO 2: Receber através de digitação uma mensagem. 
Informar se esta mensagem é ou não um dado palíndromo (no caso de haver espaços no texto, desconsiderá-los para a verificação). 
Exemplos: OVO, ARARA, SOCORRAM ME SUBI NO ONIBUS EM MARROCOS.
*/

#include <iostream>
#include <locale.h>
#include <cstdlib>
#include <string.h>

using namespace std;

int main(int argc, char** argv) 
{
	string palavra;
	cout << "Informe a frase ou palavra: ";
	//obs: só funcionou com getline
	getline(cin, palavra);
	string palavrafinal = "";
	string palavrainvertida = "";
	
	for (int ii = 0; ii < palavra.length(); ii++){
		if (palavra[ii] != ' '){
			palavrafinal += toupper(palavra[ii]);
		}
	}
	for (int ii = palavrafinal.length() - 1; ii >= 0; ii--)
	{
		palavrainvertida += palavrafinal[ii];
	}

	
	if (palavrafinal == palavrainvertida){
		cout << "A frase ou palavra informada eh palindromo" << endl;
	}
	else cout << "A frase ou palavra informada nao eh palindromo" << endl;
	return 0;
}