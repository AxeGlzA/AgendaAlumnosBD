#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>


//Declaramos prototipos de las funciones que vamos a utilizar
void cargando();
int nip();
void pantalla(int,int,int,int);
void menu();
void capturar();
void cargando();
void mostrar();
void search();
void actualizar();
void borrar();
void gotoxy(int, int);
void cuadro(int, int, int, int);
void titulo();
void carga();
void salir();

//Declaramos la estructura de agenda de alumno
struct agenda_a {
	char nombre[40],domicilio[30],fracc[30],cp[6],ciudad[25];
	char tel[20], email[20], notas[80],edad[3],sexo[10];

	struct d_academicos { //DEntro de la estructura agenda, anidamos otra para datos académicos
		int codigo, semestre, nrc, creditos;
		float cal;
		char carrera[20], uni[30], materia[20],maestro[30],seccion[4];
	} aca[10];
} age[10]; //Ambos alias son arreglos
int cont= 0;//Declaramos variable global para tener control de los arreglos
//-----------------------------------------------------------------------------------
//----------------------------PROGRAMA PRINCIPAL-------------------------------------
int main() {
	system("mode con: cols=80 lines=25");
	system("COLOR E0");
	setlocale(LC_CTYPE,"es_MX.UTF-8");
	//Funciones para poner poner ñ y acentos
	cargando();
	system("cls");
	if (nip() == 1) {
		menu();
	}
	return 0;
	return 0;
}
//-----------------------------------------------------------------------------------
void cargando() {
	int i;
	cuadro(0,0,79,24);
	gotoxy(25.5,10);
	printf("C A R G A N D O  S I S T E M A");
	for(i=3; i<=76; i++) {
		gotoxy(i,12);
		printf("%c",177);
	}
	for(i=3; i<=76; i++) {
		gotoxy(i,12);
		printf("%c",219);
		Sleep(35);
	}
}
void carga() {
	int i;
	cuadro(0,0,79,24);
	gotoxy(29,26);
	printf("C A R G A N D O . . .");
	for(i=3; i<=76; i++) {
		gotoxy(i,28);
		printf("%c",177);
	}
	for(i=3; i<=76; i++) {
		gotoxy(i,28);
		printf("%c",219);
		Sleep(35);
	}
}
//Función para pedir el nip
int nip() {
	int nip, n=3;
	while(nip!=123 && n>=0) {
		system("COLOR E0");
		cuadro(0,0,79,24);
		cuadro(1,1,78,3);
		gotoxy(28.5,2);
		printf("B A S E  D E  D A T O S\n");
		cuadro(18,7,59,13);
		cuadro(42.5,9,57.5,11);
		gotoxy(20.5,10);
		printf("Ingrese su contrase%ca:      ",164);
		scanf("%d",&nip);
		if(nip!=123) {
			system("cls");
			system("COLOR 4F");
			cuadro(0,0,79,24);
			cuadro(28.5,10,53,14);
			gotoxy(30.5,12);
			printf("TE QUEDAN %d INTENTOS",n);
			n-=1;
			Sleep(1600);
			system("cls");
		} else if (nip==123) {
			system("cls");
			cuadro(0,0,79,24);
			cargando();
			system("cls");
			cuadro(0,0,79,24);
			pantalla(14.5,2,50,22);
			pantalla(15.5,3,49,5);
			cuadro(15.5,7,23,19);cuadro(25,7,49,19);
			gotoxy(20,4);printf("B A S E  D E  D A T O S");
			gotoxy(30,20);printf("Autor: Axel Gonzalez.");
			gotoxy(35,21);printf("Version 1.1");
			Sleep(4000);
			system("cls");
			cargando();
			Sleep(1600);
			system("cls");
			return 1;
		}

	}
	if(n==-1) {
		system("COLOR 4F");
		cuadro(14,10,65,16);
		gotoxy(16,12);
		printf("EXCEDI%c EL N%cMERO DE INTENTOS,PRUEBE M%cS TARDE",224,233,181);
		Sleep(3000);
		system("cls");
		system("COLOR E0");
		salir();
		return 0;
	}
}

void menu() {
	int opc;
	do {
		system("COLOR E0");
		system("cls");
		titulo();
		gotoxy(26.5,4);
		printf("%cQu%c acci%cn desea hacer hoy?",168,130,162);
		cuadro(26.5,5.5,54,18);
		gotoxy(28.5,6);
		printf("1.- Capturar registro");
		gotoxy(28.5,8);
		printf("2.- Mostrar registros");
		gotoxy(28.5,10);
		printf("3.- Buscar registro");
		gotoxy(28.5,12);
		printf("4.- Actualizar dato");
		gotoxy(28.5,14);
		printf("5.- Borrar registro/campo");
		gotoxy(28.5,16);
		printf("6.- Salir");
		gotoxy(28.5,19);
		printf(" Elige una opci%cn: ",162);
		scanf("%i",&opc);
		carga();

		switch(opc) {
			case 1:
				capturar();
				break;
			case 2:
				mostrar();
				break;
			case 3:
				search();
				break;
			case 4:
				actualizar();
				break;
			case 5:
				borrar();
				break;

		}


	} while(opc!=6);
	system("cls");
	salir();
}

void capturar() {
	int num,i,prueba=0;
	if(cont<10) {
		system("cls");
		titulo();
		gotoxy(26.5,5);
		printf("Elegiste la opci%cn de capturar",162);
		gotoxy(31.5,8);
		printf("Tienes %d espacios",10-cont);
		gotoxy(26.5,14);
		printf("Presione <enter> para continuar");
		getch();
		carga();
		system("cls");
		cuadro(0,0,79,24);
		cuadro(1,1,78,3);
		gotoxy(26.5,2);
		printf("C A P T U R A  D E  D A T O S\n");
		gotoxy(30,4);
		printf("AGENDA DE ALUMNO");
		gotoxy(5,5);
		printf("%cN%cMERO DE REGISTRO: %d",175,233, cont+1);
		fflush(stdin);
		cuadro(4,7,75,20);
		gotoxy(6,9);
		printf("1.-Nombre: ");
		gets(age[cont].nombre);
		fflush(stdin);
		gotoxy(6,10);
		printf("2.-Edad: ");
		gets(age[cont].edad);
		fflush(stdin);
		gotoxy(6,11);
		printf("3.-Sexo(M/F): ");
		gets(age[cont].sexo);
		fflush(stdin);
		gotoxy(6,12);
		printf("4.-Domiciliio: ");
		gets(age[cont].domicilio);
		fflush(stdin);
		gotoxy(6,13);
		printf("5.-Fraccionamiento: ");
		gets(age[cont].fracc);
		fflush(stdin);
		gotoxy(6,14);
		printf("6.-Ciudad: ");
		gets(age[cont].ciudad);
		fflush(stdin);
		gotoxy(6,15);
		printf("7.-C%cdigo Postal: ",162);
		gets(age[cont].cp);
		fflush(stdin);
		gotoxy(6,16);
		printf("8.-Tel%cfono: ",130);
		gets(age[cont].tel);
		fflush(stdin);
		gotoxy(6,17);
		printf("9.-E_Mail: ");
		gets(age[cont].email);
		fflush(stdin);
		gotoxy(6,18);
		printf("10.-Notas adicionales: ");
		gets(age[cont].notas);
		fflush(stdin);
		gotoxy(16,21);
		printf("Presione <enter> para capturar datos ac%cd%cmicos",160,130);
		getch();
		carga();
		system("cls");
		cuadro(0,0,79,24);
		cuadro(1,1,78,3);
		gotoxy(26.5,2);
		printf("C A P T U R A  D E  D A T O S\n");
		gotoxy(30,4);
		printf("DATOS ACAD%cMICOS",144);
		gotoxy(5,5);
		printf("%cN%cMERO DE REGISTRO: %d",175,233, cont+1);
		fflush(stdin);
		cuadro(4,7,75,20);
		gotoxy(6,9);
		printf("1.-C%cdigo: ",162);
		scanf("%d",&age[cont].aca[cont].codigo);
		fflush(stdin);
		gotoxy(6,10);
		printf("2.-Carrera: ");
		gets(age[cont].aca[cont].carrera);
		fflush(stdin);
		gotoxy(6,11);
		printf("3-Centro Universitario: ");
		gets(age[cont].aca[cont].uni);
		fflush(stdin);
		gotoxy(6,12);
		printf("4.-Semestre: ");
		scanf("%d",&age[cont].aca[cont].semestre);
		fflush(stdin);
		gotoxy(6,13);
		printf("5-Maestro(a): ");
		gets(age[cont].aca[cont].maestro);
		fflush(stdin);
		gotoxy(6,14);
		printf("6.-Materia: ");
		gets(age[cont].aca[cont].materia);
		fflush(stdin);
		gotoxy(6,15);
		printf("7.-NRC: ");
		scanf("%d",&age[cont].aca[cont].nrc);
		fflush(stdin);
		gotoxy(6,16);
		printf("8.-Cr%cditos: ",130);
		scanf("%d",&age[cont].aca[cont].creditos);
		fflush(stdin);
		gotoxy(6,17);
		printf("9.-Secci%cn: ",162);
		gets(age[cont].aca[cont].seccion);
		fflush(stdin);
		gotoxy(6,18);
		printf("10.-Calificaci%cn: ",162);
		scanf("%f",&age[cont].aca[cont].cal);
		cont++;
		fflush(stdin);
		gotoxy(22,22);
		printf("Presione <enter> para volver al men%c",163);
		getch();
		carga();
	} else if(cont==10) {
		system("cls");
		system("COLOR 47");
		cuadro(25.5,10,53.5,14);
		gotoxy(27.5,12);
		printf("YA NO TIENES M%cS ESPACIO",181);
		getch();
		carga();
	}
}
void mostrar() {
	int i;
	system("cls");
	if(cont!=0) {
		for(i=0; i<cont; i++) {
			system("cls");
			cuadro(0,0,79,24);
			titulo();
			gotoxy(26.5,2);
			printf("M U E S T R A  D E  D A T O S\n");
			gotoxy(5,4);
			printf("%cN%cMERO DE REGISTRO: %d",175,233,i+1);
			gotoxy(2,5);
			printf("AGENDA DE ALUMNO");
			cuadro(1,6,37.5,17);
			gotoxy(3,7);
			printf("1.-Nombre: %s",age[i].nombre);
			Sleep(1);
			gotoxy(3,8);
			printf("2.-Edad: %s",age[i].edad);
			Sleep(1);
			gotoxy(3,9);
			printf("3.-Sexo(M/F): %s",age[i].sexo);
			Sleep(1);
			gotoxy(3,10);
			printf("4.-Domiciclio: %s",age[i].domicilio);
			Sleep(1);
			gotoxy(3,11);
			printf("5.-Fraccionamiento: %s",age[i].fracc);
			Sleep(1);
			gotoxy(3,12);
			printf("6.-Ciudad: %s",age[i].ciudad);
			Sleep(1);
			gotoxy(3,13);
			printf("7.-C%cdigo Postal: %s",162,age[i].cp);
			Sleep(1);
			gotoxy(3,14);
			printf("8.-Tel%cfono: %s",130,age[i].tel);
			Sleep(1);
			gotoxy(3,15);
			printf("9.-E_Mail: %s",age[i].email);
			Sleep(1);
			gotoxy(3,16);
			printf("10.-Notas: %s",age[i].notas);
			Sleep(1);
			gotoxy(38.5,5);
			printf("DATOS ACAD%cMICOS",144);
			cuadro(39.5,6,78,17);
			gotoxy(41.5,7);
			printf("1.-C%cdigo: %d",162,age[i].aca[i].codigo);
			Sleep(1);
			gotoxy(41.5,8);
			printf("2.-Carrera: %s",age[i].aca[i].carrera);
			Sleep(1);
			gotoxy(41.5,9);
			printf("3.-Centro Universitario: %s",age[i].aca[i].uni);
			Sleep(1);
			gotoxy(41.5,10);
			printf("4.-Semestre: %d",age[i].aca[i].semestre);
			Sleep(1);
			gotoxy(41.5,11);
			printf("5.-Maestro(a): %s",age[i].aca[i].maestro);
			Sleep(1);
			gotoxy(41.5,12);
			printf("6.-Materia: %s",age[i].aca[i].materia);
			Sleep(1);
			gotoxy(41.5,13);
			printf("7.-NRC: %d",age[i].aca[i].nrc);
			Sleep(1);
			gotoxy(41.5,14);
			printf("8.-Cr%cditos:  %d",130,age[i].aca[i].creditos);
			Sleep(1);
			gotoxy(41.5,15);
			printf("9.-Secci%cn:  %s",162,age[i].aca[i].seccion);
			Sleep(1);
			gotoxy(41.5,16);
			printf("10.-Calificaci%cn: %.2f",162,age[i].aca[i].cal);
			Sleep(1);
			gotoxy(14,19);
			printf("Presione <enter> para mostrar el siguiente registro");
			getch();
			carga();
		}
	} else {
		system("COLOR 47");
		cuadro(0,0,79,24);
		cuadro(27.5,10,49.5,14);
		gotoxy(29.5,12);
		printf("NO HAY DATOS TODAV%cA",214);
		gotoxy(22,18);
		printf("Presione <enter> para volver al men%c",163);
		getch();
		carga();
	}
}

void search() {
	int busca,opc;
	if(cont!=0) {
		system("cls");
		cuadro(0,0,79,24);
		titulo();
		gotoxy(27,4);
		printf("Elegiste la opci%cn buscar",162);
		gotoxy(28.5,6);
		printf("%cQu%c deseas consultar?",168,130);
		cuadro(27.5,8,49.5,15);
		gotoxy(29.5,10);
		printf("1.-Agenda del alumno");
		gotoxy(29.5,12);
		printf("2.-Datos acad%cmicos",130);
		gotoxy(29.5,14);
		printf("3.-Ambos");
		gotoxy(29.5,17);
		printf("Elige una opci%cn: ",162);
		scanf("%d",&opc);
		system("cls");
		cuadro(0,0,79,24);
		titulo();
		cuadro(6.5,8.5,72.5,12.5);
		gotoxy(8.5,10.5);
		printf("Por favor ingrese el n%cmero de registro que quiere consultar: ",163);
		scanf("%d",&busca);
		system("cls");
		if(opc==1) {
			cuadro(0,0,79,24);
			cuadro(1,1,78,3);
			gotoxy(26.5,2);
			printf("B U S Q U E D A  D E  D A T O S\n");
			gotoxy(30,4);
			printf("AGENDA DE ALUMNO");
			gotoxy(5,5);
			printf("%cN%cMERO DE REGISTRO: %d",175,233,busca);
			cuadro(4,7,75,20);
			gotoxy(6,9);
			printf("1.-Nombre: %s",age[busca-1].nombre);
			Sleep(1);
			gotoxy(6,10);
			printf("2.-Edad: %s",age[busca-1].edad);
			Sleep(1);
			gotoxy(6,11);
			printf("3.-Sexo(M/F): %s",age[busca-1].sexo);
			Sleep(1);
			gotoxy(6,12);
			printf("4.-Domiciclio: %s",age[busca-1].domicilio);
			Sleep(1);
			gotoxy(6,13);
			printf("5.-Fraccionamiento: %s",age[busca-1].fracc);
			Sleep(1);
			gotoxy(6,14);
			printf("6.-Ciudad: %s",age[busca-1].ciudad);
			Sleep(1);
			gotoxy(6,15);
			printf("7.-C%cdigo Postal: %s",162,age[busca-1].cp);
			Sleep(1);
			gotoxy(6,16);
			printf("8.-Tel%cfono: %s",130,age[busca-1].tel);
			Sleep(1);
			gotoxy(6,17);
			printf("9.-E_Mail: %s",age[busca-1].email);
			Sleep(1);
			gotoxy(6,18);
			printf("10.-Notas: %s",age[busca-1].notas);
			Sleep(1);
			gotoxy(22,22);
			printf("Presione <enter> para regresar al men%c",163);
			getch();
			carga();
		}
		if(opc==2) {
			cuadro(0,0,79,24);
			cuadro(1,1,78,3);
			gotoxy(26.5,2);
			printf("B U S Q U E D A  D E  D A T O S\n");
			gotoxy(30,4);
			printf("DATOS ACAD%cMICOS",144);
			gotoxy(5,5);
			printf("%cN%cMERO DE REGISTRO: %d",175,233,busca);
			cuadro(4,7,75,20);
			gotoxy(6,9);
			printf("1.-C%cdigo: %d",162,age[busca-1].aca[busca-1].codigo);
			Sleep(1);
			gotoxy(6,10);
			printf("2.-Carrera: %s",age[busca-1].aca[busca-1].carrera);
			Sleep(1);
			gotoxy(6,11);
			printf("3.-Centro Universitario: %s",age[busca-1].aca[busca-1].uni);
			Sleep(1);
			gotoxy(6,12);
			printf("4.-Semestre: %d",age[busca-1].aca[busca-1].semestre);
			Sleep(1);
			gotoxy(6,13);
			printf("5.-Maestro(a): %s",age[busca-1].aca[busca-1].maestro);
			Sleep(1);
			gotoxy(6,14);
			printf("6.-Materia: %s",age[busca-1].aca[busca-1].materia);
			Sleep(1);
			gotoxy(6,15);
			printf("7.-NRC: %d",age[busca-1].aca[busca-1].nrc);
			Sleep(1);
			gotoxy(6,16);
			printf("8.-Cr%cditos:  %d",130,age[busca-1].aca[busca-1].creditos);
			Sleep(1);
			gotoxy(6,17);
			printf("9.-Secci%cn:  %s",162,age[busca-1].aca[busca-1].seccion);
			Sleep(1);
			gotoxy(6,18);
			printf("10.-Calificaci%cn: %.2f",162,age[busca-1].aca[busca-1].cal);
			Sleep(1);
			gotoxy(22,22);
			printf("Presione <enter> para regresar al men%c",163);
			getch();
			carga();
		}
		if(opc==3) {
			cuadro(0,0,79,24);
			cuadro(1,1,78,3);
			gotoxy(26.5,2);
			printf("B U S Q U E D A  D E  D A T O S\n");
			gotoxy(5,4);
			printf("%cN%cMERO DE REGISTRO: %d",175,233,busca);
			gotoxy(2,5);
			printf("AGENDA DE ALUMNO");
			cuadro(1,6,37.5,17);
			gotoxy(3,7);
			printf("1.-Nombre: %s",age[busca-1].nombre);
			Sleep(1);
			gotoxy(3,8);
			printf("2.-Edad: %s",age[busca-1].edad);
			Sleep(1);
			gotoxy(3,9);
			printf("3.-Sexo(M/F): %s",age[busca-1].sexo);
			Sleep(1);
			gotoxy(3,10);
			printf("4.-Domiciclio: %s",age[busca-1].domicilio);
			Sleep(1);
			gotoxy(3,11);
			printf("5.-Fraccionamiento: %s",age[busca-1].fracc);
			Sleep(1);
			gotoxy(3,12);
			printf("6.-Ciudad: %s",age[busca-1].ciudad);
			Sleep(1);
			gotoxy(3,13);
			printf("7.-C%cdigo Postal: %s",162,age[busca-1].cp);
			Sleep(1);
			gotoxy(3,14);
			printf("8.-Tel%cfono: %s",130,age[busca-1].tel);
			Sleep(1);
			gotoxy(3,15);
			printf("9.-E_Mail: %s",age[busca-1].email);
			Sleep(1);
			gotoxy(3,16);
			printf("10.-Notas: %s",age[busca-1].notas);
			Sleep(1);
			gotoxy(38.5,5);
			printf("DATOS ACAD%cMICOS",144);
			cuadro(39.5,6,78,17);
			gotoxy(41.5,7);
			printf("1.-C%cdigo: %d",162,age[busca-1].aca[busca-1].codigo);
			Sleep(1);
			gotoxy(41.5,8);
			printf("2.-Carrera: %s",age[busca-1].aca[busca-1].carrera);
			Sleep(1);
			gotoxy(41.5,9);
			printf("3.-Centro Universitario: %s",age[busca-1].aca[busca-1].uni);
			Sleep(1);
			gotoxy(41.5,10);
			printf("4.-Semestre: %d",age[busca-1].aca[busca-1].semestre);
			Sleep(1);
			gotoxy(41.5,11);
			printf("5.-Maestro(a): %s",age[busca-1].aca[busca-1].maestro);
			Sleep(1);
			gotoxy(41.5,12);
			printf("6.-Materia: %s",age[busca-1].aca[busca-1].materia);
			Sleep(1);
			gotoxy(41.5,13);
			printf("7.-NRC: %d",age[busca-1].aca[busca-1].nrc);
			Sleep(1);
			gotoxy(41.5,14);
			printf("8.-Cr%cditos:  %d",130,age[busca-1].aca[busca-1].creditos);
			Sleep(1);
			gotoxy(41.5,15);
			printf("9.-Secci%cn:  %s",162,age[busca-1].aca[busca-1].seccion);
			Sleep(1);
			gotoxy(41.5,16);
			printf("10.-Calificaci%cn: %.2f",162,age[busca-1].aca[busca-1].cal);
			Sleep(1);
			gotoxy(22,22);
			printf("Presione <enter> para regresar al men%c",163);
			getch();

		}
	} else if(cont==0) {
		system("cls");
		system("COLOR 47");
		cuadro(0,0,79,24);
		cuadro(27.5,10,49.5,14);
		gotoxy(29.5,12);
		printf("NO HAY DATOS TODAV%cA",214);
		gotoxy(22,18);
		printf("Presione <enter> para volver al men%c",163);
		getch();
		carga();
	}
}

void actualizar() {
	int act,opc,opc1;
	system("cls");
	cuadro(0,0,79,24);
	titulo();
	gotoxy(25.5,4);
	printf("Elegiste la opci%cn actualizar",162);
	cuadro(7.5,8.5,74.5,12.5);
	gotoxy(9.5,10.5);
	printf("Ingrese el n%cmero de registro del alumno que quiere actualizar: ",163);
	scanf("%d",&act);
	system("cls");
	cuadro(0,0,79,24);
	titulo();
	gotoxy(28.5,6);
	printf("%cQu%c deseas actualizar?",168,130);
	cuadro(27.5,8,49.5,15);
	gotoxy(29.5,10);
	printf("1.-Agenda del alumno");
	gotoxy(29.5,12);
	printf("2.-Datos acad%cmicos",130);
	gotoxy(29.5,17);
	printf("Elige una opci%cn: ",162);
	scanf("%d",&opc);
	system("cls");
	if(opc==1) {
		cuadro(0,0,79,24);
		cuadro(1,1,78,3);
		gotoxy(26.5,2);
		printf("A C T U A L I Z A R D A T O S\n");
		gotoxy(30,4);
		printf("AGENDA DE ALUMNOS\n\n");
		gotoxy(28.5,6);
		printf("%cQu%c campo deseas actualizar?",168,130);
		cuadro(32,7,54,20);
		gotoxy(35,9);
		printf("1.-Nombre");;
		gotoxy(35,10);
		printf("2.-Edad");
		gotoxy(35,11);
		printf("3.-Sexo(M/F)");
		gotoxy(35,12);
		printf("4.-Domiciclio");
		gotoxy(35,13);
		printf("5.-Fraccionamiento");
		gotoxy(35,14);
		printf("6.-Ciudad");
		gotoxy(35,15);
		printf("7.-C%cdigo Postal",162);
		gotoxy(35,16);
		printf("8.-Tel%cfono",130);
		gotoxy(35,17);
		printf("9.-E_Mai");
		gotoxy(35,18);
		printf("10.-Notas");
		gotoxy(35.5,22);
		printf("Opci%cn: ",162);
		scanf("%d",&opc1);
		system("cls");
		switch(opc1) {
			case 1:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Nombre actual: %s",age[act-1].nombre);
				gotoxy(4,10);
				printf("Ingrese el nuevo nombre: ");
				gets(age[act-1].nombre);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 2:
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				fflush(stdin);
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Edad actual: %s",age[act-1].edad);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].edad);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);;
				break;
			case 3:
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				fflush(stdin);
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Sexo actual: %s",age[act-1].sexo);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].sexo);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 4:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Domicilio actual: %s",age[act-1].domicilio);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].domicilio);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 5:
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				fflush(stdin);
				gotoxy(4,5);
				printf("Fraccionamiento actual: %s",age[act-1].fracc);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].fracc);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 6:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Ciudad actual: %s",age[act-1].ciudad);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].ciudad);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 7:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("C%cdigo Postal actual: %s",162,age[act-1].cp);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].cp);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 8:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Tel%cfono actual: %s",130,age[act-1].tel);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].tel);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 9:
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				fflush(stdin);
				gotoxy(4,5);
				printf("E_Mail actual: %s",age[act-1].email);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].email);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 10:
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				fflush(stdin);
				gotoxy(4,5);
				printf("Notas actuales: %s",age[act-1].notas);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].notas);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			default:
				printf("Seleccione una opci%cn v%clida",162,160);
		}
		gotoxy(22,18);
		printf("Presione <enter> para regresar al men%c",163);
		getch();
		carga();
	} else if(opc==2) {
		cuadro(0,0,79,24);
		cuadro(1,1,78,3);
		gotoxy(26.5,2);
		printf("A C T U A L I Z A R D A T O S\n");
		gotoxy(38.5,5);
		printf("DATOS ACAD%cMICOS\n\n",144);
		gotoxy(28.5,6);
		printf("%cQu%c campo deseas actualizar?",168,130);
		cuadro(32,7,59,20);
		gotoxy(35,9);
		printf("1.-C%cdigo",162);
		gotoxy(35,10);
		printf("2.-Carrera");
		gotoxy(35,11);
		printf("3.-Centro Universitario");
		gotoxy(35,12);
		printf("4.-Semestre");
		gotoxy(35,13);
		printf("5.-Maestro(a)");
		gotoxy(35,14);
		printf("6.-Materia");
		gotoxy(35,15);
		printf("7.-NRC");
		gotoxy(35,16);
		printf("8.-Cr%cditos",130);
		gotoxy(35,17);
		printf("9.-Secci%cn",162);
		gotoxy(35,18);
		printf("10.-Calificaci%cn",162);
		gotoxy(35.5,22);
		printf("Opci%cn: ",162);
		scanf("%d",&opc1);
		system("cls");
		switch(opc1) {
			case 1:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("C%cdigo actual: %d",162,age[act-1].aca[act-1].codigo);
				gotoxy(4,10);
				printf("Ingrese el nuevo nombre: ");
				scanf("%d",&age[act-1].aca[act-1].codigo);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 2:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Carrera actual: %s",age[act-1].aca[act-1].carrera);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].aca[act-1].carrera);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 3:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Centro Universitario actual: %s",age[act-1].aca[act-1].uni);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].aca[act-1].uni);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 4:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Semestre actual: %d",age[act-1].aca[act-1].semestre);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				scanf("%d",&age[act-1].aca[act-1].semestre);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 5:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Maestro(a) actual: %s",age[act-1].aca[act-1].maestro);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].aca[act-1].maestro);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 6:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Materia actual: %s",age[act-1].aca[act-1].materia);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].aca[act-1].materia);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 7:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("NRC actual: %d",age[act-1].aca[act-1].nrc);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				scanf("%d",&age[act-1].aca[act-1].nrc);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 8:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Cr%cditos actuales: %d",130,age[act-1].aca[act-1].creditos);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				scanf("%d",&age[act-1].aca[act-1].creditos);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 9:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Secci%cn actual: %s",162,age[act-1].aca[act-1].seccion);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				gets(age[act-1].aca[act-1].seccion);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			case 10:
				fflush(stdin);
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				cuadro(3,9,77,11);
				gotoxy(4,5);
				printf("Calificaci%cn actual: %f",162,age[act-1].aca[act-1].cal);
				gotoxy(4,10);
				printf("Ingrese el nuevo dato: ");
				scanf("%f",&age[act-1].aca[act-1].cal);
				carga();
				system("cls");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				gotoxy(23.5,10.5);
				printf("%c%c Se actualiz%c perfectamente !!",173,173,162);
				break;
			default:
				system("COLOR 47");
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("A C T U A L I Z A R  D A T O S\n");
				cuadro(3,4,77,6);
				gotoxy(25.5,10.5);
				printf("Seleccione una opci%cn v%clida",162,160);
		}
		gotoxy(22,18);
		printf("Presione <enter> para regresar al men%c",163);
		getch();
		carga();
	}
}
void borrar() 
{
	int borrar,opc,opc1,opc2,opc3,opc4, i;
	system("cls");
	if(cont!=0) 
	{
		fflush(stdin);
		cuadro(0,0,79,24);
		titulo();
		gotoxy(25.5,4);
		printf("Elegiste la opci%cn borrar",162);
		cuadro(27.5,8,49.5,15);
		gotoxy(29.5,10);
		printf("1.-Registro");
		gotoxy(29.5,12);
		printf("2.-Campo",130);
		gotoxy(29.5,17);
		printf("Elige una opci%cn: ",162);
		scanf("%d",&opc);
		if(opc==1) 
		{
			system("cls");
			cuadro(0,0,79,24);
			cuadro(1,1,78,3);
			cuadro(7.5,5,77,7);
			gotoxy(26.5,2);
			printf("E L I M I N A R  D A T O S\n");
			gotoxy(25.5,4);
			printf("Elegiste borrar registro");
			fflush(stdin);
			gotoxy(8.5,6);
			printf("Por favor ingrese el n%cmero de registro que desea borrar: ",163);
			scanf("%d",&borrar);
			cuadro(3,8,77,10);
			gotoxy(4,9);
			printf("El registro actual es de %s",age[borrar-1].nombre);
			fflush(stdin);
			gotoxy(16.5,13);
			printf("%cSeguro(a) que quieres borrar este registro?",168);
			gotoxy(38.5,15);
			printf("1.-S%c",161);
			gotoxy(38.5,16);
			printf("2-No");
			gotoxy(35.5,22);
			printf("Opci%cn: ",162);
			scanf("%d",&opc2);
			fflush(stdin);
			system("cls");
			switch(opc2) 
			{
				case 1:
					//mover los elementos del arreglo para "llenar" el espacio vacío
					for (i = borrar-1; i <= 9; i++) 
					{
						//mover los elementos de egenda del alumno
						strcpy(age[i].nombre, age[i+1].nombre);
						strcpy(age[i].edad, age[i+1].edad);
						strcpy(age[i].sexo, age[i+1].sexo);
						strcpy(age[i].domicilio, age[i+1].domicilio);
						strcpy(age[i].fracc, age[i+1].fracc);
						strcpy(age[i].ciudad, age[i+1].ciudad);
						strcpy(age[i].cp, age[i+1].cp);
						strcpy(age[i].tel, age[i+1].tel);
						strcpy(age[i].email, age[i+1].email);
						strcpy(age[i].notas, age[i+1].notas);

						//mover los elementos de datos academicos
						age[i].aca[i].codigo = age[i+1].aca[i+1].codigo;
						strcpy(age[i].aca[i].carrera, age[i+1].aca[i+1].carrera);
						strcpy(age[i].aca[i].uni, age[i+1].aca[i+1].uni);
						age[i].aca[i].semestre = age[i+1].aca[i+1].semestre;
						strcpy(age[i].aca[i].maestro, age[i+1].aca[i+1].maestro);
						strcpy(age[i].aca[i].materia, age[i+1].aca[i+1].materia);
						age[i].aca[i].nrc = age[i+1].aca[i+1].nrc;
						age[i].aca[i].creditos = age[i+1].aca[i+1].cal;
						strcpy(age[i].aca[i].seccion, age[i+1].aca[i+1].seccion);
						age[i].aca[i].creditos = age[i+1].aca[i+1].creditos;
					}

					//agenda de alumno
					strcpy(age[cont].nombre, "");
					strcpy(age[cont].edad, "");
					strcpy(age[cont].sexo, "");
					strcpy(age[cont].domicilio, "");
					strcpy(age[cont].fracc, "");
					strcpy(age[cont].ciudad, "");
					strcpy(age[cont].cp, "");
					strcpy(age[cont].tel, "");
					strcpy(age[cont].email, "");
					strcpy(age[cont].notas, "");
					//datos académicos
					age[cont].aca[cont].codigo=0;
					strcpy(age[cont].aca[cont].carrera, "");
					strcpy(age[cont].aca[cont].uni, "");
					age[cont].aca[cont].semestre=0;
					strcpy(age[cont].aca[cont].maestro, "");
					strcpy(age[cont].aca[cont].materia, "");
					age[cont].aca[cont].nrc=0;
					age[cont].aca[cont].cal=0;
					strcpy(age[cont].aca[cont].seccion, "");
					age[cont].aca[cont].creditos=0;

					//restarle uno al contador, para permitir una nueva escritura
					cont-=1;

					cuadro(0,0,79,24);
					cuadro(1,1,78,3);
					gotoxy(26.5,2);
					printf("E L I M I N A R  D A T O S\n");
					gotoxy(23.5,10.5);
					printf("%c%c Se elimin%c perfectamente !!",173,173,162);
					break;

				case 2:
					cuadro(0,0,79,24);
					cuadro(1,1,78,3);
					gotoxy(26.5,2);
					printf("E L I M I N A R  D A T O S\n");
					gotoxy(25.5,10.5);
					printf("Elegiste no borrar los datos");
					break;
				default:
					cuadro(0,0,79,24);
					cuadro(1,1,78,3);
					gotoxy(26.5,2);
					printf("E L I M I N A R  D A T O S\n");
					gotoxy(25.5,10.5);
					printf("Escoge una opción v%clida",160);
			}
			gotoxy(22,18);
			printf("Presione <enter> para volver al men%c",163);
			getch();
			carga();
		} 	
		else if(opc==2) 
		{
			system("cls");
			cuadro(0,0,79,24);
			cuadro(1,1,78,3);
			cuadro(7.5,5,77,7);
			gotoxy(26.5,2);
			printf("E L I M I N A R  D A T O S\n");
			gotoxy(25.5,4);
			printf("Elegiste borrar campo");
			gotoxy(8.5,6);
			printf("Por favor ingrese el n%cmero de registro que desea borrar: ",163);
			scanf("%d",&borrar);
			system("cls");
			cuadro(0,0,79,24);
			cuadro(1,1,78,3);
			gotoxy(26.5,2);
			printf("E L I M I N A R  D A T O S\n");
			gotoxy(25.5,4);
			printf("%cDe qu%c deseas borrar un campo?",168,130);
			cuadro(27.5,8,49.5,15);
			gotoxy(29.5,10);
			printf("1.-Agenda del alumno");
			gotoxy(29.5,12);
			printf("2.-Datos acad%cmicos",130);
			gotoxy(29.5,17);
			printf("Elige una opci%cn: ",162);
			scanf("%d",&opc1);
			system("cls");
			if(opc1==1) 
			{
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("E L I M I N A R  D A T O S\n");
				gotoxy(30,4);
				printf("AGENDA DE ALUMNOS\n\n");
				gotoxy(25.5,4);
				printf("%cQu%c campo deseas borrar?",168,130);
				cuadro(32,7,54,20);
				gotoxy(35,9);
				printf("1.-Nombre");;
				gotoxy(35,10);
				printf("2.-Edad");
				gotoxy(35,11);
				printf("3.-Sexo(M/F)");
				gotoxy(35,12);
				printf("4.-Domiciclio");
				gotoxy(35,13);
				printf("5.-Fraccionamiento");
				gotoxy(35,14);
				printf("6.-Ciudad");
				gotoxy(35,15);
				printf("7.-C%cdigo Postal",162);
				gotoxy(35,16);
				printf("8.-Tel%cfono",130);
				gotoxy(35,17);
				printf("9.-E_Mai");
				gotoxy(35,18);
				printf("10.-Notas");
				gotoxy(35.5,22);
				printf("Opci%cn: ",162);
				fflush(stdin);
				scanf("%d",&opc2);
				system("cls");
				switch(opc2) 
				{
					case 1:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Nombre actual: %s",age[borrar-1].nombre);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].nombre,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 2:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Edad actual: %s",age[borrar-1].edad);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].edad,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 3:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Sexo actual: %s",age[borrar-1].sexo);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].sexo,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 4:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Domicilio actual: %s",age[borrar-1].domicilio);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].domicilio,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 5:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Fraccionamiento actual: %s",age[borrar-1].fracc);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].fracc,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 6:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Ciudad actual: %s",age[borrar-1].ciudad);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].ciudad,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 7:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("C%cdigo Postal actual: %s",162,age[borrar-1].cp);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].cp,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 8:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Tel%cfono actual: %s",130,age[borrar-1].tel);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].tel,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 9:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("E_Mail actual: %s",age[borrar-1].email);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].email,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 10:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Notas actuales: %s",age[borrar-1].notas);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].notas,"");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					default:
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						gotoxy(23.5,10.5);
						printf("Seleccione una opci%cn v%clida",162,160);
				}
				gotoxy(22,18);
				printf("Presione <enter> para regresar al men%c",163);
				getch();
				carga();
			} else if(opc==2) 
			{
				cuadro(0,0,79,24);
				cuadro(1,1,78,3);
				gotoxy(26.5,2);
				printf("E L I M I N A R  D A T O S\n");
				gotoxy(38.5,5);
				printf("DATOS ACAD%cMICOS\n\n",144);
				gotoxy(25.5,4);
				printf("%cQu%c campo deseas borrar?",168,130);
				cuadro(32,7,59,20);
				gotoxy(38.5,5);
				printf("DATOS ACAD%cMICOS\n\n",144);
				gotoxy(28.5,6);
				printf("%cQu%c campo deseas actualizar?",168,130);
				cuadro(32,7,59,20);
				gotoxy(35,9);
				printf("1.-C%cdigo",162);
				gotoxy(35,10);
				printf("2.-Carrera");
				gotoxy(35,11);
				printf("3.-Centro Universitario");
				gotoxy(35,12);
				printf("4.-Semestre");
				gotoxy(35,13);
				printf("5.-Maestro(a)");
				gotoxy(35,14);
				printf("6.-Materia");
				gotoxy(35,15);
				printf("7.-NRC");
				gotoxy(35,16);
				printf("8.-Cr%cditos",130);
				gotoxy(35,17);
				printf("9.-Secci%cn",162);
				gotoxy(35,18);
				printf("10.-Calificaci%cn",162);
				gotoxy(35.5,22);
				printf("Opci%cn: ",162);
				fflush(stdin);
				scanf("%d",&opc2);
				system("cls");
				switch(opc2) 
				{
					case 1:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("C%cdigo actual: %d",162,age[borrar-1].aca[borrar-1].codigo);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							age[borrar-1].aca[borrar-1].codigo=0;
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 2:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Carrera actual: %s",age[borrar-1].aca[borrar-1].carrera);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].aca[borrar-1].carrera," ");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 3:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Centro Universitario actual: %s",age[borrar-1].aca[borrar-1].uni);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].aca[borrar-1].uni," ");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 4:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Semestre actual: %d",age[borrar-1].aca[borrar-1].semestre);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							age[borrar-1].aca[borrar-1].semestre=0;
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 5:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Maestro(a) actual: %s",age[borrar-1].aca[borrar-1].maestro);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].aca[borrar-1].maestro," ");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 6:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Materia actual: %s",age[borrar-1].aca[borrar-1].materia);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].aca[borrar-1].materia," ");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 7:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("NRC actual: %d",age[borrar-1].aca[borrar-1].nrc);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							age[borrar-1].aca[borrar-1].nrc=0;
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 8:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Cr%cditos actuales: %d",130,age[borrar-1].aca[borrar-1].creditos);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							age[borrar-1].aca[borrar-1].creditos=0;
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						}
					case 9:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Secci%cn actual: %s",162,age[borrar-1].aca[borrar-1].seccion);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							strcpy(age[borrar-1].aca[borrar-1].seccion," ");
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						};
						break;
					case 10:
						fflush(stdin);
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						cuadro(3,4,77,6);
						gotoxy(4,5);
						printf("Calificaci%cn actual: %f",162,age[borrar-1].aca[borrar-1].cal);
						gotoxy(16.5,13);
						printf("%cSeguro(a) que quieres borrar este registro?",168);
						gotoxy(38.5,15);
						printf("1.-S%c",161);
						gotoxy(38.5,16);
						printf("2-No");
						gotoxy(35.5,22);
						printf("Opci%cn: ",162);
						scanf("%d",&opc3);
						if(opc3==1) 
						{
							age[borrar-1].aca[borrar-1].cal=0;
							system("cls");
							cuadro(0,0,79,24);
							cuadro(1,1,78,3);
							gotoxy(26.5,2);
							printf("E L I M I N A R  D A T O S\n");
							gotoxy(23.5,10.5);
							printf("%c%c Se elimin%c perfectamente !!",173,173,162);
						}
					default:
						system("cls");
						cuadro(0,0,79,24);
						cuadro(1,1,78,3);
						gotoxy(26.5,2);
						printf("E L I M I N A R  D A T O S\n");
						gotoxy(23.5,10.5);
						printf("Seleccione una opci%cn v%clida",162,160);
				}
				gotoxy(22,18);
				printf("Presione <enter> para regresar al men%c",163);
				getch();
				carga();
			}
		}
	}
	else if(cont == 0) 
	{
		system("cls");
		system("COLOR 47");
		cuadro(0,0,79,24);
		cuadro(27.5,10,49.5,14);
		gotoxy(29.5,12);
		printf("NO HAY DATOS TODAV%cA",214);
		gotoxy(22,18);
		printf("Presione <enter> para volver al men%c",163);
		getch();
		carga();
	}
}



void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X= x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

void cuadro(int x1, int y1, int x2, int y2) {
	int i;
	for(i=x1; i<=x2; i++) {
		gotoxy(i,y1);
		printf("%c",196);
		gotoxy(i,y2);
		printf("%C",196);
	}
	for(i=y1; i<=y2; i++) {
		gotoxy(x1,i);
		printf("%c",179);
		gotoxy(x2,i);
		printf("%c",179);
	}
	gotoxy(x1,y1);
	printf("%c",218);
	gotoxy(x2,y2);
	printf("%c",217);
	gotoxy(x2,y1);
	printf("%c",191);
	gotoxy(x1,y2);
	printf("%c",192);
}

void titulo() {
	cuadro(0,0,79,24);
	cuadro(1,1,78,3);
	gotoxy(30.5,2);
	printf("B A S E  D E  D A T O S\n");
}

void salir() {
	int i;
	cuadro(0,0,79,24);
	gotoxy(21,10);
	printf("S A L I E N D O  D E L  S I S T E M A");
	for(i=3; i<=76; i++) {
		gotoxy(i,12);
		printf("%c",177);
	}
	for(i=3; i<=76; i++) {
		gotoxy(i,12);
		printf("%c",219);
		Sleep(35);
	}
	system("cls");
	cuadro(0,0,79,24);
	gotoxy(13.5,12);
	printf("G R A C I A S  P O R  U S A R  E L  P R O G R A M A");
	Sleep(4000);

}

void pantalla(int x1, int y1, int x2, int y2)
{
	int i;
	for(i=x1; i<=x2; i++) {
		gotoxy(i,y1);
		printf("%c",205);
		gotoxy(i,y2);
		printf("%C",205);
	}
	for(i=y1; i<=y2; i++) {
		gotoxy(x1,i);
		printf("%c",186);
		gotoxy(x2,i);
		printf("%c",186);
	}
	gotoxy(x1,y1);
	printf("%c",205);
	gotoxy(x2,y2);
	printf("%c",188);
	gotoxy(x2,y1);
	printf("%c",187);
	gotoxy(x1,y2);
	printf("%c",200);
}
