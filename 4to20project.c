#include<stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
//programa para calcular o erro fiducial atravez de looptest de instrumentos de medição e criação de relatorios por EMILIO BRESOLIN
int main(void)
{

    FILE * pFile; //cria variavel ponteiro para arquivo
    char op; //operacao de entrada e saida do programa
    char tec[10]; //nome tecnico
    char sobre[10]; //sobrenome do tec
    char tag[10]; //TAG instrumento
    float med4[9], med8[9], med12[9], med16[9], med20[9]; //medicoes
    int i, n, x, y, z; //contadores
    float cal4=0, cal8=0, cal12=0, cal16=0, cal20=0; //calculo divisao por 10
    float tt4=0, tt8=0, tt12=0, tt16=0, tt20=0; //total
    float EF=0; //calculo final de erro fiducial
    pFile = fopen ("Relatorio.txt","a"); //abrir o arquivo ou criar "w" grava dados um em cima do outro e "a" para gravar um depois do outro
    do //inico do menu
    {
        printf("DATA : %s HORA: %s\n",__DATE__,__TIME__); //hora e data
        printf("\nEscolha:\n  0 - Sair\n  1 - Entrar\n");
        scanf(" %c", &op);
        switch(op)
        {
            case '0': //sair
                printf("Escolheu sair do menu\n");
                break;
            case '1'://entrar
                printf("\nDigite o primeiro nome do tecnico: \n");
                scanf("%s", &tec); //entrada do nome do tecnico
                printf("\nDigite o sobrenome do tecnico: \n");
                scanf("%s", &sobre); //entrada do sobrenome do tecnico
                printf("\nTecnico %s prossiga com o TAG do instrumento:\n", tec);
                scanf("%s", &tag); //entrada do tag do isntrumento
                printf("\nAgora tecnico %s prossiga com as medicoes do instrumento %s: \n", tec, tag);
                printf("\n");
                for(i=0; i<=9; i++) // para pegas as 10 medições nos 4mA
                {
                    printf("4mA:");
                    scanf("%f", &med4[i]);
                }
                for(i=0; i<=9; i++) // para criar o total dos 4mA
                {
                    tt4=tt4+med4[i];
                }
                for(i=0; i<=9; i++) // para criar a media dos 4mA
                {
                    cal4 = tt4/10;
                }
                printf("\nMedia nos 4mA: %f\n", cal4);
                printf("\n");
                for(n=0; n<=9; n++)
                {
                    printf("8mA:");
                    scanf("%f", &med8[n]);
                }
                for(n=0; n<=9; n++)
                {
                    tt8=tt8+med8[n];
                }
                for(n=0; n<=9; n++)
                {
                    cal8 = tt8/10;
                }
                printf("\nMedia nos 8mA: %f\n", cal8);
                printf("\n");
                for(x=0; x<=9; x++)
                {
                    printf("12mA:");
                    scanf("%f", &med12[x]);
                }
                for(x=0; x<=9; x++)
                {
                    tt12=tt12+med12[x];
                }
                for(x=0; x<=9; x++)
                {
                    cal12 = tt12/10;
                }
                printf("\nMedia nos 12mA: %f\n", cal12);
                printf("\n");
                for(y=0; y<=9; y++)
                {
                    printf("16mA:");
                    scanf("%f", &med16[y]);
                }
                for(y=0; y<=9; y++)
                {
                    tt16=tt16+med16[y];
                }
                for(y=0; y<=9; y++)
                {
                    cal16 = tt16/10;
                }
                printf("\nMedia nos 16mA: %f\n", cal16);
                printf("\n");
                for(z=0; z<=9; z++)
                {
                    printf("20mA:");
                    scanf("%f", &med20[z]);
                }
                for(z=0; z<=9; z++)
                {
                    tt20=tt20+med20[z];
                }
                for(z=0; z<=9; z++)
                {
                    cal20 = tt20/10;
                }
                printf("\nMedia nos 20mA: %f\n", cal20);
                EF=((cal4-4)+(cal8-8)+(cal12-12)+(cal16-16)+(cal20-20))/5;
                printf("\nERRO FIDUCIAL DO INSTRUMENTO %s FICA: +- %f \n", tag, EF);
                // comeco do relatorio
                fprintf(pFile, "Nome do tecnico: %s %s \n", tec, sobre);
                fprintf(pFile, "Tag do instrumento: %s \n", tag);
                for(i=0; i<=9; i++)
                {
                    fprintf(pFile, "4mA: %f \n", med4[i]);
                }
                fprintf(pFile, "Media: %f \n\n", cal4);
                for(n=0; n<=9; n++)
                {
                    fprintf(pFile, "8mA: %f \n", med8[n]);
                }
                fprintf(pFile, "Media: %f \n\n", cal8);
                for(x=0; x<=9; x++)
                {
                    fprintf(pFile, "12mA: %f \n", med12[x]);
                }
                fprintf(pFile, "Media: %f \n\n", cal12);
                for(y=0; y<=9; y++)
                {
                    fprintf(pFile, "16mA: %f \n", med16[y]);
                }
                fprintf(pFile, "Media: %f \n\n", cal16);
                for(z=0; z<=9; z++)
                {
                    fprintf(pFile, "20mA: %f \n", med20[z]);
                }
                fprintf(pFile, "Media: %f \n\n", cal20);
                fprintf(pFile, "Calculo fiducial: \n((%f + %f + %f + %f + %f) - 60) / 5 =\n", cal4, cal8, cal12, cal16, cal20);
                fprintf(pFile, "+- %f de Txa de incerteza de medição.\n\n", EF);
                fprintf(pFile, "DATA : %s HORA: %s\n\n\n",__DATE__,__TIME__);
                break;
            default:
                printf("Escolheu uma opção inválida\n");
                break;
        }
    }while (op != '0');
    fclose (pFile);
    getch();
    return 0;
}
