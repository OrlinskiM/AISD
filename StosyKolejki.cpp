#include <iostream>

using namespace std;

struct elem{
	int dane;
	elem* nast;
};

void push(elem* &stos, int x){				//zadanie1
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

int topEl(elem* &stos){
	if (stos!=NULL){
		int wynik = stos->dane;
    	return wynik; 
	}
     else cout << "Pusty stos" << endl;  }

bool isEmpty(elem* stos){
	if (stos==NULL) return true;
    else return false; 
}

void add(elem* &pocz, elem* &kon, int x){			//zadanie2
	if(kon!=NULL){
		elem* nowy = new elem;
       	nowy->dane = x;
       	nowy->nast = NULL;
       	kon->nast = nowy;
       	kon = nowy;}
    else {
      	elem* nowy = new elem;
       	nowy->dane = x;
      	nowy->nast = NULL;
      	kon = nowy;
      	pocz = nowy;}
   }
   
int next(elem* & pocz, elem* &kon){
		if(pocz!=NULL){
			elem* stary = pocz;
        	int wynik = stary->dane;
        	if (pocz==kon) kon=NULL;
        	pocz = stary->nast;
        	delete stary;
        	return wynik;
       }
    else { cout << "Pusta kolejka" << endl; }
  }

bool isEmptyK(elem* pocz){
	if (pocz==NULL) return true;
    else return false;
   }
  
int firstEl(elem* pocz){
	if(pocz!=NULL){
		int wynik = pocz->dane;
       	return wynik;
    }
    else cout << "Pusta kolejka" << endl;
  }

//implementacja kolejki za pomoca dwoch stosow  			zadanie5
void addSto(elem* &stos1, elem* &stos2, int x){			
	push(stos2,x); 
}

int nextSto(elem* &stos1, elem* &stos2){
	if(stos1!=NULL) return pop(stos1);
    else {
        while (stos2!=NULL){
			push(stos1, pop(stos2)); 
		}
        if(stos1!=NULL) return pop(stos1);
        else cout << "Pusta kolejka" << endl;
    } 
}

//implementacja kolejki z uzyciem tablicy					zadanie 6
const int W = 15;
int stos[W];						
int rozm = 0;
void pushTab(int x){
	if (rozm==W) cout << "Stos jest pelny";
    else {
        stos [rozm] = x;
        rozm++;
    } 
}
int popTab(){
	if (rozm==0) cout << "Stos jest pusty";
    else{rozm--;
                int wynik = stos[rozm];
                return wynik; 
	}
}
//odwracanie stosu za pomoca innego stosu					zadanie 7
void obroc(elem* &stos1, elem* &stos2){						
	int tmp = 0;
    elem* stop = NULL;
    
    while(stop!=stos1){
   		tmp=pop(stos1);
       	while(stos1!=stop){
		   	push(stos2,pop(stos1));
		}
       	push(stos1,tmp);
       	stop=stos1;
       	while(stos2!=NULL){
		   	push(stos1,pop(stos2));
		}
    }
}
//uporzadkowanie elementow malejaco							zadanie 8
void kolejnoscMalejaca(elem* &stos1,elem* &stos2){
	elem* stop = NULL;
 	int min = 0;
 	while(stos1!=stop){
	 	min = pop(stos1);
   		while(stos1!=stop){
		   		if (topEl(stos1)<min){
				   		push(stos2,min);
            			min=pop(stos2);
           		}
       			else push(stos2,pop(stos1));
     	}
     	push(stos1,min);
     	stop=stos1;
     	while(stos2!=NULL)
        	push(stos1,pop(stos2));
   	}
}
void print(elem* lista){				//funkcja pomocnicza
	for (; lista; lista = lista->nast)
		cout << lista->dane << " ";
		cout << endl;		
}

int main(){
	elem* stos = nullptr;
	cout << "Zadanie 1" << endl << "Wlozenie na stos wartosci" << endl;
	push(stos, 1);
	push(stos, 6);
	push(stos, 3);
	push(stos, 4);
	print(stos);
	cout << "Zdjecie wartosci ze stosu" << endl;
	cout << pop(stos) << endl;
	cout << "Zwrocenie elementu na wierzcholku" << endl;
	cout << topEl(stos) << endl;
	cout << "Czy stos jest pusty" << endl;
	cout << isEmpty(stos) << endl << endl;
	
	cout << "Zadanie 2" << endl << "Wlozenie do kolejki dwoch wartosci" << endl;
	elem* pocz = nullptr;
	elem* kon = nullptr;
	add(pocz, kon, 1);
	add(pocz, kon, 2);
	print(pocz);
	cout << "Pobranie pierwszego elementu" << endl;
	cout << next(pocz, kon) << endl;
	cout << "Wyœwietlenie pierwszego elementu" << endl;
	cout << firstEl(pocz) << endl;
	cout << "Czy kolejka jest pusta" << endl;
	cout << isEmptyK(pocz) << endl << endl;
	
	cout << "Zadanie 3: " << endl << "SYEUQTSAONIE" << endl << endl;
	cout << "Zadanie 4: " << endl << "EA*S*Y**" << endl << endl;
	
	cout << "Zadanie 6: " << endl << "Wpisanie na stos zrobiony z tablicy 1 i 2, zdjecie pierwszej liczby" << endl;
	pushTab(1);
	pushTab(2);
	cout << popTab() << endl << endl;
	
	cout << "Zadanie 7: " << endl << "Odwrocenie kolejnosci stosu, za pomoca drugiego stosu" << endl;
	elem* stos3 = nullptr;
	print(stos);
	obroc(stos, stos3);
	print(stos);
	cout << endl;
	
}
