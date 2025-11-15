/*
 * Bank Account Management System
 * KTH - Programmering i C
 * Funktioner:
 * - Registrera konton
 * - Logga in som admin/användare
 * - Sortera, söka, avregistrera och ändra saldo
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXACCOUNTS 200

/* ---------------------------------------------------------
 *                  STRUKT & FUNKTIONSDEKLARATIONER
 * --------------------------------------------------------- */

typedef struct {
    char kontoNr[10];
    char fornamn[16];
    char efternamn[16];
    char losenord[10];
    int saldo;
} Konto;

void filInläsning(char *filnamn, Konto konton[], int *antalKonton);
void adminMeny(Konto konton[], int *antalKonton, char *filnamn);
void användarMeny(Konto konton[], int *antalKonton, char *filnamn);

void registreraNyttKonto(Konto konton[], int *antalKonton);
void skrivaUtKonton(Konto konton[], int antalKonton);
void sorteraKonton(Konto konton[], int antalKonton);
int kontoSökande(Konto konton[], int antalKonton);

void avregKonto(Konto konton[], int *antalKonton);
void sparaTillFil(char *filnamn, Konto konton[], int antalKonton);

void utskriftEttKonto(Konto k);
int hittaRättKonto(Konto konton[], int antalKonton, char *kontoNr);
void kontoVal(Konto konton[], int index, char *filnamn, int *antalKonton);

/* ---------------------------------------------------------
 *                          MAIN
 * --------------------------------------------------------- */

int main() {
    Konto konton[MAXACCOUNTS];
    int antalKonton;
    char filnamn[100];

    printf("Ange filnamn att läsa in: ");
    scanf("%99s", filnamn);

    filInläsning(filnamn, konton, &antalKonton);

    while (1) {
        int val = 0;
        printf("\n(1) Logga in som admin\n"
               "(2) Logga in som användare\n"
               "(3) Avsluta\n"
               "Ange val: ");
        scanf("%d", &val);

        switch (val) {
            case 1: adminMeny(konton, &antalKonton, filnamn); break;
            case 2: användarMeny(konton, &antalKonton, filnamn); break;
            case 3:
                sparaTillFil(filnamn, konton, antalKonton);
                printf("Avslutar...\n");
                return 0;
            default:
                printf("Ogiltigt val\n");
        }
    }
}

/* ---------------------------------------------------------
 *                 FILINLÄSNING & SPARANDE
 * --------------------------------------------------------- */

void filInläsning(char *filnamn, Konto konton[], int *antalKonton) {
    FILE *fil = fopen(filnamn, "r");

    if (fil == NULL) {
        printf("Ingen fil hittades. Skapar en ny fil.\n");
        fil = fopen(filnamn, "w");
        fclose(fil);
        *antalKonton = 0;
        return;
    }

    printf("Laddar data från filen...\n");
    int i = 0;

    while (i < MAXACCOUNTS &&
           fscanf(fil, "%9s %15s %15s %9s %d",
                  konton[i].kontoNr,
                  konton[i].fornamn,
                  konton[i].efternamn,
                  konton[i].losenord,
                  &konton[i].saldo) == 5) {
        i++;
    }

    *antalKonton = i;
    fclose(fil);
}

void sparaTillFil(char *filnamn, Konto konton[], int antalKonton) {
    FILE *fil = fopen(filnamn, "w");

    for (int i = 0; i < antalKonton; i++) {
        fprintf(fil, "%s %s %s %s %d\n",
                konton[i].kontoNr,
                konton[i].fornamn,
                konton[i].efternamn,
                konton[i].losenord,
                konton[i].saldo);
    }

    fclose(fil);
}

/* ---------------------------------------------------------
 *                UTSKRIFTSFUNKTIONER
 * --------------------------------------------------------- */

void utskriftEttKonto(Konto k) {
    char hela_namnet[35];
    sprintf(hela_namnet, "%s %s", k.fornamn, k.efternamn);

    printf("%-8s %-25s %8d\n", k.kontoNr, hela_namnet, k.saldo);
}

void skrivaUtKonton(Konto konton[], int antalKonton) {
    if (antalKonton == 0) {
        printf("Inga konton finns registrerade.\n");
        return;
    }

    printf("%-8s %-25s %-8s\n", "Konto-nr", "Namn", "Saldo(kr)");
    printf("_______________________________________________\n");

    for (int i = 0; i < antalKonton; i++) {
        utskriftEttKonto(konton[i]);
    }
}

/* ---------------------------------------------------------
 *                 SÖK & SORTERA FUNKTIONER
 * --------------------------------------------------------- */

int hittaRättKonto(Konto konton[], int antalKonton, char *kontoNr) {
    for (int i = 0; i < antalKonton; i++) {
        if (strcmp(konton[i].kontoNr, kontoNr) == 0)
            return i;
    }
    return -1;
}

void sorteraKonton(Konto konton[], int antalKonton) {
    if (antalKonton < 2) {
        printf("För få konton för sortering.\n");
        return;
    }

    int val;
    printf("Sortera efter konto-nr (1), namn (2) eller saldo (3): ");
    scanf("%d", &val);

    for (int i = 0; i < antalKonton - 1; i++) {
        for (int j = 0; j < antalKonton - i - 1; j++) {

            int byte = 0;

            switch (val) {
                case 1:
                    byte = strcmp(konton[j].kontoNr, konton[j + 1].kontoNr) > 0;
                    break;
                case 2:
                    byte = strcmp(konton[j].efternamn, konton[j + 1].efternamn) > 0;
                    break;
                case 3:
                    byte = konton[j].saldo > konton[j + 1].saldo;
                    break;
                default:
                    printf("Ogiltigt val.\n");
                    return;
            }

            if (byte) {
                Konto temp = konton[j];
                konton[j] = konton[j + 1];
                konton[j + 1] = temp;
            }
        }
    }
}

/* ---------------------------------------------------------
 *      REGISTRERING, INLOGGNING & KONTOHANTERING
 * --------------------------------------------------------- */

void registreraNyttKonto(Konto konton[], int *antalKonton) {
    char kontoNr[20];

    while (1) {
        if (*antalKonton >= MAXACCOUNTS) {
            printf("Kontoregistret är fullt.\n");
            return;
        }

        printf("Ange kontonummer (q för att avsluta): ");
        scanf("%s", kontoNr);

        if (strcmp(kontoNr, "q") == 0)
            return;

        if (strlen(kontoNr) != 6) {
            printf("Kontonumret måste vara 6 siffror.\n");
            continue;
        }

        bool endast_siffror = true;
        for (int i = 0; i < 6; i++) {
            if (kontoNr[i] < '0' || kontoNr[i] > '9') {
                endast_siffror = false;
                break;
            }
        }

        if (!endast_siffror) {
            printf("Endast siffror tillåtna.\n");
            continue;
        }

        if (hittaRättKonto(konton, *antalKonton, kontoNr) != -1) {
            printf("Kontonumret finns redan.\n");
            continue;
        }

        Konto nytt;
        strcpy(nytt.kontoNr, kontoNr);

        printf("Ange ägarens för- och efternamn: ");
        scanf("%15s %15s", nytt.fornamn, nytt.efternamn);

        while (1) {
            printf("Ange lösenord (6 tecken): ");
            scanf("%9s", nytt.losenord);

            if (strlen(nytt.losenord) == 6)
                break;

            printf("Felaktigt antal tecken.\n");
        }

        nytt.saldo = 0;
        konton[*antalKonton] = nytt;
        (*antalKonton)++;

        printf("Konto registrerat!\n");
    }
}

/* ---------------------------------------------------------
 *                  ANVÄNDARMENY & KONTOVAL
 * --------------------------------------------------------- */

void kontoVal(Konto konton[], int index, char *filnamn, int *antalKonton) {
    while (1) {
        int val = 0;

        printf("(1) Skriv ut konto\n"
               "(2) Ändra lösenord\n"
               "(3) Ändra saldo\n"
               "(4) Huvudmeny\n"
               "Ange val: ");

        scanf("%d", &val);

        switch (val) {
            case 1:
                printf("%-8s %-25s %-8s\n", "Konto-nr", "Namn", "Saldo(kr)");
                printf("_______________________________________________\n");
                utskriftEttKonto(konton[index]);
                break;

            case 2: {
                char nytt[10];

                while (1) {
                    printf("Ange nytt lösenord (6 tecken): ");
                    scanf("%9s", nytt);

                    if (strlen(nytt) == 6) {
                        strcpy(konton[index].losenord, nytt);
                        printf("Lösenord ändrat!\n");
                        break;
                    }
                    printf("Fel antal tecken.\n");
                }
                break;
            }

            case 3: {
                int belopp, alt;

                printf("Saldo: %d kr\n(1) Insättning\n(2) Uttag\nVal: ", konton[index].saldo);
                scanf("%d", &alt);

                printf("Belopp: ");
                scanf("%d", &belopp);

                if (alt == 1) {
                    konton[index].saldo += belopp;
                } else if (alt == 2) {
                    if (belopp > konton[index].saldo) {
                        printf("Otillräckligt saldo!\n");
                    } else {
                        konton[index].saldo -= belopp;
                    }
                }
                printf("Nytt saldo: %d kr\n", konton[index].saldo);
                break;
            }

            case 4:
                return;

            default:
                printf("Ogiltigt val.\n");
        }
    }
}

/* ---------------------------------------------------------
 *                     ADMINMENY
 * --------------------------------------------------------- */

void adminMeny(Konto konton[], int *antalKonton, char *filnamn) {
    char angivet_lösen[10];
    int försök = 0;

    while (försök < 3) {
        printf("Ange admin-lösenord (q för avbryt): ");
        scanf("%9s", angivet_lösen);

        if (strcmp(angivet_lösen, "q") == 0)
            return;

        if (strcmp(angivet_lösen, "******") == 0)
            break;

        printf("Fel lösenord.\n");
        försök++;
    }

    while (1) {
        int val;
        printf("\n(1) Registrera nya konton\n"
               "(2) Skriva ut alla konton\n"
               "(3) Sortera konton\n"
               "(4) Söka efter konto\n"
               "(5) Avregistrera konto\n"
               "(6) Huvudmeny\n"
               "Ange val: ");
        scanf("%d", &val);

        switch (val) {
            case 1: registreraNyttKonto(konton, antalKonton); break;
            case 2: skrivaUtKonton(konton, *antalKonton); break;
            case 3: sorteraKonton(konton, *antalKonton); break;
            case 4: kontoSökande(konton, *antalKonton); break;
            case 5: avregKonto(konton, antalKonton); break;
            case 6: return;
            default:
                printf("Ogiltigt val.\n");
        }
    }
}

/* ---------------------------------------------------------
 *                SÖK & AVREGISTRERING
 * --------------------------------------------------------- */

int kontoSökande(Konto konton[], int antalKonton) {
    int val;

    while (1) {
        printf("\n(1) Konto-nr\n(2) Namn\n(3) Saldo-intervall\n(4) Tillbaka\nVal: ");
        scanf("%d", &val);

        if (val == 4) return -1;

        /* Sök med kontonummer */
        if (val == 1) {
            char sökNr[20];
            printf("Ange konto-nr: ");
            scanf("%19s", sökNr);

            int idx = hittaRättKonto(konton, antalKonton, sökNr);
            if (idx == -1) {
                printf("Kontot hittades inte.\n");
                return -2;
            }

            printf("%-8s %-25s %-8s\n", "Konto-nr", "Namn", "Saldo(kr)");
            printf("_______________________________________________\n");
            utskriftEttKonto(konton[idx]);
            return idx;
        }

        /* Sök via namn */
        else if (val == 2) {
            char str[20];
            printf("Ange söksträng: ");
            scanf("%19s", str);

            int count = 0, lastIdx = -1;

            printf("%-8s %-25s %-8s\n", "Konto-nr", "Namn", "Saldo(kr)");
            printf("_______________________________________________\n");

            for (int i = 0; i < antalKonton; i++) {
                if (strstr(konton[i].fornamn, str) || strstr(konton[i].efternamn, str)) {
                    utskriftEttKonto(konton[i]);
                    lastIdx = i;
                    count++;
                }
            }

            if (count == 0) {
                printf("Inga träffar.\n");
                return -2;
            }
            if (count == 1) return lastIdx;

            printf("Fler än ett konto hittades.\n");
            return -2;
        }

        /* Sök via saldo */
        else if (val == 3) {
            int min, max;
            printf("Min saldo: ");
            scanf("%d", &min);
            printf("Max saldo: ");
            scanf("%d", &max);

            int count = 0, lastIdx = -1;

            printf("%-8s %-25s %-8s\n", "Konto-nr", "Namn", "Saldo(kr)");
            printf("_______________________________________________\n");

            for (int i = 0; i < antalKonton; i++) {
                if (konton[i].saldo >= min && konton[i].saldo <= max) {
                    utskriftEttKonto(konton[i]);
                    lastIdx = i;
                    count++;
                }
            }

            if (count == 0) {
                printf("Inga konton i intervallet.\n");
                return -2;
            }
            if (count == 1) return lastIdx;

            printf("Fick inte exakt ett konto.\n");
            return -2;
        }

        else {
            printf("Ogiltigt val.\n");
        }
    }
}

void avregKonto(Konto konton[], int *antalKonton) {
    while (1) {
        int index = kontoSökande(konton, *antalKonton);

        if (index == -1) return;
        if (index == -2) continue;

        if (konton[index].saldo != 0) {
            printf("Saldo måste vara 0 för att avregistrera.\n");
            return;
        }

        char val[3];
        printf("Vill du avregistrera kontot (j/n)? ");
        scanf("%2s", val);

        if (strcmp(val, "j") != 0) return;

        for (int i = index; i < *antalKonton - 1; i++) {
            konton[i] = konton[i + 1];
        }

        (*antalKonton)--;
        printf("Kontot avregistrerat!\n");
    }
}

/* ---------------------------------------------------------
 *               ANVÄNDARLOGIN
 * --------------------------------------------------------- */

void användarMeny(Konto konton[], int *antalKonton, char *filnamn) {
    char kontoNr[10];
    char lösen[10];

    while (1) {
        printf("Ange konto (6 siffror, q för att avsluta): ");
        scanf("%9s", kontoNr);

        if (strcmp(kontoNr, "q") == 0) return;

        if (strlen(kontoNr) != 6) {
            printf("Fel: Kontonr måste ha 6 siffror.\n");
            continue;
        }

        int index = hittaRättKonto(konton, *antalKonton, kontoNr);
        if (index == -1) {
            printf("Konto saknas.\n");
            continue;
        }

        while (1) {
            printf("Ange lösenord: ");
            scanf("%9s", lösen);

            if (strcmp(lösen, "q") == 0) return;

            if (strcmp(konton[index].losenord, lösen) == 0) {
                kontoVal(konton, index, filnamn, antalKonton);
                return;
            }

            printf("Fel lösenord.\n");
        }
    }
}