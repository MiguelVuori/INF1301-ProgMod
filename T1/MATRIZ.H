#if ! defined( MATRIZ_ )
#define MATRIZ_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo matriz
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       3.00   avs   28/02/2003 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   03/08/2002 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   15/08/2001 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa um conjunto simples de fun��es para criar e
*     explorar matrizes n x n.
*     A matriz possui uma cabe�a que cont�m uma refer�ncia para o n� 0 x 0 da
*     matriz e outra para um n� corrente da matriz.
*     A cada momento o m�dulo admite no m�ximo uma �nica matriz.
*     Ao iniciar a execu��o do programa n�o existe matriz.
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
               /* Estrutura da matriz est� errada */

         MAT_CondRetMatrizNaoExiste = 2 ,
               /* Matriz n�o existe */

         MAT_CondRetMatrizVazia = 3 ,
               /* Matriz est� vazia */

         MAT_CondRetNaoPossuiNo = 4 ,
               /* N� corrente n�o possui n� na dire��o desejada */

         MAT_CondRetFaltouMemoria = 5
               /* Faltou mem�ria ao alocar dados */

   } MAT_tpCondRet ;

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor da cabeça de uma árvore
*
*
***********************************************************************/

   typedef struct tgMatriz tpMatriz;

/***********************************************************************
*
*  $FC Fun��o: MAT Criar matriz
*
*  $ED Descri��o da fun��o
*     Cria uma nova matriz n x n.
*     Caso j� exista uma matriz, esta ser� destru�da.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetFaltouMemoria
*
***********************************************************************/

   MAT_tpCondRet MAT_CriarMatriz( int n ) ;


/***********************************************************************
*
*  $FC Fun��o: MAT Destruir matriz
*
*  $ED Descri��o da fun��o
*     Destr�i o corpo e a cabe�a da �rvore, anulando a �rvore corrente.
*     Faz nada caso a �rvore corrente n�o exista.
*
***********************************************************************/

   void MAT_DestruirMatriz( void ) ;


/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� Oeste
*
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetMatrizNaoExiste
*     ARV_CondRetMatrizVazia
*     ARV_CondRetNaoPossuiNo   - n� corrente n�o possui n� � oeste
*
***********************************************************************/

		MAT_tpCondRet MAT_IrNoOeste( void ) ;


/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� Norte
*
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetMatrizNaoExiste
*     ARV_CondRetMatrizVazia
*     ARV_CondRetNaoPossuiNo   - n� corrente n�o possui n� � oeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoNorte( void ) ;


/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� Leste
*
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetMatrizNaoExiste
*     ARV_CondRetMatrizVazia
*     ARV_CondRetNaoPossuiNo   - n� corrente n�o possui n� � leste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoLeste( void ) ;


/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� Sul
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo  - n� corrente n�o possui n� � esquerda
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoSul( void ) ;


/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� Sudoeste
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo   - n� corrente n�o possui n� � sudoeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoSudoeste( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� Noroeste
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo   - n� corrente n�o possui n� � Noroeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoNoroeste( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� Nordeste
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetArvoreVazia
*     MAT_CondRetNaoPossuiNo   - n� corrente n�o possui n� � Nordeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoNordeste( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MAT Ir para n� Sudeste
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*     MAT_CondRetNaoPossuiNo   - n� corrente n�o possui n� � Sudeste
*
***********************************************************************/

   MAT_tpCondRet MAT_IrNoSudeste( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MAT Obter lista corrente
*
*  $EP Par�metros
*     $P ValorParm - � o par�metro que receber� o endere�o da lista contida no n�.
*                    Este par�metro � passado por refer�ncia.
*
*  $FV Valor retornado
*     MAT_CondRetOK
*     MAT_CondRetMatrizNaoExiste
*     MAT_CondRetMatrizVazia
*
***********************************************************************/

   MAT_tpCondRet MAT_ObterListaCorr( char ** ValorParm ) ;

#undef MATRIZ_EXT

/********** Fim do m�dulo de defini��o: M�dulo matriz **********/

#else
#endif
