/*
IFSP - CAMPUS CUBATÃO
TURMA: ADS 371 - LINGUAGEM DE PROGRAMAÇÃO
INTEGRANTES:
-> Stiven Richardy Silva Rodrigues
-> Guilherme Mendes de Sousa

EXERCICIO 1: Receber através de digitação uma mensagem: Apresentar esta mensagem, centralizada, na linha 5 da tela.
À partir daí, cada letra desta mensagem deverá "cair", da linha 5 até a linha 20, simulando uma "cascata". 
Ao final, a mensagem deverá estar toda apresentada na linha 20.
*/

#include <iostream>
#include <locale.h>
#include <windows.h>

using namespace std;

void coordenadas(short x, short y)
{
	COORD coord = {x, y};
	SetConsoleCursorPosition( 
	   GetStdHandle (STD_OUTPUT_HANDLE), coord 
	);
}

int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "");
	string mensagem;
	
	cout << "Informe a mensagem a ser exibida: ";
	cin >> mensagem;
	cout << endl;
	
	int central = (80-mensagem.size())/2;
	
	coordenadas(central, 5);
	cout << mensagem << endl;
	
	for(int j = 0; j < mensagem.size(); ++j) {
		for(int i = 5; i < 20; ++i) {
			coordenadas(central + j, i);
			cout << mensagem[j];
			Sleep(100);
			coordenadas((central + j), i);
            cout << ' ';
		}
		
        coordenadas(central + j, 20);
        cout << mensagem[j];
	}
	cout << endl;

	cout << "WOW! Efeito cascata, gostou? :-)" << endl;
	
	return 0;
}