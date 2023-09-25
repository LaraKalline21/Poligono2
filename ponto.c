#include <stdio.h> 
#include <math.h>
#include <stdlib.h>
#include "ponto.h"

int CalcularDeterminante(int num_vert, int array[num_vert][num_vert])
{
  int i = 0, k = 0, l = 0;
    double factor = 0;
    int temp = 0;
    int count = 0;
     for(i = 0; i < num_vert - 1; i++)
    {
        if(array[i][i] == 0)
        {
            for(k = i; k < num_vert; k++)
            {
                if(array[k][i] != 0)
                {
                    for(int l = 0; l < num_vert; l++)
                    {
                        temp = array[i][l];
                        array[i][l] = array[k][l];
                        array[k][l] = temp;
                    }
                    k = num_vert;
                }
            }
            count++;
        }

        if(array[i][i] != 0)
        {
            for(k = i + 1; k < num_vert; k++)
            {
                factor = -1.0 * array[k][i] /  array[i][i];
                for(int l = i; l < num_vert; l++)
                {
                    array[k][l] = array[k][l] + (factor * array[i][l]);
                }
            }
        }
    }

    temp = 1;
    // Calcula o determinante
    for(i = 0; i < num_vert; i++)
        temp *= array[i][i];

    return temp;
}