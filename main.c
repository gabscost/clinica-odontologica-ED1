#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char CodPac[10];
    char nome[30], fone[11];
} RegPaci;

typedef struct
{
    int hora, min, segund;
} RegHora;

typedef struct
{
    int dia, mes, ano;
} RegData;

typedef struct
{
    int Codcons;
    char CodPac[10];
    RegHora horario;
    RegData Data;


} Consulta;


int main()
{
    RegPaci RegPaci[10];
    RegData RegData[10];
    RegHora RegHora[10];
    Consulta Consulta[10];

    int menu = 1, Contpac =0, Contconsulta = 0;
    char aux1[10],aux[10];
    int auxdia,auxmes,auxano,flag = 0,flag2 = 0,flag3 = 0,inc = 0,aux3;


    while (menu != 0)
    {
        printf ("\n========== BEM VINDO ===================");
        printf ("\n  [1] para Cadastrar Paciente");
        printf ("\n  [2] para cadastrar Consulta");
        printf ("\n  [3] para pesquisar o paciente ");
        printf ("\n  [4] para trocar o horario do paciente ");
        printf ("\n  [0] para sair do menu ");
        printf ("\n======================================\n");
        scanf("%d", &menu);

        switch(menu)
        {
        case 1:
            if (Contpac <10)
            {



                printf("========Digite o Codigo do Paciente: ======\n");
                setbuf(stdin,NULL);
                gets(RegPaci[Contpac].CodPac);
                setbuf(stdin,NULL);

                printf("=====Digite o Nome do Paciente: =======\n");
                gets(RegPaci[Contpac].nome);
                setbuf(stdin,NULL);

                printf("=======Digite o telefone =======\n");

                gets(RegPaci[Contpac].fone);
                Contpac++;
            }

            break;
        case 2:
            printf("\n========Digite o codigo do paciente: ===========\n");
            setbuf(stdin,NULL);
            gets(aux1);
            flag2 = 0;
            for(int j=0; j<=Contpac; j++ )
            {
                if(strcmp(aux1,RegPaci[j].CodPac)==0)
                {
                    printf("\n======= Digite o dia da consulta: ======\n");
                    setbuf(stdin,NULL);
                    scanf("%d",&auxdia);
                    while(auxdia < 1 || auxdia > 30 )
                    {
                        printf("\n======== dia invalido, digite dia entre 1 a 30: =========\n");
                        setbuf(stdin,NULL);
                        scanf("%d",&auxdia);
                    }
                    printf("\n========== Digite o mes da consulta: =========\n");
                    scanf("%d",&auxmes);
                    while(auxmes < 1 || auxmes> 12 )
                    {
                        printf("\n =========mes invalido, digite mes entre 1 a 12: =========\n");
                        setbuf(stdin,NULL);
                        scanf("%d",&auxmes);
                    }

                    printf("\n======= Digite o ano da consulta: =======\n");
                    scanf("%d",&auxano);
                    while(auxano< 2022 || auxano > 2030 )
                    {
                        printf("\n ======Ano invalido, digite Ano entre 2022 a 2030: ======\n");
                        setbuf(stdin,NULL);
                        scanf("%d",&auxano);
                    }
                    flag = 0;

                    for (int l = 0; l<= Contconsulta; l++)
                    {
                        if(strcmp(aux1, RegPaci[j].CodPac)==0)
                        {
                            if(Consulta[l].Data.dia == auxdia)
                            {
                                if(Consulta[l].Data.mes == auxmes)
                                {
                                    if(Consulta[l].Data.ano == auxano)
                                    {
                                        printf("\nPaciente j� cadastrado nesta data");
                                        flag=1;
                                    }
                                }
                            }
                        }
                    }
                    if(flag==0)
                    {

                        Consulta[inc].Data.dia = auxdia;
                        Consulta[inc].Data.mes = auxmes;
                        Consulta[inc].Data.ano = auxano;
                        strcpy(Consulta[inc].CodPac, aux1);

                        printf("\n Digite o Horario da consulta: ");
                        setbuf(stdin,NULL);
                        scanf("%d",&Consulta[inc].horario.hora);
                        while(Consulta[inc].horario.hora < 0 || Consulta[inc].horario.hora > 23 )
                        {
                            printf("\n hora invalido, digite hora entre 0 a 23: ");
                            setbuf(stdin,NULL);
                            scanf("%d",&Consulta[inc].horario.hora);
                        }
                        printf("\n Digite o minuto da consulta: ");
                        scanf("%d",&Consulta[inc].horario.min);
                        while(Consulta[inc].horario.min < 0 || Consulta[inc].horario.min > 59 )
                        {
                            printf("\n Minuto invalido, digite minuto entre 0 a 59: ");
                            setbuf(stdin,NULL);
                            scanf("%d",&Consulta[inc].horario.hora);
                        }

                        printf("\n Digite o segundo da consulta: ");
                        scanf("%d",&Consulta[inc].horario.segund);
                        while(Consulta[inc].horario.segund < 0 || Consulta[inc].horario.segund > 59 )
                        {
                            printf("\n segundo invalido, digite segundo entre 0 a 59: ");
                            setbuf(stdin,NULL);
                            scanf("%d",&Consulta[inc].horario.segund);
                        }
                        printf("\nCodigo da consulta: %d",inc);

                    }
                    inc++;
                    flag2 = 2;
                }
                else if(flag2!=2)
                {
                    flag2 = 1;

                }
            }
            if(flag2==1)
            {
                printf("\n nenhum paciente com esse codigo cadastrado\n");
            }
            break;


        case 3:
            printf("\nDigite o Codigo do paciente: ");
            setbuf(stdin,NULL);
            gets(aux);
            flag3 = 0;
            if(inc == 0)
            {
                printf("\n Nao tem clientes cadastrados\n");
                flag3 = 2;
            }
            else
            {
                for(int i =0; i<=inc; i++)
                {
                    if(strcmp(Consulta[i].CodPac,aux)==0) //verificar o codigo cliente
                    {
                        printf("Data: %d/%d/%d",Consulta[i].Data.dia,Consulta[i].Data.mes,Consulta[i].Data.ano);
                        printf("\nHora: %d:%d:%d\n",Consulta[i].horario.hora,Consulta[i].horario.min,Consulta[i].horario.segund);
                        flag3 = 2;

                    }
                }
            }
            if(flag3 == 0)
            {
                printf("\nNenhum paciente encontrado");
            }
            break;

        case 4:
            printf("\nDigite o Codigo do paciente: ");
            setbuf(stdin,NULL);
            gets(aux);
            flag3 = 0;
            if(Contpac == 0)
            {
                printf("\n Nao tem clientes cadastrados\n");
                flag3 = 2;
            }
            else
            {
                for(int i =0; i<=Contpac; i++)
                {
                    if(strcmp(RegPaci[i].CodPac,aux)==0)
                    {


                        printf("\nDigite o Codigo da consulta: ");
                        scanf("%d",&aux3);



                        //for(int h =0; h<=inc; h++)// tava dando erro aq
                        //{
                            //if(inc == aux3)entrou com erro
                           // {
                                printf("\n Digite o Horario da consulta: ");
                                setbuf(stdin,NULL);
                                scanf("%d",&Consulta[i].horario.hora);
                                while(Consulta[i].horario.hora < 0 || Consulta[i].horario.hora > 23 )
                                {
                                    printf("\n hora invalido, digite hora entre 0 a 23: ");
                                    setbuf(stdin,NULL);
                                    scanf("%d",&Consulta[i].horario.hora);
                                }
                                printf("\n Digite o minuto da consulta: ");
                                scanf("%d",&Consulta[i].horario.min);
                                while(Consulta[i].horario.min < 0 || Consulta[i].horario.min > 59 )
                                {
                                    printf("\n Minuto invalido, digite minuto entre 0 a 59: ");
                                    setbuf(stdin,NULL);
                                    scanf("%d",&Consulta[i].horario.hora);
                                }

                                printf("\n Digite o segundo da consulta: ");
                                scanf("%d",&Consulta[i].horario.segund);
                                while(Consulta[i].horario.segund < 0 || Consulta[i].horario.segund > 59 )
                                {
                                    printf("\n segundo invalido, digite segundo entre 0 a 59: ");
                                    setbuf(stdin,NULL);
                                    scanf("%d",&Consulta[i].horario.segund);
                                }

                                printf("\nHorario do paciente alterado com sucesso\n");




                           // } erro
                       // } errro

                    }
                }
            }
        }
    }
}
