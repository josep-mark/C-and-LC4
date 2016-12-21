/* string "helper" function declarations */
void lc4_itoa (int n, char str[]) ;
int  lc4_strlen (const char str[]) ;
int  lc4_strlen_ptrs (const char *str) ;
char * lc4_strcpy(char des_str[], const char src_str[]) ;
char * lc4_strcpy_ptrs(char*des_str, const char*src_str) ;
char * lc4_strcat(char des_str[], const char src_str[]);
char * lc4_strcat_ptrs(char * des_str, char * src_str);
void lc4_strrev(char str[]);
void lc4_strrev_ptr(char * str);
int lc4_strcmp(char str1[], char str2[]);
int lc4_strcmp_ptr(char *str1, char *str2);
char * lc4_strupper(char str[]);
char * lc4_strupper_ptr(char * str);
char * lc4_gets(char str[]);
char * lc4_strtok(char * str, char * delimiters);

/* converts integers to ASCII null terminated string */
void lc4_itoa(int n, char str[]) {	/* classic K&R implementation */

	int i, sign;

	if ((sign = n) < 0)  /* record sign     */
		n = -n;          /* make n positive */
	i = 0;

	do {         /* generate digits in reverse order */
		str[i++] = n % 10 + '0';   /* get next digit */
	} while ((n /= 10) > 0);       /* delete it      */

	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';

	/* CIT 593 to do: after creating: strrev(), call it for str[]*/
	lc4_strrev(str);
}


/* calculates length of a string using array notation */
int lc4_strlen (const char str[]) {

    int length = 0;

    while (str[length] != '\0') {
		length++;
    }

    return length;
}


/* calculates length of a string using pointers */
int lc4_strlen_ptrs (const char *str) {

	const char *start_addr = str;

	while(*str) str++;

	return (str - start_addr);
}

/*Copies a source string (in a char array) into a destination string char array*/
char * lc4_strcpy(char des_str[], const char src_str[]) {
	int i = 0;
	int length = lc4_strlen(src_str);
	char * des_str_ptr = &des_str[0] ;

	/*If string is empty return null*/
	if (length == 0){
		return 0 ;
	}

	/*Copy every element in source to destination string including end null char*/
	for (i = 0; i < length; i ++){
		des_str[i] = src_str[i] ;
	} 

	return des_str_ptr ; //Return ptr to destination string
}

/*Copies a source string to a destination string using pointers*/
char * lc4_strcpy_ptrs(char*des_str, const char*src_str) {
	int length = lc4_strlen_ptrs(src_str);
	char * des_str_address = des_str;
	int count = 0 ;
	int plus;

	if (length == 0){
		return 0;
	}

	while (count < length) {
		*des_str = *src_str; //Dereference and set equal to for each element in the string
		des_str ++;	//update values of pointers and count
		src_str ++;
		count ++;

	}

	return des_str_address;	//return destination string ptr
}

/*Concatenates two strings*/
char * lc4_strcat(char des_str[], const char src_str[]){
	int cat_start = lc4_strlen(des_str); 	//destination string length
	int length_src = lc4_strlen(src_str);	//source string length
	int count = 0;							//count for source string
	int null_index = 0;						//

	for (null_index = 0; null_index < cat_start; null_index++){	//iterate destination string to find the null char 
		if (des_str[null_index] == '\0'){						//when des_strin[null_index] == '\0' break loop, null index equals index of null char
			break;
		}
	}

	while (count < length_src){							//iterate over source string
		des_str[null_index] = src_str[count];			//add source string to the end of des_string overwriting null
		null_index++;									//update values
		count++;										//update values
	}

	return des_str;										//return des_string ptr

}

/*function to concatenate using pointers*/
char * lc4_strcat_ptrs(char * des_str, char * src_str){
	int cat_start = lc4_strlen_ptrs(des_str); 			//des_string length
	int length_src = lc4_strlen_ptrs(src_str);			//src_str length
	char * des_str_address = &des_str[0];				//store des_str start address
	int count = 0;										//count for iteration
	

	des_str = des_str + cat_start ;						//update des_str to index of null pointer

	while (count < length_src){							//add src str to des str
		*des_str = *src_str;
		des_str++;						//update values
		src_str++;
		count++;
	}

	return des_str_address;			//return des_str ptr
}

/*Function to reverse a string*/
void lc4_strrev(char str[]){
	int length = lc4_strlen(str); //length of str
	char temp[30];					//create a temporary char array to store the values
	int count = 0;					//count variable
	int end_null = length - 1;		//find end not including null value so find last char
	int i;							//iteration variable

	while (count < length){				//fill temp array with reverse string
		temp[count] = str[end_null];	//first temp index = last str index
		count ++;						//update values
		end_null = end_null - 1;		
	}

	temp[count] = '\0';					//append null value to end of temp string

	for (i = 0; i < length; i++){		//write over string with temp values
		str[i] = temp[i];				
	}

}

/*Function to reverse a string using pointers*/
void lc4_strrev_ptr(char * str){
	int length = lc4_strlen_ptrs(str);		//length of str
	char temp[30];							//create temp char array
	int count = 0;							//count variable
	char * temp_ptr = &temp[0];				//create ptr to start of temp array
	int i;									//count variable


	while (*str){				//find null char
		str++;
	}

	str --;						//move index back 1 to char before null

	while (count < length){		//fill temp array with reverse order
		*temp_ptr = *str;		//temp[0] = str[end] and so on
		str --;					//update values
		temp_ptr ++;
		count ++;
	}

	temp_ptr = &temp[0];		//reset temp ptr to first value
	str ++;						//update str pointer to first value

	for (i = 0; i < length; i++){	//write over str array with temp values
		*str = *temp_ptr; 
		str++;
		temp_ptr++;
	}
}

/*Function to compare two strings*/
int lc4_strcmp(char str1[], char str2[]){
	int i = 0;							//counter variable
	int test;							//variable to hold test value for comparing two characters
	int length1 = lc4_strlen(str1);		//length str1
	int length2 = lc4_strlen(str2);		//length str2

	if (length1 < length2) return -1;		//if length of first less than second return -1
	if (length2 < length1) return 1;		//if length of second less than first return 1
	if (length1 == length2){				//if lengths are equal test each char
		for (i = 0; i < length1; i++){		//iterate over each char
			test = str1[i] - str2[i];		//test subtract characters
			if (test < 0) return -1;		//if second string is a greater letter return -1
			if (test > 0) return 1; 		//if first string is a greater letter return 1
		}
	}
	return 0;								//if none of the other conditions are met return 0, the two strings are equal
}


/*Compares two strings using pointers*/
int lc4_strcmp_ptr(char * str1, char * str2){
	int length1 = lc4_strlen_ptrs(str1);	//length str1
	int length2 = lc4_strlen_ptrs(str2);	//length str2
	int count = 0;							//counter var
	int test;								//test variable

	if (length1 < length2) return -1;		//check if strings are the same size
	if (length2 < length1) return 1;
	if (length1 == length2){				//if strings are of equal length
		while (count < length1){			//iterate over the arrays
			test = *str1 - *str2;			//compare characters
			if (test < 0){					//if str2 > str1 return -1
				return -1;
			}
			if (test > 0){					//if str1 > str2 return 1
				return 1;
			}
			count ++;						//update values
			str1++;
			str2++;
		}
	}
	return 0;								//if equal return 0

}

/*String to upper case*/
char * lc4_strupper(char str[]){
	int length = lc4_strlen(str);
	int i;
	int dec;
	char * str_ptr = &str[0];
	if (length == 0) return 0;	//Return null if empty string

	for (i = 0; i < length; i++){	//iterate over str
		dec = str[i];				//get char value
		if (dec > 96 && dec < 123){		//test if char is a lowercase letter
			str[i] = dec - 32;			//convert to uppercase
		}
	}

	return str_ptr;					//retrun str ptr
}

/*Convert to upper case using pointers*/
char * lc4_strupper_ptr(char * str){
	int length = lc4_strlen_ptrs(str);	
	int count = 0;
	int dec;

	if (length == 0) return 0;	//if empty string return 0

	while (count < length){				//iterate over and check chars
		dec = * str ;			
		if (dec > 96 && dec < 123){		//check if char is a lower case letter
			*str = dec - 32;			//convert to upper case
		}
		count ++;						//update values
		str ++;
	}

	return str;							//return str ptr
}

/*function to get a string from the user and print to the console*/
char * lc4_gets(char str[]){
	char getc; 				//variable to hold char
	int count = 0;			//count variable to keep the array in the right size

	while (count < 29){						//keep array under 30 values
		getc = lc4_getc();					//call get c
		if (getc == '\n' && count == 0){	//if new line and the first entry
			str[count] = '\0';				//put null value in str and end bunction
			break;
		}
		if (getc == '\n'){					//if new line entered add null value to str and break
			str[count] = '\0';
			break;
		}
		str[count] = getc;					//if char is not a new line add it to the array
		count ++;							//update count and loop
	}

	if (count == 28){						//if user typed in 29 chars add a null value to the array for the 30th char
		str[29] = '\0';
	}

	return str;								// return pointer to str

}

/*Function to mimic str token, returns a pointer to the delimiter*/
char * lc4_strtok(char * str, char * delimiters){
	char * delimiter_test = delimiters;
	int length = lc4_strlen_ptrs(str);
	int del_len = lc4_strlen_ptrs(delimiters);
	void * null_ptr;
	int i;
	int j;

	for (i = 0; i < length; i++){
		for (j = 0; j < del_len; j++){
			if (*str == *delimiters){
				return str;
			}
			delimiters++;
		}
		str++;
	}
	return null_ptr; 
}
