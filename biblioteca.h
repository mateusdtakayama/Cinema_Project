struct poltrona{
    char fileira;
    int num;
    int ocupado;
    char nome[50];

};

void zerador(int tam, struct poltrona cinema[tam][tam]);
void bemvindo();
void disponivel(int tam, struct poltrona cinema[tam][tam]);
void reservadas(int tam, struct poltrona cinema[tam][tam]);
int menu();
void reservar(int tam, struct poltrona cinema[tam][tam], int letra, int fileira, int num);
void comprar(int tam, struct poltrona cinema[tam][tam], int letra, int fileira, int num);
void cancelar(int tam, struct poltrona cinema[tam][tam], int letra, int fileira, int num);
