#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>
#include <float.h>

#define intmax(type) _Generic(type, int: INT_MAX, \
		unsigned int: UINT_MAX)
#define IS_TYPE_SIGNED(a) ((a-1) < 0)
#define MAX_VALUE_UNSIGNED(a) ((( \
		unsigned long long)1 << (sizeof(a) * CHAR_BIT)) - 1)
#define MAX_VALUE_SIGNED(a) (MAX_VALUE_UNSIGNED(a) >> 1)
#define MAX_VALUE(a) (IS_TYPE_SIGNED(a) ? \
        MAX_VALUE_SIGNED(a) : MAX_VALUE_UNSIGNED(a))

#define issigned(t) (((t)(-1)) < ((t) 0))

#define umaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
                            (0xFULL << ((sizeof(t) * 8ULL) - 4ULL)))

#define smaxof(t) (((0x1ULL << ((sizeof(t) * 8ULL) - 1ULL)) - 1ULL) | \
                            (0x7ULL << ((sizeof(t) * 8ULL) - 4ULL)))

#define maxof(t) ((unsigned long long) (issigned(t) ? smaxof(t) : umaxof(t)))

int main(int argc, char *argv[]) 
    {
    
    //Character strings
   	char *message="Printing different data types";
   	wchar_t *wmessage=L"Wide Character string";

   	//Characters
   	char ca='A';
   	wchar_t wca=L'A';

   	//Integer Data types
   	unsigned short usa=65535; 
	short ssb=-32768;
   	unsigned int usi=4294967295; 
	int ssi=-2147483648;
   	unsigned long long int ulli=4294967295L;
	long long int lli=-2147483647L;
	
   	//Floating point Data types
   	float fa=1e+37,fb=1e-37;
   	double da=1e+37,db=1e-37;
   	long double lda=1e+37L,ldb=1e-37L;

   	//Pointers
   	int *p=&ssi;

   	//Character strings
   	printf("%s\n",message);
   	printf("%ls\n\n",wmessage);

   	//Characters
  	printf("%c\n",ca);
   	printf("%lc\n\n",wca);

   	printf("%hu %hi\n",usa,ssb); //short
   	printf("%hx %hx\n\n",usa,ssb);

   	printf("%u %i\n",usi,ssi); //integer/long integers
   	printf("%x %x\n\n",usi,ssi);

   	printf("%llu %lli\n",ulli,lli); //long long integers
   	printf("%llx %llx\n\n",ulli,lli);

   	printf("%f %f\n",fa,fb); //float

   	printf("%f %f\n",da,db); //double
   	printf("%e %e\n\n",da,db);

   	printf("%llf %llf\n",lda,ldb); //long double
   	printf("%lle %lle\n\n",lda,ldb);

   	printf("%p\n\n",p); //pointer of any data type
	
    //Sizeof
	if(argc > 1) 
	{
		printf("Sizeof:\n");
		printf("size_t: %zu\n", sizeof(size_t));
		printf("bool: %zu\n", sizeof(bool));
		printf("char: %zu\n", sizeof(char));
  		printf("short: %zu\n", sizeof(short));
		printf("unsigned short: %zu\n", sizeof(unsigned short));
  		printf("int: %zu\n", sizeof(int));
		printf("unsigned int: %zu\n", sizeof(unsigned int));
  		printf("long: %zu\n", sizeof(long));
		printf("unsigned long: %zu\n", sizeof(unsigned long));
  		printf("long long: %zu\n", sizeof(long long));
		printf("unsigned long long: %zu\n", sizeof(unsigned long long));
		printf("float: %zu\n", sizeof(float));
  		printf("double: %zu\n", sizeof(double));
  		printf("long double: %zu\n", sizeof(long double));
		printf("char: %zu\n", sizeof(char));
		printf("unsigned char: %zu\n", sizeof(unsigned char));
  		printf("clock_t: %zu\n", sizeof(clock_t));
 		printf("time_t: %zu\n", sizeof(time_t));
  		printf("struct tm: %zu\n", sizeof(struct tm));
  		printf("struct timeval: %zu\n", sizeof(struct timeval));
		
		//sizeof() declared variables
        short short_var;
        unsigned short unsigned_short_var;
        long long_var;
        long long longlong_var;
		int int_var;
        char char_var;
        float float_var;
        double double_var;
        long double longdouble_var;

        //Primitives
        uint8_t uint8_t_var;

        printf("Data Types: \n");
        printf("max int: %d ", intmax(int_var));
        printf("sizeof(int): %d \n",sizeof(int_var));
        //printf("max char: %s \n", SCHAR_MAX);
        printf("sizeof(char): %d \n",sizeof(char_var));
        printf("max float: %f ", FLT_MAX);
        printf("sizeof(float): %d \n",sizeof(float_var));
        printf("max double: %lf ", DBL_MAX);
        printf("sizeof(double): %d \n",sizeof(double_var));
        printf("max long double: %f ", LDBL_MAX);
        printf("sizeof(long double): %d \n",sizeof(longdouble_var));
        //printf("max uint8_t: %d ", INT_MAX);
        //printf("sizeof(uint8_t): %d \n",sizeof(uint8_t_var));
	
        //Maxof
	    printf("schar: %llx uchar: %llx\n", maxof(char), maxof(unsigned char));
        printf("sshort: %llx ushort: %llx\n", maxof(short), maxof(unsigned short));
        printf("sint: %llx uint: %llx\n", maxof(int), maxof(unsigned int));
        printf("slong: %llx ulong: %llx\n", maxof(long), maxof(unsigned long));
        printf("slong long: %llx ulong long: %llx\n",maxof(long long), maxof(unsigned long long));
    }    
    return 0;
}
