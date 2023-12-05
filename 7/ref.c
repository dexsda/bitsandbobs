#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAXLEN 500

typedef struct {
    int num_of_dice;
    int sides;
} dice;

void print_dice(dice die){
    printf("%3d * kość d%d\n", die.num_of_dice, die.sides);
}

void strip_spaces(char * buffer) {
    int i = 0, j = 0;
    while (buffer[i++])
        if(!isspace(buffer[i-1]))
            buffer[j++] = buffer[i-1];
    buffer[j] = '\0';
}

dice parse_dice(char * token) {
    dice parsed;

    if(sscanf(token, "%dd%d", &(parsed.num_of_dice), &(parsed.sides)) == 1)
        parsed.sides = 1; /* a modifier is equal to a 1 sided die */

    return parsed;
}

int roll_die(int sides) {
    return rand() % sides + 1;
}

int roll_all_dice(dice * all_dice, int num, bool neg_modifier) {
    int i, j, sum = 0, mod_multiplier = neg_modifier ? -1 : 1;
    for (i = 0; i < num; i++){
        if (all_dice[i].sides == 1) {
            sum += mod_multiplier * all_dice[i].num_of_dice;
        } else {
            for (j = 0; j < all_dice[i].num_of_dice; j++)
                sum += roll_die(all_dice[i].sides);
        }
    }
        
    return sum;
}

double get_average(dice * all_dice, int num, bool negative_modifier, int N){
    int sum = 0, i;
    for (i = 0; i < N; i++)
        sum += roll_all_dice(all_dice, num, negative_modifier);

    return ((double)sum) / (double)N; 
}

int main() {
    char buffer[MAXLEN] = "";
    dice all_dice[MAXLEN] = { {0, 0} };
    char * token;
    bool negative_modifier;
    int i = 0;
    int result;

    srand(time(NULL));

    printf("Podaj rzut w dice notation: ");
    fgets(buffer, MAXLEN, stdin);
    strip_spaces(buffer);

    /* sprawdzamy, czy w stringu jest minus - czyli ujemny modifier */
    negative_modifier = (strchr(buffer, '-') != NULL);

    token = strtok(buffer, "+-");

    while (token != NULL){
        all_dice[i++] = parse_dice(token);
        token = strtok(NULL, "+-");
    }

    /* result = roll_all_dice(all_dice, i, negative_modifer);
    printf("Wynik rzutów: %d", result); */

    printf("Średni rzut: %f \n", get_average(all_dice, i, negative_modifier, 10000));
    
    return 0;
}
