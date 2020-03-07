#include <stdio.h>
#include <math.h>

int main()
{
   int n,m;
   FILE *fin=fopen("input.txt","r");
   FILE *fout=fopen("output.txt","w");
   fscanf(fin,"%d%d",&n,&m);
   int a,b,c;
   if(n<m) {
    a=n+1;
   } else
   {
       if(n % m > 0){
        b=n / m;
        c=n-b*m;
        a=b*m+b+c+1;
       } else
       {
           b=n / m;
           a=b*m+b;
       }
   }
   fprintf(fout,"%d",a);
   fclose(fin);
   fclose(fout);
   return 0;
}
