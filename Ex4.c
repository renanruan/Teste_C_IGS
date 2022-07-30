//---------------------------------------------------------------------------------------------------------
/*
* @4
* Desenvolva a função a qual recebe dois valores de inteiros e que faça a todas as operacoes de ‘Bitwise’ e devolva o maior resultado
* entre eles.
*/
//---------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int operacao_AND(int v1, int v2)
{
  return v1 & v2;
}

int operacao_OR(int v1, int v2)
{
  return v1 | v2;
}

int operacao_XOR(int v1, int v2)
{
  return v1 ^ v2;
}

int operacao_NOT(int v1)
{
  return ~v1;
}
/*
  O enunciado nao especifica se é para fazer operações de BIT SHIFT e nem como, então decidi implementar
  para ser realizado entre os dois valores, para demonstrar a operação
*/
int operacao_SHIFT_LEFT(int v1, int v2)
{
  return v1 << v2;
}

int operacao_SHIFT_RIGHT(int v1, int v2)
{
  return v1 >> v2;
}



int maior_valor_da_dupla(int d1, int d2) // EXTRAIDO DO EX1
{
  if(d1>d2)
  {
    return d1;
  }
  return d2;
}

int maior_valor(int v1, int v2, int v3, int v4) // EXTRAIDO DO EX1
{
  return maior_valor_da_dupla(maior_valor_da_dupla(v1,v2),maior_valor_da_dupla(v3,v4));
}



int calcular_maximum_bitwise(int v1, int v2)
{
  return maior_valor_da_dupla
  (
    maior_valor_da_dupla
    (
      maior_valor
      (
        operacao_AND(v1,v2),
        operacao_OR(v1,v2),
        operacao_XOR(v1,v2),
        operacao_NOT(v1)
      ),
      maior_valor
      (
        operacao_NOT(v2),
        operacao_SHIFT_LEFT(v1,v2),
        operacao_SHIFT_LEFT(v2,v1),
        operacao_SHIFT_RIGHT(v1,v2)
      )
    ),
    operacao_SHIFT_RIGHT(v2,v1)
  );
}

int main()
{
  int valor_1, valor_2, maior_valor;
  printf("Informe os valores.\n");
  scanf("%d %d", &valor_1, &valor_2);
  maior_valor = calcular_maximum_bitwise(valor_1, valor_2);
  printf("O maior valor e: %d .\n", maior_valor);
  return 0;
}
