#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE* fin=fopen("input.txt","r");
    FILE* fout=fopen("output.txt","w");
    int N;
    fscanf(fin,"%d",&N);
    int x[N],y[N];
    for (int i = 0; i < N; i++) fscanf(fin,"%d %d",&x[i],&y[i]);
    fclose(fin);
    if (N == 1){
        fprintf(fout,"1");
        fclose(fout);
        return 0;
    }
    if (N == 2){
        if (y[1] + y[0] > x[1] - x[0]){
            fprintf(fout,"2");
            fclose(fout);
            return 0;
        }
        else{
            fprintf(fout,"1");
            fclose(fout);
            return 0;
        }
    }
    else {
        int max = 0;
        int point[100] = {0};
        for(int i = 0; i < N; i++){
            for (int j = x[i] - y[i]; j < x[i] + y[i]; j++){
                if((j >= 0) && (j<100)) point[j]++;
            }
        }
        for(int i = 0; i < 100; i++){
            if(point[i] > max) max = point[i];
        }
        fprintf(fout,"%d",max);
        fclose(fout);
    }
    return 0;
}
