%{
#include <stdio.h>
#include <stdlib.h>
int regs[26];
int base;
double answer;
int yylex();
int yyerror(char *s);
int yywrap();
%}

%start list
%union {
  double a;
  char c;
}
%type <a> expr number DIGIT
%type <c> LETTER
%token DIGIT LETTER
%token EXIT
%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS

%%

list: /* empty */
    | list stat '\n'
    | list error '\n' {
      yyerrok;
    };

stat: expr {
        printf("%f\n", $1);
      }
    | LETTER '=' expr {
      regs[$1] = $3;
    };

expr: '(' expr ')' {
        $$ = $2;
        answer = $2;
      }
    | expr '*' expr {
        $$ = $1 * $3;
        answer = $$;
      }
    | '*' expr {
        $$ = answer * $2;
        answer = $$;
    }
    | expr '/' expr {
        $$ = $1 / $3;
        answer = $$;
      }
    | '/' expr {
        $$ = answer / $2;
        answer = $$;
      }
    | expr '+' expr {
        $$ = $1 + $3;
        answer = $$;
      }
    | '+' expr {
        $$ = answer + $2;
        answer = $$;
    }
    | expr '-' expr {
        $$ = $1 - $3;
        answer = $$;
      }
    | '-' expr {
        $$ = answer - $2;
        answer = $$;
    }
    | '-' expr %prec UMINUS {
        $$ = -$2;
        answer = $$;
      }
    | LETTER {
        $$ = regs[$1];
      }
    | number;
    | EXIT {
      return EXIT_SUCCESS;
    }

number: DIGIT {
          $$ = $1;
      };
%%

int main() {
  printf("Enter an expression: ");
  return yyparse();
}

int yyerror(char *s) {
  fprintf(stderr, "%s\n", s);
  return 1;
}

int yywrap() {
  return 1;
}
