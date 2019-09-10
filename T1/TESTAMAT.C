/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo de teste espec�fico
*
*  Arquivo gerado:              TESTARV.C
*  Letras identificadoras:      TARV
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
*     Este m�odulo cont�m as fun��es espec�ficas para o teste do
*     m�dulo �rvore. Ilustra como redigir um interpretador de comandos
*     de teste espec�ficos utilizando o arcabou�o de teste para C.
*
*  $EIU Interface com o usu�rio pessoa
*     Comandos de teste espec�ficos para testar o m�dulo �rvore:
*
*     "=criar"      - chama a fun��o MAT_CriarMatriz( )
*     "=irnorte"	- chama a fun��o MAT_IrNoNorte( )
*     "=irsul"		- chama a fun��o MAT_IrNoSul( )
*     "=iroest"		- chama a fun��o MAT_IrNoOeste( )
*     "=itleste"	- chama a fun��o MAT_IrNoLeste( )
*     "=irsudoe"	- chama a fun��o MAT_IrNoSudoeste( )
*     "=irnoroe"	- chama a fun��o MAT_IrNoNoroeste( )
*     "=irnorde"	- chama a fun��o MAT_IrNoNordeste( )
*     "=obter" <Char>
*                   - chama a fun��o MAT_ObterListaCorr( ) e compara
*                     o valor retornado com o valor <Char>
*     "=destroi"    - chama a fun��o MAT_DestruirArvore( )
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "MATRIZ.h"

/* Tabela dos nomes dos comandos de teste espec�ficos */

#define     CRIAR_MAT_CMD       "=criar"
#define		IR_PARA_CMD			"=irpara"
#define     IR_NORTE_CMD        "=irnorte"
#define     IR_SUL_CMD          "=irsul"
#define     IR_OESTE_CMD        "=iroest"
#define     IR_LESTE_CMD        "=irleste"
#define		IR_SUDOE_CMD		"=irsudoe"
#define     IR_NOROE_CMD		"=irnoroe"
#define		IR_NORDE_CMD		"=irnorde"
#define		IR_SUDE_CMD			"=irsude"
#define     OBTER_VAL_CMD       "=obter"
#define     DESTROI_CMD         "=destruir"

/***** Dados encapsulados no módulo *****/

static tpMatriz * pMatriz[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL } ;
					/* Array de ponteiros para as cabecas das matrizes */

static char matAtual = 0; /* 0 a 9, testa até 10 matrizes simultâneas */


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TMAT Efetuar opera��es de teste espec�ficas para �rvore
*
*  $ED Descri��o da fun��o
*     Efetua os diversos comandos de teste espec�ficos para o m�dulo
*     �rvore sendo testado.
*
*  $EP Par�metros
*     $P ComandoTeste - String contendo o comando
*
*  $FV Valor retornado
*     Ver TST_tpCondRet definido em TST_ESPC.H
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      MAT_tpCondRet CondRetObtido   = MAT_CondRetOK ;
      MAT_tpCondRet CondRetEsperada = MAT_CondRetFaltouMemoria ;
                                      /* inicializa para qualquer coisa */

      char ValorEsperado = '?'  ;
      char ValorObtido   = '!'  ;
      char ValorDado     = '\0' ;

      int  NumLidos = -1 ;

      TST_tpCondRet Ret ;

      /* Testar MAT Criar Matriz*/

         if ( strcmp( ComandoTeste , CRIAR_MAT_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_CriarMatriz( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar matriz." );

         } /* fim ativa: Testar MAT CriarMatriz */


		  /* Testar MAT Goto  */

         else if ( strcmp( ComandoTeste , IR_PARA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i", "j" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MATMAT_Goto( );

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para." );

         } /* fim ativa: Testar MAT Goto */


      /* Testar MAT Ir para Norte */

         else if ( strcmp( ComandoTeste , IR_NORTE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_IrNoNorte( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para Norte." );

         } /* fim ativa: Testar MAT Ir para Norte */



		 /* Testar MAT Ir para Sul */

         else if ( strcmp( ComandoTeste , IR_SUL_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_IrNoSul( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para sul." );

         } /* fim ativa: Testar MAT Ir para Sul */



		 /* Testar MAT Ir para Oeste */

         else if ( strcmp( ComandoTeste , IR_OESTE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_IrNoOeste( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para Oeste." );

         } /* fim ativa: Testar MAT Ir para Oeste */


      /* Testar MAT Ir para Leste */

         else if ( strcmp( ComandoTeste , IR_LESTE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_IrNoLeste( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir Leste." );

         } /* fim ativa: Testar MAT Ir para Leste */


		 /* Testar MAT Ir para Sudoeste */

         else if ( strcmp( ComandoTeste , IR_SUDOE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_IrNoSudoeste( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir Sudoeste." );

         } /* fim ativa: Testar MAT Ir para Sudoeste */


		 /* Testar MAT Ir para Noroeste */

         else if ( strcmp( ComandoTeste , IR_NOROE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_IrNoNoroeste( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir Noroeste." );

         } /* fim ativa: Testar MAT Ir para Noroeste */


		 /* Testar MAT Ir para Nordeste */

         else if ( strcmp( ComandoTeste , IR_NORDE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_IrNoNordeste( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir Nordeste." );

         } /* fim ativa: Testar MAT Ir para Nordeste */


		 /* Testar MAT Ir para Sudeste */

         else if ( strcmp( ComandoTeste , IR_SUDE_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_IrNoSudeste( ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir Sudeste." );

         } /* fim ativa: Testar MAT Ir para Sudeste */


      /* Testar MAT Obter valor corrente */

         else if ( strcmp( ComandoTeste , OBTER_VAL_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ci" ,
                               &ValorEsperado , &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_ObterContCorr( &ValorObtido ) ;

            Ret = TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter valor corrente." );

            if ( Ret != TST_CondRetOK )
            {
               return Ret ;
            } /* if */

            return TST_CompararChar( ValorEsperado , ValorObtido ,
                                     "Conte�do do n� est� errado." ) ;

         } /* fim ativa: Testar MAT Obter valor corrente */

      /* Testar MAT Destruir Matriz */

         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            MAT_DestruirMatriz( void );

            return TST_CondRetOK ;

         } /* fim ativa: Testar ARV Destruir �rvore */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TARV Efetuar opera��es de teste espec�ficas para �rvore */

/********** Fim do m�dulo de implementa��o: M�dulo de teste espec�fico **********/

