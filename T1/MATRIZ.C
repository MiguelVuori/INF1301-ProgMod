/***************************************************************************
*  $MCI Módulo de implementação: Módulo matriz
*
*  Arquivo gerado:              MATRIZ.C
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
*     Versão  Autores    Data     Observações
*       2.00   mfv/   09/09/2019 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       1.00   mfv/   06/09/2019 Início do desenvolvimento
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>

#define MATRIZ_OWN
#include "MATRIZ.H"
#undef MATRIZ_OWN

/***********************************************************************
*
*  $TC Tipo de dados: MAT Descritor do nó da matriz
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/

   typedef struct tgNoMatriz {

         void * conteudo;
               /* Conteúdo do nó corrente em formato de ponteiro
               *
               *$EED Assertivas estruturais
               *   O conteúdo do nó é tratado como um ponteiro para uma posição de memória
               *   */

         struct tgNoMatriz * pNoNE ;
               /* Ponteiro para o nó a nordeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, todos os nós apontados recursivamente a partir do nó corrente por pNoN e por pNoS, separadamente, são NULL ou apontam para NULL em pNoNE, ou todos os nós apontados recursivamente a partir do nó corrente por pNoE e por pNoO, separadamente, são NULL ou apontam para NULL em pNoNE.
               *   Se não for NULL, pNoNE->pNoSO, pNoNE->pNoS->pNoO e pNoNE->pNoO->pNoS apontam todos para o nó corrente.
               *   */

         struct tgNoMatriz * pNoE ;
               /* Ponteiro para o nó a este
               *
               *$EED Assertivas estruturais
               *   Se for NULL, pNoNE e pNoSE também apontam para NULL.
               *   Se não for NULL, pNoE->pNoO aponta para o nó corrente.
               *   */

         struct tgNoMatriz * pNoSE ;
               /* Ponteiro para o nó a sudeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, todos os nós apontados recursivamente a partir do nó corrente por pNoN e por pNoS, separadamente, são NULL ou apontam para NULL em pNoSE, ou todos os nós apontados recursivamente a partir do nó corrente por pNoE e por pNoO, separadamente, são NULL ou apontam para NULL em pNoSE.
               *   Se não for NULL, pNoSE->pNoNO, pNoSE->pNoN->pNoO e pNoSE->pNoO->pNoN apontam todos para o nó corrente.
               *   */

         struct tgNoMatriz * pNoS ;
               /* Ponteiro para o nó a sul
               *
               *$EED Assertivas estruturais
               *   Se for NULL, pNoSE e pNoSO também apontam para NULL.
               *   Se não for NULL, pNoS->pNoN aponta para o nó corrente.
               *   */

         struct tgNoMatriz * pNoSO ;
               /* Ponteiro para o nó a sudoeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, todos os nós apontados recursivamente a partir do nó corrente por pNoN e por pNoS, separadamente, são NULL ou apontam para NULL em pNoSO, ou todos os nós apontados recursivamente a partir do nó corrente por pNoE e por pNoO, separadamente, são NULL ou apontam para NULL em pNoSO.
               *   Se não for NULL, pNoSO->pNoNE, pNoSO->pNoN->pNoE e pNoSO->pNoE->pNoN apontam todos para o nó corrente.
               *   */

         struct tgNoMatriz * pNoO ;
               /* Ponteiro para o nó a oeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, pNoSO e pNoNO também apontam para NULL.
               *   Se não for NULL, pNoO->pNoE aponta para o nó corrente.
               *   */

         struct tgNoMatriz * pNoNO ;
               /* Ponteiro para o nó a noroeste
               *
               *$EED Assertivas estruturais
               *   Se for NULL, todos os nós apontados recursivamente a partir do nó corrente por pNoN e por pNoS, separadamente, são NULL ou apontam para NULL em pNoNO, ou todos os nós apontados recursivamente a partir do nó corrente por pNoE e por pNoO, separadamente, são NULL ou apontam para NULL em pNoNO.
               *   Se não for NULL, pNoNO->pNoSE, pNoNO->pNoS->pNoE e pNoNO->pNoE->pNoS apontam todos para o nó corrente.
               *   */

         struct tgNoMatriz * pNoN ;
               /* Ponteiro para o nó a norte
               *
               *$EED Assertivas estruturais
               *   Se for NULL, pNoNO e pNoNE também apontam para NULL.
               *   Se não for NULL, pNoN->pNoS aponta para o nó corrente.
               *   */
   } tpNoMatriz ;

/***********************************************************************
*
*  $TC Tipo de dados: Mat Descritor da cabeça de uma matriz quadrada
*
*
*  $ED Descrição do tipo
*     A cabe‡a da matriz é o ponto de acesso para uma determinada matriz quadrada.
*     Por intermédio da referência para o nó corrente, coordenadas latitudinais e longitudinais
*     pai pode-se navegar a matriz.
*
***********************************************************************/

   struct tgMatriz {

         tpNoMatriz * pNoRaiz ;
               /* Ponteiro para o nó 1 x 1 da matriz */

         tpNoMatriz * pNoCorr ;
               /* Ponteiro para o nó corrente da matriz */

		 int dimensao;
		      /* Guarda a dimensão n da matriz quadrada n x n */

		 int i;
		      /* Guarda a coordanada longitudinal do nó apontado por pNoCorr na matriz */

		 int j;
		      /* Guarda a coordenada latitudinal do nó apontado por pNoCorr na matriz */

   };


/***** Protótipos das funções encapuladas no módulo *****/
/*
   static tpNoMatriz * CriarNo( char ValorParm ) ;
   static MAT_tpCondRet CriarNoRaiz( char ValorParm ) ;
   static void DestroiArvore( tpNoMatriz * pNo ) ;
/*
/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: MAT Criar matriz
*  ****/

   MAT_tpCondRet MAT_CriarMatriz( int n , tpMatriz ** pMatriz )
   {
	   if ( n < 0 ) // n não pode ser negativo - entrada invalida
	   {}
	   else
	   {
		   *pMatriz = ( tpMatriz * ) malloc( sizeof( tpMatriz )) ;
		   if ( *pMatriz == NULL )
		   {
			   return MAT_CondRetFaltouMemoria ;
		   }
		   if ( n == 0 )
			   // caso a dimensao fornecida seja 0 é criada apenas a cabeça com uma matriz vazia (sem uma matriz)
		   {
			   (*pMatriz)->i = 0;
			   (*pMatriz)->j = 0;
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
				   MAT_DestruirMatriz( *pMatriz );
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
					   MAT_DestruirMatriz( *pMatriz );
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
					   MAT_DestruirMatriz( *pMatriz );
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
						   MAT_DestruirMatriz( *pMatriz );
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
				   MAT_DestruirMatriz( *pMatriz );
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
					   MAT_DestruirMatriz( *pMatriz );
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
			   (*pMatriz)->i = 1;
			   (*pMatriz)->j = 1;
			   (*pMatriz)->pNoCorr = (*pMatriz)->pNoRaiz;
		   }
		   return MAT_CondRetOK;
		}
	}
			   
				 
/***************************************************************************
*
*  Função: MAT Destruir matriz
*  ****/

  void MAT_DestruirMatriz( tpMatriz * pMatriz )
   {
	   if ( pMatriz == NULL )
	   {/*entrada sem conteudo*/}
	   else
	   {
		   if ( pMatriz->pNoRaiz != NULL )
		   {
			   tpNoMatriz * pNoMatriz;
			   while ( pMatriz->pNoRaiz != NULL )
			   {
				   pNoMatriz = pMatriz->pNoRaiz;
				   pMatriz->pNoRaiz = pNoMatriz->pNoE;
				   while ( pNoMatriz->pNoS != NULL )
				   {
					   pNoMatriz = pNoMatriz->pNoS;
					   free( pNoMatriz->pNoN );
				   }
				   free( pNoMatriz );
			   }
		   }
		   free( pMatriz );
	   }
  }

/***************************************************************************
*
*  Função: MAT Goto 
*  ****/

MAT_tpCondRet MAT_Goto( tpMatriz * pMatriz , int i, int j)
{
	tpNoMatriz* aux;
	int difi,difj;

	if ( pMatriz == NULL)
		return MAT_CondRetMatrizNaoExiste ;
	if (( i > (pMatriz->dimensao) )||( j > (pMatriz->dimensao)) )
		return MAT_CondRetNaoPossuiNo ;
	difi = pMatriz->i - i ;
	difj = pMatriz->j - j ;

	while( difi != 0 )
	{
		if( difi < 0)
		{
			pMatriz->pNoCorr = pMatriz->pNoCorr->pNoN ;
			difi++ ;
		}
		else
		{
			pMatriz->pNoCorr = pMatriz->pNoCorr->pNoS ;
			difi-- ;
		}
	}
	while( difj != 0 )
	{
		if( difj < 0)
		{
			pMatriz->pNoCorr = pMatriz->pNoCorr->pNoO ;
			difj++ ;
		}
		else
		{
			pMatriz->pNoCorr = pMatriz->pNoCorr->pNoE ;
			difj-- ;
		}
	}
	pMatriz->j = j ;
	pMatriz->i = i ;
	return MAT_CondRetOK ;

}

/***************************************************************************
*
*  Função: MAT ObterContCorr 
*  ****/

MAT_tpCondRet MAT_ObterContCorr(  tpMatriz * pMatriz, void * ValorParm )
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;
	ValorParm = pMatriz->pNoCorr->conteudo;
	return MAT_CondRetOK;
}

/***************************************************************************
*
*  Função: MAT InsereLista 
*  ****/

MAT_tpCondRet MAT_InsereLista( tpMatriz * pMatriz, void * ValorParm )
{
	if ( pMatriz == NULL )
		return MAT_CondRetMatrizNaoExiste;
	if ( pMatriz->pNoRaiz == NULL )
		return MAT_CondRetMatrizVazia;

	pMatriz->pNoCorr->conteudo = ValorParm;
	return MAT_CondRetOK;
}
