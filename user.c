#include <libc.h>

char buff[24];

int pid;

int add(int par1, int par2) {
	/*asm("movl 8(%ebp), %eax;"
		"addl 12(%ebp), %eax;"
		);*/

	int result;
	asm("movl 8(%%ebp), %0;"
		"addl 12(%%ebp), %0;"
		:"=r"(result)
		);
	return result;
}

long inner (long n){
	int i;
	long suma;
	suma = 0;
	for(i=0; i<n; i++) suma = suma+i;
	return suma;
}

long outer (long n)
{
	int i;
	long acum;
	acum = 0;
	for (i = 0; i < n; ++i)
	{
		acum = acum + inner(i);
	}
	return acum;
}

int __attribute__ ((__section__(".text.main")))
  main(void)
{
    /* Next line, tries to move value 0 to CR3 register. This register is a privileged one, and so it will raise an exception */
     /* __asm__ __volatile__ ("mov %0, %%cr3"::"r" (0) ); */

	write(1, "Lorem ipsuin vulputate. Pe rhoncus liauctor faucibus sapien metus. ", 10);
 	while(1){

 		int ticks = gettime();
 		char ticks_s[4];
 		itoa(ticks, ticks_s);
 		write(1, ticks_s, strlen(ticks_s));
		write(1, "\n", 1); 

 	}
 	return 0;
}
