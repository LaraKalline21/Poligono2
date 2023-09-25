#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ponto.h"

int main(int argc, char* argv[])
{
    //Abre o arquivo passado como argumento
    FILE *stream = fopen(argv[1], "r"); //"r" - read
    //Dá erro caso nao tenha arquivo
    if(stream == NULL)
    {
        perror("Nao foi possivel abrir o arquivo");
        exit(1);
    }
    int j = 0; //para contar as linhas
    //linhas a serem lidas  
    char line[101];
    //array do struct 
    struct Ponto pontos[100]; //definicao  de array dos pontos
    //lê as linhas
    while (fgets(line, 101, stream)) //feof - lê até o final do arquivo
    {
        int qtd_vertices=0;
        if(j == 0)
        {
            qtd_vertices = atoi(strdup(line));
        }
        
        pontos[j].num_vertices = qtd_vertices;
        //alocação de memoria com malloc e copia na string linha
        char* linha = strdup(line); 
        //pontos x
        char* token_x = strtok(linha, " ");
        pontos[j].X = atoi(token_x);
        //pontos y
        char * token_y = strtok(NULL, "");

        pontos[j].Y = atof(token_y);
        //incrementa
        j++;
        //limpa o espaço de memoria
        free(linha); 
    }
    int num_vert = pontos[0].num_vertices;
    int array[num_vert][num_vert];
    // #     0    1     3
    // 0     1    2     1
    // 1     3    8     1
    // 2     5    1     1
    
    for(int i = 1; i < j; i++)
    {
         for(int k = 0; k < j - 1; k++){
            if(k == 0){
                array[i-1][k] = (int)pontos[i].X;
            }
            else if(k == 1){
                array[i-1][k] = (int)pontos[i].Y;
            }
            else if(k == 2){
                array[i-1][k] = 1;
            }
         }
    }
    int determinante = 0;
    determinante = CalcularDeterminante(num_vert, array);

    if(determinante < 0){
        determinante *= -1;
    }

    float areaTriagulo = determinante / 2;

    printf("A area do poligono eh %.0f", areaTriagulo);	


    // faz a transformação em um triangulo...
    
    return 0;
}