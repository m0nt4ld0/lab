#include <stdio.h>
#include <conio.h>

void multiplicar(int[][3],int[][4], int[][4]);
void muestra(const int [][4], int);

int main(void){
    int m1[2][3]={{1,7,3},{4,5,6}},
        m2[3][4]={{1,2,3,4},{5,6,7,8},{4,3,2,1}},
        r[2][4]={{0}};
    multiplicar(m1,m2,r);
    muestra(r,2);
    getch();
}

void multiplicar (int m[][3],int n[][4],int r[][4])
{
    int fi, co,ciclo;
    for(fi=0;fi<2;fi++)
    {
        for(co=0;co<4;co++)
        {
            for(ciclo=0;ciclo<3;ciclo++)
                r[fi][co]+=m[fi][ciclo]*n[ciclo][co];
        }
    }
}

void muestra(const int x[][4], int cfilas)
{
    int f,c;
    for(f=0;f<cfilas;f++)
        {
            for(c=0;c<4;c++){
                printf("\t%d",x[f][c]);
            }
            printf("\n");
        }
}
