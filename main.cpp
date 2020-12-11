#include <iostream>

using namespace std;

template <typename T>
struct Nodo {
  T data; // valore
  Nodo<T>* next; //puntatore al prossimo nodo    	 
  Nodo<T>* head = nullptr; //puntatore all'inizio della lista
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
  	
  Nodo<float>* nuovo;

  for(int i = 1; i < 10; i++) {
    nuovo = new Nodo<float>{(float)(i*5)};     
    ins_testa(nuovo->head,nuovo);  
  }  

  stampa_lista(nuovo->head);

  ////////////////////////////////////////////////////////////

  Nodo<int>* nuovo1;

  for(int i = 1; i < 10; i++) {
    nuovo1 = new Nodo<int>{i*7};     
    ins_testa(nuovo1->head,nuovo1);  
  }  
  stampa_lista(nuovo1->head);  
}


