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

constexpr auto nb_expoentes = 10;
constexpr auto base = 1.000000004;

void metodo_estudante_desavisado(const std::vector<unsigned int>& expoentes)
{
	std::vector <double> sols(nb_expoentes);
	auto comeco = std::chrono::steady_clock::now();
	for (int i = 0; i < nb_expoentes; i++) 
	{
		const unsigned int expoente = expoentes[i];
		double res = base;
		for (unsigned int j = 2; j <= expoente; j++)
			res *= base;
		sols[i] = res;
	}
	auto fim = std::chrono::steady_clock::now();
	auto duracao = 
		std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco);
	std::cout << "O tempo que levou para fazer as contas foi de: "
		<< duracao.count() << " ms" << std::endl;
	// imprimindo algumas saidas para que a otimização
	// não perceba que o código sem isso não imprime nada
	std::cout << "Expoentes: " << std::endl; 
	for (int i = 0; i < nb_expoentes; i += 1+(nb_expoentes / 10))
		std::cout << sols[i] << std::endl;
}

void metodo_pow_STL(const std::vector<unsigned int>& expoentes)
{
	std::vector <double> sols(nb_expoentes);
	auto comeco = std::chrono::steady_clock::now();
	for (int i = 0; i < nb_expoentes; i++)
	{
		const unsigned int expoente = expoentes[i];
		sols[i] = pow(base, expoente);
	}
	auto fim = std::chrono::steady_clock::now();
	auto duracao =
		std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco);
	std::cout << "O tempo que levou para fazer as contas foi de: "
		<< duracao.count() << " ms" << std::endl;
	// imprimindo algumas saidas para que a otimização
	// não perceba que o código sem isso não imprime nada
	std::cout << "Expoentes: " << std::endl;
	for (int i = 0; i < nb_expoentes; i += 1+(nb_expoentes / 10))
		std::cout << sols[i] << std::endl;
}

void metodo_estudante_avisado(const std::vector<unsigned int>& expoentes)
{
	std::vector <double> sols(nb_expoentes);
	auto comeco = std::chrono::steady_clock::now();
	for (int i = 0; i < nb_expoentes; i++)
	{
		const unsigned int expoente = expoentes[i];
		double res = 1, pot = base;
		unsigned int j = 1;
		while(1) {
			if(expoente & j) res *= pot;
			if(!(j <<= 1)) break;
			pot *= pot;
		}
		sols[i] = res;
	}
	auto fim = std::chrono::steady_clock::now();
	auto duracao =
		std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco);
	std::cout << "O tempo que levou para fazer as contas foi de: "
		<< duracao.count() << " ms" << std::endl;
	// imprimindo algumas saidas para que a otimização
	// não perceba que o código sem isso não imprime nada
	std::cout << "Expoentes: " << std::endl;
	for (int i = 0; i < nb_expoentes; i+=1+(nb_expoentes/10))
		std::cout << sols[i] << std::endl;
}


int main()
{
	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<unsigned int> 
		distribution(1<<31, (unsigned int) -1);
	std::vector<unsigned int> expoentes(nb_expoentes);
	for (int i = 0; i < nb_expoentes; i++)
		expoentes[i] = distribution(generator);
	metodo_estudante_desavisado(expoentes);
	metodo_pow_STL(expoentes);
	metodo_estudante_avisado(expoentes);
	return 0;
}
