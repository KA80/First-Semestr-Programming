#include <stdio.h>

int main()
{
    int a,c,i,p;
    int a2;
    int n;
    int t[100];
    int r[100];
    int m[100];
    FILE *fin = fopen("input.txt","r");
    FILE *fout = fopen("output.txt","w");
    fscanf(fin,"%d%d%d",&n,&a,&c);
    for (i=1;i<=n;i+=1)
    {
        fscanf(fin,"%d%d%d",&t[i],&r[i],&m[i]);
    }
    a2=a;
    p=0;
    for (i=1;i<=n;i+=1)
    {
        p=p+c*t[i];
        if((a2>=r[i])&(m[i]>c*t[i]))
        {
            p=p+c*t[i];
            a2=a2+m[i];
        }
    }
    a2=a2-p;
    fprintf(fout,"%d",a2);
    fclose(fin);
    fclose(fout);
    return 0;
}
