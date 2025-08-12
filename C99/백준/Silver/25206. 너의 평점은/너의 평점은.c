#include <stdio.h>
#include <string.h>

int main() {
    char name[51];
    char grade[3];
    double credit;
    double sumCredit = 0.0;
    double res = 0.0;
    for (int i = 0; i < 20; i++) {
        scanf("%s %lf %s", name, &credit, grade);
        if (strcmp(grade, "P") == 0) continue;
        sumCredit += credit;
        double point = 0.0;
        if (!strcmp(grade, "A+")) point = 4.5;
        else if (!strcmp(grade, "A0")) point = 4.0;
        else if (!strcmp(grade, "B+")) point = 3.5;
        else if (!strcmp(grade, "B0")) point = 3.0;
        else if (!strcmp(grade, "C+")) point = 2.5;
        else if (!strcmp(grade, "C0")) point = 2.0;
        else if (!strcmp(grade, "D+")) point = 1.5;
        else if (!strcmp(grade, "D0")) point = 1.0;
        else if (!strcmp(grade, "F")) point = 0.0;
        res += credit * point;
    }
    printf("%.6lf\n", res / sumCredit);
    return 0;
}
