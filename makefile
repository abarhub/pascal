SRC = pascal.tab.c lexyy.c misc.c arbre.c verifi.c genere.c genere_asm86.c genere_jvm.c table_symbol.c
PARSE = pascal.tab.c
LEX = lexyy.c
SRC1 = misc.c arbre.c verifi.c genere.c genere_asm86.c genere_jvm.c table_symbol.c type.c
SRC2 = $(PARSE) $(LEX) $(SRC1)
OBJ = $(SRC2:.c=.obj)

OPT = -y -v /q

all3: $(OBJ)
	bcc32 $(OPT) /q -epascal $**

#	ilink32 /v /q  $**  , pascal.exe, , cw32.lib import32.lib
# c0d32.obj

pascal.tab.obj: pascal.y
	bison -d pascal.y
	bcc32 $(OPT) -c pascal.tab.c

lexyy.obj: pascal.l pascal.tab.h
	flex pascal.l
	bcc32 $(OPT) -c lexyy.c

.c.obj:
	bcc32 $(OPT) -c $<

all:
	bison -d pascal.y
	flex pascal.l
	bcc32 -v -y -epascal $(SRC)

all2:
	bison -d pascal.y
	flex pascal.l
	redir -o toto.txt bcc32 -v -y -epascal $(SRC)

run:
	pascal <test1.pas