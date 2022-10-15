#include "rentalmotor.h"

int main(){
    mll list_penyewa;
    adr_penyewa p;
    adr_motor m;
    infotype_penyewa info_penyewa;
    infotype_motor info_motor;
    int banyak_penyewa, banyak_motor, pilihan;
    string ktp_penyewa, plat_motor;

    create_list(list_penyewa);
    pilihan = selectMenu();
    while (pilihan != 0){
        switch(pilihan){
            case 1:
                cout << "Masukkan banyak penyewa    : ";
                cin >> banyak_penyewa;
                for (int i=1;i<=banyak_penyewa;i++){
                    cout << "=== Penyewa " << i << " ===" << endl;
                    cout << "Masukkan nama penyewa" << "     : ";
                    cin >> info_penyewa.namaPenyewa;
                    cout << "Masukkan No.KTP penyewa" << "   : ";
                    cin >> info_penyewa.ktp;
                    cout << "Masukkan No.Telp penyewa" << "  : ";
                    cin >> info_penyewa.noTelp;
                    p = newElm_penyewa(info_penyewa);
                    insertLast_penyewa(list_penyewa, p);
                    cout << "Masukkan banyak motor disewa    : ";
                    cin >> banyak_motor;
                    for (int j=1;j<=banyak_motor;j++){
                        cout << "    --- Motor " << j << " ---" << endl;
                        cout << "    Masukkan model motor" << "      : ";
                        cin >> info_motor.modelMotor;
                        cout << "    Masukkan plat motor" << "       : ";
                        cin >> info_motor.plat;
                        cout << "    Masukkan tarif sewa motor" << " : ";
                        cin >> info_motor.tarifSewa;
                        m = newElm_motor(info_motor);
                        insertLast_motor(list_penyewa, p, m);
                    }
                    cout << endl;
                }
                break;
            case 2:
                showAllData(list_penyewa);
                break;
            case 3:
                showData_penyewa(list_penyewa);
                break;
            case 4:
                showData_penyewa(list_penyewa);
                if(first(list_penyewa) != NULL){
                    cout << "Masukkan ktp penyewa  : ";
                    cin >> ktp_penyewa;
                    showData_motor(list_penyewa, ktp_penyewa);
                }
                break;
            case 5:
                showData_penyewa(list_penyewa);
                if(first(list_penyewa) != NULL){
                    cout << "Masukkan ktp penyewa  : ";
                    cin >> ktp_penyewa;
                    delete_penyewa(list_penyewa, ktp_penyewa);
                }
                break;
            case 6:
                showAllData(list_penyewa);
                if(first(list_penyewa) != NULL){
                    cout << "Masukkan ktp penyewa   : ";
                    cin >> ktp_penyewa;
                    cout << "Masukkan plat motor    : ";
                    cin >> plat_motor;
                    delete_motor(list_penyewa, ktp_penyewa, plat_motor);
                }
                break;
            case 7:
                if(first(list_penyewa) != NULL){
                    showData_penyewa(list_penyewa);
                    cout << "Masukkan ktp penyewa   : ";
                    cin >> ktp_penyewa;
                    p = search_penyewa(list_penyewa, ktp_penyewa);
                    if (p != NULL){
                        cout << "Penyewa ditemukan!" << endl;
                        cout << "Atas nama  : " << info(p).namaPenyewa << " ";
                        cout << "No.KTP     : " << info(p).ktp << " ";
                        cout << "No.Telp    : " << info(p).noTelp << endl;
                    }else{
                        cout << "Penyewa dengan No.KTP " << ktp_penyewa << " tidak ditemukan!" << endl;
                    }
                }else{
                    cout << "Tidak ada penyewa saat ini" << endl;
                }
                break;
            case 8:
                if(first(list_penyewa) != NULL){
                    showAllData(list_penyewa);
                    cout << "Masukkan ktp penyewa   : ";
                    cin >> ktp_penyewa;
                    cout << "Masukkan plat motor: ";
                    cin >> plat_motor;
                    m = search_motor(list_penyewa, ktp_penyewa, plat_motor);
                    if (m != NULL){
                        cout << "Motor ditemukan!" << endl;
                        cout << "Dengan nama motor  : " << info(m).modelMotor;
                    }else{
                        cout << "Penyewa atau Motor tidak ditemukan!" << endl;
                    }
                }else{
                    cout << "Tidak ada penyewa saat ini" << endl;
                }
                break;
            case 9:
                count_motor(list_penyewa);
                break;
            case 10:
                sum_tarifSewa(list_penyewa);
                break;
            }
        cout << endl;
        pilihan = selectMenu();
    }
    return 0;
}
