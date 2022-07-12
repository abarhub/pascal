#include <stdio.h>

extern void test1_asm(void);

int main(int argc,char *argv) {

	printf("Test pascal asm\n");

	test1_asm();

	printf("Fin du test\n");
	return 0;

}