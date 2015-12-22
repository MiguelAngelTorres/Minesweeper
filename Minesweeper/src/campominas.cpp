#ifndef CAMPOMINAS
#define CAMPOMINAS

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "campominas.h"		

	Campominas::Campominas(int fil, int col, int minas): table(fil,col){		
			Casilla aux ;
			aux.bomb=false;
			aux.mark=false;
			aux.open=false;
			srand(time(0));
			int bomba_x,bomba_y ;
			for(int j=0; j<fil; j++){
				for(int z=0; z<col; z++){
					table.Cambia(j,z,aux);
				}
			}
			int i = 0;
			while(i<minas){
				bomba_x= (table.Filas())*(rand()/(RAND_MAX+1.0));
				bomba_y= (table.Columnas())*(rand()/(RAND_MAX+1.0));
				
				aux= table.Consulta(bomba_x,bomba_y) ;
				if(aux.bomb==false){
					aux.bomb=true;
					table.Cambia(bomba_x,bomba_y,aux);
					i++;
				}
			}
		}
		
		bool Campominas::TestBoom()const{
		
			int filas = table.Filas();
			int columnas = table.Columnas();
			Casilla aux ;
			for(int i=0; i<filas; i++){
				for(int j=0; j<columnas; j++){
					aux=table.Consulta(i,j);
					if(aux.open && aux.bomb)
						return true ;
				}
			}
		return false ;	
		}
		
		bool Campominas::TodasAbiertas()const{
			int filas = table.Filas();
			int columnas = table.Columnas();
			Casilla aux ;
			for(int i=0; i<filas; i++){
				for(int j=0; j<columnas; j++){
					aux=table.Consulta(i,j);
					if(!aux.open && !aux.bomb)
						return false ;
				}
			}
		return true ;
		}
	
		void Campominas::Marcar(int filas, int columnas){
			Casilla aux= table.Consulta(filas,columnas);
			if(!aux.open){
					aux.mark=!aux.mark;
					table.Cambia(filas,columnas,aux);

			
			}
		}

		void Campominas::Abrir(int filas, int columnas){
			if(table.Filas()>filas && table.Columnas()>columnas && filas>=0 && columnas>=0){
				Casilla aux= table.Consulta(filas,columnas);
				if(!aux.open && !aux.mark){				
					aux.open=true ;
					table.Cambia(filas,columnas,aux);
					
					if(AroundBombs(filas, columnas)==0 && !aux.bomb){
						for(int i=filas-1; i<=filas+1; i++)
							for(int j=columnas-1; j<=columnas+1; j++)
								Abrir(i,j);
						
					
					}
				}
			}
		}
		
		int Campominas::AroundBombs(int filas, int columnas){
			int aroundbomb=0;
			Casilla aux;
			aux=table.Consulta(filas,columnas);
			if(aux.bomb)
				aroundbomb=-1;
			for(int i=filas-1; i<=filas+1; i++){
				for(int j=columnas-1; j<=columnas+1; j++){
					if(i<table.Filas() && j<table.Columnas() && j>=0 && i>=0){
						aux=table.Consulta(i,j);
						if(aux.bomb)
							aroundbomb++ ;
					}
				}
			}
		return aroundbomb;
		}
		
		void Campominas::PrettyPrint(std::ostream& os){
			int filas = table.Filas();
			int columnas = table.Columnas();
			Casilla aux ;
			os<< "\n"<< "\n"<< "\n"<< "\n"<< std::endl ;
			os<< "  " ;
			for(int z=0; z<columnas; z++)
				os<< "   " << z ;
				os<< std::endl ; 
			for(int i=0; i<filas; i++){
				os<< "   " ;
				for(int j=0; j<columnas; j++){
					os<< ".___" ;
				}
				os<< "." << std::endl ;
				os << i << "  " ;
				for(int j=0; j<columnas; j++){
					os<< "|" ;
					aux = table.Consulta(i,j);
					if(aux.open==false && aux.mark==false)
						os<< " * ";
					if(aux.open==false && aux.mark==true)
							os<< " ? ";
					if(aux.open==true && aux.bomb==false){
						int bombas = AroundBombs(i,j);
						if(bombas>0)
							os<< " " << bombas << " " ;
						else
							os<< "   " ;
					}
					if(aux.open==true && aux.bomb==true)
							os<< " x " ;
				}
				os<< "|" << std::endl ;
			}
			os<<  "   " ;
			for(int j=0; j<columnas; j++){
					os<< ".___" ;
				}
				os<< std::endl ;
		}

		void Campominas::Mapa(std::ostream& os){
			if(TodasAbiertas() || TestBoom()){
				int filas = table.Filas();
				int columnas = table.Columnas();
				Casilla aux ;
				os<< "\n"<< "\n"<< "\n"<< "\n"<< std::endl ;
				os<< "  " ;
				for(int z=0; z<columnas; z++)
					os<< "   " << z ;
					os<< std::endl ;
				for(int i=0; i<filas; i++){
					os<< "   " ;
					for(int j=0; j<columnas; j++){
						os<< ".___" ;
					}
					os<< "." << std::endl ;
					os << i << "  " ;
					for(int j=0; j<columnas; j++){
						os<< "|" ;
						aux = table.Consulta(i,j);
						if(aux.bomb==false){
							int bombas = AroundBombs(i,j);
							if(bombas>0)
								os<< " " << bombas << " " ;
							else
								os<< "   " ;
												
						}else{
							os<< " x " ;
						}
					}
					os<< "|" << std::endl ;
				}
				os<<  "   " ;
				for(int j=0; j<columnas; j++){
						os<< ".___" ;
				}
					os<< std::endl ;
			}
		}		


#endif
