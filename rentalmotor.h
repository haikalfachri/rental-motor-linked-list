#ifndef RENTALMOTOR_H_INCLUDED
#define RENTALMOTOR_H_INCLUDED

#include <string>
#include <iostream>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nextMotor(P) (P)->nextMotor
#define first(S) ((S).first)
#define last(S) ((S).last)

struct penyewa{
    string ktp;
    string namaPenyewa;
    string noTelp;
};

struct motor{
    string plat;
    string modelMotor;
    int tarifSewa;
};

typedef penyewa infotype_penyewa;
typedef motor infotype_motor;
typedef struct elm_penyewa *adr_penyewa;
typedef struct elm_motor *adr_motor;

struct elm_penyewa{
    infotype_penyewa info;
    adr_penyewa next;
    adr_penyewa prev;
    adr_motor nextMotor;
};

struct elm_motor{
    infotype_motor info;
    adr_motor next;
    adr_motor prev;
};

struct mll{
    adr_penyewa first;
    adr_penyewa last;
};

int selectMenu(); //menampilkan menu dan memilih menunya

void create_list(mll &list_penyewa); //create mll(membuat pointer first dan last menjadi NULL
adr_penyewa newElm_penyewa(infotype_penyewa info); //allocate memory of elemen parent
adr_motor newElm_motor(infotype_motor info); //allocate memory of elemen child

void insertLast_penyewa(mll &list_penyewa, adr_penyewa p); //insert last parent

void deleteLast_penyewa(mll &list_penyewa); //delete last parent
void deleteFirst_penyewa(mll &list_penyewa); //delete first parent
void deleteAfter_penyewa(mll &list_penyewa, adr_penyewa prec); //delete after parent
void delete_penyewa(mll &list_penyewa, string ktp_penyewa); //all delete parent methods

void insertLast_motor(mll &list_penyewa, adr_penyewa p, adr_motor m); //insert last child of parent

void deleteFirst_motor(mll &list_penyewa, adr_penyewa p); //delete child first of parent
void deleteLast_motor(mll &list_penyewa, adr_penyewa p); //delete child last of parent
void deleteAfter_motor(mll &list_penyewa, adr_penyewa p, adr_motor prec); //delete after child of parent
void delete_motor(mll &list_penyewa, string ktp_penyewa, string plat_motor); //all delete child method

void showData_penyewa(mll list_penyewa); //show parent
void showData_motor(mll list_penyewa, string ktp_penyewa); //show child of parent
void showAllData(mll list_penyewa); //show all data parent with their child

adr_penyewa search_penyewa(mll list_penyewa, string ktp_penyewa); //fond parent
adr_motor search_motor(mll list_penyewa, string ktp_penyewa, string plat_motor); //find child of parent

void count_motor(mll list_penyewa);//count how many child each parent has
void sum_tarifSewa(mll list_penyewa); //menjumlahkan tarif sewa motor yang disewa penyewa

#endif // RENTALMOTOR_H_INCLUDED
