%start commands

%token SETTOKEN DRAWTOKEN COLORTOKEN
%token LOCATIONTOKEN CIRCLETOKEN RECTANGLETOKEN
%token SEMICOLON LEFTPAREN RIGHTPAREN COMMA
%token NUMBER NAME

%%

commands:
  /* nothing
   */
  | commands command
  ;

command: SETTOKEN set SEMICOLON
  | DRAWTOKEN draw SEMICOLON
  ;

set: COLORTOKEN NAME
    { setcolor($2); }
  | LOCATIONTOKEN LEFTPAREN NUMBER COMMA NUMBER RIGHTPAREN
    { setlocation($3,$5); }
  ;
draw: CIRCLETOKEN NUMBER
    { drawcircle($2);}
  | RECTANGLETOKEN LEFTPAREN NUMBER COMMA NUMBER RIGHTPAREN
    { drawrectangle($3,$5); }
  ;

%%
