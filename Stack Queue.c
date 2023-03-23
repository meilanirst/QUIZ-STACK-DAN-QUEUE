#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#define MAX 255
#define MAX_STACK 5
#define MAX_QUEUE 5


menuutama (char judul[100], char menu[10][100], int jm, int pil)
{
    printf("\n\n");
    printf("  ===================================\n");
    printf("%s\n", judul);
    printf("  ===================================\n");
    int i;
    for (i = 1; i <= jm; i++)
    {
        if (pil == i)
        {
            printf("   ==> \t");
        }
        else
        {
            printf("\t");
        }
        printf("%d. %s \n", i, menu[i - 1]);
    }
    printf("  ===================================\n");
}
int main()
{
    system("color F8");
    int pil = 1;
    int pil1 = 1;
    int pil2 = 1;
    char namamenu[3][100] = {"Stack String", "Queue Integer", "Exit Program"};
    int jumlahmenu = 3;
    char key;
    while (1)
    {
        system("cls");
        menuutama("    TUGAS QUIZ STACK DAN QUEUE    ", namamenu, jumlahmenu, pil);
        key = getch();
        if(key == 72)
        {
            if (pil > 1)
            {
                pil--;
            }
        }
        else if (key == 80)
        {
            if (pil < 3)
            {
                pil++;
            }
        }
        else if (key == 13)
        {
            if (pil == 1)
            {
                stack1();
            }
            else if (pil == 2)
            {
                 Queue1();
            }
            else
            {
                Exit1();
                getch();
            }
        }
    }

    return 0;
}

struct
{
    int top;
    char data[50][50];
}tumpuk;

void inisialisasi()
{
    tumpuk.top = -1;
}

int IsFull()
{
    if(tumpuk.top == MAX_STACK-1) return 1;
    else return 0;
}

int IsEmpty()
{
    if(tumpuk.top == -1) return 1;
    else return 0;
}

void Push(char d[50])
{
    tumpuk.top++;
    strcpy(tumpuk.data[tumpuk.top],d);
}

void Pop()
{
    printf("Data yang terambil = %s\n",tumpuk.data[tumpuk.top]);
    tumpuk.top--;
}

void Clear()
{
    tumpuk.top=-1;
}

void TampilStack()
{
    for(int i=tumpuk.top;i>=0;i--)
    {
        printf("Data ke-%d: %s\n",i, tumpuk.data[i]);
    }
}

int stack1()
{
   int pilihan;
   inisialisasi();
   char datainput[50];
   do{
        system ("cls");
        fflush (stdin);
          printf("1. Push Stack\n");
          printf("2. Pop Stack\n");
          printf("3. Print Stack\n");
          printf("4. Delete Stack\n");
          printf("5. Return to Menu Utama\n");
          printf("Pilihan : ");
          scanf("%d",&pilihan);
          fflush (stdin);

          switch(pilihan)
          {
          case 1: if(IsFull() != 1)
                    {
                        system ("cls");
                        printf("Data yang ingin diinput = ");
                        scanf(" %[^\n]",datainput);
                        Push(datainput);
                        printf ("\nPress any key to continue .  .  .");
                        getch ();
                    }
                   else
                   {
                       printf("Stack penuh\n");
                       printf ("\nPress any key to continue .  .  .");
                       getch ();
                   }
           break;
           case 2: system ("cls");
                   if(IsEmpty() != 1)
                        Pop();
                   else
                        printf("Stack masih kosong\n");
                        printf ("\nPress any key to continue .  .  .");
                   getch ();
           break;
           case 3: system ("cls");
                   if(IsEmpty() != 1)
                        TampilStack();
                   else
                        printf("\nStack masih kosong\n");
                        printf ("\nPress any key to continue .  .  .");
                    getch ();
           break;
           case 4:  system ("cls");
                    Clear();
                        printf("\Data sudah dihapus\n");
                        printf ("\nPress any key to continue .  .  .");
                        getch ();
           break;
           case 5: main (); break;
           }
        }
        while(pilihan != 5);

}

struct
{
    int data[MAX_QUEUE];
    int head;
    int tail;
} antrian;

void Create()
{
    antrian.head=antrian.tail=-1;
}

int isEmpty()
{
    if(antrian.tail==-1) return 1;
    else return 0;
}

int isFull()
{
    if(antrian.tail==MAX_QUEUE-1) return 1;
    else return 0;
}

void Enqueue(int data)
{
    if(isEmpty()==1)
    {
        antrian.head=antrian.tail=0;
        antrian.data[antrian.tail]=data;
        printf("%d masuk!",antrian.data[antrian.tail]);
        printf ("\nPress any key to continue .  .  .");
    }
    else if (isFull()==0)
    {
        antrian.tail++;
        antrian.data[antrian.tail]=data;
        printf("%d masuk!",antrian.data[antrian.tail]);
        printf ("\nPress any key to continue .  .  .");
    }
 }

int Dequeue()
{
    int i;
    int e = antrian.data[antrian.head];
    for(i=antrian.head;i<=antrian.tail-1;i++)
    {
        antrian.data[i] = antrian.data[i+1];
    }
    antrian.tail--;
    printf("Data yang terambil = %d\n",antrian.data[i]);
    return e;
}

void clear()
{
    antrian.head=antrian.tail=-1;
    printf("Data sudah dikosongkan");
}

void Tampil()
{
    if(isEmpty()==0)
    {
        for(int i=antrian.head;i<=antrian.tail;i++)
        {
            printf("Data ke-%d = %d\n",i,antrian.data[i]);
        }
    }
    else
    printf("data kosong!\n");
}

int Queue1()
{
   int pilihan;
   Create();
   int datainput;
   do{
        system ("cls");
        fflush (stdin);
          printf("1. Enqueue Int\n");
          printf("2. Dequeue Int\n");
          printf("3. Print Queue\n");
          printf("4. Delete Queue\n");
          printf("5. Return to Menu Utama\n");
          printf("Pilihan : ");
          scanf("%d",&pilihan);
          fflush (stdin);

          switch(pilihan)
          {
          case 1: if(isFull() != 1)
                    {
                        system ("cls");
                        printf("Data = ");
                        scanf("%d",&datainput);
                        Enqueue(datainput);
                        getch ();
                    }
                   else
                   {
                        printf("Sudah penuh\n");
                        printf ("Press any key to continue .  .  .");
                        getch ();
                   }

           break;
           case 2:
                   system ("cls");
                   if(isEmpty() != 1)
                        Dequeue();
                   else
                        printf("\nData masih kosong\n");
                        printf ("\nPress any key to continue .  .  .");
                   getch ();
           break;
           case 3: system ("cls");
                   if(isEmpty() != 1)
                        Tampil();
                   else
                        printf("Tidak ada data dalam antrian\n");
                        printf ("\nPress any key to continue .  .  .");
                    getch ();
           break;
           case 4:  system ("cls");
                    clear();
                    printf ("\nPress any key to continue .  .  .");
                    getch ();
           break;
           case 5: main(); break;
           }
        }
        while(pilihan != 5);
}

int Exit1()
{
    system ("cls");
    printf ("TERIMAKASIH ~ GOODLUCK\n\n");
    exit (0);
}
