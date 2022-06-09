#pragma once
template <class T>
class Matriz
{
private:
	T d,p;
	T** mat;
public:
	Matriz();
	Matriz(T);
	void segmentar( );
	void encerar();
	void ingresar();
	void imprimir();
	void setDimension(T);
	void setProceso(T);
	void setMatriz(T** matri);
	T getDimension();
	T getProceso();
	T** getMatriz();

	Matriz<T> procesar(Matriz<T> );
	//Matriz<T> procesarParalelo(Matriz<T>,T p );

};
