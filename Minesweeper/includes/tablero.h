#ifndef TABLERO_H_
#define TABLERO_H_

	struct Casilla{
		bool open;
		bool bomb;
		bool mark;	
	};


class Tablero{
	private:
		Casilla dato[20][20];
		int filas, columnas ;
	public:
	
		Tablero(int fil, int col){
			filas=fil;
			columnas=col;
		}

		int Filas()const
		{
			return filas;
		}

		int Columnas()const
		{
			return filas;
		}

		Casilla Consulta(int fil, int col)const
		{
			if(fil<filas && col<columnas)
				return dato[fil][col];
				
		}
		
		void Cambia(int fil, int col, Casilla nueva)
		{
			dato[fil][col].open = nueva.open ;
			dato[fil][col].bomb = nueva.bomb ;
			dato[fil][col].mark = nueva.mark ;
		}
};

#endif
