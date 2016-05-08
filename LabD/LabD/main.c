/**************************************************************
 
 Name:  Tyler Reinecke
 Program: Lab D - The Book Club
 Version: 1.0
 
 CS II Lab D
 The Book Club
 
 Write a program that inputs and holds up to 30 novels. Be sure that the program holds at least the title, author
 (last name first), genre, a quality rating (1-10), and the number of pages. Experiment and find a way to sort 
 the completed list by one of the following choices (at the users’ discretion): by author, by category, or by number of pages.
 Have the program display the sorted list.
 
 ******************************************************************/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Structure Definition
struct novel
{
    char title[30];
    char author[50];
    char authorsort[50];
    char genre[20];
    char genresort[20];
    int rating;
    int pages;
};

struct novel declaration(int);
void sort(struct novel [], int);

int main(int argc, const char * argv[])
{
    //Structure Array
    struct novel library[30] = {0};
    
    int count = 0;
    int stay = 1;
    char flag;
    
    //Home Menu
    while(stay == 1)
    {
        int nav;
        puts("What would you like to do?\n\t\tType 1 for entering novels.\n\t\tType 2 for sorting novels\n\t\tType 3 for exit program.");
        scanf("%d", &nav);
        
        switch (nav)
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
    int length, i;
    //Creating each novel
    struct novel book;
    getchar();
    puts("Please enter the title of the novel.");
    gets(book.title);
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
    printf("How would you like to sort the novels?\n\t\tType 1 for by author.\n\t\tType 2 for by genre.\n\t\tType 3 for by number of pages.\n");
    int prefer, i, pass, cmp = 0;
    //char swap[50];
    struct novel temp;
    scanf("%d", &prefer);
    
    switch(prefer)
    {
        case 1:
            
            for(pass = 0; pass <= runs; pass++)
            {
                for(i = 0; i < runs - 1; i++)
                {
                    cmp = strcmp(bookcase[i].authorsort, bookcase[i + 1].authorsort);
                    if(cmp > 0)
                    {
                        temp = bookcase[i];
                        bookcase[i] = bookcase[i+1];
                        bookcase[i+1] = temp;
                    }
                }
            }
            putchar('\n');
            printf("%31s%31s%31s%31s%31s\n\n", "Title", "Author", "Genre", "Rating", "Pages");
            for(i = 0; i < runs; i++)
                printf("%31s%31s%31s%31d%31d\n", bookcase[i].title, bookcase[i].author, bookcase[i].genre, bookcase[i].rating, bookcase[i].pages);
            putchar('\n');
            putchar('\n');
            break;
            
        case 2:
            for(pass = 0; pass <= runs; pass++)
            {
                for(i = -1; i < runs - 1; i++)
                {
                    cmp = strcmp(bookcase[i].genresort, bookcase[i + 1].genresort);
                    if(cmp > 0)
                    {
                        temp = bookcase[i];
                        bookcase[i] = bookcase[i+1];
                        bookcase[i+1] = temp;
                    }
                }
            }
            putchar('\n');
            printf("%31s%31s%31s%31s%31s\n\n", "Title", "Author", "Genre", "Rating", "Pages");
            for(i = 0; i < runs; i++)
                printf("%31s%31s%31s%31d%31d\n", bookcase[i].title, bookcase[i].author, bookcase[i].genre, bookcase[i].rating, bookcase[i].pages);
            putchar('\n');
            putchar('\n');
            break;
            
        case 3:
            for(pass = 0; pass <= runs; pass++)
            {
                for(i = 0; i < runs - 1; i++)
                {
                    if(bookcase[i].pages > bookcase[i + 1].pages)
                    {
                        temp = bookcase[i];
                        bookcase[i] = bookcase[i+1];
                        bookcase[i+1] = temp;
                    }
                }
            }
            putchar('\n');
            printf("%31s%31s%31s%31s%31s\n\n", "Title", "Author", "Genre", "Rating", "Pages");
            for(i = 0; i < runs; i++)
                printf("%31s%31s%31s%31d%31d\n", bookcase[i].title, bookcase[i].author, bookcase[i].genre, bookcase[i].rating, bookcase[i].pages);
            putchar('\n');
            putchar('\n');
            break;
            
        default:
            printf("Invalid choice, please choose 1-3.");
            break;
    }
}