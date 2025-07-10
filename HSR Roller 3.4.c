#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//global variables
#define PLAYABLE_CHARACTER_COUNT 74
#define ECHOES_OF_WAR_COUNT 7
//SAVE FILE
#define SAVE_FILE "saved_hsr_characters.txt"

// ANSI color codes
#define RESET             "\x1b[0m" // resets the color to white
#define COLOR_WIND        "\x1b[32m" // green
#define COLOR_LIGHTNING   "\x1b[95m" // bright purple
#define COLOR_FIRE        "\x1b[31m" // red
#define COLOR_ECHO        "\x1b[1;31m" // bold red
#define COLOR_IMAGINARY   "\e[1;33m" // bold yellow
#define COLOR_ICE         "\x1b[36m" // cyan
#define COLOR_PHYSICAL    "\x1b[90m" // bright grey
#define COLOR_QUANTUM     "\x1b[38;5;54m" // dark purple

// ANSI string compares to return a certain global color variable when called
const char* fightingStyleColor(const char* fightingStyle) {
    if      (strcmp(fightingStyle, "Wind") == 0) return COLOR_WIND;
    else if (strcmp(fightingStyle, "Lightning") == 0) return COLOR_LIGHTNING;
    else if (strcmp(fightingStyle, "Fire") == 0) return COLOR_FIRE;
    else if (strcmp(fightingStyle, "Imaginary") == 0) return COLOR_IMAGINARY;
    else if (strcmp(fightingStyle, "Ice") == 0) return COLOR_ICE;
    else if (strcmp(fightingStyle, "Physical") == 0) return COLOR_PHYSICAL;
    else if (strcmp(fightingStyle, "Quantum") == 0) return COLOR_QUANTUM;
    else return RESET;
}

int main () {
    //HSR version 3.4
    //giant list of all characters
    //alphabetically ordered
    char *playableCharacters[PLAYABLE_CHARACTER_COUNT] = {
        //A
        "Acheron", "Aglaea", "Anaxa", "Archer", 
        "Argenti", "Arlan", "Asta", "Aventurine",
        //B
        "Bailu", "Black Swan", "Blade", "Boothill", 
        "Bronya",
        //C
        "Castorice", "Cipher", "Clara",
        //D
        "Dan Heng", "Dan Heng - Imbibitor", "Dr. Ratio",
        //F
        "Feixiao", "Firefly", "Fu Xuan", "Fugue",
        //G
        "Gallagher", "Gepard", "Guinaifen",
        //H
        "Hanya", "Herta", "Himeko", "Hook",
        "Huohuo", "Hyacine",
        //J
        "Jade", "Jiaoqiu", "Jing Yuan", "Jingliu",
        //K
        "Kafka",
        //L
        "Lingsha", "Luka", "Luocha", "Lynx",
        //M
        "March 7th", "March 7th (The Hunt)", "Misha", "Moze", 
        "Mydei",
        //N
        "Natasha",
        //P
        "Pela", "Phainon",
        //Q
        "Qingque",
        //R
        "Rappa", "Robin", "Ruan Mei",
        //S
        "Saber", "Sampo", "Seele", "Serval", "Silver Wolf", 
        "Sparkle", "Sunday", "Sushang",
        //T
        "The Herta", "Tingyun", "Topaz & Numby", "Trailblazer (Fire) / PMC", 
        "Trailblazer (Ice) / RMC", "Trailblazer (Imaginary) / HMC", "Trailerblazer (Physical) / DMC", "Tribbie",
        //W
        "Welt",
        //X
        "Xueyi",
        //Y
        "Yanqing", "Yunli", "Yukong"
    };
    char *playableCharactersFightingStyle[PLAYABLE_CHARACTER_COUNT] = {
        //A
        "Lightning", "Lightning", "Wind", "Quantum", 
        "Physical", "Lightning", "Fire", "Imaginary",
        //B
        "Lightning", "Wind", "Wind", "Physical", 
        "Wind",
        //C
        "Quantum", "Quantum", "Physical",
        //D
        "Wind", "Imaginary", "Imaginary",
        //F
        "Wind", "Fire", "Quantum", "Fire",
        //G
        "Fire", "Ice", "Fire",
        //H
        "Physical", "Ice", "Fire", "Fire",
        "Wind", "Wind",
        //J
        "Quantum", "Fire", "Lightning", "Ice",
        //K
        "Lightning",
        //L
        "Fire", "Physical", "Imaginary", "Quantum",
        //M
        "Ice", "Imaginary", "Ice", "Lightning", 
        "Imaginary",
        //N
        "Physical",
        //P
        "Ice", "Physical",
        //Q
        "Quantum",
        //R
        "Imaginary", "Physical", "Ice",
        //S
        "Wind", "Wind", "Quantum", "Lightning", "Quantum", 
        "Quantum", "Imaginary", "Physical",
        //T
        "Ice", "Lightning", "Fire", "Fire", 
        "Ice", "Imaginary", "Physical", "Quantum",
        //W
        "Imaginary",
        //X
        "Quantum",
        //Y
        "Ice", "Physical", "Imaginary"
    };
    char *playableCharactersPath[PLAYABLE_CHARACTER_COUNT] = {
        //randomize specifically for path or element?
    };
    //alphabetically ordered bosses
    char *echosOfWar[ECHOES_OF_WAR_COUNT] = {
        "Borehole Plant's Past Nightmares", "Destruction's Beginning", "Divine Seed", "End of the Eternal Freeze", "Glance of Twilight",
        "Inner Beast's Battlefield", "Salutations of Ashen Dreams"
    };
    //seeds the random number generator
    srand(time(NULL));
    //main menu
    printf("Honkai Star Rail Roller 3.4 v1\n");
    printf("By DoggieSquad\n");
    printf("1. Roll it! (All)\n");
    printf("2. Roll it! (Save File)\n");
    printf("3. Write into Save File\n");
    printf("4. Erase Save File\n");
    printf("5. Exit\n");
    int option;
    printf("Choose an option by typing in a number: ");
    scanf("%d", &option);
    //switch case for option
    switch (option) {
        case 1: {
            //makes sure that the characters selected are all unique
            int count = 0, selected[4];
            while (count < 4) {
                int idx = rand() % PLAYABLE_CHARACTER_COUNT;
                int dup = 0;
                for (int j = 0; j < count; j++) {
                    if (selected[j] == idx) { dup = 1; break; }
                }
                if (!dup) selected[count++] = idx;
            }
            printf("Here is your randomized team:\n\n");
            for (int i = 0; i < 4; i++) {
                const char* style = playableCharactersFightingStyle[selected[i]];
                printf("Character %d: %s%s%s - %s%s%s\n", 
                    i+1, fightingStyleColor(style), playableCharacters[selected[i]], RESET, // #, color, character, reset
                    fightingStyleColor(style), style, RESET); // color, string of style, reset
            }

            int echo = rand() % ECHOES_OF_WAR_COUNT;
            printf("\nEcho of War: %s%s%s\n\n", COLOR_ECHO, echosOfWar[echo], RESET); // color, boss, reset

            printf("Good luck in your battle!\n");
            system("pause");
            return 0;
        }
        case 2: {
            //rolls through your saved characters put in the txt or in case 3
            FILE *fp = fopen(SAVE_FILE, "r");
            if (!fp) { 
                printf("No saved characters.\n");
                system("pause");
                return 0;
            }
            int saved[200], count = 0, selected[4];
            while (count < 200 && fscanf(fp, "%d\n", &saved[count]) == 1) count++;
            fclose(fp);
            if (count < 4) { 
                printf("Need at least 4 saved chars.\n");
                system("pause");
                return 0;
            }
            int sel[4], selCount = 0;
            while (selCount < 4) {
                int r = rand() % count, dup = 0;
                for (int j = 0; j < selCount; j++) 
                    if (selected[j] == saved[r]) { 
                    dup = 1; 
                    break; 
                }
                if (!dup) selected[selCount++] = saved[r];
            }
            printf("Team from saved characters:\n\n");
            for (int i = 0; i < 4; i++) {
                const char* style = playableCharactersFightingStyle[selected[i]];
                printf("Character %d: %s%s%s - %s%s%s\n", 
                    i+1, fightingStyleColor(style), playableCharacters[selected[i]], RESET, //#, color, character, reset
                    fightingStyleColor(style), style, RESET); // color, string of style, reset
            }
            int echo = rand() % ECHOES_OF_WAR_COUNT;
            printf("\nEcho of War: %s%s%s\n\n", COLOR_ECHO, echosOfWar[echo], RESET); // color, boss, reset
            system("pause");
            return 0;
        }
        case 3: {
            //outputs the entire list of playable characters within the game
            printf("Available characters (index: name):\n");
            for (int i = 0; i < PLAYABLE_CHARACTER_COUNT; i++) {
                printf("%2d: %s\n", i, playableCharacters[i]);
            }
            printf("Enter character indices to save (enter -1 to stop):\n");
            FILE *fp = fopen(SAVE_FILE, "a");
            //failsafe
            if (!fp) { 
                printf("Cannot open save file.\n"); 
                system("pause");
                return 0; 
            }
            // reads the number, makes sure it is related to the index list, 
            // then gets the string related to the number to output the character's name
            while (1) {
                int idx;
                printf("> ");
                if (scanf("%d", &idx) != 1) 
                    break;
                if (idx < 0) 
                    break;
                if (idx >= PLAYABLE_CHARACTER_COUNT) {
                    printf("Invalid index.\n");
                    continue;
                }
                fprintf(fp, "%d\n", idx);
                printf("Saved %s.\n", playableCharacters[idx]);
            }
            fclose(fp);
            system("pause");
            return 0;
        }
        case 4: {
            //erases the txt file when prompted
            if (remove(SAVE_FILE)==0) 
                printf("All saved characters erased.\n");
            else 
                printf("Failed to erase.\n");
            system("pause");
            return 0;
        }
        case 5: {
            //exits the program
            printf("Goodbye!\n");
            system("pause");
            return 0;
        }
    }
    //failsafe
    printf("Invalid option selected. Please restart the program and choose a valid option.\n");
    system("pause");
    return 0;
}