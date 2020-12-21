#include <iostream> 

/*
*             RESULTADO ESPERADO P/ N = 5
* 
*                          *
*                         ***
*                        *****
*                       *******
*                      *********
*                         ***
*                        *****
*                       *******
*                      *********
*                     ***********
*                    *************
*                        *****
*                       *******
*                      *********
*                     ***********
*                    *************
*                   ***************
*                  *****************
*                       *******
*                      *********
*                     ***********
*                    *************
*                   ***************
*                  *****************
*                 *******************
*                *********************
*                      *********
*                     ***********
*                    *************
*                   ***************
*                  *****************
*                 *******************
*                *********************
*               ***********************
*              *************************
*/

int main()
{
    const int N = 5;
    // sua arvore de natal vai ter altura (3n-1)n/2
    // e vai ter uma base de tamanho 6n-5
    const int base = 6 * N - 5;
    int nb_estrelas_na_l1_da_estrutura = 1;
    for (int i = 0; i < N; i++)
    {
        int nb_estrelas_na_l_atual = nb_estrelas_na_l1_da_estrutura;
        for (int j = 0; j < N+i; j++)
        {
            int nb_espacos = (base - nb_estrelas_na_l_atual) / 2;
            for (int k = 0; k < nb_espacos; k++)
                std::cout << " ";
            for (int k = 0; k < nb_estrelas_na_l_atual; k++)
                std::cout << "\033[32m*\033[0m";
            std::cout << std::endl;
            nb_estrelas_na_l_atual += 2;
        }
        nb_estrelas_na_l1_da_estrutura += 2;
    }

    std::cout << std::endl;
    return 0;
}
