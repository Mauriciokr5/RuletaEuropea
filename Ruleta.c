#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>
#include "Elem.h"
#include "Circular.h"
int menu();
Circular nuevaRuleta();
Elem girarRuleta(Circular c);
int esJuegoACero(Elem e);
int esVoisinsDeZero(Elem e);
int esORPHELINS(Elem e);
int validacion(Elem e, Elem elems[], int tam);
int casosApuesta(Elem e,int op);
void caso5(int num);
void caso6(int num);

int main(){

	if (casosApuesta(girarRuleta(nuevaRuleta()),menu())) {
		printf("GANASTE!\n");
	}else{
		printf("perdiste :c\n");
	}

	return 0;
}

int menu(){
	int opcion;
	printf("\tRuleta Europea\n");
	printf("Escoge el numero de tu apuesta:\n");
	printf("1.-JUEGO A CERO [12, 35, 3, 26, 0, 32, 15]\n");
	printf("2.-VOISINS DE ZERO (VECINOS DEL CERO) [22, 18, 29, 7, 28, 12, 35, 3, 26, 0, 32, 15, 19, 4, 21, 2, 25]\n");
	printf("3.-ORPHELINS (HUÉRFANOS) [17, 34, 6, 1, 20, 14, 31, 9]\n");
	printf("4.-TIERS [33, 16, 24, 5, 10, 23, 8, 30, 11, 36, 13, 27]\n");
	printf("5.-VECINOS [n-2,n-1,n,n+1,n+2]\n");
	printf("6.-UN SOLO NUMERO [n]\n");
	scanf("%d", &opcion);
	//casos especiales
	if (opcion==5) {
		printf("Ingrese el numero\n");
		int num; scanf("%d", &num);
		caso5(num);
		exit(0);
	}
	if (opcion==6) {
		printf("Ingrese el numero\n");
		int num; scanf("%d", &num);
		caso6(num);
		exit(0);
	}

	return opcion;
}

void caso6(int num){
	if (num==girarRuleta(nuevaRuleta())) {
		printf("GANASTE!\n");
	}else{
		printf("perdiste :c\n");
	}
}

void caso5(int num){
	Circular d = nuevaRuleta();
	Elem elems[5];
	//encontramos el numero en la ruleta
	while(num!=top(d)){
		d = rotar(d);
	}
	//giramos la ruleta dos posiscion antes del numero
	for (int i = 0; i < 35; i++) {
		d = rotar(d);
	}
	//guardamos los siguientes 5 numeros en un arreglo
	for (int i = 0; i < 5; i++) {
		elems[i]=top(d);
		d = rotar(d);
	}
	//validamos
	if (validacion(girarRuleta(nuevaRuleta()), elems, 5)) {
		printf("GANASTE!\n");
	}else{
		printf("perdiste :c\n");
	}



}

Elem girarRuleta(Circular c){
	srand (time(NULL));
	int altr =rand() % 100;
	printf("Ahi va!\n");
	for (int i = 0; i < altr; i++) {
		ImpElem(top(c));
		c =rotar(c);
		fflush(stdout);

		usleep((5*i*i)/(altr*altr)*100000);
		printf("  \r ");
	}
	ImpElem(top(c));
	printf("\n");
	return top(c);
}

Circular nuevaRuleta(){
	Circular c = empty();
	int numRuleta[37] = {0, 26, 3, 35, 12, 28, 7, 29, 18, 22, 9, 31, 14, 20, 1, 33, 16, 24, 5, 10, 23, 8, 30, 11, 36, 13, 27, 6, 34, 17, 25, 2, 21, 4, 19, 15, 32};
	for (int i = 36; i >=0; i--) {
		c = push(numRuleta[i],c);
	}
	return c;
}

int validacion(Elem e, Elem elems[], int tam){
	int flag=0;
	for (int i = 0; i<tam; i++) {
		ImpElem(elems[i]);
		if (e==elems[i]){
			flag=1;
		}
	}
	return flag;
}

int casosApuesta(Elem e,int op){


	if (op==1) {
		int n = 7;
		Elem cubre[7] = {12, 35, 3, 26, 0, 32, 15};
		return validacion(e,cubre,n);
	}
	if (op==2) {
		int n = 17;
		Elem cubre[17] = {22, 18, 29, 7, 28, 12, 35, 3, 26, 0, 32, 15, 19, 4, 21, 2, 25};
		return validacion(e,cubre,n);
	}
	if (op==3) {
		int n = 8;
		Elem cubre[8] = {17, 34, 6, 1, 20, 14, 31, 9};
		return validacion(e,cubre,n);
	}
	if (op==4) {
		int n = 12;
		Elem cubre[12] = {33, 16, 24, 5, 10, 23, 8, 30, 11, 36, 13, 27};
		return validacion(e,cubre,n);
	}
	return 0;

}
