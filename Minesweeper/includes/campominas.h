#ifndef CAMPOMINAS_H_ 
#define CAMPOMINAS_H_

#include "tablero.h"
 
class Campominas{
	private:
		Tablero table;																			
	public:
		Campominas(int fil, int col, int minas);
		int Filas()const{
			return table.Filas() ;
		}
		int Columnas()const{
			return table.Columnas();
		}
		bool TestBoom()const;
		bool TodasAbiertas()const;
		void Marcar(int filas, int columnas);
		void Abrir(int filas, int columnas);
		int AroundBombs(int filas, int columnas);
		void PrettyPrint(std::ostream& os=std::cout);
		void Mapa(std::ostream& os=std::cout);
};

#endif
