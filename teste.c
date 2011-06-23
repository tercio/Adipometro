/*

Calculo de Massa Corporea utilizando o protocolo

Jackson & Pollock,1978 - http://www.rgnutri.com.br/sap/avaliacao/ana1.php

*/

#include <stdio.h>
#include <stdlib.h>

int
main (int argc, char *argv[]) {

    float percG,dc,soma, peso, peito, subaxilar, subescapular, abdominal, suprailiaca, coxa, triceps = 0.0;
    int idade;
    char sexo;

    if (argc != 11) {
        printf ("uso: %s sexo(m|f) idade peso(kg) triceps peito sub-axilar subescapular abdominal supra-iliaca coxa\n",argv[0]);
        exit(0);
    }

    sexo = argv[1][0];
    idade = atoi (argv[2]);
    peso = atof(argv[3]);
    triceps = atof(argv[4]);
    peito = atof(argv[5]);
    subaxilar = atof(argv[6]);
    subescapular = atof(argv[7]);
    abdominal = atof(argv[8]);
    suprailiaca = atof(argv[9]);
    coxa = atof(argv[10]);
    
    soma = triceps+peito+subaxilar+subescapular+abdominal+suprailiaca+coxa;
    //printf ("Soma total: %.2f\n",soma);

    if (sexo == 'm') {

        dc = 1.112-0.00043499*soma+0.00000055*(soma*soma)-0.0002886*idade;

    } else if (sexo == 'f') {

        dc = 1.097-0.00046971*soma+0.00000056*(soma*soma)-0.00012828*idade;

    } else {
        printf ("sexo nao reconhecido...\n");
        exit(0);
    }

    printf ("\n\n==================================================================\n");
    percG = ((4.95/dc)-4.5)*100.0;
    printf ("Dens. Corporea :\t%.6f\n",dc);
    printf ("%% Gordura :\t\t%.2f %%\n",percG);
    printf ("Gordura :\t\t%.2f kg\n",peso*percG/100.0);
    printf ("Massa Magra :\t\t%.2f kg\n",peso - peso*percG/100.0);
    printf ("==================================================================\n\n");

    return 0;
}
