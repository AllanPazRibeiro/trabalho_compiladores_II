/*
    ADD ->  000
    WR  ->  001
    RD  ->  011
    INC ->  100
    DEC ->  101 
*/

/*
    (^\w+){1,3}\s\s(\w+)(?:\,?(\s|\w+)) -> RegEx para capturar os grupos do assembly acima

    Compilar -> gcc -o compiler compiler.c
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

int AssemblyToMachine(char word[50])
{
    char * regexString = "(^//w+){1,3}//s//s(//w+)(?://,?(//s|//w+))";
    size_t maxGroups = 3;
    struct assembly_struct data;

    regex_t regexCompiled;
    regmatch_t groupArray[maxGroups];

    if (regcomp(&regexCompiled, regexString, REG_EXTENDED))
    {
        printf("Could not compile regular expression.\n");
        return 1;
    };

    if (regexec(&regexCompiled, word, maxGroups, groupArray, 0) == 0)
    {
        unsigned int g = 0;
        for (g = 0; g < maxGroups; g++)
        {
            if (groupArray[g].rm_so == (size_t)-1)
            break;  // No more groups

            char sourceCopy[strlen(word) + 1];
            strcpy(sourceCopy, word);
            sourceCopy[groupArray[g].rm_eo] = 0;

            puts(groupArray[g].rm_so + '\n');
            puts(groupArray[g].rm_eo + '\n');
            puts(sourceCopy + groupArray[g].rm_so + '\n');
        }
    }

  regfree(&regexCompiled);

  return 0;
}

void  ReadLine() 
{
    char filename[] = "assembly.txt";
    FILE *file = fopen ( filename, "r" );
    if ( file != NULL )
    {
        char line [ 128 ]; /* or other suitable maximum line size */
        while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
        {
           AssemblyToMachine(line);           
        }

        fclose ( file );
   }
   else
   {
      perror ( filename ); /* why didn't the file open? */
   }
}

void main () {
    ReadLine();
}