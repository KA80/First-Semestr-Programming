#include<stdio.h>

int main()
{
    FILE* fin=fopen("input.txt","r");
    FILE* fout=fopen("output.txt","w");
    int N,M;
    fscanf(fin,"%d %d",&N,&M);
    //printf("N %d M %d\n",N,M);
    char simvol[600];
    for(int i=0;i<N*(M+1);i++)
    {
        fscanf(fin,"%c",&simvol[i]);
        //printf("%c",simvol[i]);
    }
    int vivod=0;
    int i=0;
    while(i<N*(M+1))
    {
        //printf("i %d\n",i);
        int na4alo=0,konec=0;
        while((simvol[i]!='#') && (i<N*(M+1)))
        {
            if (simvol[i+1]=='#')
            {
                na4alo=i+1;
                //printf("na4alo %d\n",na4alo);
            }
            i++;
        }
        while((simvol[i]=='#') && (i<N*(M+1)))
        {
            if (simvol[i+1]!='#')
            {
                konec=i;
                //printf("konec %d\n",konec);
            }
            i++;
        }
        for(int j=na4alo;j<konec+1;j++)
        {
            //printf("%d",j);
            if(simvol[j-(M+1)]=='*')
            {
                vivod++;
                //printf("%d ",vivod);
                break;
            }
        }
    }
    fprintf(fout,"%d",vivod);
    fclose(fin);
    fclose(fout);
}
