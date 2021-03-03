#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int menu();
void integrantes();
void llenar();
void ingresar();
void ingresarCpu();
int validar(int x, int y, int opc);
void mostrarTabla(int opc);
int atacar(int x, int y, int tipo);
void Star();
int verificarGanador(int tipo);
char marUser [10][10];
char marCpu[10][10];
char marUserJuego [10][10];
char marCpuJuego[10][10];


main(){
	do{
		switch(menu()){
			case 1:
				llenar();
			  	system("cls");
  				ingresar();
  				ingresarCpu();
		      Star();
  				getch();
			break;
			case 2:
			  system("cls");
				integrantes();
			break;
		}
	}while(menu()!=3);
}

int menu(){
	int opc =0;
	system("cls");
	printf("--------Menu--------");
	printf("\n1) Star");
	printf("\n2) Integrantes");
	printf("\n3) Salir");
	printf("\nOpcion: ");
	scanf("%i", &opc);
	return opc;
}
void ingresar(){
	int x=0;
	int y=0;
	int validado=0;
	for (int i = 0; i<4; i++){
		do{
			system("cls");
			mostrarTabla(1);
			printf("\n%i BARCO", i+1);
			printf("\nUBICACION EN X: ");
			scanf("%i", &x);
			printf("\nUBICACION EN Y: ");
			scanf("%i", &y);
			validado=validar(x,y,1);
			if(validado==2){
				printf("\nSe ingreso el %i barco exitosamente", i+1);
				printf("\nPresione cualquier tecla para continuar.....");
				getch();
			}else if(validado==1){
				printf("\nYa existe un barco en esa posicion");
				printf("\nPresione cualquier tecla para continuar.....");
				getch();
			}
		}while(validado!=2);
		validado =0;
	}
}

int validar(int x , int y, int opc){

	if(opc==1){
		if(marUser[x][y] == '@'){
			return 1;
		}else{
			marUser[x][y] = '@';
			return 2;
		}
	}else if(opc ==2){
		if(marCpu[x][y] == '@'){
			return 1;
		}else{
			marCpu[x][y] = '@';
			return 2;
		}
	}

}

void mostrarTabla(int opc){

	if(opc == 1){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if(j==9){
					printf("|\n");
				}else{
					printf("| %c ", marUser[i][j]);
				}

			}
		}
	}
	if(opc == 2){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if(j==9){
					printf("|\n");
				}else{
					printf("| %c ", marCpu[i][j]);
				}
			}
		}
	}
  if(opc == 3){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if(j==9){
					printf("|\n");
				}else{
					printf("| %c ", marCpuJuego[i][j]);
				}

			}
		}
	}
	if(opc == 4){
		for (int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if(j==9){
					printf("|\n");
				}else{
					printf("| %c ", marUserJuego[i][j]);
				}
			}
		}
	}
}

void ingresarCpu(){
	int x=0, y=0;
	int validado = 0;
	srand(time(0));
	for(int i=0; i<4;i++){
		do{
			x = rand() % 10;
			printf("\n%i",x);
			y = rand() % 10;
			printf("\n%i", y);
			getch();
			validado = validar(x,y,2);
		}while(validado !=2);
		validado =0;
	}
}

void llenar(){
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			marUser[i][j]='~';
			marCpu[i][j]='~' ;
      marUserJuego[i][j]='~';
			marCpuJuego[i][j]='~' ;
		}
	}
}

void integrantes(){
	printf("\nTUBAY SUAREZ MARIO ALBERTO");
	printf("\nSANTOS ABAD GIRET DANIEL");
	printf("\nGORDILLO");
}

void  Star(){
	int x =0, y=0, validar =0, ganador=0;
  do{
    do{
      system("cls");
      printf("****************USER***************\n");
      mostrarTabla(3);
      printf("Ingrese la cordenada en X: ");
  		scanf("%i", &x);
  		printf("Ingrese la cordenada en Y: ");
  		scanf("%i", &y);
      if(marCpuJuego[x][y]=='X'||marCpuJuego[x][y]=='*'){
        printf("Upss. Ya atacaste en esa posicion.....");
        printf("\nIntenta en otra coordenada...");
      }else{
        validar = atacar(x,y,1);
        if(validar == 1){
          printf("\nBoommm....... Barco Destruido");
          ganador = verificarGanador(1);
            if(ganador == 4){
              printf("\nFelicidades, Ganaste...");
              validar = 2;
            }
        }else{
          printf("\nNo le diste a ningun barco");
        }
      }
      getch();
  	}while(validar!=2);
    if(ganador == 4)
    {
      ganador = 4;
    }else{
    do {
      system("cls");
      printf("****************CPU***************\n");
      mostrarTabla(4);
      printf("Ingrese la cordenada en X: ");
      x = rand() % 10;
      printf("%i", x);
  		printf("\nIngrese la cordenada en Y: ");
      y = rand() % 10;
  		printf("%i", y);
      if(marUserJuego[x][y]=='X'||marUserJuego[x][y]=='*'){
        printf("Upss. Ya atacaste en esa posicion.....");
        printf("\nIntenta en otra coordenada...");
      }else{
        validar = atacar(x,y,2);
        if(validar == 1){
          printf("\nBoommm....... Barco Destruido");
          getch();
          ganador = verificarGanador(2);
          if(ganador == 5){
            ganador=2;
          }
        }else{
          printf("\nNo le diste a ningun barco");
        }
      }
      getch();
  	}while(validar!=2);
    if(ganador == 5){
      ganador =4;
    }
  }
}while(ganador!=4);
}

int atacar(int x, int y, int opc){
  if(opc == 1){
    if(marCpu[x][y]=='@'){
      marCpuJuego[x][y] = 'X';
      return 1;
    }else{
      marCpuJuego[x][y] = '*';
      return 2;
    }
  }
  if(opc == 2){
    if(marUser[x][y]=='@'){
      marUserJuego[x][y] = 'X';
      return 1;
    }else{
      marUserJuego[x][y] = '*';
      return 2;
    }
  }
}


int verificarGanador(int tipo){
  int ganUser=0, ganCpu=0;
  if(tipo == 1){
    for(int i =0; i<10;i++){
      for(int j =0; j<10; j++){
        if(marCpuJuego[i][j]=='X'){
          ganUser = ganUser+1;
        }
      }
    }
  }
  if(tipo == 2){
    for (int  i = 0; i < 100; i++) {
      for(int j =0; j<100; j++){
        if(marUserJuego[i][j]=='X'){
          ganCpu= ganCpu+1;
        }
      }
    }
  }
  if(ganUser==4){
      return 4;
  }else if(ganCpu == 4){
      return 5;
  }
}
