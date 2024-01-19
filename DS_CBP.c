#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct mynode
{
    char name[50];
    char gen[6];
    int age;
    struct mynode *link;
} Node;

Node *start = NULL;
char source[20], des[20], train[40];
char station[40], cla[40];
int time1, time2, a[55];

int seat(int p)
{
    int i;
    printf("\t-:SEAT MATRIX:-\n");
    printf("\t(U)\t(M)\t(L)\t(L)\t(U)\n\n");
    printf("\t01\t02\t03\t04\t05\n\n");
    printf("\t06\t07\t08\t09\t10\n\n");
    printf("\t11\t12\t13\t14\t15\n\n");
    printf("\t16\t17\t18\t19\t20\n\n");
    printf("\t21\t22\t23\t24\t25\n\n");
    printf("\t26\t27\t28\t29\t30\n\n");
    printf("\t31\t32\t33\t34\t35\n\n");
    printf("\t36\t37\t38\t39\t40\n\n");
    printf("\t41\t42\t43\t44\t45\n\n");
    printf("\t46\t47\t48\t49\t50\n\n");
    printf("\t51\t52\t53\t54\t55\n\n");
    printf("\t56\t57\t58\t59\t60\n\n");

    printf("Enter Seat Numbers: \n");
    for (i = 0; i < p; i++)
        scanf("%d", &a[i]);
}

void add_node(char new_name[20], char gender[6], int b)
{
    /*  new_name - New name that needs to be booked
        gender   - gender
        b        - age  */
    Node *newptr = NULL, *ptr;
    newptr = (Node *)malloc(sizeof(Node));
    strcpy(newptr->name, new_name);
    strcpy(newptr->gen, gender);
    newptr->age = b;
    newptr->link = NULL;
    if (start == NULL)
        start = newptr;
    else
    {
        ptr = start;
        while (ptr->link != NULL)
            ptr = ptr->link;
        ptr->link = newptr;
    }
}

void details(int k)
{
    /*  k - No. of Passengers  
        i - for iteration
        a - age*/
    int i, a;
    char name[20], gen[6];
    for (i = 1; i <= k; i++)
    {
        printf("\nEnter Details of Passenger %d\n", i);
        printf("Name : ");
        fflush(stdin);
        gets(name);
        printf("Gender : ");
        fflush(stdin);
        gets(gen);
        printf("Age : ");
        fflush(stdin);
        scanf("%d", &a);
        add_node(name, gen, a);
    }
}

int cal(int y1, int y2, int h)
{
    /*y1 - Ac coach price
      y2 - Sleeper Class price
      h  - No. of passengers
      b  - bill without GST
      c  - bill with GST
      i  - for iteration
      n  - Class in AC Coach*/
    int b, c, i, n;
    printf("\nEnter Your Choice......\n");
    printf("1. A.C Coach....\n");
    printf("2. Sleeper Coach.......\n");
    printf("Choosen Coach : ");
    scanf("%d", &i);
    switch (i)
    {
        case 1:
        {
            printf("\nEnter Your Choice....\n");
            printf("1. 3A Class....\n");
            printf("2. 2A Class....\n");
            printf("3. 1st Class A.C.....\n");
            printf("Choosen Class : ");
            scanf("%d", &n);
            switch (n)
            {
                case 1:
                {
                    strcpy(cla, "3A Class");
                    b = y1 * h;
                    c = b + (b * 0.18);
                }
                break;
                case 2:
                {
                    strcpy(cla, "2A Class");
                    b = (y1 + 1000) * h;
                    c = b + (b * 0.18);
                }
                break;
                case 3:
                {
                    strcpy(cla, "1st Class A.C.");
                    b = (y1 + 3000) * h;
                    c = b + (b * 0.18);
                }
                break;
                default:
                {
                    printf("\t\tEnter Right Choice......\n");
                }
            }
        }
        break;
        case 2:
        {
            strcpy(cla, "Sleeper Class");
            b = y2 * h;
            c = b + (b * 0.18);
        }
        break;
        default:
        {
            printf("\t\tEnter Right Choice......\n");
        }
    }
    return c;
}

void bill(int y, int j)
{
    /*y - Total Bill
      j - Total No. of Passengers*/
    int i;
    Node *ptr = start;
    for (i = 1; i <= j; i++)
    {
        printf("\nDetails of Passenger %d\n", i);
        printf("Name: ");
        puts(ptr->name);
        printf("Gender: ");
        puts(ptr->gen);
        printf("Age: %d\n\n", ptr->age);
        ptr = ptr->link;
    }
    printf("Source Place : ");
    puts(source);
    printf("Destination Place : ");
    puts(des);
    printf("The Boarding Station : ");
    puts(station);
    printf("Train Is : ");
    puts(train);
    printf("Allocated Class : ");
    puts(cla);
    printf("Boarding Time : %d:%d0\n", time1, time2);
    printf("Total Bill Amount : %d\n", y);
    printf("Allocated Seats Are : ");
    for (i = 0; i < j; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\nThank You......\n");
} 

int main()
{
    int i, j, a1, a2, b, c;
    /*
        i for Train No
        j for No.of Seats
        a1 is the cost of A.C Coach
        a2 is the cost of Sleeper Coach
    */
    int x = 0, d;
    printf("Enter Number Of Passengers : ");
    fflush(stdin);
    scanf("%d", &j);
    details(j);
    printf("\nEnter The Source Place : ");
    fflush(stdin);
    gets(source);
    printf("Enter The Destination Place : ");
    gets(des);
    printf("\nThe Following Trains are Available.....\n");
    printf("1. Rajdhani Express.........10:00 a.m........Sealdah Station\n");

    printf("2. Satabdi Express..........05:00 p.m........Howrah Station\n");

    printf("3. Humsafar Express..........11:00 p.m........Kolkata Chitpur Station\n");

    printf("4. Garib-Rath Express.........05:00 p.m........Sealdah Station\n");

    printf("5. Duronto Express............07:00 a.m.........Santraganchi Station\n");

    printf("\nEnter Train No : ");
    scanf("%d", &i);
    do
    {
        switch (i)
        {
            case 1:
            {
                strcpy(train, "Rajdhani Express");
                strcpy(station, "Sealdah Station");
                time1 = 10;
                time2 = 00;
                a1 = 2099;
                a2 = 1560;
                d = cal(a1, a2, j);
                printf("Total Bill Amount : %d\n", d);
            }
            break;
            case 2:
            {
                strcpy(train, "Satabdi Express");
                strcpy(station, "Howrah Station");
                time1 = 05;
                time2 = 00;
                a1 = 1801;
                a2 = 981;
                d = cal(a1, a2, j);
                printf("Total Bill Amount : %d\n", d);
            }
            break;
            case 3:
            {
                strcpy(train, "Humsafar Express");
                strcpy(station, "Kolkata Chitpur Station");
                time1 = 11;
                time2 = 00;
                a1 = 2199;
                a2 = 1780;
                d = cal(a1, a2, j);
                printf("Total Bill Amount: %d\n", d);
            }
            break;
            case 4:
            {
                strcpy(train, "Garib-Rath Express");
                strcpy(station, "Sealdah Station");
                time1 = 05;
                time2 = 00;
                a1 = 1759;
                a2 = 1200;
                d = cal(a1, a2, j);
                printf("Total Bill Amount: %d\n", d);
            }
            break;
            case 5:
            {
                strcpy(train, "Duronto Express");
                strcpy(station, "Santraganchi Station");
                time1 = 07;
                time2 = 00;
                a1 = 2205;
                a2 = 1905;
                d = cal(a1, a2, j);
                printf("Total Bill Amount: %d\n", d);
            }
            break;
            default:
                printf("Enter Correct choice.....\n");
                x=1;
                break;
        }
    } while (x);
    printf("\nNow Book Your Seats......\n\n");
    seat(j);
    bill(d, j);
    return 0;
}
