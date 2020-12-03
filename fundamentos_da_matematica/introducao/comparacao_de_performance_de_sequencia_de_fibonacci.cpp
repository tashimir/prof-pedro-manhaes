/*
*
* Autor: Pedro Machado Manhães de Castro
* YouTube: https://www.youtube.com/pedromachadomanhaesdecastro
* Home Page: https://www.cin.ufpe.br/~pmmc
* Instagram: https://www.instagram.com/prof.pedromanhaes/
* Facebook: https://www.facebook.com/prof.pedromanhaes
* Twitch: https://www.twitch.tv/pedromachadomanhaes
* LinkedIn: https://www.linkedin.com/in/pedro-machado-manhaes-de-castro/
* Twitter: https://twitter.com/PedroMMdeCastro
*
* LICENCE: Free to use
*
*/

#include <iostream>
#include <cmath>
#include <chrono> 
#include <vector>
#include <random>

constexpr auto nb_casos = 1;

void metodo_estudante_desavisado(const std::vector<unsigned int>& casos)
{
	std::vector <unsigned int> sols(nb_casos);
	auto comeco = std::chrono::steady_clock::now();
	for (int i = 0; i < nb_casos; i++)
	{

		const unsigned int n = casos[i];
		if (n == 0 || n == 1) 
		{
			sols[i] = n;
			continue;
		}
		unsigned int x = 1, y = 1, z;
		for (unsigned int j = 3; j <= n; j++)
		{
			z = (y + x) % 10000;
			x = y;
			y = z;
		}
		sols[i] = y;
	}
	auto fim = std::chrono::steady_clock::now();
	auto duracao =
		std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco);
	std::cout << "O tempo que levou para fazer as contas foi de: "
		<< duracao.count() << " ms" << std::endl;
	// imprimindo algumas saidas para que a otimização
	// não perceba que o código sem isso não imprime nada
	std::cout << "Fibs: " << std::endl;
	for (int i = 0; i < nb_casos; i += 1 + (nb_casos / 10))
		std::cout << i << ": " << sols[i] << std::endl;
}

void metodo_estudante_avisado(const std::vector<unsigned int>& casos)
{
	std::vector <unsigned int> sols(nb_casos);
	auto comeco = std::chrono::steady_clock::now();
	for (int i = 0; i < nb_casos; i++)
	{
		unsigned int n = casos[i];
		if (n == 0 || n == 1)
		{
			sols[i] = n;
			continue;
		}
		--n;
		unsigned int j = 1;
		unsigned int res11 = 1, res12 = 0, res21 = 0, res22 = 1;
		unsigned int pot11 = 1, pot12 = 1, pot21 = 1, pot22 = 0;
		unsigned int t11, t12, t21, t22;
		while(1) 
		{
			if (n & j) {
				t11 = res11 * pot11 + res12 * pot21;
				t12 = res11 * pot12 + res12 * pot22;
				t21 = res21 * pot11 + res22 * pot21;
				t22 = res21 * pot12 + res22 * pot22;
				res11 = t11 % 10000;
				res12 = t12 % 10000;
				res21 = t21 % 10000;
				res22 = t22 % 10000;
			}
			if (!(j <<= 1)) break;
			t11 = pot11 * pot11 + pot12 * pot21;
			t12 = pot11 * pot12 + pot12 * pot22;
			t21 = pot21 * pot11 + pot22 * pot21;
			t22 = pot21 * pot12 + pot22 * pot22;
			pot11 = t11 % 10000; 
			pot12 = t12 % 10000; 
			pot21 = t21 % 10000; 
			pot22 = t22 % 10000;
		}
		sols[i] = res11;
	}
	auto fim = std::chrono::steady_clock::now();
	auto duracao =
		std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco);
	std::cout << "O tempo que levou para fazer as contas foi de: "
		<< duracao.count() << " ms" << std::endl;
	// imprimindo algumas saidas para que a otimização
	// não perceba que o código sem isso não imprime nada
	std::cout << "Fibs: " << std::endl;
	for (int i = 0; i < nb_casos; i += 1 + (nb_casos / 10))
		std::cout << i << ": " << sols[i] << std::endl;
}


int main()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<unsigned int>
		distribution(1 << 31, (unsigned int)-1);
	std::vector<unsigned int> casos(nb_casos);
	for (int i = 0; i < nb_casos; i++)
		casos[i] = distribution(generator);
	metodo_estudante_desavisado(casos);
	metodo_estudante_avisado(casos);
	return 0;
}
