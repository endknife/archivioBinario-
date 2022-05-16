#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

const string filename = "dati.dat";
const string aCapo = " ";

struct Studente
{
	string name;
	string surname;
	int debts;
};

void trasformaInBin(string parola, int i, int bin[8])
{
	int numero = (int)parola[i];
	int numeroDiv;
	int resto;
	int counter = 0;
	while (numero > 0) 
	{
		numeroDiv = numero / 2;
		resto = numero % 2;
		//cout << numero << "   ";
		//cout << resto << endl;
		numero = numeroDiv;
		bin[7 - counter] = resto;
		counter++;
	}

}

void writeInFile() 
{
	int bin[8];
	for (int i = 0; i < 8; i++)
		bin[i] = 0;
	
	fstream filed;
	filed.open(filename.c_str(), ios::out);
	if (filed.is_open())
	{
		char scelta;
		do
		{
			Studente studenti;
			cout << "Nome studente: ";
			cin >> studenti.name;
			cout << "Cognome studente: ";
			cin >> studenti.surname;
			cout << "Debiti studente: ";
			cin >> studenti.debts;
			string debt = to_string(studenti.debts);

			for (int i = 0; i < size(studenti.name); i++)
			{
				trasformaInBin(studenti.name, i, bin);

				for (int j = 0; j < 8; j++)
				{
					filed << bin[j];
				}

			}
			filed << aCapo;

			for (int i = 0; i < size(studenti.surname); i++)
			{
				trasformaInBin(studenti.surname, i, bin);

				for (int j = 0; j < 8; j++)
				{
					filed << bin[j];
				}

			}
			filed << aCapo;

			for (int i = 0; i < size(debt); i++)
			{
				trasformaInBin(debt, i, bin);

				for (int j = 0; j < 8; j++)
				{
					filed << bin[j];
				}

			}
			filed << aCapo;
			filed << endl;
			cout << "Inserisci x per uscire: ";
			cin >> scelta;
		} while (scelta != 'x');
	}
}

void readFromFile() {

}

int main() 
{
	writeInFile();
	ifstream filed(filename.c_str());
	string line;
	if (filed.is_open()) {
		while (getline(filed, line)) {
			cout << line << endl;
			cout << "size: " << size(line) << endl;
			for (int i = 0; i < size(line); i++)
			{
				if (line[i] != ' ')
				{
					cout << i << endl;
				}
				else 
				{
					cout << endl;
				}
			}
			cout << "Size: " << size(line);
		}
		filed.close();
	}
}
