#include "rentalmotor.h"

int selectMenu(){
    cout << "=========================== Menu =============================" << endl;
    cout << "1. Menambah n Penyewa dan m Motor yang disewa" << endl;
    cout << "2. Menampilkan Semua Data" << endl;
    cout << "3. Menampilkan Semua Penyewa" << endl;
    cout << "4. Menampilkan Semua Motor yang Disewa Seorang Penyewa" << endl;
    cout << "5. Menghapus Penyewa" << endl;
    cout << "6. Menghapus Motor yang Disewa Seorang Penyewa" << endl;
    cout << "7. Mencari Penyewa" << endl;
    cout << "8. Mencari Motor yang Disewa Seorang Penyewa" << endl;
    cout << "9. Menghitung Motor yang Disewa Setiap Penyewa" << endl;
    cout << "10.Menghitung tarif sewa yang harus dibayar setiap penyewa" << endl;
    cout << "0. Exit" << endl;
    cout << "=============================================================" << endl;
    cout << "Pilihan Menu:  ";
    int input;
    cin >> input;
    return input;
}

void create_list(mll &list_penyewa){
    first(list_penyewa) = NULL;
    last(list_penyewa) = NULL;
}

adr_penyewa newElm_penyewa(infotype_penyewa info){
    adr_penyewa p = new elm_penyewa;
    info(p) = info;
    next(p) = NULL;
    prev(p) = NULL;
    nextMotor(p) = NULL;
    return p;
}

adr_motor newElm_motor(infotype_motor info){
    adr_motor m = new elm_motor;
    info(m) = info;
    next(m) = NULL;
    prev(m) = NULL;
    return m;
}

void insertLast_penyewa(mll &list_penyewa, adr_penyewa p){
    //insert last parent
    if (first(list_penyewa) == NULL && last(list_penyewa) == NULL){
        first(list_penyewa) = p;
        last(list_penyewa) = p;
    }else{
        prev(p) = last(list_penyewa);
        next(last(list_penyewa)) = p;
        last(list_penyewa) = p;
    }
}

void deleteLast_penyewa(mll &list_penyewa){
    //delete last parent
    if (first(list_penyewa) != NULL && last(list_penyewa) != NULL){
        last(list_penyewa) = prev(last(list_penyewa));
        next(last(list_penyewa)) = NULL;
    }
}

void deleteFirst_penyewa(mll &list_penyewa){
    //delete first parent
    if (first(list_penyewa) != NULL && last(list_penyewa) != NULL){
        first(list_penyewa) = next(first(list_penyewa));
        prev(first(list_penyewa)) = NULL;
    }
}

void deleteAfter_penyewa(mll &list_penyewa, adr_penyewa prec){
    //delete after parent
    adr_penyewa p = next(prec);
    next(prec) = next(p);
    prev(next(p)) = prec;
    prev(p) = NULL;
    next(p) = NULL;
}

void delete_penyewa(mll &list_penyewa, string ktp_penyewa){
    //delete parent (using all delete methods)
    adr_penyewa p = first(list_penyewa);
    if (next(first(list_penyewa)) == NULL){ //delete jika hanya ada 1 elemen
        first(list_penyewa) = NULL;
        last(list_penyewa) = NULL;
    }else{ //delete ketika lebih dari 1 elemen
        while (p != NULL){
            if (info(p).ktp == ktp_penyewa){
                if (p == first(list_penyewa)){
                    deleteFirst_penyewa(list_penyewa);
                }else if (p == last(list_penyewa)){
                    deleteLast_penyewa(list_penyewa);
                }else{
                    adr_penyewa prec = prev(p);
                    deleteAfter_penyewa(list_penyewa, prec);
                }
            }
            p = next(p);
        }
    }

}

void insertLast_motor(mll &list_penyewa, adr_penyewa p, adr_motor m){
    //insert last child of parent
    adr_penyewa q = first(list_penyewa);
    while (q != NULL){
        if (q == p){
            if (nextMotor(p) == NULL){
                nextMotor(p) = m;
            }else{
                adr_motor n = nextMotor(p);
                while (next(n) != NULL){
                    n = next(n);
                }
                next(n) = m;
                prev(m) = n;
            }
        }
        q = next(q);
    }
}

void deleteFirst_motor(mll &list_penyewa, adr_penyewa p){
    //delete child of parent
    adr_motor n;
    if (nextMotor(p) != NULL){
        n = nextMotor(p);
        nextMotor(p) = next(n);
        next(n) = NULL;
        prev(n) = NULL;
    }
}

void deleteLast_motor(mll &list_penyewa, adr_penyewa p){
    //delete child of parent
    adr_motor n, prec;
    if (nextMotor(p) != NULL){
        n = nextMotor(p);
        while (next(n) != NULL){
            prec = n;
            n = next(n);
        }
        next(prec) = NULL;
        prev(n) = NULL;
    }
}

void deleteAfter_motor(mll &list_penyewa, adr_penyewa p, adr_motor prec){
    //delete child of parent
    adr_motor n;
    n = next(prec);
    next(prec) = next(n);
    prev(next(n)) = prec;
}

void delete_motor(mll &list_penyewa, string ktp_penyewa, string plat_motor){
    adr_penyewa p = first(list_penyewa);
    while (p != NULL){
        if (info(p).ktp == ktp_penyewa){
            if (next(nextMotor(p)) == NULL){ //delete jika hanya ada 1 elemen
                nextMotor(p) = NULL;
            }else{
                adr_motor m = nextMotor(p);
                while (m != NULL){
                    if (info(m).plat == plat_motor){
                        if (m == nextMotor(p)){
                            deleteFirst_motor(list_penyewa, p);
                        }else if (next(m) == NULL){
                            deleteLast_motor(list_penyewa, p);
                        }else{
                            adr_motor prec = prev(m);
                            deleteAfter_motor(list_penyewa, p, prec);
                        }
                    }
                    m = next(m);
                }
            }
        }
        p = next(p);
    }
}

void showData_penyewa(mll list_penyewa){
    //show parent
    adr_penyewa p = first(list_penyewa);
    int i = 1;
    if (first(list_penyewa) == NULL){
        cout << "Tidak ada penyewa saat ini" << endl;
    }else{
        while (p != NULL){
            cout << "=== Penyewa " << i << " ===" << endl;
            cout << "Nama   : " << info(p).namaPenyewa << " | ";
            cout << "No.KTP : " << info(p).ktp << " | ";
            cout << "No.Telp: " << info(p).noTelp << endl;
            cout << endl;
            i++;
            p = next(p);
        }
    }
}

void showData_motor(mll list_penyewa, string ktp_penyewa){
    //show child of parent
    adr_penyewa p = first(list_penyewa);
    adr_motor m;
    int i = 1;
    if (first(list_penyewa) == NULL){
        cout << "Tidak ada penyewa saat ini" << endl;
    }else{
        while (p != NULL){
            if (info(p).ktp == ktp_penyewa){
                m = nextMotor(p);
                cout << "Atas nama " << info(p).namaPenyewa << " | ";
                cout << "No.Telp  : " << info(p).noTelp << endl;
                while (m != NULL){
                    cout << "   --- Motor " << i << " ---" << endl;
                    cout << "   Model : " << info(m).modelMotor << " | ";
                    cout << "Plat  : " << info(m).plat << " | ";
                    cout << "Tarif Sewa : " << info(m).tarifSewa << endl;
                    i++;
                    m = next(m);
                }
            }
            p = next(p);
        }
    }

}

void showAllData(mll list_penyewa){
    //show all parent with their child
    adr_penyewa p = first(list_penyewa);
    adr_motor m;
    int i = 1;
    int j;
    if (first(list_penyewa) == NULL){
        cout << "Tidak ada penyewa saat ini" << endl;
    }else{
        while (p != NULL){
            cout << "=== Penyewa " << i << " ===" << endl;
            cout << "Nama   : " << info(p).namaPenyewa << " | ";
            cout << "No.KTP : " << info(p).ktp << " | ";
            cout << "No.Telp: " << info(p).noTelp << endl;
            m = nextMotor(p);
            j = 1;
            while (m != NULL){
                cout << "   --- Motor " << j << " ---" << endl;
                cout << "   Model : " << info(m).modelMotor << " | ";
                cout << "Plat  : " << info(m).plat << " | ";
                cout << "Tarif Sewa : " << info(m).tarifSewa << endl;
                j++;
                m = next(m);
            }
            cout << endl;
            i++;
            p = next(p);
        }
    }
}


adr_penyewa search_penyewa(mll list_penyewa, string ktp_penyewa){
    //search parent
    adr_penyewa p = first(list_penyewa);
    while (p != NULL){
        if (info(p).ktp == ktp_penyewa){
            return p;
        }
        p = next(p);
    }
    return p;
}

adr_motor search_motor(mll list_penyewa, string ktp_penyewa, string plat_motor){
    //search child of parent
    adr_penyewa p = first(list_penyewa);
    while (p != NULL){
        if (info(p).ktp == ktp_penyewa){
            adr_motor m = nextMotor(p);
            while (m != NULL){
                if (info(m).plat == plat_motor){
                    return m;
                }
                m = next(m);
            }
            return m;
        }
        p = next(p);
    }
    return NULL;
}

void count_motor(mll list_penyewa){
    adr_penyewa p = first(list_penyewa);
    adr_motor m;
    int jumlah_motor;
    int i = 1;
    if (first(list_penyewa) == NULL){
        cout << "Tidak ada penyewa saat ini" << endl;
    }else{
        while (p != NULL){
            cout << "=== Penyewa " << i << " ===" << endl;
            cout << "Nama   : " << info(p).namaPenyewa << " | ";
            cout << "No.KTP : " << info(p).ktp << " | ";
            cout << "No.Telp: " << info(p).noTelp << endl;
            m = nextMotor(p);
            jumlah_motor = 0;
            while (m != NULL){
                jumlah_motor++;
                m = next(m);
            }
            cout << "Jumlah motor  : ";
            cout << jumlah_motor << " motor" << endl;
            p = next(p);
            i++;
        }
    }
}

void sum_tarifSewa(mll list_penyewa){
    adr_penyewa p = first(list_penyewa);
    adr_motor m;
    int tarifSewa;
    int i = 1;
    if (first(list_penyewa) == NULL){
        cout << "Tidak ada penyewa saat ini" << endl;
    }else{
        while (p != NULL){
            cout << "=== Penyewa " << i << " ===" << endl;
            cout << "Nama   : " << info(p).namaPenyewa << endl;
            cout << "No.KTP : " << info(p).ktp << endl;
            cout << "No.Telp: " << info(p).noTelp << endl;
            tarifSewa = 0;
            m = nextMotor(p);
            while (m!= NULL){
                tarifSewa += info(m).tarifSewa;
                m = next(m);
            }
            cout << "Total Tarif Sewa : Rp." << tarifSewa << endl;
            p = next(p);
            i++;
        }
    }
}

