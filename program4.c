#define MAX_LEN 30

/* TRAP wrapper function declarations */
void lc4_putc(char c) ;
void lc4_puts(char* string) ;

int main() {

  	int i = 0 ;
  	char* str1="A string" ;
	  char* str2 = "String reversal" ;
      

    lc4_puts(str2);
    lc4_putc('\n');
    lc4_puts("And the reverse is ");
    lc4_putc('\n');
    lc4_strrev(str2);
    lc4_puts(str2);
    lc4_putc('\n');

  lc4_puts(str2);
  lc4_putc('\n');
  lc4_puts("And the reverse is ");
  lc4_putc('\n');
  lc4_strrev_ptr(str2);
  lc4_puts(str2);

    

	return 0 ;
}
