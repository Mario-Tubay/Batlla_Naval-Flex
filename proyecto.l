%{
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "y.tab.h"
%}
LETRA		[a-zA-Z]
ID		{LETRA}({LETRA}|{DIGITO}|_)*

%%

"include"|"INCLUDE"|"define"|"DEFINE"|"main"|"void"|"srand"|"rand" {return P_RESERVADO;}
"return"|"RETURN"|"Return" {return RETURN;}

"#" {return NUMERAL;}
"<" {return S_MENOR;}
">"  {return S_MAYOR;}
"(" {return A_PARENTESIS;}
")" {return C_PARENTESIS;}
"{" {return A_LLAVES;}
"}" {return C_LLAVES;}
"[" {return A_CORCHETES;}
"]" {return C_CORCHETES;}
";" {return CIERRE_INSTRUCCION;}
"," {return COMA;}
"=" {return ASIGNACION;}
"ID" {return ID}
"++" {return INCREMENTO;}
"!"   {return S_ADMIRACION}

"*"|"+"|"-"|"/" {return OPERADORES;}

"int"|"char"			 {return TIPO_DATO;}
"for"                             {return FOR;}
"if"                              {return IF;}
"else"                            {return ELSE}
"do"                              {return DO;}
"while"                           {return WHILE;}
"switch"                          {return SWITCH;}
"break"                           {return BREAK;}
"case"                            {return CASE;}
"getch"                           {return GETCH;}

"stdio.h"|"STDIO.H"|"conio.h"|"CONIO.H"|"stdlib.h"|"STDLIB.H"|"time.h"|"TIME.H"  { return LIBRERIA;}
%%

