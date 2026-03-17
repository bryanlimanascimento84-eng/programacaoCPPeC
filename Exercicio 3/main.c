#include <stdio.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

static int days_in_month(int month, int year) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2: {
            int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
            return leap ? 29 : 28;
        }
        default:
            return 30;
    }
}

static int read_date_auto(int *day, int *month, int *year) {
    struct termios oldt, newt;
    if (tcgetattr(STDIN_FILENO, &oldt) != 0) {
        return 0;
    }
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    if (tcsetattr(STDIN_FILENO, TCSANOW, &newt) != 0) {
        return 0;
    }

    int digits[8] = {0};
    int pos = 0;
    int need_remove_space = 0;

    while (pos < 8) {
        int c = getchar();
        if (c == EOF || c == '\n' || c == '\r') {
            break;
        }
        if (c == 8 || c == 127) {
            if (need_remove_space) {
                fputs("\b \b", stdout);
                need_remove_space = 0;
                continue;
            }
            if (pos > 0) {
                fputs("\b \b", stdout);
                pos--;
                if (pos == 2 || pos == 4) {
                    // When we backspace to a position where a space was previously emitted,
                    // remove that space as well (so the user can edit the previous group cleanly).
                    fputs("\b \b", stdout);
                    need_remove_space = 0;
                }
            }
            continue;
        }
        if (c >= '0' && c <= '9') {
            if (pos < 8) {
                digits[pos++] = c - '0';
                putchar(c);
                if (pos == 2 || pos == 4) {
                    putchar(' ');
                    need_remove_space = 1;
                } else {
                    need_remove_space = 0;
                }
            }
            if (pos == 8) {
                break;
            }
        }
    }

    putchar('\n');
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    if (pos < 8) {
        return 0;
    }

    *day = digits[0] * 10 + digits[1];
    *month = digits[2] * 10 + digits[3];
    *year = digits[4] * 1000 + digits[5] * 100 + digits[6] * 10 + digits[7];
    return 1;
}

int main() {
    time_t now_time = time(NULL);
    struct tm now_tm = *localtime(&now_time);

    int today_day = now_tm.tm_mday;
    int today_month = now_tm.tm_mon + 1; // tm_mon é 0..11
    int today_year = now_tm.tm_year + 1900;

    printf("Data e hora atual: %s", ctime(&now_time));
    printf("Data atual: %02d/%02d/%d\n", today_day, today_month, today_year);

    int birth_day, birth_month, birth_year;
    printf("\nDigite sua data de nascimento (dia mes ano): ");
    if (!read_date_auto(&birth_day, &birth_month, &birth_year)) {
        printf("Entrada inválida.\n");
        return 1;
    }

    int age_years = today_year - birth_year;
    int age_months = today_month - birth_month;
    int age_days = today_day - birth_day;

    if (age_days < 0) {
        age_months--;
        int prev_month = today_month - 1;
        int prev_year = today_year;
        if (prev_month < 1) {
            prev_month = 12;
            prev_year--;
        }
        age_days += days_in_month(prev_month, prev_year);
    }

    if (age_months < 0) {
        age_years--;
        age_months += 12;
    }

    printf("\nVocê tem: %d anos, %d meses e %d dias\n", age_years, age_months, age_days);

    if (age_years >= 18) {
        printf("Você é maior de idade.\n");
    } else {
        printf("Você é menor de idade.\n");

        struct tm eighteenth = now_tm;
        eighteenth.tm_year = birth_year + 18 - 1900;
        eighteenth.tm_mon = birth_month - 1;
        eighteenth.tm_mday = birth_day;
        eighteenth.tm_hour = 0;
        eighteenth.tm_min = 0;
        eighteenth.tm_sec = 0;
        time_t eighteenth_time = mktime(&eighteenth);

        double diff_days = difftime(eighteenth_time, now_time) / (60.0 * 60.0 * 24.0);
        int days_until = (int)(diff_days + 0.5);

        if (days_until == 0) {
            printf("Você faz 18 anos hoje.\n");
        } else if (days_until == 1) {
            printf("Você é maior de idade amanhã.\n");
        } else if (days_until == 2) {
            printf("Você é maior de idade em dois dias.\n");
        } else if (days_until == 3) {
            printf("Você é maior de idade em três dias.\n");
        }
    }

    return 0;
}

