#include <stdio.h>

int main() {
    int coluna, escolher;
    int cone[9][2] = {{4,3}, {4,4}, {4,5}, {4,6}, {4,7}, {3,4}, {3,5}, {3,6}, {2,5}};
    int octaedro[5][2] ={{2,4,}, {3,4}, {4,4}, {3,3}, {3,5}}; 
    int estrela[7][2] = {{3,2},{3,3},{3,4},{3,5},{3,6},{4,4},{2,4}};
    int naviodiagonal[4][2] = {{0,0}, {1,1}, {2,2}, {3,3}};
    int navio[4][2] = {{2,5},{0,1}, {4,4}, {4,3}};
    char letra, linha;
    int index[10][10] = {0};

    printf("Iniciando jogo\n");

    while (1){
    

    //Exibe letras de A a J na tabela, usando o como cordenadas.
    printf("\n   ");
    for (letra = 'A'; letra <= 'J'; letra++){
        printf("%c ", letra);
    }
    printf("\n");
    
    //Campo
    for(int i = 0; i < 10; i++) {
            printf("%d  ", i);//Exibe numero de 1 a 10 na tabela, usando o como cordenadas.
        for (int j = 0; j < 10; j++){
            printf("%d ", index[i][j]); }//for2
      printf("\n");
    }

    
    printf("\n1. Usar Bombas");
    printf("\n2. Atacar por Cordenadas\n");
    scanf("%d", &escolher);

    if(escolher == 1) {
        int escolherbomba;
        printf("\n1. Bomba Estrela");
    printf("\n2. Bomba Octaedro");
    printf("\n3. Bom Cone\n");
    scanf("%d", &escolherbomba);

    
    
    
    if(escolherbomba == 1){
    for (int i = 0; i < 7; i++){
            int _linha = estrela[i][0];  // Pega a coordenada da linha
            int _coluna = estrela[i][1]; // Pega a coordenada da coluna
            index[_linha][_coluna] = 5;
        
    }
} else if(escolherbomba == 2){
        for (int i = 0; i < 5; i++){
                int _linha = octaedro[i][0];  // Pega a coordenada da linha
                int _coluna = octaedro[i][1]; // Pega a coordenada da coluna
                index[_linha][_coluna] = 5;
            
        }
} else if (escolherbomba == 3){
    for (int i = 0; i < 9; i++){
            int _linha = cone[i][0];
            int _coluna = cone[i][1];
            index[_linha][_coluna] = 5;
        }
        
    }
    

    
//campo atualiado
for (int i = 0; i < 10; i++){
    for (int j = 0; j < 10; j++){
        printf(" %d", index[i][j]);
    }
    printf("\n");
}
    } else if(escolher == 2) {

        //Exibe letras de A a J na tabela, usando o como cordenadas.
    printf("\n   ");
    for (letra = 'A'; letra <= 'J'; letra++){
        printf("%c ", letra);
    }
    printf("\n");
    
    //Campo
    for(int i = 0; i < 10; i++) {
            printf("%d  ", i);//Exibe numero de 1 a 10 na tabela, usando o como cordenadas.
        for (int j = 0; j < 10; j++){
            printf("%d ", index[i][j]); }//for2
      printf("\n");
    }

    printf("\nEscola uma cordenada: \n");
    printf("-> ");
    scanf(" %c%d", &linha, &coluna);

    linha = linha - 'A';

  


    //navio
    int acertou = 0;
    for (int i = 0; i < 4; i++) {
        // Comparando a linha e coluna numérica do navio com a linha e coluna do ataque
        if (navio[i][0] == linha && navio[i][1] == coluna) {
            index[linha][coluna]= 3;
            acertou = 1;
            break;  // Se acertou, não precisa continuar verificando os outros navios
        }
    }

    for (int i = 0; i < 4; i++) {
        // Comparando a linha e coluna numérica do navio com a linha e coluna do ataque
        if (naviodiagonal[i][0] == linha && naviodiagonal[i][1] == coluna) {
            index[linha][coluna]= 3;
            acertou = 1;
            break;  // Se acertou, não precisa continuar verificando os outros navios
        }
    }


if (acertou){
    printf("\nACERTOU!!!\n\n");
    printf("\nUm Acertado, continuando....");
} else {
    printf("\nErrou!\n\n");
}}

//Campo
for(int i = 0; i < 10; i++) {
    printf("%d  ", i);//Exibe numero de 1 a 10 na tabela, usando o como cordenadas.
for (int j = 0; j < 10; j++){
    printf("%d ", index[i][j]); }//for2
printf("\n");
}




    
    }//While }    
}//Main }