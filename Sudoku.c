#include <stdio.h>
#include <stdlib.h>

#include "sudoku.h"
#include<conio.h>
#include<windows.h>

extern int row,col,val,counter;

int ** creatPattern(void)
{
    int i,j;
    int **pattern;
    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,15);


    int array[9][9]=
    {
        {3,1,6,5,0,8,4,9,2}
        ,{5,2,0,1,0,4,7,6,8}
        ,{4,8,7,6,0,0,5,3,1}
        ,{2,6,3,0,1,0,9,8,7}
        ,{9,7,4,8,6,3,1,2,5}
        ,{8,5,1,7,0,0,6,4,3}
        ,{1,3,8,0,0,7,2,5,6}
        ,{6,9,2,3,0,1,8,7,4}
        ,{7,4,0,2,0,6,0,1,9}
    };

    pattern=(int**)malloc(9*sizeof(int*));

    for (i=0; i<9; i++)
    {
        pattern[i]=(int*)malloc(9*sizeof(int));

        for(j=0; j<9; j++)
        {
            SetConsoleTextAttribute(h,11);
            pattern[i][j]=array[i][j];
        }


    }
    return pattern;

}
void PrintPattern(int **arr)
{
    int i=0,j=0;
    int ii=0,jj=0;
    char c=0;
    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);


    printf("");

    for (i=0 ; i<9; i++,ii++)
    {
        i=ii;


        if(i==0)
        {
            SetConsoleTextAttribute(h,11);
            printf("==========================================================================");
        }
        if(i%3==0)
        {


            printf("\n");




        }
        else


            printf("\n");
        for(j=0; j<9; j++,jj++)
        {
            j==jj;

            if(j%3==0)
            {
                if(arr[i][j]>0&&arr[i][j]<=9)
                {
                    SetConsoleTextAttribute(h,14);



                    printf("||  ");

                        printf("%d   ",arr[i][j]);






                    SetConsoleTextAttribute(h,14);
                }
                else if (arr[i][j]==0)
                {
                    printf("||      ",arr[i][j]);
                }

            }
            else
            {

                if(arr[i][j]>0&&arr[i][j]<=9)
                {
                    SetConsoleTextAttribute(h,14);

                    printf("|   ");
                        printf("%d   ",arr[i][j]);






                }
                else if (arr[i][j]==0)
                    printf("|       ",arr[i][j]);
                SetConsoleTextAttribute(h,7);

            }
            if(j+1==9)
            {
                c++;

                if(c!=3)

                {

                    printf("||\n||______|_______|_______||______|_______|_______||______|_______|_______");
                    SetConsoleTextAttribute(h,14);
                    printf("||");
                }

                else
                {

                    c=0;
                    SetConsoleTextAttribute(h,7);
                    if(j==8&&i==8)
                        SetConsoleTextAttribute(h,11);

                    printf("||\n++======+=======+=======++======+=======+=======++======+=======+=======++");
                }

            }

        }

    }

    printf("\n");
}
void ScanVal(int **arr)
{

    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,15);
    printf("ENTER ( ROW  COLUMEN  VALUE ) : ");
    printf("                                             ");
    SetConsoleTextAttribute(h,2);
    printf("NOTE:(Delete Cell =500 , Exit=100.)\n");
    //fflush(stdin);

    scanf("%d",&row);

    if(row==500)
    {
l:

        system("cls");
        PrintPattern(arr);
        SetConsoleTextAttribute(h,10);
        printf("Enter The Cell You Want Delete : (ROW COLUMEN): \n");
       // fflush(stdin);
        scanf("%d",&row);
        scanf("%d",&col);

        DeleteCell((row-1),(col-1),arr);
        system("cls");
        PrintPattern(arr);
        SetConsoleTextAttribute(h,15);
        printf("ENTER ( ROW  COLUMEN  VALUE ) : ");
        printf("                                             ");

        SetConsoleTextAttribute(h,2);
        printf("NOTE:(Delete Cell =500 , Exit=100.)\n");
        //fflush(stdin);
        scanf("%d",&row);
        if(row==500)
            goto l;

    }

    if(row==100)
    {
        exit("EXIT_SCCESS");
    }

    scanf("%d",&col);
    scanf("%d",&val);





}
int  ValidNum(int row,int col,int val,int **arr)
{
    int flage,i=0;



    for(i=0; i<9; i++)
    {
        if(arr[row][col]==val)
            continue;
        if(arr[row][i]==val)

            return 0;

        if(arr[i][col]==val)
            return 0;
    }
    flage=cheakBlock(row,col,val,arr);

    if(flage==0)
        return 0;

    return 1;
}


int cheakBlock(int row,int col,int val,int **arr)
{
    int i,j;
    if(row>=0&&row<=2) //first three blocks
    {
        if(col>=0&&col<=2) //block 1
        {
            for (i=0; i<3; i++)
            {
                for(j=0; j<3; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;
                }
            }

        }
        else if(col>=3&&col<=5)//block 2
        {
            for (i=0; i<3; i++)
            {
                for(j=3; j<6; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
        else if (col >=6&&col<=8) //block 3
        {
            for (i=0; i<3; i++)
            {
                for(j=6; j<9; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
    }

    else if(row>=3&&row<=5)  // second three block
    {
        if(col>=0&&col<=2) //block 4
        {
            for (i=3; i<6; i++)
            {
                for(j=0; j<3; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
        else if(col>=3&&col<=5)//block 5
        {

            for (i=3; i<6; i++)
            {
                for(j=3; j<6; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
        else if (col >=6&&col<=8) //block 6
        {
            for (i=3; i<6; i++)
            {
                for(j=6; j<8; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }
            return 0;
        }
    }


    else if(row>=6&&row<=8)  // third three blocks
    {
        if(col>=0&&col<=2) //block 7
        {
            for (i=6; i<9; i++)
            {
                for(j=0; j<3; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
        else if(col>=3&&col<=5)//block 8
        {
            for (i=6; i<9; i++)
            {
                for(j=3; j<6; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
        else if (col >=6&&col<=8) //block 9
        {
            for (i=6; i<9; i++)
            {
                for(j=6; j<9; j++)
                {
                    if(arr[row][col]==val)
                        continue;
                    if(arr[i][j]==val)

                        return 0;

                }
            }

        }
    }
    return 1;
}
void DeleteCell(int row,int col,int **arr)
{
    HANDLE h =GetStdHandle(STD_OUTPUT_HANDLE);

    if(OriginalValCheck(row,col,arr))
    {
        arr[row][col]=0;
        counter++;
    }
    else
    {
        system("cls");
        PrintPattern(arr);
        SetConsoleTextAttribute(h,4);
        printf("CAN'T DELETE THIS CELL....\n");
        ScanVal(arr);
    }

}


int countNotOriginalValues(int **arr)
{
    int i,j;
    static volatile int cnt=0;
    static volatile int flage=0;
    //for one time and in the next time become 1


    for(i=0; i<9&&flage==0; i++)
    {
        for(j=0; j<9; j++)
        {
            if(!(arr[i][j]))
                    cnt++;
        }
    }
    flage=1;

    return cnt; //number of the Not original Values
}
int *CreatNotOriginal(int count,int **arr )
{
    static volatile int flag = 0;
    int *NotoriginalIndexs=(int*)malloc ((count*2)*sizeof(int));
    int i=0,j=0,k=0;

    for(i=0; i<9 && flag == 0; i++)
    {
        for(j=0; j<9; j++)
        {
            if(!(arr[i][j]))
            {

                NotoriginalIndexs[k]=i;
                NotoriginalIndexs[k+1]=j;
                k+=2;
            }

        }
    }
    flag = 1;


    return NotoriginalIndexs;

}
int OriginalValCheck(int row,int col,int arr)
{
    int flage = 0,i,size;
    int *NotoriginalIndexs=CreatNotOriginal(countNotOriginalValues(arr),arr);
    size = countNotOriginalValues(arr);
    for(i=0; i< (2*size); i+=2)
    {
        // if true ,it is original and it will be invalid
        if((NotoriginalIndexs[i]==row) && (NotoriginalIndexs[i+1]= (col)))
        {
           flage=1;
        }
    }
    if(flage==1)
    {
        return 1;
    }
    else
    {
        return 0;

    }

}



