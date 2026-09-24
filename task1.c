#include <stdio.h>

void find_combinations(int score) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

    for (int td_2pt = 0; td_2pt * 8 <= score; td_2pt++) {
        for (int td_fg = 0; td_fg * 7 <= score; td_fg++) {
            for (int td = 0; td * 6 <= score; td++) {
                for (int fg = 0; fg * 3 <= score; fg++) {
                    for (int safety = 0; safety * 2 <= score; safety++) {
                        int total = (td_2pt * 8) + (td_fg * 7) + (td * 6) + (fg * 3) + (safety * 2);
                        
                        if (total == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td_2pt, td_fg, td, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        if (scanf("%d", &score) != 1) {
            printf("Invalid input. Please enter an integer.\n");
            // Clear invalid characters from input buffer
            while (getchar() != '\n');
            continue;
        }

        if (score == 1) {
            break;
        }

        if (score < 0) {
            printf("Invalid input: Score cannot be negative.\n");
            continue;
        }

        find_combinations(score);
    }

    return 0;
}