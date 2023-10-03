/*
=---------------=
=-> Cabe�alho <-=
=---------------=
*/
/**
 * @author Kau� dos Santos Lima
 * @since 03/10/2023
 * @details Criando e abrindo arquivos.
 * @note r: Permiss�o de abertura somente para leitura. � necess�rio que o arquivo j� esteja presente no disco.
 *   w: Permiss�o de abertura para escrita (grava��o). Este c�digo cria o arquivo caso ele n�o exista, 
 *   e caso o mesmo exista ele recria o arquivo novamente fazendo com que o conte�do seja perdido. 
 *   Portanto devemos tomar muito cuidado ao usar esse tipo de abertura.
 *   a: Permiss�o para abrir um arquivo texto para escrita(grava��o), permite acrescentar novos dados 
 *   ao final do arquivo. Caso n�o exista, ele ser� criado.
 **/

/*
=--------------=
=-> Includes <-=
=--------------=
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/*
=------------------=
=-> Estruturas <-=
=------------------=
*/
// < Cria a estrutura dia, m�s e ano de nascimento da pessoa cadastrada na agenda >
struct dma
{
    int d;
    int m;
    int a;
};

typedef struct dma t_dma;

// < Cria a estrutura para a pessoa que ser� cadastrada >
struct pessoa
{
    unsigned char nome[64];
    struct dma dt_nasc;
};

typedef struct pessoa t_pessoa;

/*
=------------------=
=-> Subprogramas <-=
=------------------=
*/
// < Fun��o para abrir/criar um arquivo >
FILE *criar_arquivo (char filename[])
{
    FILE *arq;
    
    arq = fopen(filename, "a");
    
    return arq;
}

/*
=------------------------=
=-> Programa principal <-=
=------------------------=
*/
int main(void) 
{
	// < Seta localidade para aceitar acentos >
	setlocale(LC_ALL, "Portuguese");
	
    // < Declara��o de vari�veis locais >
    FILE *arq;
    int d, m, a, i = 0;
    unsigned char filename[] = "agenda.txt", nome[64], resp[8]; //unsigned para pegar acentos
    t_dma dt;
    t_pessoa agenda[1000];
    
    // < Criando um arquivo >
    arq = criar_arquivo(filename);
    
    // < Trata erros >
    if(arq == NULL)
	{
        printf("[!] Erro na abertura do arquivo \"%s\"[!]\n", filename);
        
        return -1;
    }
    
	// < Entrada de dados >
    do
	{
        printf("\n<--= A G E N D A =-->\n");
        printf("> Deseja adicionar uma entrada na agenda? [S/N]: ");
        scanf("%1s",resp);
        getchar();
        
        if(resp[0] == 'S' || resp[0] == 's')
		{
            printf("<--= Dados da pessoa #%i =-->\n", i + 1);
            
			printf("> Nome: ");
            scanf("%65[^\n]s", agenda[i].nome);
            getchar();
            
            printf("> Dia de nascimento: ");
            scanf("%i", &agenda[i].dt_nasc.d);
            
            printf("> M�s de nascimento: ");
            scanf("%i", &agenda[i].dt_nasc.m);
            
            printf("> Ano de nascimento: ");
            scanf("%i", &agenda[i].dt_nasc.a);

            dt = agenda[i].dt_nasc;
            
            // < Escreve no arquivo >
            fprintf(arq,"-----------------------------------------------------\nPessoa: %s\nData de nascimento: %i/%i/%i\n", agenda[i].nome, dt.d, dt.m, dt.a);
            
            // < Incrementa a quantidade de pessoas listadas >
			if(i <= 1000)
			{
                i++;
            }
        }
    } while (resp[0]=='S'||resp[0]=='s');
    
    // < Fecha o arquivo >
    fclose(arq);
    
    return 0;
}
