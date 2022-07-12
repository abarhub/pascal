#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void internal_error(char *s,int a1,int a2,int a3,int a4);

char  *create_string(char *s)
{
    char *p = (char *) malloc(strlen(s) + 1);
    if(p==NULL) internal_error("Cannot malloc in create-string",0,0,0,0);
    strcpy(p,s);
    return p;
}

int max1(int a,int b)
{
    return  (a>b) ? a : b;
}

char *token_name(int i)
{
    static char buf[10];
    switch(i)
    {
	default  : if(i<256)
		   {
		       if(i<32 || i>126)
			   sprintf(buf, "0%o", i);
		       else
		           sprintf(buf, "'%c'", i);
		       return buf;
		   }
		   else
		       return("<Unknown token>");
	case   0 : return("<End of input>");
    }
}