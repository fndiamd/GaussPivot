#include <stdio.h>
#include <stdlib.h>

float hasilpers[5];
float peubah[5][5];


float inputPeubah(int x){
    int i, j;
    for(i=0; i<x; i++){
        printf("Persamaan ke-%d \n", i+1);
        for(j=0; j<x; j++){
            printf("Masukan peubah X%d = ", j+1);
            scanf("%f", &peubah[i][j]);
        }
        printf("Hasil persamaan ke-%d = ", i+1);
        scanf("%f", &hasilpers[i]);
        printf("\n");
    }
}

float getGausPers(int x, int baris, int prevBaris){
    baris = baris - 1; // => 2
    prevBaris = prevBaris - 1; // => 0
    int i, j;
    float hasilGaus[5], baru[5], hasilPersBaru;
    for(i=0; i<x; i++){
        hasilGaus[i] = peubah[prevBaris][i] * peubah[baris][prevBaris] / peubah[prevBaris][prevBaris];
        baru[i] = peubah[baris][i] - hasilGaus[i];
    }

    hasilPersBaru = hasilpers[prevBaris] * peubah[baris][prevBaris] / peubah[prevBaris][prevBaris];
    hasilpers[baris] -= hasilPersBaru;

    for(i=0; i<x; i++){
        peubah[baris][i] = baru[i];
    }

}

void getHasilPeubah(int z){
    float x[5];
    int i;

    for(i=0; i<z; i++){ x[i] = 0; }

    switch(z){
        case 2:
            x[1] = ( hasilpers[1] - (x[0] * peubah[1][0]) ) / peubah[1][1];
            x[0] = ( hasilpers[0] - (x[1] * peubah[0][1]) ) / peubah[0][0];
            break;
        case 3:
            x[2] = ( hasilpers[2] - ( ( x[0] * peubah[2][0] + x[1]*peubah[2][1] ) ) ) / peubah[2][2] ;
            x[1] = ( hasilpers[1] - ( ( x[0] * peubah[1][0] + x[2]*peubah[1][2] ) ) ) / peubah[1][1] ;
            x[0] = ( hasilpers[0] - ( ( x[1] * peubah[0][1] + x[2]*peubah[0][2] ) ) ) / peubah[0][0] ;
            break;
        case 4:
            x[3] = ( hasilpers[3] - ( ( x[0] * peubah[3][0] + x[1]*peubah[3][1] + x[2]*peubah[3][2] ) ) ) / peubah[3][3];
            x[2] = ( hasilpers[2] - ( ( x[0] * peubah[2][0] + x[1]*peubah[2][1] + x[3]*peubah[2][3] ) ) ) / peubah[2][2];
            x[1] = ( hasilpers[1] - ( ( x[0] * peubah[1][0] + x[2]*peubah[1][2] + x[3]*peubah[1][3] ) ) ) / peubah[1][1];
            x[0] = ( hasilpers[0] - ( ( x[1] * peubah[0][1] + x[2]*peubah[0][2] + x[3]*peubah[0][3] ) ) ) / peubah[0][0];
            break;

    }


    for(i=0; i<z; i++){
        printf("X%d = %g \n",i, x[i]);
    }

}


int main(){
    int i, j, pers;
    printf("Masukan banyak persamaan = ");
    scanf("%d", &pers);
    inputPeubah(pers);

    for (i=2; i<= pers; i++){
        for (j=1; j<i; j++){
            getGausPers(pers, i, j);
        }
    }
    printf("=================MATRIKS GAUS===============\n\n");
    for(i=0; i<pers; i++){
        printf("|\t");
        for(j=0; j<pers; j++){
            printf("%.2g\t", peubah[i][j]);
        }
        printf("| %.2g\t|", hasilpers[i]);
        printf("\n");
    }
    printf("\n============================================\nHasil : \n");
    getHasilPeubah(pers);
}
