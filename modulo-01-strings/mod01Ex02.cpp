/*
IFSP - CAMPUS CUBAT�O
TURMA: ADS 371 - LINGUAGEM DE PROGRAMA��O
INTEGRANTES:
-> Stiven Richardy Silva Rodrigues
-> Guilherme Mendes de Sousa

EXERCICIO 2: Receber atrav�s de digita��o uma mensagem. 
Informar se esta mensagem � ou n�o um dado pal�ndromo (no caso de haver espa�os no texto, desconsider�-los para a verifica��o). 
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
	//obs: s� funcionou com getline
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