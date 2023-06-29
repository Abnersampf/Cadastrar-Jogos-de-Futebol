#include <stdio.h>
#include <locale.h>

struct jogo
{ 
  char data[20];
  char local[50];
  char time1[50];
  char time2[50];
};

struct jogo informacoes[999];

int opcao, continuar, posicao1 = 0, posicao2 = 0, posicao2_reserva = 0, posicao_data, contador, contador2, contador3, data_existe = 0;
int qtd_posicoes2[99];
int num_posicoes2[99];
char data_escolhida[20];
char continuar2[20];

void cadastrar()
{
  posicao2_reserva = 0;
  // Apresenta o cadastro de jogo(s)
  system("cls");
  printf("\n-------------------------------------");
  printf("\n|         CADASTRAR UM JOGO         |");
  printf("\n-------------------------------------");

  // Colhe as informações do jogo
  printf("\nAVISO: NÃO CADASTRE DUAS DATAS IGUAIS");
  printf("\n");
  printf("\nDigite a data do jogo: ");
  scanf(" %[^\n]s", &informacoes[posicao1].data);
  do
  {
    printf("\nDigite o local do jogo: ");
    scanf(" %[^\n]s", &informacoes[posicao2].local);
    printf("\nDigite o nome do 1º time: ");
    scanf(" %[^\n]s", &informacoes[posicao2].time1);
    printf("\nDigite o nome do 2º time: ");
    scanf(" %[^\n]s", &informacoes[posicao2].time2);
    printf("\nDeseja cadastrar mais um jogo nessa data ?");
    printf("\n[1 - SIM | 0 - NÃO]: ");
    scanf("%d", &continuar);
    printf("\n------------------------------------------");

    posicao2++;
    posicao2_reserva++;
    qtd_posicoes2[posicao1] = posicao2_reserva;
    num_posicoes2[posicao1] = posicao2;

  } while (continuar != 0);
      
  posicao1++;

}

void listar()
{
  system("cls");
  printf("\n---------------------------------------");
  printf("\n|       APRESENTAR O(S) JOGO(s)       |");
  printf("\n---------------------------------------");
  printf("\nDigite uma data: ");
  scanf(" %[^\n]s", &data_escolhida);
  // Verifica se a data que o usuário digitou é valida 
  for (contador = 0; contador < posicao1; contador++)
  {
    if (strcmp(informacoes[contador].data, data_escolhida) == 0)
    {
      data_existe = 1;
      posicao_data = contador;
    }
  }
      // Se a data for válida o programa vai mostrar os jogos que aconteceram nessa data
  if (data_existe == 1)
  {
    contador3 = num_posicoes2[posicao_data] - qtd_posicoes2[posicao_data];
    printf("\nOs jogos que aconteceram em %s foram:", data_escolhida);
    for (contador = 0; contador < qtd_posicoes2[posicao_data]; contador++)
    {
      printf("\n=======================");
      printf("\n|       JOGO %d        |", contador + 1);
      printf("\n=======================");
      printf("\nLocal do jogo: %s", informacoes[contador3].local);
      printf("\nTime 1: %s", informacoes[contador3].time1);
      printf("\nTime 2: %s", informacoes[contador3].time2);
      contador3++;
    }
    }
    else
    {
      printf("\nNenhum jogo foi registrado nessa data !");
    }
    data_existe = 0;
    printf("\n");
    printf("\nDigite algo para continuar... ");
    scanf("%s", continuar2);
}

int main()
{

  setlocale(LC_ALL, "Portuguese_Brazil");

  do
  {
    // Apresenta o menu de opções
    system("cls");
    printf("\n----------------------------");
    printf("\n|      MENU DE OPÇÕES      |");
    printf("\n----------------------------");
    printf("\n|1 - Cadastrar jogo(s)");
    printf("\n|2 - Apresentar o(s) jogo(s)");
    printf("\n|3 - Sair");
    printf("\n----------------------------");
    // Pegunta o que o usuário quer fazer
    printf("\nDigite o que deseja fazer: ");
    scanf("%d", &opcao);

    // Cadastra o(s) jogo(s)
    if (opcao == 1)
    {
      cadastrar();
    }
    // Apresenta os jogos (De acordo com a data digitada);
    else if (opcao == 2)
    {
      listar();
    }

  } while (opcao != 3);
  
  return 0;
}
