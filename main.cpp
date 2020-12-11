#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
  T data; // valore
  Nodo* next; //puntatore al prossimo nodo  
};

//INSERIMENTO IN TESTA
template <typename T>
void ins_testa(T* &head,T* nuovo) {   
  nuovo->next = head;
  head = nuovo;
}

//INSERIMENTO IN CODA
template <typename T>
void ins_coda(T* &head,T* nuovo) {   
  T* fine_lista = head;

  if(head == nullptr) { //Se lista vuota
    ins_testa(head,nuovo);
  }
  else {

  //cerco l'ultimo nodo, devo fermarmi quando nodo->next é nullptr
  while(fine_lista->next != nullptr) {
    fine_lista = fine_lista->next;
  }

  fine_lista->next = nuovo; //aggiungiamo il nuovo nodo alla fine, quindi l'ultimo nodo corrente deve puntare all'indirizzo del nuovo
  nuovo->next = nullptr; //ci assicuriamo che l'ultimo nodo punti a nullptr
  }
}

/*template <typename T>
T* cerca_lista(T* head,T* precedente,int data) {

}*/

template <typename T>
void stampa_lista(T* head) {
  T* scorri = head;

  while(scorri != nullptr) {
    cout << "data: " << scorri->data << endl;
    scorri = scorri->next;
  }
}

int main() {  

  Nodo<float>* head = nullptr; //puntatore all'inizio della lista	

  for(int i = 1; i < 10; i++) {
    Nodo<float>* nuovo = new Nodo<float>{(float)i*5};     
    ins_testa(head,nuovo);  
  }  

  stampa_lista(head);
}


#ifndef _CELLALP_H
#define _CELLALP_H
template< class T >
class Cella{
 public:
 Cella() {}
 Cella(const T& elemento){ this->elemento = elemento; }
 void setElemento(T e){ elemento = e; }
 T getElemento() const {return elemento; }
 void setSucc(Cella *p){ succ=p; }
 Cella * getSucc() const{ return succ;}
 void setPrec(Cella *p) { prec=p;}
 Cella * getPrec() const{ return prec;}
 bool operator==(Cella);
 private:
 T elemento;
 Cella * prec;
 Cella * succ;
};
#endif // _CELLALP_H