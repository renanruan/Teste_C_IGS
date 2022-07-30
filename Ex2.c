//-------------------------------------------------------------------------------------------------------
/*
* @2
* Desenvolva a função que retorna o valor fatorial no parâmetro 'valor_ft'
*
*/
//-------------------------------------------------------------------------------------------------------
#include <stdio.h>

void calc_fatorial(int *valor_ft, int valor_n) // alterei a chamada da função para se adequar ao formatos das variaveis
{
  *valor_ft = 1;
  for(int i = valor_n; i > 1; i--)
  {
    *valor_ft *= i;
  }
}

int main()
{
  int v, vf = 0;
  int *pv = &v;
  scanf("%d", &v);
  calc_fatorial(&vf, *pv);
  printf("Valor fatorial de: [%d] é [%d]", v, vf);
  return 0;
}
