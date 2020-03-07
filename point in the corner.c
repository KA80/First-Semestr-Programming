#include <stdio.h>

int main()
{
    FILE* fin=fopen("input.txt","r");
    FILE* fout=fopen("output.txt","w");
    int x1,y1,x2,y2,x,y;
    fscanf(fin,"%d %d %d %d %d %d",&x1,&y1,&x2,&y2,&x,&y);
    int xcenter,ycenter;
    xcenter=(x1+x2)/2;
    ycenter=(y1+y2)/2;
    int xnij,ynij,xverh,yverh;
    if (y1<y2)
    {
        ynij=(y1+ycenter)/2;
        yverh=(y2+ycenter)/2;
    }
    else
    {
        ynij=(y2+ycenter)/2;
        yverh=(y1+ycenter)/2;
    }
    if (x1<x2)
    {
        xnij=(x1+xcenter)/2;
        xverh=(x2+xcenter)/2;
    }
    else
    {
        xnij=(x2+xcenter)/2;
        xverh=(x1+xcenter)/2;
    }
    if ((x>=xnij) && (x<=xverh) && (y>=ynij) && (y<=yverh))
    {
        fprintf(fout,"CENTER");
    }
    else
    {
        fprintf(fout,"CORNER");
    }
    fclose(fin);
    fclose(fout);
}
