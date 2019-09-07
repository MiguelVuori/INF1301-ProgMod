#if ! defined( MATRIZ_ )
#define MATRIZ_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo matriz
*
*  Arquivo gerado:              MATRIZ.H
*  Letras identificadoras:      MAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa
*
*  $HA Histórico de evolução:
*     Vers�o  Autor    Data     Observações
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestrutura��o
*       1.00   avs   15/08/2001 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar matrizes n x n.
*     A matriz possui uma cabeça que contém uma referência para o nó 0 x 0 da
*     matriz e outra para um nó corrente da matriz.
*     A cada momento o módulo admite no máximo uma única matriz.
*     Ao iniciar a execução do programa não existe matriz.
*
***************************************************************************/
 
#if defined( MATRIZ_OWN )
   #define MATRIZ_EXT
#else
   #define MATRIZ_EXT extern
#endif


/***********************************************************************
*
*  $TC Tipo de dados: MAT Condicoes de retorno
*
*
***********************************************************************/

   typedef enum {

         MAT_CondRetOK = 0 ,
               /* Executou correto */

         MAT_CondRetErroEstrutura = 1 ,
               /* Estrutura da matriz está errada */

         MAT_CondRetMatrizNaoExiste = 2 ,
               /* Matriz não existe */

         MAT_CondRetMatrizVazia = 3 ,
               /* Matriz está vazia */

         MAT_CondRetNaoPossuiNo = 4 ,
               /* No corrente não possui nó na direção desejada */

         MAT_CondRetFaltouMemoria = 5
               /* Faltou memória ao alocar dados */

   } MAT_tpCondRet ;

/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor da cabeça de uma matriz
*
*
***********************************************************************/

   typedef struct tgMatriz tpMatriz;

/***********************************************************************
*
*  $FC Função: MAT Criar matriz
*
*  $EP Parâmetros
*     $P pMatriz - endereço do ponteiro para a cabeça da árvore a ser manipulada.
*	  $P n - dimensão da matriz
*
*  $ED Descrição da função
*     Cria uma nova matriz n x n.
*     Caso já exista uma matriz, esta será destruída.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetFaltouMemoria
*
***********************************************************************/

   MAT_tpCondRet MAT_CriarMatriz( int n , tpMatriz ** pMatriz) ;


/***********************************************************************
*
*  $FC Função: MAT Destruir matriz
*
*  $EP Parâmetros
*    $P pArvore - endereço do ponteiro para a cabeça da matriz a ser manipulada.
*
*  $ED Descrição da função
*     Destrói o corpo e a cabeça da matriz, anulando a matriz corrente.
*     Faz nada caso a matriz corrente não exista.
*
***********************************************************************/

   void MAT_DestruirMatriz( tpMatriz ** pMatriz ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Oeste
*
*  $EP Parâmetros
*     $P pArvore - ponteiro para a cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetMatrizNaoExiste
*     ARV_CondRetMatrizVazia
*     ARV_CondRetNaoPossuiNo   - nó corrente não possui nó á oeste
*
***********************************************************************/

	MAT_tpCondRet MAT_IrNoOeste( tpMatriz * pMatriz ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Norte
*
*  $EP Parâmetros
*     $P pArvore - ponteiro para a cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetMatrizNaoExiste
*     ARV_CondRetMatrizVazia
*     ARV_CondRetNaoPossuiNo   - nó corrente não possui nó á norte
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoNorte( tpMatriz * pMatriz ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Leste
*
*  $EP Parâmetros
*     $P pArvore - ponteiro para a cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetMatrizNaoExiste
*     ARV_CondRetMatrizVazia
*     ARV_CondRetNaoPossuiNo   - nó corrente não possui nó á leste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoLeste( tpMatriz * pMatriz ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Sul
*
*  $EP Parâmetros
*     $P pArvore - ponteiro para a cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo  - nó corrente não possui nó á sul
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoSul( tpMatriz * pMatriz ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Sudoeste
*
*  $EP Parâmetros
*     $P pArvore - ponteiro para a cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo   - nó corrente não possui nó á sudoeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoSudoeste( tpMatriz * pMatriz ) ;

/***********************************************************************
*
*  $FC Função: MAT Ir para nó Noroeste
*
*  $EP Parâmetros
*     $P pArvore - ponteiro para a cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo   - nó corrente não possui nó á Noroeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoNoroeste( tpMatriz * pMatriz ) ;

/***********************************************************************
*
*  $FC Função: MAT Ir para nó Nordeste
*
*  $EP Parâmetros
*     $P pArvore - ponteiro para a cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetArvoreVazia
*     MAT_CondRetNaoPossuiNo   - nó corrente não possui nó á Nordeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoNordeste( tpMatriz * pMatriz ) ;

/***********************************************************************
*
*  $FC Função: MAT Ir para nó Sudeste
*
*  $EP Parâmetros
*     $P pArvore - ponteiro para a cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo   - nó corrente não possui nó á Sudeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoSudeste( tpMatriz * pMatriz ) ;

/***********************************************************************
*
*  $FC Função: MAT Obter lista corrente
*
*  $EP Parâmetros
*     $P ValorParm - O parâmetro que receberá o endereço da lista contida no nó.
*                    Este parâmetro é passado por referência.
*     $P pArvore - ponteiro para a cabeça da árvore a ser manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*
***********************************************************************/

   MAT_tpCondRet MAT_ObterListaCorr( char ** ValorParm ) ;

#undef MATRIZ_EXT

/********** Fim do módulo de definição: Módulo matriz **********/

#else
#endif
