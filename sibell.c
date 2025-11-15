#include <stdio.h>

int main() {
    int val;

    printf("Välj ett nummer (1-5): ");
    scanf("%d", &val);

    switch (val) {
        case 1:
            printf("🌹 Du är som semikolon i mitt C-program, utan dig faller allt samman.\n");
            break;
        case 2:
            printf("💘 Om kärlek var kod, skulle du vara min huvudfunktion: int main(void) ❤️\n");
            break;
        case 3:
            printf("✨ Jag försökte kompilera utan dig... men fick bara syntaxfel i hjärtat.\n");
            break;
        case 4:
            printf("💕 Du har satt mitt hjärta i en oändlig loop av kärlek: while(1) { <3 }\n");
            break;
        case 5:
            printf("💞 Du är min favoritvariabel, deklarerad i hjärtat, aldrig deallokerad.\n");
            break;
        default:
            printf("🤭 Fel val, men du är fortfarande helt rätt för mig!\n");
            break;
    }

    return 0;
}
