#include <stdio.h>
#include <conio.h>
#define ARCHIVO "personas"
#define con_MSJ 1
#define TEXTO1 "texto1.txt"
#define TEXTO2 "texto2.txt"

typedef struct{
    int di, me, an;
}t_fecha;

typedef struct{
    long dni;
    char apyn[36];
    char sex;
    t_fecha fec;
    float importe;
}t_pers;

void crearDatos(void);
int abrirArchivo(FILE**,const char*,const char*,int);

int main(void){
    t_pers reg;
    FILE *fpEnt,
        *fpSal1,
        *fpSal2;
    crearDatos();
    if(!abrirArchivo(&fpEnt,ARCHIVO,"rb",con_MSJ))
        return 1;
    if(!abrirArchivo(&fpSal1,TEXTO1,"wb",con_MSJ))
    {
        fclose(fpEnt);
        return 2;
    }
    if(!abrirArchivo(&fpSal2,TEXTO2,"wb",con_MSJ))
    {
        fclose(fpSal1);
        fclose(fpEnt);
        return 4;
    }
    fread(&reg,sizeof(t_pers),1,fpEnt);
    while(!feof(fpEnt))
    {
        fprintf(fpSal1,"%ld|%s|%c|%d/%d/%d|%.2f\n",reg.dni,reg.apyn,reg.sex,reg.fec.di,reg.fec.me,reg.fec.an,reg.importe);
        fprintf(fpSal2,"%08ld%-*s%c%02d%02d%04d%09.2f\n",reg.dni,sizeof(reg.apyn)-1,reg.apyn,reg.sex,
                reg.fec.di,reg.fec.me,reg.fec.an,reg.importe);
        fread(&reg,sizeof(t_pers),1,fpEnt);
    }
    fclose(fpEnt);
    fclose(fpSal1);
    fclose(fpSal2);
    return 0;
}

void crearDatos(void){
    FILE *fp = fopen(ARCHIVO, "wb");
    t_pers pers[] = {{37346201,"Montaldo, Mariela",'F',{23,02,1993},15.5},
                    {36662695,"Macias, Cintia",'F',{26,06,1992},6.6},
                    };
    if(fp){
        fwrite(pers,sizeof(pers),1,fp);
        fclose(fp);
    }
}

int abrirArchivo(FILE**fp,const char*nombre,const char*modo,int conSin)
{
    *fp=fopen(nombre,modo);
    if(*fp)
        return 1;
    else
    {
        if(conSin==con_MSJ)
            fprintf(stderr,"Error abriendo \"%s\" en modo \"%s\".\n",nombre,modo);
        return 0;
    }
}
