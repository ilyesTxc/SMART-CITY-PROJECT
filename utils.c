#include "utils.h"

void viderBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void pause() {
    printf("Appuyez sur Entrée pour continuer...");
    getchar();
}
