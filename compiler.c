/*
    ADD ->  000
    WR  ->  001
    RD  ->  011
    INC ->  100
    DEC ->  101 
*/

/*
    (^\w+){1,3}\s\s(\w+)(?:\,?(\s|\w+)) -> RegEx para capturar os grupos do assembly acima
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

struct assembly_struct {
    char inst[50];
    char par1[50];
    char par2[50];
};

int RegexVerifier(char palavra[50], char regexp[50])
{
    regex_t regex;
    int reti;
    char msgbuf[100];

    /* Compile regular expression */
    reti = regcomp(&regex, regexp, 0);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    /* Execute regular expression */
    reti = regexec(&regex, palavra, 0, NULL, 0);

    /* Free memory allocated to the pattern buffer by regcomp() */
    regfree(&regex);
    return reti;
}

void AssemblyToMachine() 
{
    struct assembly_struct data;

    char filename[] = "ini_test.ini";
    FILE *file = fopen ( filename, "r" );
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
                        
        }

        fclose ( file );
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }
}

void main () {
    AssemblyToMachine();
}