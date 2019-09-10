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
*  Autores: mfv - Miguel Fagundes Vuori
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       2.00   mfv   09/09/2019 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       1.00   mfv   06/09/2019 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*     explorar matrizes n x n.
*     A matriz possui uma cabeça que contém uma referência para o nó 1 x 1 da
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
*     $P pMatriz - endereço do ponteiro para a cabeça da matriz a ser manipulada.
*	  $P n - dimensão da matriz
*
*  $ED Descrição da função
*     Cria uma nova matriz n x n.
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
*    $P pMatriz - endereço da cabeça da matriz a ser manipulada.
*
*  $ED Descrição da função
*     Destrói o corpo e a cabeça da matriz, anulando a matriz corrente.
*     Faz nada caso a matriz corrente não exista.
*
***********************************************************************/

   void MAT_DestruirMatriz( tpMatriz * pMatriz ) ;

/***********************************************************************
*
*  $FC Função: MAT Ir para nó ixj
*
*  $EP Parâmetros
*     $P pMatriz - ponteiro para a cabeça da matriz a ser manipulada.
*	  $P i - número da linha da matriz
*     $P j - número da coluna da matriz
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetNaoPossuiNo   - não existe tal nó
*
*
***********************************************************************/

	MAT_tpCondRet MAT_Goto( tpMatriz * pMatriz, int i, int j ) ;

/***********************************************************************
*
*  $FC Função: MAT Obter conteudo corrente
*
*  $EP Parâmetros
*     $P ValorParm - O parâmetro que receberá o conteudo do nó.
*     $P pMatriz - endereço da cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*
***********************************************************************/

   MAT_tpCondRet MAT_ObterContCorr( tpMatriz * pMatriz , void * ValorParm ) ;

/***********************************************************************
*
*  $FC Função: MAT Insere Lista
*
*  $EP Parâmetros
*     $P ValorParm - O valor ser inserido no nó.
*                    
*     $P pMatriz - endereço da cabeça da matriz a ser manipulada.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*
***********************************************************************/

   MAT_tpCondRet MAT_InsereLista( tpMatriz * pMatriz, void * ValorParm );

#undef MATRIZ_EXT

/********** Fim do módulo de definição: Módulo matriz **********/

#else
#endif
