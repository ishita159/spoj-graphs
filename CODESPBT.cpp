#include <bits/stdc++.h>
using namespace std;

int insertion(int vetor[], int n)
{
    int i, aux, pos, cont = 0;

    for (i = 1; i < n; i++)
    {
        aux = vetor[i];

        pos = i - 1;

        while (pos >= 0 && (vetor[pos] > aux))
        {
            vetor[pos + 1] = vetor[pos];
            pos = pos - 1;
            cont++;
        }
        vetor[pos + 1] = aux;
    }
    return cont;
}

int main()
{

    int t, n, i, j;
    /*Tamanho maximo de resultados*/
    int numero_alteracao[5];
    /*Tamanho maximo do vetor */
    int vetor[100000];

    scanf("%d", &t);
    /*Pega valor tela*/

    for (i = 0; i < t; i++)
    {
        /*Loop com numero de vezes que o usuario digitou (1 numero)*/
        scanf("%d", &n);
        /*Numero de elementos na lista*/
        for (j = 0; j < n; j++)
        {
            scanf("%d", &vetor[j]);
            /*Salva a lista na ordem digitada*/
        }

        numero_alteracao[i] = insertion(vetor, n);
    }

    for (i = 0; i < t; i++)
    {
        printf("%d\n", numero_alteracao[i]);
    }
    return 0;
}