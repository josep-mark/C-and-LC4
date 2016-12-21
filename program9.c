#define MAX_LEN 30

/* TRAP wrapper function declarations */
void lc4_putc(char c) ;
void lc4_puts(char* string) ;
void lc4_gets_asm(char*string) ;

int main() {

  	int i = 0 ;
  	char* str1="A stRiNg83" ;
    char str2[1] = {'s'};
    char * delimiter = lc4_strtok(str1, str2);
    
    lc4_puts(str1);
    lc4_putc('\n');
    lc4_puts("Find token with delimiter of: s");
    lc4_puts(delimiter);
    
    return 0;
    


}
