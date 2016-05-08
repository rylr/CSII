/**************************************************************
 
 Name:  Tyler Reinecke
 Program: Lab D - The Book Club
 Version: 1.0
 
 CS II Lab E
 The Book Club Save
 
 Write a program that inputs and holds up to 100 novels. Be sure that the program holds at least the title, author (last name first), category, whether its an enjoyable book (rate 1-10), and the number of pages. Experiment and find a way to sort the completed list by one of the following choices (at the users’ discretion): by title (be CAREFUL – think about library listings), by author, by category, or by number of pages. Have the program display the sorted list in a table. The user should be able to save their list to a file with their choice of name. The program should be able to read back from said file in a separate program run. Be sure the user can save the list after it has been sorted, and they can add books when the list has been read in from the file.
 
 ******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Structure Definition
struct novel
{
    char title[30];
    char titlesort[30];
    char author[50];
    char authorsort[50];
    char genre[20];
    char genresort[20];
    int rating;
    int pages;
};

struct novel declaration(int);
void sort(struct novel [], int);
void titlesort(struct novel []);
int comp(struct novel [], int, int);
void print(struct novel [], int);
void input(struct novel [], int);
void output();


int main(int argc, const char * argv[])
{
    //Structure Array
    struct novel library[100] = {0};
    
    int count = 0;
    int stay = 1;
    char flag;
    
    //Home Menu
    while(stay == 1)
    {
        int nav;
        puts("What would you like to do?\n\t\tType 1 for entering novels.\n\t\tType 2 for sorting novels.\n\t\tType 3 for displaying list.\n\t\tType 3 for saving list to a file.\n\t\tType 4 for reading list from a file.\n\t\tType 5 for exit program.");
        scanf("%d", &nav);
        
        switch(nav)
        {
            case 1:
                do
                {
                    //Each novel declaration
                    library[count] = declaration(count);
                    count++;
                    
                    //Another Novel?
                    puts("Another novel to input? Y/N");
                    getchar();
                    flag = getchar();
                    
                }
                while((flag == 'y' || flag == 'Y') && (count < 30));
                
                stay = 1;
                break;
                
            case 2:
                sort(library, count);
                stay = 1;
                break;
                
            case 3:
                print(library, count);
                break;
                
            case 4:
                input(library, count);
                break;
            
            case 5:
                output();
                break;
                
            case 6:
                stay = 0;
                break;
                
            default:
                puts("Invalid choice, please choose 1-3.");
                break;
        }
    }
    
    return 0;
}


struct novel declaration(int num)
{
    int i;
    unsigned long length;
    //Creating each novel
    struct novel book;
    getchar();
    puts("Please enter the title of the novel.");
    gets(book.title);
    strcpy(book.titlesort, book.title);
    length = strlen(book.title);
    for(i = 0; i < length; i++)
    {
        book.titlesort[i] = toupper(book.titlesort[i]);
    }
    
    puts("Please enter the author of the novel. (Last name first)");
    gets(book.author);
    strcpy(book.authorsort, book.author);
    length = strlen(book.author);
    for(i = 0; i < length; i++)
    {
        book.authorsort[i] = toupper(book.authorsort[i]);
    }
    
    puts("Please enter the genre of the novel.");
    gets(book.genre);
    strcpy(book.genresort, book.genre);
    length = strlen(book.genre);
    for(i = 0; i < length; i++)
    {
        book.genresort[i] = toupper(book.genresort[i]);
    }
    
    puts("Please rate the novel of a scale of 1-10.");
    scanf("%d", &book.rating);
    
    puts("Please enter the number of pages in the novel.");
    scanf("%d",&book.pages);
    
    return book;
}


void sort(struct novel bookcase[], int runs)
{
    //Sorting novels
    printf("How would you like to sort the novels?\n\t\tType 1 for by Title.\n\t\tType 2 for by Author.\n\t\tType 3 for by Genre.\n\t\tType 4 for by number of pages.\n");
    int prefer, i, pass;
    struct novel temp;
    scanf("%d", &prefer);
    
    for(pass = 0; pass <= runs; pass++)
        for(i = 0; i < runs - 1; i++)
            if(comp(bookcase, prefer, i) > 0)
            {
                temp = bookcase[i];
                bookcase[i] = bookcase[i + 1];
                bookcase[i + 1] = temp;
            }
}


int comp(struct novel books[], int choice, int sub)
{
    int cmp = 0;
    switch(choice)
    {
        case 1:
            titlesort(books);
            cmp = strcmp(books[sub].titlesort, books[sub + 1].titlesort);
            if(cmp > 0)
                return 1;
            else
                return 0;
            
            break;
            
        case 2:
            cmp = strcmp(books[sub].authorsort, books[sub + 1].authorsort);
            if(cmp > 0)
                return 1;
            else
                return 0;
            
            break;
            
        case 3:
            cmp = strcmp(books[sub].genresort, books[sub + 1].genresort);
            if(cmp > 0)
                return 1;
            else
                return 0;
            
            break;
            
        case 4:
            if(books[sub].pages > books[sub + 1].pages)
                return 1;
            else
                return 0;
            
            break;
            
        default:
            printf("Invalid choice, please choose 1-3.");
            break;
    }
    
    return 0;
}


void titlesort(struct novel bookstand[])
{
    int the, a, an;
    char hold[30] = "";
    
    //Search
    the = strncmp(bookstand->titlesort, "THE", 4);
    a = strncmp(bookstand->titlesort, "A", 2);
    an = strncmp(bookstand->titlesort, "AN", 3);
    
    if(the == 0)
    {
        strcpy(hold, bookstand->titlesort + 4);
        strcat(hold, ", THE");
        strcpy(bookstand->titlesort, hold);
        printf("%s",  hold);
    }
    else
        if(a == 0)
        {
            strcpy(hold, bookstand->titlesort + 2);
            strcat(hold, ", A");
            strcpy(bookstand->titlesort, hold);
            printf("%s", hold);
        }
        else
            if(an == 0)
            {
                strcpy(hold, bookstand->titlesort + 3);
                strcat(hold, ", AN");
                strcpy(bookstand->titlesort, hold);
                printf("%s", hold);
            }
    
}


void print(struct novel stand[], int runs)
{
    int i;
    titlesort(stand);
    putchar('\n');
    printf("%31s%31s%31s%31s%31s\n\n", "Title", "Author", "Genre", "Rating", "Pages");
    for(i = 0; i < runs; i++)
        printf("%31s%31s%31s%31d%31d\n", stand[i].title, stand[i].author, stand[i].genre, stand[i].rating, stand[i].pages);
    putchar('\n');
    putchar('\n');
}


void input(struct novel books[], int amount)
{
    char name[50];
    int i;
    puts("What would you like to name the file?");
    scanf("%s", name);
    FILE *novelfile = NULL;
    if((novelfile = fopen(name, "ab")) == NULL)
    {
        puts("Unable to open the file.");
        exit(1);
    }
    for(i = 0; i < amount; i++)
    {
        //fprintf("%31s%31s%31s%31d%31d\n", books[i].title, books[i].author, books[i].genre, books[i].rating, books[i].pages);
    }
}


void output(struct novel books[], int num)
{
    char name[50];
    puts("What would you like to name the file?");
    scanf("%s", name);
    FILE *novelfile = NULL;
    if((novelfile = fopen(name, "a")) == NULL)
    {
        puts("Unable to open the file.");
        exit(1);
    }
}
