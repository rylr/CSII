/**************************************************************
 
 Name:  Tyler Reinecke
 Program: Lab C - Pig Latin
 Version: 1.0
 
 CS II Lab C
 Pig Latin
 
 Write a program that encodes English language phrases into pig Latin. Pig
 Latin is a form of coded language often used for amusement. Many variations exist
 in the methods used to form pig Latin phrases. For simplicity, use the following
 algorithm: To form a pig Latin phrase from an English language phrase, tokenize the
 phrase into words with the function strtok() (this will take some
 experimentation).
 
 To translate each English word into a pig Latin word, place the
 first letter of the English word at the end of the English word, and add the letters
 “ay”. Thus the word “jump” becomes “umpjay”, the word “the” becomes “hetay”,
 and the word “computer” becomes “omputercay”. Blanks between words remain
 as blanks. Assume the following: the English phrase given by the user consists of
 words separated by blanks, there are no punctuation marks, and all words have two
 or more letters. Function printlatinword() should display each word.
 
 Hint: Each time a token is found in a call to strtok(), pass the token pointer to function
 printlatinword(), and print the pig Latin word from there.
 Hence, printing one word at a time.
 ******************************************************************/

#include <stdio.h>
#include <string.h>

void printlatinword(char []);

int main (void)
{
    char input[1000];
    puts("Please type in an English phrase.");
    gets(input);                                                //Stores user-entered string
    char *sep = NULL;                                           //Each token
    sep = strtok(input, " ");
    while(sep != NULL)                                          //While the string still has tokens
    {
        printlatinword(sep);
        sep = strtok(NULL, " ");                                //Sets sep to the next token in the same string
    }
    printf("\n");
    
    return 0;
}

void printlatinword(char word[])
{
    char first = word[0];                                       //Sets first to the first letter in the word
    char second = word[1];                                      //Sets second to the second letter in the word

    printf("%s%c%s", strchr(word, second), first, "ay ");       //Prints the word, starting from the second letter,
}                                                               //the first letter of the word at the end of the word,
                                                                //and also "ay"