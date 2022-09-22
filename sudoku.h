#ifndef SUDOKO_H_
#define SUDOKO_H_



int **creatPattern();
void PrintPattern(int **arr);
void ScanVal(int **arr);
int ValidNum(int row,int col,int val ,int **arr);
int cheakBlock(int row,int col,int val ,int **arr);
void DeleteCell(int row ,int col,int **arr);
int OriginalValCheck(int row,int col,int arr);
int CheakIndexOfRow(int x);
int CheakIndexOfcol(int x);
int countNotOriginalValues(int **arr);
int *CreatNotOriginal(int count ,int **arr );
int countNotOriginalValues(int **arr);


#endif // SUDOKO_H_


