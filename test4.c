#include <stdio.h>

//extern void test1_asm(void);

int main(int argc,char *argv) 
{
	float f=8.6;
	int i=73;

	printf("Test pascal asm\n");

	//test1_asm();
	printf("int=%d\n",i);
	printf("float=%f\n",f);
	printf("Fin du test\n");
	return 0;

}