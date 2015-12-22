#include <iostream>
#include "campominas.h"

 using namespace std;


int main(){
	int filas;
	int columnas;
	int num_minas;
	bool todasabiertas ;
	bool explosion ;

	do{
		cout << "Write the dimension of the game table(<rows> <columns>) : " ;
		cin >> filas ;
		cin >> columnas ;
	}while(filas>20 && columnas>20 && filas<0 && columnas<0);

	do{
		cout << "Write the number of mines: " ;
		cin >> num_minas ;
	}while(num_minas> filas*columnas);

	Campominas mijuego(filas,columnas,num_minas);
	

	char accion;
	do{
		mijuego.PrettyPrint();
		cout << "\n" << "Order action and place (<o=open||m=mark> <row> <column>): "; 
		cin >> accion ; 
		cin >> filas ;
		cin >> columnas ;
		if(filas>=0 && filas<mijuego.Filas() && columnas>=0 && columnas<mijuego.Columnas()){			
			if(accion=='o')
				mijuego.Abrir(filas,columnas);
			else if(accion=='m')
					mijuego.Marcar(filas, columnas);
		}
		todasabiertas= mijuego.TodasAbiertas() ;
		explosion= mijuego.TestBoom();
	}while(!todasabiertas && !explosion);
	

	mijuego.Mapa();

	if(explosion){
		cout << endl << endl << "SORRY, MAYBE NEXT TIME." << endl ;
	}else{
		cout << endl << endl << "¡¡¡CONGRATULATIONS, YOU HAVE COMPLETED THE GAME!!!" << endl ;	
	}
}
