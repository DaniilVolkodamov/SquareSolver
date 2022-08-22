#include <stdio.h>
#include <math.h>

int main()
{
    float koef_a, koef_b, koef_c;
    float discr;
    float ans1, ans2;
    printf("Калькулятор для решения квадратного уравнения.\n");
    printf("Введите первый коэффициент:\n");
    scanf("%f", &koef_a);
    printf("Введите второй коэффициент:\n");
    scanf("%f", &koef_b);
    printf("Введите третий коэффициент:\n");
    scanf("%f", &koef_c);
    discr = koef_b * koef_b - 4 * koef_a * koef_c;
    if (koef_a == 0)
            printf("Ваше уравнение не является квадратным.\n");
    else if (discr < 0)
        printf("Решений нет\n");
    else if (discr == 0)
    {
        ans1 = -koef_b / (2 * koef_a);
        printf("1 решение: %f\n", ans1);
    }
    else
    {
        discr = sqrt(discr);
        ans1 = (-koef_b + discr) / (2 * koef_a);
        ans2 = (-koef_b - discr) / (2 * koef_a);
        printf("2 решения: %f, %f\n", ans1, ans2);
    }
    return 0;
}