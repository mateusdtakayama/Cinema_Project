#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include "biblioteca.h"


void zerador(int tam, struct poltrona cinema[tam][tam]){

    for(int i=0; i<tam; i++){
            for(int j=0; j<tam; j++){
                cinema[i][j].ocupado = 0;
            }
    }

}

void programa(int tam, struct poltrona cinema[tam][tam], char letra, int fileira, int num){

    int opcao;

    do{


            switch(menu()){

            case 1:
                reservar(tam, cinema, letra, fileira, num);
                system("pause");
                break;
            case 2:
                comprar(tam, cinema, letra, fileira, num);
                system("pause");
                break;
            case 3:
                cancelar(tam, cinema, letra, fileira, num);
                system("pause");
                break;
            case 4:
                opcao = 4;
                break;
            default:
                {
                printf(" Opção não está no menu. \n");
                break;
                }

            }
        system("cls");
        }while(opcao!=4);

}
void disponivel(int tam, struct poltrona cinema[tam][tam]){

    // salva a cor original
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvando os atributos do console */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int caracter = 97;
    for(int i=0; i<tam;i++){
        for(int j=0; j<tam;j++){

            if(cinema[i][j].ocupado == 0){ // 0 = livre

                printf(" ");
                // muda para cor 32
                SetConsoleTextAttribute(hConsole, 32);

                printf("%c%d" , caracter, j);

                //volta a cor ao normal
                SetConsoleTextAttribute(hConsole, saved_attributes);

                printf(" ");

            }else if(cinema[i][j].ocupado == 2){ //2 = comprada
                printf(" ");
                // muda para cor 64
                SetConsoleTextAttribute(hConsole, 64);

                printf("%c%d" , caracter, j);

                //volta a cor ao normal
                SetConsoleTextAttribute(hConsole, saved_attributes);

                printf(" ");
            }else{

                printf(" ");

                // muda para cor 248
                SetConsoleTextAttribute(hConsole, 248);

                printf("**"); // 1 = reservada

                 //volta a cor ao normal
                SetConsoleTextAttribute(hConsole, saved_attributes);

                printf(" ");
            }
            if(j+1 == tam){
                    caracter++;
            }

        }
        printf("\n\n");

    }

}

void bemvindo(){

    printf("  ______   __                         _____  __                                                         \n");
    printf(" /      \\ |  \\                       |     \\|  \\                                                        \n");
    printf("|  $$$$$$\ \$$   _______    ______      \$$$$$|  $$____    ______   _______    _______   ______   _______  \n");
    printf("| $$   \\$$|  \\|       \\  /      \\       | $$| $$    \\  /      \\ |       \\  /       \\ /      \\ |       \\ \n");
    printf("| $$      | $$| $$$$$$$\\|  $$$$$$\\ __   | $$| $$$$$$$\\|  $$$$$$\| $$$$$$$\\|  $$$$$$$|  $$$$$$\\| $$$$$$$\\ \n");
    printf("| $$   __ | $$| $$  | $$| $$    $$|  \\  | $$| $$  | $$| $$  | $$| $$  | $$ \\$$    \\ | $$  | $$| $$  | $$ \n");
    printf("| $$__/  \\| $$| $$  | $$| $$$$$$$$| $$__| $$| $$  | $$| $$__/ $$| $$  | $$ _\\$$$$$$\\| $$__/ $$| $$  | $$ \n");
    printf(" \\$$    $$| $$| $$  | $$ \$$     \\ \\$$    $$|  $$  | $$ \\$$    $$| $$  | $$|       $$ \\$$    $$| $$  | $$ \n");
    printf("  \\$$$$$$  \\$$ \\$$   \\$$  \\$$$$$$$  \\$$$$$$  \\$$   \\$$  \\$$$$$$  \\$$   \$$ \\$$$$$$$   \\ $$$$$$  \\$$   \\$$ \n");
    system("pause");
    system("cls");
}
void reservadas(int tam, struct poltrona cinema[tam][tam]){

     // salva a cor original
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvando os atributos do console */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    int caracter = 97;
    for(int i=0; i<tam;i++){
        for(int j=0; j<tam;j++){

            if(cinema[i][j].ocupado == 0){
                printf("     ");
            }else if(cinema[i][j].ocupado == 2){
                printf("     ");
            }else{
                printf(" ");
                // muda para cor 248
                SetConsoleTextAttribute(hConsole, 248);

                printf("%c%d" , caracter, j);

                //volta a cor ao normal
                SetConsoleTextAttribute(hConsole, saved_attributes);

                printf(" ");
            }
            if(j+1 == tam){
                    caracter++;
            }

        }
        printf("\n");
    }
}

int menu(){
    int opcao;
        printf("---------- Menu ---------- \n");
        printf(" 1. Reservar poltrona. \n");
        printf(" 2. Comprar poltrona. \n");
        printf(" 3. Cancelar reserva. \n");
        printf(" 4. Sair do programa. \n");
        printf("-------------------------- \n");
        printf("Digite a opção desejada: ");
        scanf("%d" , &opcao);

    return opcao;
}

void reservar(int tam, struct poltrona cinema[tam][tam], int letra, int fileira, int num){
    printf("Poltronas disponíveis: \n");
    disponivel(tam, cinema);
    fflush(stdin);
    printf("Em qual fileira deseja reservar? \n");
    scanf("%c", &letra);
    fileira = letra - 97;
    printf("Qual o numero da poltrona? \n");
    scanf("%d" , &num);

    printf("Reservando %c%d... \n", letra, num);

    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            if(i == fileira && j == num){
                if(cinema[i][j].ocupado != 1 && cinema[i][j].ocupado != 2){
                   cinema[i][j].ocupado = 1;
                }else{
                    printf("A poltrona inserida não está disponível! \n");
                }

            }
        }
    }
}

void comprar(int tam, struct poltrona cinema[tam][tam], int letra, int fileira, int num){
    printf("Poltronas disponíveis: \n");
    disponivel(tam, cinema);
    fflush(stdin);
    printf("Em qual fileira deseja comprar? \n");
    scanf("%c", &letra);
    fileira = letra - 97;
    printf("Qual o numero da poltrona? \n");
    scanf("%d" , &num);

    printf("Comprando %c%d... \n", letra, num);

    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            if(i == fileira && j == num ){
                if(cinema[i][j].ocupado != 1 && cinema[i][j].ocupado != 2){
                   cinema[i][j].ocupado = 2;
                }else{
                    printf("A poltrona inserida não está disponível! \n");
                }
            }
        }
    }
}


void cancelar(int tam, struct poltrona cinema[tam][tam], int letra, int fileira, int num){

    printf("Poltronas reservadas: \n");
    reservadas(tam, cinema);
    fflush(stdin);
    printf("Em qual fileira deseja cancelar a reserva? \n");
    scanf("%c", &letra);
    fileira = letra - 97;
    printf("Qual o numero da poltrona? \n");
    scanf("%d" , &num);

    printf("Cancelando %c%d... \n", letra, num);

    for(int i=0;i<tam;i++){
        for(int j=0;j<tam;j++){
            if(i == fileira && j == num ){
                if(cinema[i][j].ocupado != 0 && cinema[i][j].ocupado != 2){
                   cinema[i][j].ocupado = 0;
                }else{
                    printf("A poltrona inserida não foi reservada! \n");
                }
            }
        }
    }
}
