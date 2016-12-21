#define MAX_LEN 30

/* TRAP wrapper function declarations */
void lc4_putc(char c) ;
void lc4_puts(char* string) ;

int main() {

  	int i = 0 ;
  	char* str1="a string" ;
	char str2[MAX_LEN] = {'a',' ','v','t','r','i','n','g'} ;
    char str3[MAX_LEN] = {'\0'};
    char str4[MAX_LEN] = {'\0'};
    int result;
    int result1;
    int result2;
    int result3;
    int result4;
    int result5;

    result = lc4_strcmp(str1, str2);
    lc4_itoa(result, str3); 
    lc4_puts(str1);
    lc4_puts(" Compared to ");
    lc4_puts(str2);
    lc4_putc('\n');
    lc4_puts(str3);
    lc4_putc('\n'); 

    result1 = lc4_strcmp(str2, str1);
    lc4_itoa(result1, str3); 
    lc4_puts(str2);
    lc4_puts(" Compared to ");
    lc4_puts(str1);
    lc4_putc('\n');
    lc4_puts(str3); 
    lc4_putc('\n');

    result2 = lc4_strcmp(str1, str1);
    lc4_itoa(result2, str3); 
    lc4_puts(str1);
    lc4_puts(" Compared to ");
    lc4_puts(str1);
    lc4_putc('\n');
    lc4_puts(str3); 
    lc4_putc('\n');

    result3 = lc4_strcmp_ptr(str1, str2);
    lc4_itoa(result3, str4); 
    lc4_puts(str1);
    lc4_puts(" Compared to ");
    lc4_puts(str2);
    lc4_putc('\n');
    lc4_puts(str4); 
    lc4_putc('\n');

    result4 = lc4_strcmp_ptr(str2, str1);
    lc4_itoa(result4, str4); 
    lc4_puts(str2);
    lc4_puts(" Compared to ");
    lc4_puts(str1);
    lc4_putc('\n');
    lc4_puts(str4); 
    lc4_putc('\n');

    result5 = lc4_strcmp_ptr(str1, str1);
    lc4_itoa(result5, str4); 
    lc4_puts(str1);
    lc4_puts(" Compared to ");
    lc4_puts(str1);
    lc4_putc('\n');
    lc4_puts(str4); 
    lc4_putc('\n');


	return 0 ;
}
