#include <stdio.h>
#include <math.h>
#include <windows.h>
int fact(int x)
{
    if (x == 0)
        return 1;
    else
        return x * fact(x - 1);
}

int main()
{
    system("cls");
    int n, r;
    float p, q;
    int ch;
    double s;
    double a;

    printf("Enter number of occurrence of events(n) \n");
    scanf(" %d", &n);
    printf("Enter the probability of success(p) \n");
    scanf("%f", &p);

    if (p >= 0 && p <= 1)
    {
        printf("Enter the number of times success is occurring(r)[r cannot be decimal] \n");
        scanf("%d", &r);

        if (r >= 0 && r <= n)
        {
            printf("Enter your operation from the following \n 1. At least r success \t 2. At most r success \t 3. r success \t 4. not r \n");
            scanf("%d ", &ch);
            q = 1.0 - p;

            switch (ch)
            {
            case 1:
                s = 0;
                printf("The event is happening %d times out of which the probability of success of the event is %f then find the probability to get at least %d successes? \n", (int)n, p, (int)r);
                for (int i = r; i <= n; i++)
                {
                    a = (fact(n) / (fact(n - i) * fact(i))) * pow(p, i) * pow(q, (n - i));
                    s = s + a;
                }
                printf("\n----------------ANSWER-----------------\n");
                printf("The required probability is %f", s);
                break;

            case 2:
                s = 0;
                printf("The event is happening %d times out of which the probability of success of the event is %f then find the probability to get at most %d successes?", (int)n, p, (int)r);
                for (int i = 0; i <= r; i++)
                {
                    a = (fact(n) / (fact(n - i) * fact(i))) * pow(p, i) * pow(q, (n - i));
                    s = s + a;
                }
                printf("\n ----------------ANSWER-----------------\n");
                printf("The required probability is %f", s);
                break;

            case 3:
                printf("The event is happening %d times out of which the probability of success of the event is %f then find the probability to get %d successes?", (int)n, p, (int)r);
                a = (fact(n) / (fact(n - r) * fact(r))) * pow(p, r) * pow(q, (n - r));
                printf("\n ----------------ANSWER-----------------\n");
                printf("The required probability is %f", a);
                break;

            case 4:
                printf("The event is happening %d times out of which the probability of success of the event is %f then find the probability to not get %d successes?", (int)n, p, (int)r);
                a = 1.0 - (fact(n) / (fact(n - r) * fact(r))) * pow(p, r) * pow(q, (n - r));
                printf("\n ----------------ANSWER-----------------\n");
                printf("The required probability is %f", a);
                break;

            default:
                printf("Wrong choice");
            }
        }

        else
            printf("Value of r lies between 0 and n");
    }

    else
        printf("Probability lies between 0 and 1");

    return 0;
}