#include <iostream.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>

int pil,x;
void pilih();
void buat_baru();
void tambah_belakang();
void tambah_depan();
void hapus_belakang();
void hapus_depan();
void tampil();

struct simpul
{
    int INFO;
    struct simpul *LINK;
} *P, *FIRST=NULL, *LAST=NULL,*hapus,*bantu;

void clrscr()
{
    system("cls");
}

int main()
{
    do
    {
        clrscr();
        cout<<"MENU SINGLE LINKEDLIST"<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan"<<endl;
        cout<<"6. Selesai"<<endl;
        cout<<"Pilihan Anda : ";
        cin>>pil;
        pilih();
    } while(pil!=6);
    return 0;
}

void pilih()
{
    if(pil==1)
        tambah_depan();
    else if(pil==2)
        tambah_belakang();
    else if(pil==3)
        hapus_depan();
     else if(pil==4)
        hapus_belakang();
      else if(pil==5)
        tampil();
    else
        cout<<"selesai";
}

void buat_baru()
{
    P=(simpul*)malloc(sizeof(struct simpul));
    cout<<"input nilai   : ";cin>>x;
    P->INFO=x;
    P->LINK=NULL;
}

void tambah_belakang()
{
    buat_baru();
    if(FIRST==NULL)
    {
        FIRST=P;
    }
    else
    {
        LAST->LINK=P;
    }
    LAST=P;
    LAST->LINK=NULL;
    cout<<endl<<endl;
    tampil();
}

void tambah_depan()
{
    buat_baru();
    if(FIRST!=NULL)
    {
        P->LINK=FIRST;
        FIRST=P;
    }
    else
    {
        FIRST=P;
        LAST=P;
        LAST->LINK=NULL;
        printf("Linked list belum ada");
    }
    cout<<endl<<endl;
    tampil();
}

void hapus_depan()
{
    if (FIRST==NULL)
        cout<<"Kosong";
    else
    {
        hapus=FIRST;
        FIRST=FIRST->LINK;
        free(hapus);
    }
   cout<<endl<<endl;
    tampil();
}

void hapus_belakang()
{
    if (FIRST==NULL)
        cout<<"Kosong";
    else if(FIRST==LAST)
    {
         hapus=FIRST;
         FIRST=FIRST->LINK;
         free(hapus);
    }
    else
    {
        hapus=FIRST;
        while(hapus->LINK!=LAST)
             hapus=hapus->LINK;
        LAST=hapus;
        hapus=LAST->LINK;
        LAST->LINK=NULL;
        free(hapus);
    }
    cout<<endl<<endl;
    tampil();
}

void tampil()
{
     if (FIRST==NULL)
          cout<<"Kosong";
     else
     {
         bantu=FIRST;
         while(bantu!=NULL)
         {
            cout<<"  "<<bantu->INFO;
            bantu=bantu->LINK;
         }
     }
     getch();
}