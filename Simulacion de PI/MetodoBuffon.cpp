/*
DATOS DEL PROGRAMA

NOMBRE          : MetodoBuffon.cpp correspondiente al taller 1 Simulacion de sistemas
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
long double simulacion(long long n)
{
    float x, y, z;
    float b=2;
	float contador = 0, corta_lin= 0;
	while(contador < n)
	{
		x= ((rand()%100)/100.0)*0.5;
		y= ((rand()%100)/100.0)* 3.1415;
		z=0.5* sin(y);
		if(x > z)
			contador ++;

		else
            corta_lin ++;

	}
	b=b+(corta_lin/n);
	return b;
}

/*Programa Principal*/
int main() {
	int simulaciones;
    long long numero;

    cout << "Para no realizar experimentos teclee 0" << endl;
	cout << "ingrese el numero de experimentos: ";

	cin>> simulaciones;

	if(simulaciones==0){
    system ("pause");
    return 0;
    }

    for (int i=0; i<= simulaciones; i++)
	{

       cout<<"Ingrese numero de simulaciones: ";
       cin >> numero;

       if(numero <=0) cout << "\nEl numero debe ser mayor a 0 simulaciones\n" << endl;
       else cout<<"pi es = " << simulacion(numero)<<endl<<endl;
    }

	system ("pause");
	return 0;
}

