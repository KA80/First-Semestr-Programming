#include <stdio.h>

int main()
{
    FILE* fin=fopen("input.txt","r");
    FILE* fout=fopen("output.txt","w");
/////////////////////////////////////////////////ВВОД ПЕРЕМЕННЫХ////////////////////////////////////////////////////////////
    long int N;
    fscanf(fin,"%d",&N);
    long int a[1000];
    long int b[1000];
    long int c[1000];
    //printf("N %d\n",N);
    for (int i=0;i<N;i++)
    {
        fscanf(fin,"%d",&a[i]);
        b[i]=a[i];
        c[i]=a[i];
        //printf("a[N] %d ",a[i]);
    }
/////////////////////////////////////////////НЕЧЕТНЫЕ ДОСКИ ЗАБОРА/////////////////////////////////////////////////////
    long int s4et1=0;
    for (int i=0;i<N;i+=2)
    {
        //printf("i ne4et %d\n",i);
        if (N%2==0)
        {
            if (i==0)
            {
                if (b[i]<=b[i+1])
                {
                    b[i]=b[i+1]+1;
                    s4et1=s4et1+a[i+1]-a[i]+1;
                }
            }
            else
            {
                if ((b[i]<=b[i+1]) || b[i]<=b[i-1])
                {
                    if (b[i-1]<b[i+1])
                    {
                        b[i]=b[i+1]+1;
                        s4et1=s4et1+a[i+1]-a[i]+1;
                    }
                    else
                    {
                        b[i]=b[i-1]+1;
                        s4et1=s4et1+a[i-1]-a[i]+1;
                    }
                }
            }
        }
        else
        {
            if (i==0)
            {
                if (b[i]<=b[i+1])
                {
                    b[i]=b[i+1]+1;
                    s4et1=s4et1+a[i+1]-a[i]+1;
                }
            }
            else
            {
                if (i==N)
                {
                    if (b[i]<=b[i-1])
                    {
                        b[i]=b[i-1]+1;
                        s4et1=s4et1+a[i-1]-a[i]+1;
                    }
                }
                else
                {
                    if ((b[i]<=b[i+1]) || b[i]<=b[i-1])
                    {
                        if (b[i-1]<b[i+1])
                        {
                            b[i]=b[i+1]+1;
                            s4et1=s4et1+a[i+1]-a[i]+1;
                        }
                        else
                        {
                            b[i]=b[i-1]+1;
                            s4et1=s4et1+a[i-1]-a[i]+1;
                        }
                    }
                }
            }
        }
    }
/////////////////////////////////////////////ЧЕТНЫЕ ДОСКИ ЗАБОРА///////////////////////////////////////////////////////
    long int s4et2=0;
    for (int i=1;i<N;i+=2)
    {
        if (i==N-1)
        {
            c[i+1]=0;
        }
        //printf("i 4et %d\n",i);
        if (N%2==0)
        {
            if (i==N)
            {
                if (c[i]<=c[i-1])
                {
                    c[i]=c[i-1]+1;
                    s4et2=s4et2+a[i-1]-a[i]+1;
                }
            }
            else
            {
                if ((c[i]<=c[i+1]) || c[i]<=c[i-1])
                {
                    if (c[i-1]<c[i+1])
                    {
                        c[i]=c[i+1]+1;
                        s4et2=s4et2+a[i+1]-a[i]+1;
                    }
                    else
                    {
                        c[i]=c[i-1]+1;
                        s4et2=s4et2+a[i-1]-a[i]+1;
                    }
                }
            }
        }
        else
        {
            if ((c[i]<=c[i+1]) || c[i]<=c[i-1])
            {
                if (c[i-1]<c[i+1])
                {
                    c[i]=c[i+1]+1;
                    s4et2=s4et2+a[i+1]-a[i]+1;
                }
                else
                {
                    c[i]=c[i-1]+1;
                    s4et2=s4et2+a[i-1]-a[i]+1;
                }
            }
        }
    }
    /////////////////////////////////////////////СРАВНЕНИЕ/////////////////////////////////////////////////////////////
    //printf("s4et1=%d\n",s4et1);
    //printf("s4et2=%d\n",s4et2);
    if (s4et1<=s4et2)
    {
        for(int i=0;i<N;i++)
        {
            fprintf(fout,"%d ",b[i]);
            //printf("b[i] %d ",b[i]);
        }
    }
    else
    {
        for(int i=0;i<N;i++)
        {
            fprintf(fout,"%d ",c[i]);
            //printf("c[i] %d ",c[i]);
        }
    }
    fclose(fin);
    fclose(fout);
}
