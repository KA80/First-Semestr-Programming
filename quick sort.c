#include <stdio.h>
#include <stdlib.h>

void sort(long int num[100000], int left, int right){
    int pointR = right;
    int pointL = left;
    long int number = num[right];
    while (pointL < pointR){
        while (num[pointL] < num[pointR]) pointL++;
        while (((num[pointR] <= num[pointR - 1]) || (num[pointR] <= num[pointL])) && (pointR != pointL)) {
            if (num[pointR] > num[pointL]) pointL++;
            else {
                if ((pointR - 1) != pointL) {
                    long int temp1 = num[pointR], temp2 = num[pointR - 1];
                    num[pointR] = num[pointL];
                    num[pointR - 1] = temp1;
                    num[pointL] = temp2;
                    pointR--;
                } else {
                    long int temp = num[pointR];
                    num[pointR] = num[pointL];
                    num[pointL] = temp;
                    pointR--;
                }
            }
        }
    }
    if (pointR > left ) sort(num, left, pointR - 1);
//    left = point - 1;
//    right = point + 1;
    if (pointR < right ) sort(num, pointL + 1, right);

}

int main(){
    FILE* fin=fopen("input.txt","r");
    FILE* fout=fopen("output.txt","w");
    int N;
    fscanf(fin,"%d",&N);
    long int num[N];
    for (int i = 0; i < N; i++) fscanf(fin,"%ld",&num[i]);
    sort (num, 0, N - 1);
    for (int i = 0; i < N; i++) fprintf(fout,"%ld ",num[i]);
    fclose(fin);
    fclose(fout);
}
