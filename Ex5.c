//---------------------------------------------------------------------------------------------------------
/*
* @5
* Desenvolva a função a qual recebe três arrays, os dois primeiros são de inteiros o terceiro é de caracteres, o qual deve ser
* preenchido com 'X' ou 'O' pela função.
*
* A função deve comparar os dois arrays de inteiros, procurando se os valores do array de 'cartela' é encontrada
* dentro do array de 'sorteio'.
* Caso o numero de 'cartela' seja encontrada dentro do array de 'sorteio', a posicao do número da 'cartela' (índice) deve ser
* usada para marcar o 'X' dentro do array 'marcacao', caso contrário voce deve marcar 'O'.
* Obs.1: Arrays: 'cartela' e 'marcacao' tem o mesmo tamanho, já o array de sorteio pode ser de tamanho diferente.
* Obs.2: Os numeros nos arrays de inteiros não estão ordenados e não ha duplicacao
* +++++++++++++++++++++++++++++++++++++++
* Exemplo....
*
* Sorteio: 1, 5, 6, 7, 8, 45, 3, 10, 13
* Cartela: 1, 2, 3, 4, 5, 6, 7, 11
* Marcacao: X, O, X, O, X, X, X, 0
* +++++++++++++++++++++++++++++++++++++++
*/
//---------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SORTEIO 30
#define MAX_MARCACAO 15

int ordenar_array(int *array, int max_elementos) // INSERTION SORT // EXTRAIDO DO EX3
{
  int id_insercao, id_varredura;
  int aux;

  for(id_insercao = 1; id_insercao < max_elementos; id_insercao++) // LOOP DE ESCOLHA DO PIVO
  {
    aux = array[id_insercao];

    if(aux == 0)
    {
        break;
    }

    for(id_varredura = id_insercao - 1; id_varredura >=0; id_varredura--) // LOOP DE ORDENACAO DO PIVO
    {
      if(aux < array[id_varredura])
      {
        array[id_varredura+1] = array[id_varredura];
      }
      else
      {
        break;
      }
    }
    array[id_varredura+1] = aux;
  }

  return id_insercao;
}

int buscar_numero_no_array(int *array, int num, int min_id, int max_id) // DIVIDE AND CONQUER
{
  if(min_id == max_id)
  {
    return num == array[min_id];
  }
  else
  {
      int id = (min_id + max_id) / 2;

      if(array[id] < num)
      {
        return buscar_numero_no_array(array, num, id+1, max_id);
      }
      else if(array[id] > num)
      {
        return buscar_numero_no_array(array, num, min_id, id);
      }
      else
      {
        return 1;
      }
  }
}

void avaliar_marcacao(int *sorteio, int tam_sorteio, int *cartela, char* marcacao, int tam_marcacao)
{
  int numeros_sorteados = ordenar_array(sorteio, tam_sorteio); // PREPARA ARRAY ORDENANDO

  for(int i = 0; i < tam_marcacao; i++)
  {
    if(buscar_numero_no_array(sorteio, cartela[i], 0 , numeros_sorteados-1)) // BUSCA VALOR
    {
      marcacao[i] = 'O';
    }
    else
    {
      marcacao[i] = 'X';
    }
  }
}

int main()
{
  int sorteio[MAX_SORTEIO] = {11,21,5,1,8,20,60,58,44,49,25,12,14,27,50,56,9,29,33,10,40,6,51,55,22};
  int cartela[MAX_MARCACAO] = {2,15,33,41,48,3,20,35,44,57,12,29,40,50,60};
  char marcacao[MAX_MARCACAO] = {""};

  avaliar_marcacao(sorteio, MAX_SORTEIO, cartela,marcacao, MAX_MARCACAO);

  int idx = 0;
  do
  {
    printf(" %c ", marcacao[idx]);
    if((++idx)%5 == 0)
    {
      printf("\n");
    }
  }while (idx < MAX_MARCACAO);
  return 0;
}
