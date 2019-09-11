/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTMAT.C
*  Letras identificadoras:      TMAT
*
*  Nome da base de software:    Exemplo de teste automatizado
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\SIMPLES.BSW
*
*  Projeto: Disciplinas INF 1628 / 1301
*  Gestor:  DI/PUC-Rio
*  Autores: mfv - Miguel Fagundes Vuori
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observações
*       2.00   mfv   09/09/2019 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       1.00   mfv   07/09/2019 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para o teste do
*     módulo matriz. Ilustra como redigir um interpretador de comandos
*     de teste específicos utilizando o arcabouço de teste para C.
*
*  $EIU Interface com o usuário pessoa
*     Comandos de teste específicos para testar o módulo árvore:
*
*     "=criar"      - chama a função MAT_CriarMatriz( )
*     "=irpara"		- chama a função MAT_Goto()
*     "=obter"      - chama a função MAT_ObterContCorr( )
*     "=destruir"    - chama a fun��o MAT_DestruirArvore( )
*     "=insere"
*     "=mudar"  <int>
*                   - muda a matriz de teste
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>

#include    "TST_ESPC.H"

#include    "generico.h"
#include    "lerparm.h"

#include    "MATRIZ.h"
#include	"LISTA.H"

/* Tabela dos nomes dos comandos de teste específicos */

#define     CRIAR_MAT_CMD       "=criar"
#define		IR_PARA_CMD			"=irpara"
#define     OBTER_VAL_CMD       "=obter"
#define     INSERE_VAL_CMD      "=insere"
#define     DESTROI_CMD         "=destruir"
#define     MUDAR_MAT_CMD       "=mudar"
#define		CRIAR_LISTA_CMD     "=criarlista"

/***** Dados encapsulados no módulo *****/

static tpMatriz * pMatriz[] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL } ;
					/* Array de ponteiros para as cabecas das matrizes */

static int matAtual = 0; /* 0 a 9, testa até 10 matrizes simultâneas */

static void DestruirValor( void * pValor ) ;

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TMAT Efetuar operações de teste específicas para Matriz
*
*  $ED Descrição da função
*     Efetua os diversos comandos de teste específicos para o módulo
*     matriz sendo testado.
*
*  $EP Parâmetros
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
      LIS_tppLista ValorObtido ;
      char ValorDado     = '\0' ;
      LIS_tppLista ListaChar;
      int  tam = -1 ;
      int  i = -1;
      int  j = -1;
      int  NumLidos = -1 ;
	  int NumMat;

	  LIS_tppLista lista;

      TST_tpCondRet Ret ;

	  /* Testar MAT Criar matriz */

         if ( strcmp( ComandoTeste , CRIAR_MAT_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "ii" , &tam,
                               &CondRetEsperada ) ;
            if ( NumLidos != 2 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_CriarMatriz( tam,  &pMatriz[matAtual] ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao criar matriz nxn." ) ;

         } /* fim ativa: Testar MAT Cria matriz */

      /* Testar MAT Destroi matriz */

         else if ( strcmp( ComandoTeste , DESTROI_CMD ) == 0 )
         {

            MAT_DestruirMatriz( pMatriz[matAtual] ) ;

            return TST_CondRetOK ;

         } /* fim ativa: Testar MAT Destroi matriz */

      /* Testar MAT Goto ixj */

         else if ( strcmp( ComandoTeste , IR_PARA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "iii" , &i,
                               &j , &CondRetEsperada ) ;
            if ( NumLidos != 3 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_Goto( pMatriz[matAtual], i, j ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para ixj." );

         } /* fim ativa: Testar MAT Goto ixj */

      /* Testar MAT Obter valor corrente */

         else if ( strcmp( ComandoTeste , OBTER_VAL_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                                      &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_ObterContCorr( pMatriz[matAtual], &ValorObtido ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                   "Retorno errado ao obter valor corrente." ); 

         } /* fim ativa: Testar MAT Obter Valor Corrente */

      /* Testar MAT Insere lista */

         else if ( strcmp( ComandoTeste , INSERE_VAL_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &CondRetEsperada ) ;
            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            CondRetObtido = MAT_InsereLista( pMatriz[matAtual], lista ) ;

            return TST_CompararInt( CondRetEsperada , CondRetObtido ,
                                    "Retorno errado ao ir para pai." );

         } /* fim ativa: Testar MAT Insere lista*/

         /* CriarLista */

         else if ( strcmp( ComandoTeste , CRIAR_LISTA_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                       &CondRetEsperada ) ;

            if ( NumLidos != 1 )
            {
               return TST_CondRetParm ;
            } /* if */

            ListaChar =
                 LIS_CriarLista( DestruirValor ) ;

            return TST_CondRetOK ;

         } /* fim ativa: CriarLista */

      /* mudar matriz de testes */

         else if ( strcmp( ComandoTeste , MUDAR_MAT_CMD ) == 0 )
         {

            NumLidos = LER_LerParametros( "i" ,
                               &NumMat ) ;
            if ( NumLidos != 1 || (NumMat < 0 || NumMat > 9) )
            {
               return TST_CondRetParm ;
            } /* if */

            matAtual = NumMat ;

            return TST_CondRetOK ;
                                    

         } /* fim ativa: mudar matriz de teste */

      /* Testar MAT Obter valor corrente */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TMAT Efetuar operações de teste específicas para matriz */

   /*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TLIS -Destruir valor
*
***********************************************************************/

   void DestruirValor( void * pValor )
   {

      free( pValor ) ;

   } /* Fim função: TLIS -Destruir valor */

/********** Fim do módulo de implementação: Módulo de teste específico **********/