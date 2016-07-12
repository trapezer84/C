%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "glob.h"
#include "tn.h"

extern Symboltable();
extern Reporterror();

%}
L [a-zA-Z_]
D [0-9]
%%

"const"   return(TCONST);
"else"   return(TELSE);
"if"   return(TIF);
"int"   return(TINT);
"return"   return(TRETURN);
"void"   return(TVOID);
"while"   return(TWHILE);
"+"   return (TPLUS);
"-"   return (TMINUS);
"*"   return(TSTAR);
"/"   return (TSLASH);
"!"   return (TNOT);
"%"	return(TMOD);
"="  return(TASSIGN);
"=="   return(TEQUAL);
"!="   return(TNOTEQU);
"<="   return(TLESSE);
">="   return(TGREATE);
"&&"   return(TAND);
"||"   return(TOR);
"++"   return(TINC);
"--"   return(TDEC);
"+="   return(TADDASSIGN);
"-="   return(TSUBASSIGN);
"*="   return(TMULASSIGN);
"/="   return(TDIVASSIGN);
"%="   return(TMODASSIGN);
"<"    return(TLESS);
">"    return(TGREAT);
"("	return(TLPAREN);
")"	return(TRPAREN);
"["	return(TLBRACKET);
"]"	return(TRBRACKET);
"{"	return(TLBRACE);
"}"	return(TRBRACE);
","	return(TCOMMA);
";"	return(TSEMICOLON);
{L}({L}|{D})*   Symboltable(); return(TIDENT);
{D}+   return(TNUMBER);
{D}+{L}({D}|{L})* Reporterror(1); return(TERROR);
"/*"([^*]|\*+[^*/])*\**"*/"   ;
"//".*   ;
[ \t]   ;
"\n"   return(NEWLINE);
.   Reporterror(2); return(TERROR);
%%



