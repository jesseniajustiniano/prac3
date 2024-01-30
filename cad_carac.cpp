#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

// Función para realizar la suma de una cadena de números
int sumaCadena(string cadena) {
	stringstream ss(cadena);
	int numero, suma = 0;
	char operador;
	
	while (ss >> numero) {
		suma += numero;
		ss >> operador; // Ignorar el operador
	}
	
	return suma;
}

// Función para imprimir el nombre completo con las iniciales en mayúsculas
void imprimirNombreCompleto(string nombreCompleto) {
	stringstream ss(nombreCompleto);
	string nombre, apellido1, apellido2;
	
	ss >> nombre >> apellido1 >> apellido2;
	
	cout << char(toupper(apellido1[0])) << apellido1.substr(1) << " "
		<< char(toupper(apellido2[0])) << apellido2.substr(1) << " "
		<< char(toupper(nombre[0])) << nombre.substr(1) << endl;
}

// Función para ofuscar una cadena según las reglas dadas
string ofuscarCadena(string cadena) {
	for (char& c : cadena) {
		switch (c) {
		case 'A': case 'a': c = '4'; break;
		case 'E': case 'e': c = '3'; break;
		case 'I': case 'i': c = '1'; break;
		case 'O': case 'o': c = '0'; break;
		case 'S': case 's': c = '5'; break;
		case 'T': case 't': c = '7'; break;
		}
	}
	return cadena;
}

int main() {
	char opcion;
	
	do {
		cout << "MENU PRINCIPAL" << endl;
		cout << "(1) - String suma de una cadena." << endl;
		cout << "(2) - String Nombre completo." << endl;
		cout << "(3) - String ofuscar." << endl;
		cout << "(s) - Salir" << endl;
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1': {
			string cadena;
			cout << "Ingrese una cadena de números para sumar: ";
			cin.ignore(); // Ignorar el salto de línea anterior
			getline(cin, cadena);
			cout << "Resultado: " << sumaCadena(cadena) << endl;
			break;
		}
		case '2': {
			string nombreCompleto;
			cout << "Ingrese un nombre completo: ";
			cin.ignore(); // Ignorar el salto de línea anterior
			getline(cin, nombreCompleto);
			cout << "Nombre completo: ";
			imprimirNombreCompleto(nombreCompleto);
			break;
		}
		case '3': {
			string cadena;
			cout << "Ingrese una cadena para ofuscar: ";
			cin.ignore(); // Ignorar el salto de línea anterior
			getline(cin, cadena);
			cout << "Resultado: " << ofuscarCadena(cadena) << endl;
			break;
		}
		case 's':
		case 'S':
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
		}
		
	} while (opcion != 's' && opcion != 'S');
	
	return 0;
}
