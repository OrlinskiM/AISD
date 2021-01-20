#include <iostream>

using namespace std;

struct elem{
	int dane;
	elem* nast;
};

void wypelnij(elem* &lista){										//wypelnienie listy przykladowymi wartosciami od 1 do 5
	for(int i=5; i>0; i--){
			elem* nowy = new elem{i, lista};
			lista = nowy;
		}
}

void insert(int x, int i, elem* &a) {								//zadanie 1
	if (i==0){
	   	elem* nowy = new elem{x, a};
      	a = nowy;
	}else if (i>0){
   		elem* nowy = new elem{x, nullptr};
      	elem* poprz = a;
      	
      	for (int j = 0; j < i - 1; ++j){
            poprz=poprz->nast;
            if (poprz==NULL) cout << "Indeks poza zasiegiem listy" << endl;
		}
		
   	nowy->nast = poprz->nast;
    poprz->nast = nowy;
   }else cout<<"Bledne dane" << endl;
}    

void remove(int i, elem* &lista){		
	if(i==0){
		elem* stary = lista;
        lista = lista->nast;
        delete stary;
	}else if(i>0){
		elem* poprz = lista;
		
		for (int j = 0; j < i - 1; ++j){
            poprz=poprz->nast;
            if (poprz==NULL) cout << "Indeks poza zasiegiem listy" << endl;
		}
		
		elem* stary = poprz->nast;
		poprz->nast = stary->nast;
		delete stary;
 	}else cout<<"Bledne dane" << endl;
} 

int read(int i, elem* lista){
		for (int j = 0; j < i - 1; ++j){
            lista=lista->nast;
            if (lista==NULL) cout << "Indeks poza zasiegiem listy" << endl;
		}
	return lista->dane;
}

int size(elem* lista){												//zadanie 2
	int ilosc = 1;
	while(lista->nast){
		lista = lista->nast;
		ilosc++;
	}
	return ilosc;
}

void print(elem* lista){											//zadanie 3
	for (; lista; lista = lista->nast)
		cout << lista->dane << " ";
		cout << endl;		
}

void push(elem* &stos, int x){										//zadanie4
	elem* nowy = new elem{x, stos};
    stos = nowy; 
}

int pop(elem* &stos){
	if (stos!=NULL){
		elem* stary = stos;
    	int wynik = stos->dane;
        stos = stos->nast;
        delete stary;
        return wynik;
	}else cout << "Pusty stos" << endl; 
}

void printReversed(elem* lista,elem* &stos) {
	for (int i = 1; i <= size(lista); ++i) {
		push(stos,read(i, lista));
	}
	while (stos!=NULL) {
		cout << pop(stos) << " ";
	}
	cout << endl;
}

void printReversedNoStack(elem* lista){								//zadanie 5
	for (int i = size(lista) ; i != 0; i--) {
		cout << read(i, lista) << " ";
	}
	cout << endl;
}

void destroy(elem* &lista){											//zadanie 6
	if (lista==NULL) cout << "Lista jest juz pusta";		
    else{elem* temp = lista;
              while(temp!=NULL)
                 {elem* stary = temp;
                  temp = temp->nast;
                  delete stary;
        }
    } 
}

int main(){
	cout << "Zadanie 1" << endl;
	cout << "wypelniam liste przykladowymi wartosciami od 1 do 5, dodaje dwie dodatkowe" << endl;
	elem* lista = nullptr;
	wypelnij(lista);			
	insert(9, 0, lista);		//zadanie 1.1
	insert(7, 5, lista);
	print(lista);
	cout << "Usuwam drugi element" << endl;
	remove(1, lista);			//zadanie 1.2
	print(lista);
	cout << "Czytam element piaty" << endl;
	cout << read(5, lista);		//zadanie 1.3
	cout << endl << endl;
	cout << "Zadanie 2" << endl;
	cout << "Wyswietlam wielkosc listy" << endl;
	cout << size(lista) << endl << endl;
	cout << "Zadanie 3" << endl;
	cout << "Wyswietlam wszystkie elementy listy" << endl;
	print(lista);
	cout << endl;
	cout << "Zadanie 4" << endl;
	cout << "Wypisuje elementy w odwrotnej kolejnosci" << endl;
	elem* stos = nullptr;
	printReversed(lista, stos);
	cout << endl;
	cout << "Zadanie 5" << endl;
	cout << "Wypisuje elementy w odwrotnej kolejnosci bez uzycia stosu" << endl;
	printReversedNoStack(lista);
	cout << endl;
}
