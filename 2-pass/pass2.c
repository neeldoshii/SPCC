#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
FILE *f1,*f2,*f3,*f4;
char ch[100],chp[100];
int addr=1000;
int as=5;
int bs=2;
f1=fopen("input.txt","r");
f2=fopen("optab.txt","r");
f3=fopen("littab2.txt","w");
f4=fopen("symtab2.txt","w");
while (fscanf(f1,"%s",ch) !=EOF)
{
if(strcmp(ch,"-")==0)
{
addr++;
}
if(strcmp(ch,"db")==0)
{
fprintf(f4,"%s\t%d\n",chp,addr);
}
if(strcmp(chp,"LTORG")==0)
{
fprintf(f3,"%s\t%d\n",ch,addr);
}
strcpy(chp,ch);
}
fprintf(f3,"%d\n%d\n",as,bs);
fclose(f4);
fclose(f3);
fclose(f2);
fclose(f1);
}

/*
input1.txt
** START 2000
2000 ** LDA FIVE
2003 ** STA ALPHA
2006 ** LDCH CHARZ
2009 ** STCH
2012 ALPHA RESW
2018 FIVE WORD
2021 CHARZ BYTE Z
2023 C1 RESB
2024 ** END **
*/

/*
optab1.txt
LDA 03
LDA 0f
LDCH 53
STCH 57
END *
*/

/*
symtab2.txt --> manually use this
2000 **
2003 **
2006 **
2009 **
2012 ALPHA
2018 FIVE
2021 CHARZ
2023 C1
2024 **
*/

