#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    FILE* fin=fopen("input.txt","r");
    FILE* fout=fopen("output.txt","w");
    int porch, floor, apart, NumGuess;
    fscanf(fin,"%d %d %d %d",&porch,&floor,&apart,&NumGuess);
    int guess[100001] = {0};
    for (int i = 0; i < NumGuess; i++){
        fscanf(fin,"%d",&guess[i]);
    }
    int PorchGuess = 0, FloorGuess = 0, RisePorch[10001] = {0};
    for(int i = 0; i < NumGuess; i++){
        PorchGuess = (apart - 1) / (floor * guess[i]) + 1;
        FloorGuess = (apart - (PorchGuess - 1) * floor * guess[i] - 1) / guess[i] + 1;
        if ((PorchGuess <= porch) && (RisePorch[PorchGuess] < FloorGuess))
            RisePorch[PorchGuess] = FloorGuess;
    }
    int sum = 0;
    for (int i = 0; i < porch + 1; i++)
        sum += RisePorch[i];
    if (sum == 0)
        fprintf(fout, "-1");
    else
        fprintf(fout, "%d", sum);
    fclose(fin);
    fclose(fout);
    return 0;
}
