# Bankprogram

Ett menybaserat bankhanteringssystem skrivet i C. Programmet hanterar registrering, inloggning, sökning, sortering och administrering av bankkonton via en textfil. Projektet är utvecklat som en del av kursen *Programmering i C* vid KTH.

---

## Översikt

Detta program implementerar ett komplett banksystem där både användare och administratörer kan interagera med konton. Kontodata lagras i en textfil och läses automatiskt in vid programmets start. Programmet använder structs, arrayer, filhantering och menybaserad interaktion för att skapa ett stabilt och lättanvänt konsolsystem.

---

## Funktioner

### Användare
- Logga in med kontonummer och lösenord  
- Visa kontouppgifter  
- Ändra lösenord  
- Göra insättningar och uttag  

### Administratör
- Registrera nya konton  
- Skriva ut alla konton  
- Sortera konton (kontonummer, namn eller saldo)  
- Söka efter konton (nummer, namn eller saldo-intervall)  
- Avregistrera konton med saldo 0  


Konton läses in vid programmets start och sparas tillbaka när programmet avslutas.
(Om filen saknas skapas den automatiskt)

---

## Kompilering och körning

### Kompilera:
```bash
gcc -o bank Bankprogram.c
./bank
konton.txt
