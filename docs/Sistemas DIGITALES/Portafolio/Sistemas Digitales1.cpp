////hola DEATH
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"cripta de DEATH.h"
///////////////////////////////////////////////////
void menu();
int sifrar();
int digito1(int bit);
int digito2(int bit);
int digito3(int bit);
int digito4(int bit);
int digito5(int bit);
int digito6(int bit);
int digito7(int bit); //linea 467
int desifrar();
int hammin3(int bit);
int hammin5(int bit);
int hammin6(int bit);
int hammin7(int bit);
int hammin9(int bit);
int hammin10(int bit);
int hammin11(int bit); //linea 1453
///////////////////////////////////////////////////
void menu(){
	int op;
	printf("		que desea hacer \n");
	printf("	sifrar un codigo	=	1 \n");
	printf("	desifras un codigo	=	2 \n");
	printf("	Salir			=	3 \n");
	printf("\n");
	printf("		eliga una opcion:	");
	scanf("%i",&op);
	while(op<1 || op>3){
		printf("'ERROR' Ingrese una opcion valida \n");
		printf("	sifrar un codigo	=	1 \n");
		printf("	desifras un codigo	=	2 \n");
		printf("	Salir			=	3 \n");
		printf("\n");
		printf("		eliga una opcion:	");
		scanf("%i",&op);
	}
	if(op==1){
		sifrar();
	}
	else if(op==2){
		desifrar();
	}
	else{
		NULL;
	}
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
int sifrar(){
	int bit;
	system("cls");
	printf("ingrese la cantidad de digitos a usar (desde 1 a 7): ");
	scanf("%i",&bit);
	while(bit<1 || bit>7){
		printf("solo puede ingresar 7 digitos como maximo \n como mino 1 \n ingrese la cantidad de digitos: ");
		scanf("%i",&bit);
	}
	if(bit==1){
		digito1(bit);
	}
	else if(bit==2){
		digito2(bit);
	}
	else if(bit==3){
		digito3(bit);
	}
	else if(bit==4){
		digito4(bit);
	}
	else if(bit==5){
		digito5(bit);
	}
	else if(bit==6){
		digito6(bit);
	}
	else{
		digito7(bit);
	}
}
///////////////////////////////////////////////////
int digito1(int bit){
	char codigo[0];
	char codificado[3];
	int p1,p2,d3;
	int co0;
	printf("ingrese el codigo a codificar: ");
	scanf("%s",&codigo);
	co0=ACIInum(toascii(codigo[0]));
	d3=co0;
//	printf("d3 es: %i \n",d3);
	p1=d3;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("d3 es: %i \n",d3);
	printf("el codigo codificado es: ");
	for(int i=0;i<3;i++){
		printf("%c",codificado[i]);
	}
	printf("\n\n");
	system("pause");
	system("cls");
	menu();
}
///////////////////////////////////////////////////
int digito2(int bit){
	char codigo[1];
	char codificado[5];
	int p1,p2,d3,p4,d5;
	int co0,co1;
	printf("ingrese el codigo a codificar: ");
	scanf("%s",&codigo);
	co0=ACIInum(toascii(codigo[0]));
	co1=ACIInum(toascii(codigo[1]));
	d3=co0;
	d5=co1;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
	p1=d3+d5;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("d5 es: %i \n",d5);
	printf("el codigo codificado es: ");
	for(int i=0;i<5;i++){
		printf("%c",codificado[i]);
	}
	printf("\n\n");
	system("pause");
	system("cls");
	menu();
}
///////////////////////////////////////////////////
int digito3(int bit){
	char codigo[2];
	char codificado[6];
	int p1,p2,d3,p4,d5,d6;
	int co0,co1,co2;
	printf("ingrese el codigo a codificar: ");
	scanf("%s",&codigo);
	co0=ACIInum(toascii(codigo[0]));
	co1=ACIInum(toascii(codigo[1]));
	co2=ACIInum(toascii(codigo[2]));
	d3=co0;
	d5=co1;
	d6=co2;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
	p1=d3+d5;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
	printf("el codigo codificado es: ");
	for(int i=0;i<6;i++){
		printf("%c",codificado[i]);
	}
	printf("\n\n");
	system("pause");
	system("cls");
	menu();
}
///////////////////////////////////////////////////
int digito4(int bit){
	char codigo[3];
	char codificado[7];
	int p1,p2,d3,p4,d5,d6,d7;
	int co0,co1,co2,co3;
	printf("ingrese el codigo a codificar: ");
	scanf("%s",&codigo);
	co0=ACIInum(toascii(codigo[0]));
	co1=ACIInum(toascii(codigo[1]));
	co2=ACIInum(toascii(codigo[2]));
	co3=ACIInum(toascii(codigo[3]));
	d3=co0;
	d5=co1;
	d6=co2;
	d7=co3;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
	p1=d3+d5+d7;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6+d7;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6+d7;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
	codificado[6]=ACIInumchar(d7);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
	printf("el codigo codificado es: ");
	for(int i=0;i<7;i++){
		printf("%c",codificado[i]);
	}
	printf("\n\n");
	system("pause");
	system("cls");
	menu();
}
///////////////////////////////////////////////////
int digito5(int bit){
	char codigo[4];
	char codificado[9];
	int p1,p2,d3,p4,d5,d6,d7,p8,d9;
	int co0,co1,co2,co3,co4;
	printf("ingrese el codigo a codificar: ");
	scanf("%s",&codigo);	
	co0=ACIInum(toascii(codigo[0]));
	co1=ACIInum(toascii(codigo[1]));
	co2=ACIInum(toascii(codigo[2]));
	co3=ACIInum(toascii(codigo[3]));
	co4=ACIInum(toascii(codigo[4]));
	d3=co0;
	d5=co1;
	d6=co2;
	d7=co3;
	d9=co4;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("d9 es: %i \n",d9);
	p1=d3+d5+d7+d9;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6+d7;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6+d7;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	p8=d9;
	if(p8%2==0){
		p8=0;
	}
	else{
		p8=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
	codificado[6]=ACIInumchar(d7);
	codificado[7]=ACIInumchar(p8);
	codificado[8]=ACIInumchar(d9);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("p8 es: %i \n",p8);
//	printf("d9 es: %i \n",d9);
	printf("el codigo codificado es: ");
	for(int i=0;i<9;i++){
		printf("%c",codificado[i]);
	}
	printf("\n\n");
	system("pause");
	system("cls");
	menu();
}
///////////////////////////////////////////////////
int digito6(int bit){
	char codigo[5];
	char codificado[9];
	int p1,p2,d3,p4,d5,d6,d7,p8,d9,d10;
	int co0,co1,co2,co3,co4,co5;
	printf("ingrese el codigo a codificar: ");
	scanf("%s",&codigo);
	co0=ACIInum(toascii(codigo[0]));
	co1=ACIInum(toascii(codigo[1]));
	co2=ACIInum(toascii(codigo[2]));
	co3=ACIInum(toascii(codigo[3]));
	co4=ACIInum(toascii(codigo[4]));
	co5=ACIInum(toascii(codigo[5]));
	d3=co0;
	d5=co1;
	d6=co2;
	d7=co3;
	d9=co4;
	d10=co5;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("d9 es: %i \n",d9);
//	printf("d10 es: %i \n",d10);
	p1=d3+d5+d7+d9;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6+d7+d10;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6+d7;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	p8=d9+d10;
	if(p8%2==0){
		p8=0;
	}
	else{
		p8=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
	codificado[6]=ACIInumchar(d7);
	codificado[7]=ACIInumchar(p8);
	codificado[8]=ACIInumchar(d9);
	codificado[9]=ACIInumchar(d10);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("p8 es: %i \n",p8);
//	printf("d9 es: %i \n",d9);
//	printf("d10 es: %i \n",d10);
	printf("el codigo codificado es: ");
	for(int i=0;i<10;i++){
		printf("%c",codificado[i]);
	}
	printf("\n\n");
	system("pause");
	system("cls");
	menu();
}
///////////////////////////////////////////////////
int digito7(int bit){
	char codigo[6];
	char codificado[10];
	int p1,p2,d3,p4,d5,d6,d7,p8,d9,d10,d11;
	int co0,co1,co2,co3,co4,co5,co6;
	printf("ingrese el codigo a codificar: ");
	scanf("%s",&codigo);
	co0=ACIInum(toascii(codigo[0]));
	co1=ACIInum(toascii(codigo[1]));
	co2=ACIInum(toascii(codigo[2]));
	co3=ACIInum(toascii(codigo[3]));
	co4=ACIInum(toascii(codigo[4]));
	co5=ACIInum(toascii(codigo[5]));
	co6=ACIInum(toascii(codigo[6]));
	d3=co0;
	d5=co1;
	d6=co2;
	d7=co3;
	d9=co4;
	d10=co5;
	d11=co6;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("d9 es: %i \n",d9);
//	printf("d10 es: %i \n",d10);
//	printf("d11 es: %i \n",d11);
	p1=d3+d5+d7+d9+d11;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6+d7+d10+d11;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6+d7;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	p8=d9+10+d11;
	if(p8%2==0){
		p8=0;
	}
	else{
		p8=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
	codificado[6]=ACIInumchar(d7);
	codificado[7]=ACIInumchar(p8);
	codificado[8]=ACIInumchar(d9);
	codificado[9]=ACIInumchar(d10);
	codificado[10]=ACIInumchar(d11);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("p8 es: %i \n",p8);
//	printf("d9 es: %i \n",d9);
//	printf("d10 es: %i \n",d10);
//	printf("d11 es: %i \n",d11);
	printf("el codigo codificado es: ");
	for(int i=0;i<11;i++){
		printf("%c",codificado[i]);
	}
	printf("\n\n");
	system("pause");
	system("cls");
	menu();
}
///////////////////////////////////////////////////
///////////////////////////////////////////////////
 int desifrar(){
	int bit;
	system("cls");
	printf("ingrese la cantidad de digitos (3,5,6,7,9,10,11): ");
	scanf("%i",&bit);
	while(bit<3 || bit>11){
		printf("solo puede ingresar los digitos 3, 5, 6, 7, 9, 10, 11\n ingrese la cantidad de digitos: ");
		scanf("%i",&bit);
	}
	if(bit==3){
		hammin3(bit);
	}
	else if(bit==5){
		hammin5(bit);
	}
	else if(bit==6){
		hammin6(bit);
	}
	else if(bit==7){
		hammin7(bit);
	}
	else if(bit==9){
		hammin9(bit);
	}
	else if(bit==10){
		hammin10(bit);
	}
	else{
		hammin11(bit);
	}
}
///////////////////////////////////////////////////
int hammin3(int bit){
	char codigo[2];
	char secreto[0];
	int p1,p2;
	int s1,s2;
	int d3;
	int co0;
	char codificado[2];
	int binario[3];
	int aux=0;
	printf("ingrese el codigo a DE-codificar: ");
	scanf("%s",&codigo);
	secreto[0]=codigo[2];
//	printf("el codigo es: ");
//	for(int i=0;i<3;i++){
//		printf("%c",codigo[i]);
//	}
//	printf("\n");
//	for(int i=0;i<1;i++){
//		printf("%c",secreto[i]);
//	}
//	printf("\n");
	s1=ACIInum(toascii(codigo[0]));
	s2=ACIInum(toascii(codigo[1]));
	co0=ACIInum(toascii(secreto[0]));
	d3=co0;
//	printf("d3 es: %i \n",d3);
	p1=d3;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("s1 es: %i \n",s1);
//	printf("s2 es: %i \n",s2);
//	printf("d3 es: %i \n",d3);
	binario[3]=0;
	binario[2]=0;
	if(s1==p1){
		binario[1]=0;
	}
	else{
		binario[1]=1;
		aux++;
	}
	if(s2==p2){
		binario[0]=0;
	}
	else{
		binario[0]=1;
		aux++;
	}
	if(aux>0){
		printf("hay un error en el codigo y se encuentra en la posicion binaria: ");
		for(int i=0;i<4;i++){
			printf("%i",binario[i]);
		}
		printf("\n");
		int posicion;
		posicion=CobinarioAnum(binario);
		printf("cuya psicion es: %i",posicion);
		if(codigo[posicion-1]=='1'){
			codigo[posicion-1]='0';
		}
		else if(codigo[posicion-1]=='0'){
			codigo[posicion-1]='1';
		}
		printf("El codigo correcto es: ");
		for(int i=0;i<3;i++){
			printf("%c",codigo[i]);
		}
		secreto[0]=codigo[2];
		printf("\n");
		printf("Su origen es: ");
		for(int i=0;i<1;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
	else{
		printf("El codigo ingresado esta bien y su origen es: ");
		for(int i=0;i<1;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("cls");
		menu();
	}
}
///////////////////////////////////////////////////
int hammin5(int bit){
	char codigo[4];
	char secreto[1];
	int p1,p2,p4;
	int s1,s2,s4;
	int d3,d5;
	int co0,co1;
	char codificado[4];
	int binario[3];
	int aux=0;
	printf("ingrese el codigo a DE-codificar: ");
	scanf("%s",&codigo);
	secreto[0]=codigo[2];
	secreto[1]=codigo[4];
//	printf("el codigo es: ");
//	for(int i=0;i<5;i++){
//		printf("%c",codigo[i]);
//	}
//	printf("\n");
//	for(int i=0;i<2;i++){
//		printf("%c",secreto[i]);
//	}
//	printf("\n");
	s1=ACIInum(toascii(codigo[0]));
	s2=ACIInum(toascii(codigo[1]));
	s4=ACIInum(toascii(codigo[3]));
	co0=ACIInum(toascii(secreto[0]));
	co1=ACIInum(toascii(secreto[1]));
	d3=co0;
	d5=co1;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
	p1=d3+d5;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("s1 es: %i \n",s1);
//	printf("s2 es: %i \n",s2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("s4 es: %i \n",s4);
//	printf("d5 es: %i \n",d5);
	binario[3]=0;
	if(s1==p1){
		binario[2]=0;
	}
	else{
		binario[2]=1;
		aux++;
	}
	if(s2==p2){
		binario[1]=0;
	}
	else{
		binario[1]=1;
		aux++;
	}
	if(s4==p4){
		binario[0]=0;
	}
	else{
		binario[0]=1;
		aux++;
	}
	if(aux>0){
		printf("hay un error en el codigo y se encuentra en la posicion binaria: ");
		for(int i=0;i<4;i++){
			printf("%i",binario[i]);
		}
		printf("\n");
		int posicion;
		posicion=CobinarioAnum(binario);
		printf("cuya psicion es: %i",posicion);
		if(codigo[posicion-1]=='1'){
			codigo[posicion-1]='0';
		}
		else if(codigo[posicion-1]=='0'){
			codigo[posicion-1]='1';
		}
		printf("El codigo correcto es: ");
		for(int i=0;i<5;i++){
			printf("%c",codigo[i]);
		}
		secreto[0]=codigo[2];
		secreto[1]=codigo[4];
		printf("\n");
		printf("Su origen es: ");
		for(int i=0;i<2;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
	else{
		printf("El codigo ingresado esta bien y su origen es: ");
		for(int i=0;i<2;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
}
///////////////////////////////////////////////////
int hammin6(int bit){
	char codigo[5];
	char secreto[2];
	int p1,p2,p4;
	int s1,s2,s4;
	int d3,d5,d6;
	int co0,co1,co2;
	char codificado[5];
	int binario[3];
	int aux=0;
	printf("ingrese el codigo a DE-codificar: ");
	scanf("%s",&codigo);
	secreto[0]=codigo[2];
	secreto[1]=codigo[4];
	secreto[2]=codigo[5];
//	printf("el codigo es: ");
//	for(int i=0;i<6;i++){
//		printf("%c",codigo[i]);
//	}
//	printf("\n");
//	for(int i=0;i<3;i++){
//		printf("%c",secreto[i]);
//	}
//	printf("\n");
	s1=ACIInum(toascii(codigo[0]));
	s2=ACIInum(toascii(codigo[1]));
	s4=ACIInum(toascii(codigo[3]));
	co0=ACIInum(toascii(secreto[0]));
	co1=ACIInum(toascii(secreto[1]));
	co2=ACIInum(toascii(secreto[2]));
	d3=co0;
	d5=co1;
	d6=co2;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
	p1=d3+d5;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("s1 es: %i \n",s1);
//	printf("s2 es: %i \n",s2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("s4 es: %i \n",s4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
	binario[3]=0;
	if(s1==p1){
		binario[2]=0;
	}
	else{
		binario[2]=1;
		aux++;
	}
	if(s2==p2){
		binario[1]=0;
	}
	else{
		binario[1]=1;
		aux++;
	}
	if(s4==p4){
		binario[0]=0;
	}
	else{
		binario[0]=1;
		aux++;
	}
	if(aux>0){
		printf("hay un error en el codigo y se encuentra en la posicion binaria: ");
		for(int i=0;i<4;i++){
			printf("%i",binario[i]);
		}
		printf("\n");
		int posicion;
		posicion=CobinarioAnum(binario);
		printf("cuya psicion es: %i",posicion);
		if(codigo[posicion-1]=='1'){
			codigo[posicion-1]='0';
		}
		else if(codigo[posicion-1]=='0'){
			codigo[posicion-1]='1';
		}
		printf("El codigo correcto es: ");
		for(int i=0;i<6;i++){
			printf("%c",codigo[i]);
		}
		secreto[0]=codigo[2];
		secreto[1]=codigo[4];
		secreto[2]=codigo[5];
		printf("\n");
		printf("Su origen es: ");
		for(int i=0;i<3;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
	else{
		printf("El codigo ingresado esta bien y su origen es: ");
		for(int i=0;i<3;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
}
///////////////////////////////////////////////////
int hammin7(int bit){
	char codigo[6];
	char secreto[3];
	int p1,p2,p4;
	int s1,s2,s4;
	int d3,d5,d6,d7;
	int co0,co1,co2,co3;
	char codificado[6];
	int binario[3];
	int aux=0;
	printf("ingrese el codigo a DE-codificar: ");
	scanf("%s",&codigo);
	secreto[0]=codigo[2];
	secreto[1]=codigo[4];
	secreto[2]=codigo[5];
	secreto[3]=codigo[6];
//	printf("el codigo es: ");
//	for(int i=0;i<7;i++){
//		printf("%c",codigo[i]);
//	}
//	printf("\n");
//	for(int i=0;i<4;i++){
//		printf("%c",secreto[i]);
//	}
//	printf("\n");
	s1=ACIInum(toascii(codigo[0]));
	s2=ACIInum(toascii(codigo[1]));
	s4=ACIInum(toascii(codigo[3]));
	co0=ACIInum(toascii(secreto[0]));
	co1=ACIInum(toascii(secreto[1]));
	co2=ACIInum(toascii(secreto[2]));
	co3=ACIInum(toascii(secreto[3]));
	d3=co0;
	d5=co1;
	d6=co2;
	d7=co3;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
	p1=d3+d5+d7;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6+d7;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6+d7;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
	codificado[6]=ACIInumchar(d7);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("s1 es: %i \n",s1);
//	printf("s2 es: %i \n",s2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("s4 es: %i \n",s4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
	binario[3]=0;
	if(s1==p1){
		binario[2]=0;
	}
	else{
		binario[2]=1;
		aux++;
	}
	if(s2==p2){
		binario[1]=0;
	}
	else{
		binario[1]=1;
		aux++;
	}
	if(s4==p4){
		binario[0]=0;
	}
	else{
		binario[0]=1;
		aux++;
	}
	if(aux>0){
		printf("hay un error en el codigo y se encuentra en la posicion binaria: ");
		for(int i=0;i<4;i++){
			printf("%i",binario[i]);
		}
		printf("\n");
		int posicion;
		posicion=CobinarioAnum(binario);
		printf("cuya psicion es: %i",posicion);
		if(codigo[posicion-1]=='1'){
			codigo[posicion-1]='0';
		}
		else if(codigo[posicion-1]=='0'){
			codigo[posicion-1]='1';
		}
		printf("El codigo correcto es: ");
		for(int i=0;i<7;i++){
			printf("%c",codigo[i]);
		}
		secreto[0]=codigo[2];
		secreto[1]=codigo[4];
		secreto[2]=codigo[5];
		secreto[3]=codigo[6];
		printf("\n");
		printf("Su origen es: ");
		for(int i=0;i<4;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
	else{
		printf("El codigo ingresado esta bien y su origen es: ");
		for(int i=0;i<4;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
}
///////////////////////////////////////////////////
int hammin9(int bit){
	char codigo[8];
	char secreto[4];
	int p1,p2,p4,p8;
	int s1,s2,s4,s8;
	int d3,d5,d6,d7,d9;
	int co0,co1,co2,co3,co4;
	char codificado[8];
	int binario[3];
	int aux=0;
	printf("ingrese el codigo a DE-codificar: ");
	scanf("%s",&codigo);
	secreto[0]=codigo[2];
	secreto[1]=codigo[4];
	secreto[2]=codigo[5];
	secreto[3]=codigo[6];
	secreto[4]=codigo[8];
//	printf("el codigo es: ");
//	for(int i=0;i<9;i++){
//		printf("%c",codigo[i]);
//	}
//	printf("\n");
//	for(int i=0;i<5;i++){
//		printf("%c",secreto[i]);
//	}
//	printf("\n");
	s1=ACIInum(toascii(codigo[0]));
	s2=ACIInum(toascii(codigo[1]));
	s4=ACIInum(toascii(codigo[3]));
	s8=ACIInum(toascii(codigo[7]));
	co0=ACIInum(toascii(secreto[0]));
	co1=ACIInum(toascii(secreto[1]));
	co2=ACIInum(toascii(secreto[2]));
	co3=ACIInum(toascii(secreto[3]));
	co4=ACIInum(toascii(secreto[4]));
	d3=co0;
	d5=co1;
	d6=co2;
	d7=co3;
	d9=co4;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("d9 es: %i \n",d9);
	p1=d3+d5+d7+d9;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6+d7;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6+d7;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	p8=d9;
	if(p8%2==0){
		p8=0;
	}
	else{
		p8=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
	codificado[6]=ACIInumchar(d7);
	codificado[7]=ACIInumchar(p8);
	codificado[8]=ACIInumchar(d9);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("s1 es: %i \n",s1);
//	printf("s2 es: %i \n",s2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("s4 es: %i \n",s4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("p8 es: %i \n",p8);
//	printf("s8 es: %i \n",s8);
//	printf("d9 es: %i \n",d9);
	if(s1==p1){
		binario[3]=0;
	}
	else{
		binario[3]=1;
		aux++;
	}
	if(s2==p2){
		binario[2]=0;
	}
	else{
		binario[2]=1;
		aux++;
	}
	if(s4==p4){
		binario[1]=0;
	}
	else{
		binario[1]=1;
		aux++;
	}
	if(s8==p8){
		binario[0]=0;
	}
	else{
		binario[0]=1;
		aux++;
	}
	if(aux>0){
		printf("hay un error en el codigo y se encuentra en la posicion binaria: ");
		for(int i=0;i<4;i++){
			printf("%i",binario[i]);
		}
		printf("\n");
		int posicion;
		posicion=CobinarioAnum(binario);
		printf("cuya psicion es: %i",posicion);
		if(codigo[posicion-1]=='1'){
			codigo[posicion-1]='0';
		}
		else if(codigo[posicion-1]=='0'){
			codigo[posicion-1]='1';
		}
		printf("El codigo correcto es: ");
		for(int i=0;i<9;i++){
			printf("%c",codigo[i]);
		}
		secreto[0]=codigo[2];
		secreto[1]=codigo[4];
		secreto[2]=codigo[5];
		secreto[3]=codigo[6];
		secreto[4]=codigo[8];
		printf("\n");
		printf("Su origen es: ");
		for(int i=0;i<5;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
	else{
		printf("El codigo ingresado esta bien y su origen es: ");
		for(int i=0;i<5;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
}
///////////////////////////////////////////////////
int hammin10(int bit){
	char codigo[9];
	char secreto[5];
	int p1,p2,p4,p8;
	int s1,s2,s4,s8;
	int d3,d5,d6,d7,d9,d10;
	int co0,co1,co2,co3,co4,co5;
	char codificado[9];
	int binario[3];
	int aux=0;
	printf("ingrese el codigo a DE-codificar: ");
	scanf("%s",&codigo);
	secreto[0]=codigo[2];
	secreto[1]=codigo[4];
	secreto[2]=codigo[5];
	secreto[3]=codigo[6];
	secreto[4]=codigo[8];
	secreto[5]=codigo[9];
//	printf("el codigo es: ");
//	for(int i=0;i<10;i++){
//		printf("%c",codigo[i]);
//	}
//	printf("\n");
//	for(int i=0;i<6;i++){
//		printf("%c",secreto[i]);
//	}
//	printf("\n");
	s1=ACIInum(toascii(codigo[0]));
	s2=ACIInum(toascii(codigo[1]));
	s4=ACIInum(toascii(codigo[3]));
	s8=ACIInum(toascii(codigo[7]));
	co0=ACIInum(toascii(secreto[0]));
	co1=ACIInum(toascii(secreto[1]));
	co2=ACIInum(toascii(secreto[2]));
	co3=ACIInum(toascii(secreto[3]));
	co4=ACIInum(toascii(secreto[4]));
	co5=ACIInum(toascii(secreto[5]));
	d3=co0;
	d5=co1;
	d6=co2;
	d7=co3;
	d9=co4;
	d10=co5;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("d9 es: %i \n",d9);
//	printf("d10 es: %i \n",d10);
	p1=d3+d5+d7+d9;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6+d7+d10;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6+d7;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	p8=d9+10;
	if(p8%2==0){
		p8=0;
	}
	else{
		p8=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
	codificado[6]=ACIInumchar(d7);
	codificado[7]=ACIInumchar(p8);
	codificado[8]=ACIInumchar(d9);
	codificado[9]=ACIInumchar(d10);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("s1 es: %i \n",s1);
//	printf("s2 es: %i \n",s2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("s4 es: %i \n",s4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("p8 es: %i \n",p8);
//	printf("s8 es: %i \n",s8);
//	printf("d9 es: %i \n",d9);
//	printf("d10 es: %i \n",d10);
	if(s1==p1){
		binario[3]=0;
	}
	else{
		binario[3]=1;
		aux++;
	}
	if(s2==p2){
		binario[2]=0;
	}
	else{
		binario[2]=1;
		aux++;
	}
	if(s4==p4){
		binario[1]=0;
	}
	else{
		binario[1]=1;
		aux++;
	}
	if(s8==p8){
		binario[0]=0;
	}
	else{
		binario[0]=1;
		aux++;
	}
	if(aux>0){
		printf("hay un error en el codigo y se encuentra en la posicion binaria: ");
		for(int i=0;i<4;i++){
			printf("%i",binario[i]);
		}
		printf("\n");
		int posicion;
		posicion=CobinarioAnum(binario);
		printf("cuya psicion es: %i",posicion);
		if(codigo[posicion-1]=='1'){
			codigo[posicion-1]='0';
		}
		else if(codigo[posicion-1]=='0'){
			codigo[posicion-1]='1';
		}
		printf("El codigo correcto es: ");
		for(int i=0;i<10;i++){
			printf("%c",codigo[i]);
		}
		secreto[0]=codigo[2];
		secreto[1]=codigo[4];
		secreto[2]=codigo[5];
		secreto[3]=codigo[6];
		secreto[4]=codigo[8];
		secreto[5]=codigo[9];
		printf("\n");
		printf("Su origen es: ");
		for(int i=0;i<6;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
	else{
		printf("El codigo ingresado esta bien y su origen es: ");
		for(int i=0;i<6;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
}
///////////////////////////////////////////////////
int hammin11(int bit){
	char codigo[10];
	char secreto[6];
	int p1,p2,p4,p8;
	int s1,s2,s4,s8;
	int d3,d5,d6,d7,d9,d10,d11;
	int co0,co1,co2,co3,co4,co5,co6;
	char codificado[10];
	int binario[3];
	int aux=0;
	printf("ingrese el codigo a DE-codificar: ");
	scanf("%s",&codigo);
	secreto[0]=codigo[2];
	secreto[1]=codigo[4];
	secreto[2]=codigo[5];
	secreto[3]=codigo[6];
	secreto[4]=codigo[8];
	secreto[5]=codigo[9];
	secreto[6]=codigo[10];
//	printf("el codigo es: ");
//	for(int i=0;i<11;i++){
//		printf("%c",codigo[i]);
//	}
//	printf("\n");
//	for(int i=0;i<7;i++){
//		printf("%c",secreto[i]);
//	}
//	printf("\n");
	s1=ACIInum(toascii(codigo[0]));
	s2=ACIInum(toascii(codigo[1]));
	s4=ACIInum(toascii(codigo[3]));
	s8=ACIInum(toascii(codigo[7]));
	co0=ACIInum(toascii(secreto[0]));
	co1=ACIInum(toascii(secreto[1]));
	co2=ACIInum(toascii(secreto[2]));
	co3=ACIInum(toascii(secreto[3]));
	co4=ACIInum(toascii(secreto[4]));
	co5=ACIInum(toascii(secreto[5]));
	co6=ACIInum(toascii(secreto[6]));
	d3=co0;
	d5=co1;
	d6=co2;
	d7=co3;
	d9=co4;
	d10=co5;
	d11=co6;
//	printf("d3 es: %i \n",d3);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("d9 es: %i \n",d9);
//	printf("d10 es: %i \n",d10);
//	printf("d11 es: %i \n",d11);
	p1=d3+d5+d7+d9+d11;
	if(p1%2==0){
		p1=0;
	}
	else {
		p1=1;
	}
	p2=d3+d6+d7+d10+d11;
	if(p2%2==0){
		p2=0;
	}
	else{
		p2=1;
	}
	p4=d5+d6+d7;
	if(p4%2==0){
		p4=0;
	}
	else{
		p4=1;
	}
	p8=d9+10+d11;
	if(p8%2==0){
		p8=0;
	}
	else{
		p8=1;
	}
	codificado[0]=ACIInumchar(p1);
	codificado[1]=ACIInumchar(p2);
	codificado[2]=ACIInumchar(d3);
	codificado[3]=ACIInumchar(p4);
	codificado[4]=ACIInumchar(d5);
	codificado[5]=ACIInumchar(d6);
	codificado[6]=ACIInumchar(d7);
	codificado[7]=ACIInumchar(p8);
	codificado[8]=ACIInumchar(d9);
	codificado[9]=ACIInumchar(d10);
	codificado[10]=ACIInumchar(d11);
//	printf("p1 es: %i \n",p1);
//	printf("p2 es: %i \n",p2);
//	printf("s1 es: %i \n",s1);
//	printf("s2 es: %i \n",s2);
//	printf("d3 es: %i \n",d3);
//	printf("p4 es: %i \n",p4);
//	printf("s4 es: %i \n",s4);
//	printf("d5 es: %i \n",d5);
//	printf("d6 es: %i \n",d6);
//	printf("d7 es: %i \n",d7);
//	printf("p8 es: %i \n",p8);
//	printf("s8 es: %i \n",s8);
//	printf("d9 es: %i \n",d9);
//	printf("d10 es: %i \n",d10);
//	printf("d11 es: %i \n",d11);
	if(s1==p1){
		binario[3]=0;
	}
	else{
		binario[3]=1;
		aux++;
	}
	if(s2==p2){
		binario[2]=0;
	}
	else{
		binario[2]=1;
		aux++;
	}
	if(s4==p4){
		binario[1]=0;
	}
	else{
		binario[1]=1;
		aux++;
	}
	if(s8==p8){
		binario[0]=0;
	}
	else{
		binario[0]=1;
		aux++;
	}
	if(aux>0){
		printf("hay un error en el codigo y se encuentra en la posicion binaria: ");
		for(int i=0;i<4;i++){
			printf("%i",binario[i]);
		}
		printf("\n");
		int posicion;
		posicion=CobinarioAnum(binario);
		printf("cuya psicion es: %i \n",posicion);
		if(codigo[posicion-1]=='1'){
			codigo[posicion-1]='0';
		}
		else if(codigo[posicion-1]=='0'){
			codigo[posicion-1]='1';
		}
		printf("El codigo correcto es: ");
		for(int i=0;i<11;i++){
			printf("%c",codigo[i]);
		}
		secreto[0]=codigo[2];
		secreto[1]=codigo[4];
		secreto[2]=codigo[5];
		secreto[3]=codigo[6];
		secreto[4]=codigo[8];
		secreto[5]=codigo[9];
		secreto[6]=codigo[10];
		printf("\n");
		printf("Su origen es: ");
		for(int i=0;i<7;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
	else{
		printf("El codigo ingresado esta bien y su origen es: ");
		for(int i=0;i<7;i++){
			printf("%c",secreto[i]);
		}
		printf("\n\n");
		system("pause");
		system("cls");
		menu();
	}
}
///////////////////////////////////////////////////
int main (){
	menu();
}
