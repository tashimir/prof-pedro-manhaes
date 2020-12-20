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

// imprime um * 
// (verde, se voce estiver no windows 10)
inline void verde()
{ 
    // primeira linha e terceira linha
    // estao ai para colorir de verde
    // se voce estiver no Windows10 deve funcionar
    // senao, voce pode comentar essas linhas mesmo
    std::cout << "\033[32m"; 
    std::cout << "*";
    std::cout << "\033[0m";
}

int main()
{
    const int n = 5;
    // sua arvore de natal vai ter altura n^2
    // e vai ter uma base de tamanho 4n-3
    int base = 6 * n - 5;
    int nb_estrelas_na_linha_1_da_estrutura = 1;
    for (int i = 0; i < n; i++)
    {
        int nb_estrelas_na_l_atual = nb_estrelas_na_linha_1_da_estrutura;
        for (int j = 0; j < n+i; j++)
        {
            int nb_espacos = (base - nb_estrelas_na_l_atual) / 2;
            for (int k = 0; k < nb_espacos; k++)
                std::cout << " ";
            for (int k = 0; k < nb_estrelas_na_l_atual; k++)
                verde();
            std::cout << std::endl;
            nb_estrelas_na_l_atual += 2;
        }
        nb_estrelas_na_linha_1_da_estrutura += 2;
    }

    std::cout << std::endl;
    return 0;
}
