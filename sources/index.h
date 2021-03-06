#ifndef INDEX_FILE
#define INDEX_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#include "ferramentas.h"

#define MAX_STR 100
#define MAX_VET 50000
//para o carregamento do arquivo principal.
typedef struct{

	char pais[3];
	char tipoIp[5];
	char ip[25]; //ipv4, ipv6 ou asn
	char data[10];
  	char status[10];
  	char ipQuantity[10];

	long int posicaoLinha;

}tpTuplaPrincipal;

typedef struct indexPais
{
	char pais[3];
	long int posicaoIndexPrincipal;
}tpIndexPais;

typedef struct indexTipoIp{
	char tipoIp[5];
	long int posicao;
}tpIndexTipoIp;

typedef struct rankingPais
{
	char pais[3];
	long int quantidade;
}tpRankingPais;

typedef struct indexPorData{
	char data[10];
	long int posicao;
}tpIndexPorData;

tpTuplaPrincipal linhaParaStruct(char * linha);
void printaTuplaPrincipal(tpTuplaPrincipal tuplaPrincipal);
tpTuplaPrincipal buscaLinha(long int posicao);

// --- FUNÇÕES PARA CRIAÇÃO DE INDEX ---
void indexarPaisesOrdenados();
void indexarPorPais(tpTuplaPrincipal tuplaPrincipal, FILE * indexXpais);
void indexarPorData(tpTuplaPrincipal tuplaPrincipal, FILE *indexPorData);
void indexarPorTipo(tpTuplaPrincipal tuplaPrincipal, FILE * arquivoIndexIpv4, 
													 FILE * arquivoIndexIpv6, 
													 FILE * arquivoIndexAsn);

// FUNÇÕES DE PESQUISA
char * buscarPorDataAlocacao(char *tipoIp, char *ip);
void buscaIndexPorPais();
int contarQuantidadeTipoIp(char *nomeArquivo); //(ipv4, ipv6, asn)
long int ipPorStatus(char * acao, char * tipoIp, char * nomeArquivoIndexPorIp);
int quantidadeRecursos(char *tipoIp, char *tipoData, char *data);

// FUNÇÕES AUXILIARES
void zerarTudo();
char * traduzir(char *argv);
void contar(char *argv[]);
//reune todos os index para fazer os indexadores
void indexador();




int main(int argc, char *argv[]);

#endif