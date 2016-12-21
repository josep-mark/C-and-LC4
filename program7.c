#define MAX_LEN 30

/* TRAP wrapper function declarations */
void lc4_putc(char c) ;
void lc4_puts(char* string) ;

int main() {

  	int i = 0 ;
  	char* str1="A stRiNg83" ;
    char str2[MAX_LEN];

    lc4_gets(str2);
    lc4_puts(str2);
	
    return 0;
    


}
