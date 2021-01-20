#include <iostream>

using namespace std;

struct elem{
	int dane;
	elem* poprz;
	elem* nast;
};
            
void insert(int x, int i, elem* &a){					//zadanie 1
    if (i==1){
        elem* nowy = new elem;
        nowy->dane = x;
        nowy->nast = a;
        nowy->poprz = NULL;

        if (a!=NULL) {
            a->poprz = nowy;
        } 
        a = nowy;
    }else if (i>1){
        elem* tempElem = a;
        for (int k=1; k<i; k++){ 
            if (tempElem->nast != NULL) {
                tempElem = tempElem->nast; 
            }
        }
        elem* nowy = new elem;
        nowy->dane = x;

        elem* nextElem = tempElem->nast;
        tempElem->nast = nowy;

        if (nextElem!=NULL) {
            nextElem->poprz = nowy;
        }

        nowy->poprz = tempElem;
        nowy->nast = nextElem;
        nextElem = nowy;
    }
}

void remove(int i, elem* &lista){
	if (i==1){
		elem* wsk = lista;
       	lista = lista->nast;
       	if (lista!=NULL) {
		   	lista->poprz = NULL;
		}
       	delete wsk;
	}else {
       	elem* wsk = lista;
      	for(int j=1;j<=i;j++){
           wsk=wsk->nast;
    	}
      	wsk->poprz->nast = wsk->nast;
      	if(wsk->nast!=NULL) {
		  	wsk->nast->poprz = wsk->poprz;
		}
     	delete wsk;
  	}
}

void reverse(elem* &lista){						//zadanie 2
	while(lista!=NULL){
		elem* kopia = lista->nast;
       	lista->nast = lista->poprz;
       	lista->poprz = kopia;
       	lista = kopia;
       	lista=lista->nast;
	}
}

void to_cyclic(elem* lista){					 //zadanie 3
	elem* pierwszy = lista;
   	while(lista->nast!=NULL){
       	lista=lista->nast;
	}
  	lista->nast = pierwszy;
}

void reverse_cyclic(elem* &lista){				//zadanie 4
    elem* start = lista->nast;
    elem* kopia = lista;
    elem* kopia2 = NULL;
    lista=lista->nast;
    do {
        kopia2=lista->nast; lista->nast=kopia;
        kopia=lista; 
        lista=kopia2; 
    }while(lista!=start);
}

int main(){
	
}

  
