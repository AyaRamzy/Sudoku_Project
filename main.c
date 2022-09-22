#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <windows.h>
#include "sudoko.h"

int row,col,val,counter=14;


int main()
{


    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);

    int ** pattern;



    pattern=creatPattern();
    PrintPattern(pattern);


    ScanVal(pattern);

    while(1)

    {

        if(ValidNum((row-1),(col-1),val,pattern))
        {
            counter--;


            pattern[row-1][col-1]=val;
            system("cls");
            PrintPattern(pattern);

            ScanVal(pattern);



        }
        else
        {
            system("cls");
            PrintPattern(pattern);


            SetConsoleTextAttribute(h,4);
            printf("NOT CORRECT TRY AGAIN ....... \n");
            ScanVal(pattern);

        }


    if(counter==0)
        {
            if(getch=='a')
        {
            return 0;
        }

            system("cls");
            PrintPattern(pattern);
            SetConsoleTextAttribute(h,10);
            printf("\nCONGRATULATION  YOU ARE WINNER : )\n");

            system("COLOR 02");
            SetConsoleTextAttribute(h,4);
            printf("press any key to finish the game ......\n");

            getch();
            return 0;


        }

    }

    return 0;
}
