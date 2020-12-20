#include <iostream> 

/*
* 
*                  RESULTADO ESPERADO
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
*                        *****
*                       *******
*                      *********
*                     ***********
*                    *************
*                       *******
*                      *********
*                     ***********
*                    *************
*                   ***************
*                      *********
*                     ***********
*                    *************
*                   ***************
*                  *****************
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

// Driver Code 
int main()
{
    const int n = 5;
    // sua arvore de natal vai ter altura n^2
    // e vai ter uma base de tamanho 4n-3
    int base = 4 * n - 3;
    for (int i = 1; i <= n; i++)
    {
        int nb_estrelas_l1 = 2 * i - 1;
        int nb_espacos_l1 = (base - nb_estrelas_l1) / 2;
        for (int j = 1; j <= n; j++)
        {
            int nb_espacos_lj = nb_espacos_l1 - (j - 1);
            for (int k = 0; k < nb_espacos_lj; k++)
                std::cout << " ";
            int nb_estrelas_lj = nb_estrelas_l1 + 2 * (j - 1);
            for (int k = 0; k < nb_estrelas_lj; k++)
                verde();
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
    return 0;
}
