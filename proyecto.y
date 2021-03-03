%{
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "y.tab.h"
int yylval;
int yystopparser = 0;
FILE *yyin;
char *yyltext;
char *yytext;
int yylex();
int yyerror(char *);
%}

%token ID
%token P_RESERVADO NUMERAL S_MENOR S_MAYOR A_PARENTESIS C_PARENTESIS A_LLAVES C_LLAVES A_CORCHETESC_CORCHETES CIERRE_INSTRUCCION COMA ASIGNACION
%token INCREMENTO OPERADORES TIPO_DATO FOR IF ELSE DO WHILE SWITCH BREAK LIBRERIA LETRA DIGITO RETURN ENTERO S_ADMIRACION CASE GETCH

%%
programa   	: asignacion { printf("Compilacion OK\n"); }
;

asignacion 	: ID ASIGNACION expresion
;

%%


int main(int argc,char *argv[]) {
  if ((yyin = fopen(argv[1], "rt")) == NULL) {
		printf("\nNo se puede abrir el archivo: %s\n", argv[1]);
  } else {
		yyparse();
  }
  fclose(yyin);
  return 0;
}

int yyerror(char *error) {
	printf("Syntax Error\n");
	exit (1);
}
