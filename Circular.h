#include <stdlib.h>
typedef struct Nodo{
  Elem dato;
  struct Nodo *next;
}*Circular;

Circular empty(){return NULL;}
int isempty(Circular c){return c==NULL;}

Circular push(Elem e, Circular c){
  Circular temp = (Circular)malloc(sizeof(struct Nodo));
  temp->dato = e;
  if (isempty(c)) {
    temp->next = temp;
    c= temp;
  }else{
    temp->next=c->next;
    c->next=temp;
  }
  return c;
}
Elem top(Circular c){return c->next->dato;}
Circular rotar(Circular c){return c->next;}

Circular pop (Circular c){
  if (c==c->next) {
    return empty();
  }else{
    c->next=c->next->next;
    return c;
  }

}
