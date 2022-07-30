//-------------------------------------------------------------------------------------------------------
/*
* @1
* Desenvolver a função: ‘maior_valor’; que recebe quatro valores do tipo inteiro e retorna o maior valor.
*
*/
//-------------------------------------------------------------------------------------------------------
#include <stdio.h>

int maior_valor_da_dupla(int d1, int d2)
{
  if(d1>d2)
  {
    return d1;
  }
  return d2;
}

int maior_valor(int v1, int v2, int v3, int v4)
{
  return maior_valor_da_dupla(maior_valor_da_dupla(v1,v2),maior_valor_da_dupla(v3,v4));
}

int main()
{
  int a, b, c, d;
  scanf("%d %d %d %d", &a, &b, &c, &d);
  int valor = maior_valor(a, b, c, d);
  printf("%d", valor);
  return 0;
}
