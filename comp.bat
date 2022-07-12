bcc32 -c pascal.tab.c
bcc32 -c lexyy.c
bcc32 -c misc.c
bcc32 -c arbre.c
bcc32 -c verifi.c
bcc32 -c genere.c
bcc32 -c genere_asm86.c
bcc32 -c genere_jvm.c
bcc32 -c table_symbol.c

bcc32 -epascal.exe pascal.tab.obj lexyy.obj misc.obj arbre.obj verifi.obj genere.obj genere_asm86.obj genere_jvm.obj table_symbol.obj