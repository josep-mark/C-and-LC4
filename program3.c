#define MAX_LEN 30

/* TRAP wrapper function declarations */
void lc4_putc(char c) ;
void lc4_puts(char* string) ;

int main() {

  	int i = 0 ;
  	char* str1="a string" ;
	  char str2[MAX_LEN] = {'T','h','i','s',' ','i','s','\0'} ;
    char str3[MAX_LEN] ={'\0'} ;
    char str4[MAX_LEN] ={'\0'} ;
    char str5[MAX_LEN] = {'T','h','i','s',' ','i','s','\0'} ;

    
    lc4_strcat(str2, str1);
    lc4_puts(str2);
    lc4_putc('\n');
    lc4_puts(str1);

    i = lc4_strlen (str1) ;
    lc4_itoa(i, str3) ;
    lc4_puts (", length = ") ; lc4_puts (str3) ; lc4_putc('\n') ;

    lc4_puts(str2);
    i = lc4_strlen(str2) ;
    lc4_itoa(i, str4) ;
    lc4_puts (", length = ") ; lc4_puts (str4) ; lc4_putc('\n') ;

    lc4_strcat_ptrs(str5, str1);
    lc4_puts(str5);
    i = lc4_strlen(str5) ;
    lc4_itoa(i, str4) ;
    lc4_puts (" length = ") ; lc4_puts (str4) ; lc4_putc('\n') ;

    
    

	return 0 ;
}
