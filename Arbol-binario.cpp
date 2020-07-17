#include <iostream>
#include <cstdlib>

using namespace std;

struct nodo{
	int dato;
	struct nodo *izq, *der;
};

typedef struct nodo *ARBOL;

void menu()
{
	cout << "Menu" << endl;
	cout << "1. Insertar nodo" << endl;
	cout << "2. Ver arbol" << endl;
	cout << "3. Preorden" << endl;
	cout << "4. Postorden" << endl;
	cout << "5. Inorden" << endl;
	cout << "6. Altura" << endl;
	cout << "7. Nivel" << endl;
	cout << "8. Hojas" << endl;
	cout << "9. Buscar elemento" << endl;
	cout << "10. Salir" << endl;
	cout << "Ingrese una opcion:\t>>  ";
}

ARBOL crearNodo(int x)
{
	ARBOL nuevoNodo = new(struct nodo);
	nuevoNodo->dato=x;
	nuevoNodo->izq=NULL;
	nuevoNodo->der=NULL;
	return nuevoNodo;
}
void insertar(ARBOL &arbol, int x)
{
	if(arbol==NULL)
		arbol = crearNodo(x);
	else if(x<arbol->dato)
		insertar(arbol->izq,x);
	else if(x>arbol->dato)
		insertar(arbol->der,x);
}

void preOrden(ARBOL &arbol)
{
	ARBOL temporal = new(struct nodo);
	temporal = arbol;
	if(temporal!=NULL)
	{
		cout << temporal->dato << " ";
		preOrden(temporal->izq);
		preOrden(temporal->der);
	}
}

void inOrden(ARBOL &arbol)
{
	ARBOL temporal = new(struct nodo);
	temporal = arbol;
	if(temporal!=NULL)
	{
		inOrden(temporal->izq);
		cout << temporal->dato << " ";
		inOrden(temporal->der);
	}
}

void posOrden(ARBOL &arbol)
{
	ARBOL temporal = new(struct nodo);
	temporal = arbol;
	if(temporal!=NULL)
	{
		posOrden(temporal->izq);
		posOrden(temporal->der);
		cout << temporal->dato << " ";	
	}
}

void verArbol(ARBOL &arbol, int n)
{
	ARBOL temporal = new(struct nodo);
	temporal = arbol;
	if (temporal == NULL)
	return;
	
	verArbol(temporal->der, n+1);
	for(int i=0; i<n; i++)
		cout << " ";
	cout << temporal->dato << endl;
	verArbol(temporal->izq, n+1);
}

int alturaAB(ARBOL &arbol)
{
    int AltIzq, AltDer;

    if(arbol==NULL)
        return -1;
    else
    {
        AltIzq = alturaAB(arbol->izq);
        AltDer = alturaAB(arbol->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}
int contarHojas(ARBOL &arbol)
{
    if (arbol==NULL)
    {
        return 0;
    }
    if ((arbol->der ==NULL)&&(arbol->izq ==NULL))
    {
        return 1;
    }else{
        return contarHojas(arbol->izq) + contarHojas(arbol->der);
    }
}
bool busquedaRec(ARBOL &arbol, int num)
{
    int r=0;   // 0 indica que lo encontre
    if(arbol==NULL)
    {
    	return r;
	}    
    if(num<arbol->dato)
    {
    	r = busquedaRec(arbol->izq, num);
	}else if(num> arbol->dato){
		r = busquedaRec(arbol->der, num);
	}else{
		r = 1;   // son iguales, lo encontre
	}    
    return r;
}
int main()
{
	ARBOL arbol = NULL;
	int opcion;
	int valor;
	int h,x;
	do
	{
		menu(); cin >> opcion;
		switch(opcion)
		{
			case 1:
				cout << "Ingrese valor a insertar: "; cin >> valor;
				insertar(arbol, valor);
				cout << "Nodo Ingresado" << endl;
				break;
			case 2:
				verArbol(arbol, 0);
				break;
			case 3:
				preOrden(arbol);
				cout << endl;
				break;
			case 4:
				posOrden(arbol);
				cout << endl;
				break;
			case 5:
				inOrden(arbol);
				cout << endl;
				break;
			case 6:
				h = alturaAB(arbol);
				cout << "La altura del arbol es: " << h+1 << endl;
				break;
			case 7:
				h = alturaAB(arbol);
				cout << "El arbol tiene: " << h << " nivel(es)" << endl;
				break;
			case 8:
				h= contarHojas(arbol);
				cout << "El arbol tiene: " << h << " hoja(s)" << endl;
				break;
			case 9:
				bool band;
                cout<<"Valor a buscar: "; cin>> x;
                band = busquedaRec(arbol,x);
                if(band==1)
                    cout << "Encontrado!" << endl;
                else
                    cout << "No encontrado!" << endl;
                break;
			case 10:
				cout << "Adios!" << endl;
				exit(1);
			default: 
				cout << "Ingrese una opcion valida!!" << endl;
				break;			
		}
		system("pause");
		system("cls");	
	}while(opcion!=10);	
}
