#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <pthread.h>

void multiply(int nbr, int indice)
{
    int compteur = 0;
    for (int i = 0; i < 2*nbr; i++)
    {
        if(i % 2 == indice){
            printf("Je suis le processus %d, je retourne la valeur \n", i);
        }
    }
    exit(EXIT_SUCCESS);
}

int main(){
    exercice1();


    exercice2();
    return 0;
}

void exercice1(){
    printf("Exercice 1\n");
    
    printf("Je suis le processus numéro %x \n", getpid());
    pid_t pid = fork();
    printf ("Fork m'a renvoyé la valeur : ", pid);
    if (pid == 0){
        printf("Je suis le fils, mon pid est %x et mon père est %x\n", getpid(), getppid());
    } else {
        printf("Je suis le père, mon pid est %x et mon fils est %x\n", getpid(), pid);
    }
}


void exercice2(){
    pid_t pid = fork();

    if (pid < 0) {
        perror("Erreur lors de la création du processus");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        // Code du processus fils : il explore la 2ème moitié du tableau
        multiply(10, 0);
    } else {
        // Code du processus père : il explore la 1ère moitié du tableau
        multiply(10, 1);
    }
    
}