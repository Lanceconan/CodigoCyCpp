/*
DATOS DEL PROGRAMA

NOMBRE          : MetodoMontecarlo.cpp correspondiente al taller 1 Simulacion de sistemas
FECHA ENTREGA   : Miercoles 30 de Abril 2014
UTEM

Programa probado y testeado en un notebook HP con Windows 8 | 64 bit | 4GB de RAM
*/

/*Librerias usadas*/
#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

/*Funcion de simulacion*/
long double SimulacionPi(long long n)
{
	float X, Y, pitagoras, pi;
	long long contador = 0;
	for(long long i=0; i<n; i++)
	{
		X = (rand()%100)/100.0;
		Y = (rand()%100)/100.0;
		pitagoras = sqrt(X*X + Y*Y);
		if(pitagoras <= 1) contador++;
	}
	return contador*4.0/n;
}

/*Programa Principal*/
int main() {
	int simulaciones;
     long long numero;

	cout << "Para no realizar experimentos teclee 0" << endl;
	cout << "ingrese el numero de experimentos" << endl;
	cin>> simulaciones;

	if(simulaciones==0){return 0;}

	for (int i=0; i< simulaciones; i++)
	{
	 cout<<"Ingrese numero de simulaciones: ";
	 cin >> numero;
	 if(numero <=0) cout << "\nEl numero debe ser mayor a 0 simulaciones\n" << endl;

	 else cout<<"pi es = " << SimulacionPi(numero)<<endl<< endl;
	}
	system ("pause");
	return 0;
	}
