#include <stdio.h>
#include <math.h>

double result(double D, double w, double T, double v){
    double t = (D-w*T)/(v-w);;
    if (((v*t-0.00001)>D) || (v - w == 0) || (t <= 0))  t=0;
    if (t>T) t=T;
    return v*t;
}

int main(){
    FILE* fin=fopen("input.txt","r");
    FILE* fout=fopen("output.txt","w");
    double D,T;
    fscanf(fin,"%lf %lf",&D,&T);
    double v1,v2;
    fscanf(fin,"%lf %lf",&v1,&v2);
    double w1,w2;
    fscanf(fin,"%lf %lf",&w1,&w2);
    double d[4]={result(D,w1,T,v1),result(D,w2,T,v1),result(D,w1,T,v2),result(D,w2,T,v2)};
    fprintf(fout,"%.4f",fmax(d[3],fmax(d[2],fmax(d[0],d[1]))));
    fclose(fin);
    fclose(fout);
    return 0;
}
