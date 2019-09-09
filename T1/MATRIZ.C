/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo matriz
*
*  Arquivo gerado:              MATRIZ.C
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
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>

#define MATRIZ_OWN
#include "MATRIZ.H"
#undef MATRIZ_OWN

/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor do n� da matriz
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o do n�
*
***********************************************************************/

   typedef struct tgNoMatriz {

         void * conteudo;
               /* Conte�do do n� corrente em formato de ponteiro
               *
               *$EED Assertivas estruturais
               *   O conte�do do n� � tratado como um ponteiro para uma posi��o de mem�ria
               *   */

         struct tgNoMatriz * pNoNE ;
               /* Ponteiro para o n� a nordeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, todos os n�s apontados recursivamente a partir do n� corrente por pNoN e por pNoS, separadamente, s�o NULL ou apontam para NULL em pNoNE, ou todos os n�s apontados recursivamente a partir do n� corrente por pNoE e por pNoO, separadamente, s�o NULL ou apontam para NULL em pNoNE.
               *   Se n�o for NULL, pNoNE->pNoSO, pNoNE->pNoS->pNoO e pNoNE->pNoO->pNoS apontam todos para o n� corrente.
               *   */

         struct tgNoMatriz * pNoE ;
               /* Ponteiro para o n� a este
               *
               *$EED Assertivas estruturais
               *   Se for NULL, pNoNE e pNoSE tamb�m apontam para NULL.
               *   Se n�o for NULL, pNoE->pNoO aponta para o n� corrente.
               *   */

         struct tgNoMatriz * pNoSE ;
               /* Ponteiro para o n� a sudeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, todos os n�s apontados recursivamente a partir do n� corrente por pNoN e por pNoS, separadamente, s�o NULL ou apontam para NULL em pNoSE, ou todos os n�s apontados recursivamente a partir do n� corrente por pNoE e por pNoO, separadamente, s�o NULL ou apontam para NULL em pNoSE.
               *   Se n�o for NULL, pNoSE->pNoNO, pNoSE->pNoN->pNoO e pNoSE->pNoO->pNoN apontam todos para o n� corrente.
               *   */

         struct tgNoMatriz * pNoS ;
               /* Ponteiro para o n� a sul
               *
               *$EED Assertivas estruturais
               *   Se for NULL, pNoSE e pNoSO tamb�m apontam para NULL.
               *   Se n�o for NULL, pNoS->pNoN aponta para o n� corrente.
               *   */

         struct tgNoMatriz * pNoSO ;
               /* Ponteiro para o n� a sudoeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, todos os n�s apontados recursivamente a partir do n� corrente por pNoN e por pNoS, separadamente, s�o NULL ou apontam para NULL em pNoSO, ou todos os n�s apontados recursivamente a partir do n� corrente por pNoE e por pNoO, separadamente, s�o NULL ou apontam para NULL em pNoSO.
               *   Se n�o for NULL, pNoSO->pNoNE, pNoSO->pNoN->pNoE e pNoSO->pNoE->pNoN apontam todos para o n� corrente.
               *   */

         struct tgNoMatriz * pNoO ;
               /* Ponteiro para o n� a oeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, pNoSO e pNoNO tamb�m apontam para NULL.
               *   Se n�o for NULL, pNoO->pNoE aponta para o n� corrente.
               *   */

         struct tgNoMatriz * pNoNO ;
               /* Ponteiro para o n� a noroeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, todos os n�s apontados recursivamente a partir do n� corrente por pNoN e por pNoS, separadamente, s�o NULL ou apontam para NULL em pNoNO, ou todos os n�s apontados recursivamente a partir do n� corrente por pNoE e por pNoO, separadamente, s�o NULL ou apontam para NULL em pNoNO.
               *   Se n�o for NULL, pNoNO->pNoSE, pNoNO->pNoS->pNoE e pNoNO->pNoE->pNoS apontam todos para o n� corrente.
               *   */

         struct tgNoMatriz * pNoN ;
               /* Ponteiro para o n� a norte
               *
               *$EED Assertivas estruturais
               *   Se for NULL, pNoNO e pNoNE tamb�m apontam para NULL.
               *   Se n�o for NULL, pNoN->pNoS aponta para o n� corrente.
               *   */
   } tpNoMatriz ;

/***********************************************************************
*
*  $TC Tipo de dados: Mat Descritor da cabe�a de uma matriz quadrada
*
*
*  $ED Descri��o do tipo
*     A cabe�a da matriz � o ponto de acesso para uma determinada matriz quadrada.
*     Por interm�dio da refer�ncia para o n� corrente, coordenadas latitudinais e longitudinais
*     pai pode-se navegar a matriz.
*
***********************************************************************/

   typedef struct tgMatriz {

         tpNoMatriz * pNoRaiz ;
               /* Ponteiro para o n� 1,1 da matriz */

         tpNoMatriz * pNoCorr ;
               /* Ponteiro para o n� corrente da matriz */

		 int dimensao;
		      /* Guarda a dimens�o n da matriz quadrada n x n */

		 int CoorI;
		      /* Guarda a coordanada longitudinal do n� apontado por pNoCorr na matriz */

		 int CoorJ;
		      /* Guarda a coordenada latitudinal do n� apontado por pNoCorr na matriz */

   } tpMatriz ;


/***** Prot�tipos das fun��es encapuladas no m�dulo *****/
/*
   static tpNoMatriz * CriarNo( char ValorParm ) ;

   static MAT_tpCondRet CriarNoRaiz( char ValorParm ) ;

   static void DestroiArvore( tpNoMatriz * pNo ) ;
/*
/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: MAT Criar matriz
*  ****/

   MAT_tpCondRet MAT_CriarMatriz( int n , tpMatriz ** pMatriz )
   {
	   if ( n < 0 ) // n n�o pode ser negativo - entrada invalida
	   {}
	   else
	   {
		   *pMatriz = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
		   if ( *pMatriz == NULL )
		   {
			   return MAT_CondRetFaltouMemoria ;
		   }
		   if ( n == 0 )
			   // caso a dimensao fornecida seja 0 � criada apenas a cabe�a com uma matriz vazia (sem uma matriz)
		   {
			   (*pMatriz)->CoorI = 0;
			   (*pMatriz)->CoorJ = 0;
			   (*pMatriz)->dimensao = 0;
			   (*pMatriz)->pNoCorr = NULL;
			   (*pMatriz)->pNoRaiz = NULL;
		   }
		   else
		   {
			   tpNoMatriz * pNoMatriz;
			   pNoMatriz = ( tpNoMatriz * ) malloc( sizeof( tpNoMatriz )) ;
			   if ( pNoMatriz == NULL )
			   {
				   MAT_DestruirMatriz( pMatriz );
				   return MAT_CondRetFaltouMemoria ;
			   }
			   (*pMatriz)->pNoRaiz = pNoMatriz ;
			   (*pMatriz)->dimensao = n;
			   pNoMatriz->conteudo = NULL;
			   pNoMatriz->pNoN = NULL;
			   pNoMatriz->pNoNE = NULL;
			   pNoMatriz->pNoNO = NULL;
			   pNoMatriz->pNoO = NULL;
			   pNoMatriz->pNoSO = NULL;
			   for ( n-- ; n > 0 ; n-- )
			   {
				   pNoMatriz->pNoS = ( tpNoMatriz * ) malloc( sizeof( tpNoMatriz )) ;
				   pNoMatriz = pNoMatriz->pNoS;
				   if ( pNoMatriz == NULL )
				   {
					   MAT_DestruirMatriz( pMatriz );
					   return MAT_CondRetFaltouMemoria ;
				   }
				   pNoMatriz->conteudo = NULL ;
				   pNoMatriz->pNoNO = NULL ;
				   pNoMatriz->pNoO = NULL ;
				   pNoMatriz->pNoSO = NULL ;
			   }
			   pNoMatriz->pNoS = NULL ;
			   pNoMatriz->pNoSE = NULL ;
			   (*pMatriz)->pNoCorr = (*pMatriz)->pNoRaiz;
			   n = (*pMatriz)->dimensao - 2 ;
			   if ( n == -1 )
			   {
				   pNoMatriz->pNoE = NULL;
				   return MAT_CondRetOK;
			   }
			   while ( n > 0 )
			   {
				   pNoMatriz = ( tpNoMatriz * ) malloc( sizeof( tpNoMatriz )) ;
				   if ( pNoMatriz == NULL )
				   {
					   MAT_DestruirMatriz( pMatriz );
					   return MAT_CondRetFaltouMemoria ;
				   }
				   (*pMatriz)->pNoCorr->pNoE = pNoMatriz;
				   pNoMatriz->pNoN = NULL ;
				   pNoMatriz->pNoNE = NULL ;
				   pNoMatriz->pNoNO = NULL ;
				   pNoMatriz->pNoO = (*pMatriz)->pNoCorr;
				   pNoMatriz->conteudo = NULL ;
				   pNoMatriz = (*pMatriz)->pNoCorr;
				   (*pMatriz)->pNoCorr = (*pMatriz)->pNoCorr->pNoE;
				   while ( pNoMatriz->pNoS != NULL )
				   {
					   pNoMatriz->pNoSE = ( tpNoMatriz * ) malloc( sizeof( tpNoMatriz ));
					   if ( pNoMatriz->pNoSE == NULL )
					   {
						   pNoMatriz->pNoE->pNoS = NULL;
						   (*pMatriz)->pNoCorr->pNoE = NULL;
						   MAT_DestruirMatriz( pMatriz );
						   return MAT_CondRetFaltouMemoria ;
					   }
					   pNoMatriz->pNoE->pNoSO = pNoMatriz->pNoS;
					   pNoMatriz->pNoS->pNoNE = pNoMatriz->pNoE;
					   pNoMatriz->pNoE->pNoS = pNoMatriz->pNoSE;
					   pNoMatriz->pNoS->pNoE = pNoMatriz->pNoSE;
					   pNoMatriz->pNoSE->pNoN = pNoMatriz->pNoE;
					   pNoMatriz->pNoSE->pNoO = pNoMatriz->pNoS;
					   pNoMatriz->pNoSE->pNoNO = pNoMatriz;
					   pNoMatriz->pNoSE->conteudo = NULL;
					   pNoMatriz = pNoMatriz->pNoS;
				   }
				   pNoMatriz->pNoE->pNoSO = NULL;
				   pNoMatriz->pNoE->pNoS = NULL;
				   pNoMatriz->pNoE->pNoSE = NULL;
				   n--;
			   }

			   pNoMatriz = ( tpNoMatriz * ) malloc( sizeof( tpNoMatriz )) ;
			   if ( pNoMatriz == NULL )
			   {
				   MAT_DestruirMatriz( pMatriz );
				   return MAT_CondRetFaltouMemoria ;
			   }
			   pNoMatriz->pNoE = NULL;
			   pNoMatriz->pNoSE = NULL;
			   (*pMatriz)->pNoCorr->pNoE = pNoMatriz;
			   pNoMatriz->pNoN = NULL ;
			   pNoMatriz->pNoNE = NULL ;
			   pNoMatriz->pNoNO = NULL ;
			   pNoMatriz->pNoO = (*pMatriz)->pNoCorr;
			   pNoMatriz->conteudo = NULL ;
			   pNoMatriz = (*pMatriz)->pNoCorr;
			   while ( pNoMatriz->pNoS != NULL )
			   {
				   pNoMatriz->pNoSE = ( tpNoMatriz * ) malloc( sizeof( tpNoMatriz ));
				   if ( pNoMatriz->pNoSE == NULL )
				   {
					   pNoMatriz->pNoE->pNoS = NULL;
					   MAT_DestruirMatriz( pMatriz );
					   return MAT_CondRetFaltouMemoria ;
				   }
				   pNoMatriz->pNoE->pNoNE = NULL;
				   pNoMatriz->pNoE->pNoE = NULL;
				   pNoMatriz->pNoE->pNoSE = NULL;
				   pNoMatriz->pNoE->pNoSO = pNoMatriz->pNoS;
				   pNoMatriz->pNoS->pNoNE = pNoMatriz->pNoE;
				   pNoMatriz->pNoE->pNoS = pNoMatriz->pNoSE;
				   pNoMatriz->pNoS->pNoE = pNoMatriz->pNoSE;
				   pNoMatriz->pNoSE->pNoN = pNoMatriz->pNoE;
				   pNoMatriz->pNoSE->pNoO = pNoMatriz->pNoS;
				   pNoMatriz->pNoSE->pNoNO = pNoMatriz;
				   pNoMatriz->pNoSE->conteudo = NULL;
				   pNoMatriz = pNoMatriz->pNoS;
			   }
			   pNoMatriz->pNoE->pNoSO = NULL;
			   pNoMatriz->pNoE->pNoS = NULL;
			   (*pMatriz)->CoorI = 1;
			   (*pMatriz)->CoorJ = 1;
			   (*pMatriz)->pNoCorr = (*pMatriz)->pNoRaiz;
		   }
		   return MAT_CondRetOK;
		}
	}
			   
				 
/***************************************************************************
*
*  Fun��o: MAT Destruir matriz
*  ****/

  void MAT_DestruirMatriz( tpMatriz ** pMatriz )
   {
	   if ( pMatriz == NULL )
	   {/* entrada sem conte�do */}
	   else if ( *pMatriz == NULL )
	   {/* entrada sem conte�do */}
	   else
	   {
		   if ( (*pMatriz)->pNoRaiz != NULL )
		   {
			   tpNoMatriz * pNoMatriz;
			   while ( (*pMatriz)->pNoRaiz != NULL )
			   {
				   pNoMatriz = (*pMatriz)->pNoRaiz;
				   (*pMatriz)->pNoRaiz = pNoMatriz->pNoE;
				   while ( pNoMatriz->pNoS != NULL )
				   {
					   pNoMatriz = pNoMatriz->pNoS;
					   free( pNoMatriz->pNoN );
				   }
				   free( pNoMatriz );
			   }
		   }
		   free( *pMatriz );
	   }
  }
MAT_tpCondRet MAT_IrNoOeste( tpMatriz * pMatriz )
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	if ( pMatriz->pNoCorr->pNoO == NULL )
		return MAT_CondRetNaoPossueNo;
	pMatriz->pNoCorr = pMatriz->pNoCorr->pNoO;
	return MAT_CondRetOK;
}
MAT_tpCondRet MAT_IrNoNorte( tpMatriz * pMatriz ) ;
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	if ( pMatriz->pNoCorr->pNoN == NULL )
		return MAT_CondRetNaoPossueNo;
	pMatriz->pNoCorr = pMatriz->pNoCorr->pNoN;
	return MAT_CondRetOK;
}
MAT_tpCondRet MAT_IrNoLeste( tpMatriz * pMatriz ) ;
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	if ( pMatriz->pNoCorr->pNoE == NULL )
		return MAT_CondRetNaoPossueNo;
	pMatriz->pNoCorr = pMatriz->pNoCorr->pNoE;
	return MAT_CondRetOK;
}
MAT_tpCondRet MAT_IrNoSul( tpMatriz * pMatriz ) ;
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	if ( pMatriz->pNoCorr->pNoS == NULL )
		return MAT_CondRetNaoPossueNo;
	pMatriz->pNoCorr = pMatriz->pNoCorr->pNoS;
	return MAT_CondRetOK;
}
MAT_tpCondRet MAT_IrNoSudoeste( tpMatriz * pMatriz ) ;
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	if ( pMatriz->pNoCorr->pNoSO == NULL )
		return MAT_CondRetNaoPossueNo;
	pMatriz->pNoCorr = pMatriz->pNoCorr->pNoSO;
	return MAT_CondRetOK;
}
MAT_tpCondRet MAT_IrNoNoroeste( tpMatriz * pMatriz ) ;
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	if ( pMatriz->pNoCorr->pNoNO == NULL )
		return MAT_CondRetNaoPossueNo;
	pMatriz->pNoCorr = pMatriz->pNoCorr->pNoNO;
	return MAT_CondRetOK;
}
MAT_tpCondRet MAT_IrNoNordeste( tpMatriz * pMatriz ) ;
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	if ( pMatriz->pNoCorr->pNoNE == NULL )
		return MAT_CondRetNaoPossueNo;
	pMatriz->pNoCorr = pMatriz->pNoCorr->pNoNE;
2	return MAT_CondRetOK;
}
MAT_tpCondRet MAT_IrNoSudeste( tpMatriz * pMatriz ) ;
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	if ( pMatriz->pNoCorr->pNoSE == NULL )
		return MAT_CondRetNaoPossueNo;
	pMatriz->pNoCorr = pMatriz->pNoCorr->pNoSE;
	return MAT_CondRetOK;
}

MAT_tpCondRet MAT_ObterListaCorr(  tpMatriz * pMatriz, void ** ValorParm )
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	ValorParm = pMatriz->pNoCorr->conteudo;
	return MAT_CondRetOK;
}
// na fun��o deve ser alterado no header file o parametro "char **" para "void **" 