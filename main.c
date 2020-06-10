#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "PilhaDinamica.c"

void validarExpressao(char expressao[],int tamExp);
void converterExpressao(char expressaoSaida[],int tamNovaExp,int tamExp);

int main(){

    char *expressao;
    int opcao;
    int tam;


    do{
            system("cls");
            printf("\nESCOLHA UMA DAS 2 OPCOES\n");
            printf("\n1 - INFORMAR EXPRESSAO\n");
            printf("\n2 - SAIR DO PROGRAMA\n");
            scanf("%d",&opcao);
            fflush(stdin);

            switch(opcao){

                case 1:

                    printf("\nDigite o tamanho da expressao\n");
                    scanf("%d",&tam);
                    fflush(stdin);
                    //tam = tam+1;
                    expressao = (char *)malloc(tam*sizeof(char*));
                    printf("\nDigite a expressao\n");
                    gets(expressao);
                    fflush(stdin);
                    validarExpressao(expressao,tam);
                break;

                case 2:printf("\nObrigado por usar o programa\n");
                break;

                default:printf("\nOpcao invalida digite novamente\n");


            }

            printf("\nTECLE ENTER PARA CONTINUAR\n");
            getchar();
            fflush(stdin);



    }while(opcao!=2);

}


void validarExpressao(char expressao[],int tamExp){

    bool validadorQuant;
    int tamNovaExp;
    int contParent1,contParent2,contSinal,contLetras;
    contParent1 = contParent2 = contSinal = contLetras = 0;
    expressao[tamExp] = '\0';

    //1 - valida  2 - caractere invalido 3 - parentização incorreta
    int validador;

    for(int i=0;i<tamExp;i++){

        if(expressao[0]!='('){
            validador=3;
            break;
        }

        if(expressao[i]=='('){
            ++contParent1;
        }

        if(expressao[i]==')'){
            ++contParent2;
        }

        if((expressao[i]<='Z' && expressao[i]>='A')||(expressao[i]<='z' && expressao[i]>='a')){
            validador =1;
            ++contLetras;
        }else{
            if(expressao[i]=='+' || expressao[i]=='-' || expressao[i]=='*' || expressao[i]=='/'){
                validador=1;
                ++contSinal;
            }else{
                if(expressao[i]=='(' || expressao[i]==')'){
                    validador=1;
                }else{
                    validador=2;
                    break;
                }
            }
        }

        if(validador==1){
            if((expressao[i]=='(' && expressao[i+1]==')')||(expressao[i]==')' && expressao[i+1]=='(')){
                validador=3;
            }else{
                if(expressao[i]==')' && ((expressao[i+1]<='Z' && expressao[i+1]>='A') || (expressao[i+1]<='z' && expressao[i+1]>='a'))){
                    validador=3;
                }else{
                    if(expressao[i]=='(' && ((expressao[i-1]<='Z' && expressao[i-1]>='A') || (expressao[i-1]<='z' && expressao[i-1]>='a'))){
                        validador=3;
                    }
                }
            }
        }
    }

    validadorQuant = (contParent1==contParent2 &&  contParent2==contSinal);
    tamNovaExp = contLetras+contSinal;

    //avaliar condições finais fora du for e printar na tela o resultado
    if(validadorQuant==1 && validador==1){
        converterExpressao(expressao,tamNovaExp,tamExp);
    }else{
        if(validador==2){
            printf("\nA expressao aritmetica %s possui caracteres invalidos\n",expressao);
        }else{
            if(validadorQuant==0 || validador==3){
                printf("\nA expressao aritmetica %s nao esta corretamente parentizada\n",expressao);
            }
        }
    }


}

void converterExpressao(char expressaoSaida[],int tamNovaExp,int tamExp){

    Pilha p;
    inicialize(&p);

    expressaoSaida[tamExp] = '\0';

    char novaExp[tamNovaExp];
    novaExp[tamNovaExp] = '\0';

    int posicao=0;
    char *sinal;

     for(int i=0;i<tamExp;i++){
        if((expressaoSaida[i]<='Z' && expressaoSaida[i]>='A')||(expressaoSaida[i]<='z' && expressaoSaida[i]>='a')){
            novaExp[posicao] = expressaoSaida[i];
            posicao++;
        }else{
            if(expressaoSaida[i]=='+' || expressaoSaida[i]=='-' || expressaoSaida[i]=='*' || expressaoSaida[i]=='/'){
               push(&p,expressaoSaida[i]);
            }else{
                if(expressaoSaida[i]==')'){
                    sinal = pop(&p);
                    novaExp[posicao] = sinal;
                    posicao++;
                }
            }
        }
     }

     printf("\nExpressao posfixa\n");
     printf("%s",novaExp);


}
