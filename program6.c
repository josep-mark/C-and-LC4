#define MAX_LEN 30

/* TRAP wrapper function declarations */
void lc4_putc(char c) ;
void lc4_puts(char* string) ;

int main() {

  	int i = 0 ;
  	char* str1="A stRiNg83" ;
    char* str2 = "Another string93489";
	
    lc4_puts(str1);
    lc4_putc('\n');
    lc4_strupper(str1);
    lc4_puts(str1);
    lc4_putc('\n');

    lc4_puts(str2);
    lc4_putc('\n');
    lc4_strupper_ptr(str2);
    lc4_puts(str2);
	return 0 ;


}
