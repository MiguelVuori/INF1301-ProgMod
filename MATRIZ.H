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
*     Versão  Autor    Data     Observações
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
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
               /* Nó corrente não possui nó na direção desejada */

         MAT_CondRetFaltouMemoria = 5
               /* Faltou memória ao alocar dados */

   } MAT_tpCondRet ;


/***********************************************************************
*
*  $FC Função: MAT Criar matriz
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

   MAT_tpCondRet MAT_CriarMatriz( int n ) ;


/***********************************************************************
*
*  $FC Função: MAT Destruir matriz
*
*  $ED Descrição da função
*     Destrói o corpo e a cabeça da árvore, anulando a árvore corrente.
*     Faz nada caso a árvore corrente não exista.
*
***********************************************************************/

   void MAT_DestruirMatriz( void ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Oeste
*
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetMatrizNaoExiste
*     ARV_CondRetMatrizVazia
*     ARV_CondRetNaoPossuiNo   - nó corrente não possui nó à oeste
*
***********************************************************************/

		MAT_tpCondRet MAT_IrNoOeste( void ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Norte
*
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetMatrizNaoExiste
*     ARV_CondRetMatrizVazia
*     ARV_CondRetNaoPossuiNo   - nó corrente não possui nó à oeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoNorte( void ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Leste
*
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetMatrizNaoExiste
*     ARV_CondRetMatrizVazia
*     ARV_CondRetNaoPossuiNo   - nó corrente não possui nó à leste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoLeste( void ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Sul
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo  - nó corrente não possui nó à esquerda
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoSul( void ) ;


/***********************************************************************
*
*  $FC Função: MAT Ir para nó Sudoeste
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo   - nó corrente não possui nó à sudoeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoSudoeste( void ) ;

/***********************************************************************
*
*  $FC Função: MAT Ir para nó Noroeste
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo   - nó corrente não possui nó à Noroeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoNoroeste( void ) ;

/***********************************************************************
*
*  $FC Função: MAT Ir para nó Nordeste
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetArvoreVazia
*     MAT_CondRetNaoPossuiNo   - nó corrente não possui nó à Nordeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoNordeste( void ) ;

/***********************************************************************
*
*  $FC Função: MAT Ir para nó Sudeste
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo   - nó corrente não possui nó à Sudeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoSudeste( void ) ;

/***********************************************************************
*
*  $FC Função: MAT Obter lista corrente
*
*  $EP Parâmetros
*     $P ValorParm - é o parâmetro que receberá o endereço da lista contida no nó.
*                    Este parâmetro é passado por referência.
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
