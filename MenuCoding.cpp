#include "MenuCoding.h"
#include "list_parent_double.h"
#include "list_child_singlecircular.h"

#include <iostream>

using namespace std;

List_parent LPa;
List_child LCh;

address_parent PPP;
address_parent P;
address_child C;

infotype_parent x;
infotype_child y;

//void createAll();

void mainMenu(){ //
    int pil;
    clrscr();
    cout<<"---------- MAIN MENU ----------"<<endl;
    cout<<"1. Registrasi Akun"<<endl;
    cout<<"2. Login"<<endl;
    //cout<<"3. ADMIN"<<endl;
    cout<<"Pilihan: ";
    cin>>pil;
    switch (pil){
    case 1:
        clrscr();
        registUser(); //L1
        break;
    case 2:
        clrscr();
        Login(); //L1,L2
        break;
    /*case 3:
        clrscr();
        //loginAdmin();
        break;
    */
    }

}

void clrscr(){
    system("cls");
}

void registUser(){ //List_parent &L
    //infotype_parent x;
//    List_parent LP;
    cout<<"---------- REGISTER ----------"<<endl;
    cout<<"Nama                 : "; cin>>x.Nama;
    cout<<"Jenis Kelamin        : "; cin>>x.JenisKelamin;
    cout<<"Email                : "; cin>>x.email;
    cout<<"No Handphone         : "; cin>>x.NoHp;
    cout<<"Username             : "; cin>>x.username;
    cout<<"Password             : "; cin>>x.password;
    cout<<"0";
    P = alokasi(x);
    insertFirst(LPa,P);
    mainMenu();
}

void Login() //List_parent &L1, List_child &L2
{
        infotype_parent tmp;

    string uname,pass;
    cout<<"---------- LOGIN ----------"<<endl;
    cout<<"Username             : "; cin>>uname; cin>>tmp.username;
    cout<<"Password             : "; cin>>pass;
    PPP = findElm(LPa,tmp);
    if (uname == "admin"){
        if (pass == "12345"){
            cout<<"WELCOME ADMIN!"<<endl;
            menuAdmin(); //L1,L2
        }
    }
    else
        {
        P = LPa.first;
        while(P!= NULL){
            if (P->info.password == pass && P->info.username == uname){
                tmp.username=info(P).username;
                menuUser(); //L1,L2
            }
            else
            {
                P= P->next;
            }
        }
        }
   /* else
    {


        cout<<"Anda belum terdaftar, silahkan registrasi"<<endl;
    } */
}

void menuUser(){ //List_parent &L1, List_child &L2
    //address_child P;
    //infotype_parent XP;
    //infotype_child x;
    int pil;
    clrscr();
    cout<<"***** MENU *****"<<endl;
    cout<<"1. Pengajuan SIM"<<endl;
    cout<<"2. Lihat Pengajuan SIM"<<endl;
    cout<<"3. Profile"<<endl;
    cout<<"4. Edit Pengajuan SIM"<<endl;
    cout<<"5. LogOut"<<endl;
    //cout<<"5. Log Out"<<endl;
    cout<<"Pilihan  : "<<endl;
    cin>>pil;
    address_parent z;
    switch (pil){
    case 1:
        clrscr();
        //y.no_antrian = rand()%999+1000;
        cout<<"Masukan ID Pengajuan (5 angka)   : ";cin>>y.id_pengajuan;
        cout<<"Tempat, Tanggal Lahir            : ";cin>>y.TTL;
        cout<<"Tinggi                           : ";cin>>y.tinggi;
        cout<<"Pekerjaan                        : ";cin>>y.pekerjaan;
        cout<<"Golongan Darah                   : ";cin>>y.GolDarah;
        cout<<"Jenis Sim                        : ";cin>>y.JenisSim;
        cout<<"Tanggal Tes                      : ";cin>>y.tanggal_tes;
        cout<<"Alamat Rumah                     : ";cin>>y.alamat;
        cout<<"Alamat Samsat                    : ";cin>>y.alamat_samsat;
        y.status_pengajuan="SILAHKAN LAKUKAN TES SIM";
        C = alokasi(y);
        insertFirst(listanak(PPP),C);
        insertFirst(LCh,C);
        menuUser(); //L1,L2
        break;

    case 2:
        clrscr();
        printInfo(listanak(PPP));
        getch();
        break;
        /*cout<<"Nomor Antrian            : "<<x.no_antrian<<endl;
        cout<<"Tempat, Tanggal Lahir    : "<<x.TTL<<endl;
        cout<<"Tinggi                   : "<<x.tinggi<<endl;
        cout<<"Pekerjaan                : "<<x.pekerjaan<<endl;
        cout<<"Golongan Darah           : "<<x.GolDarah<<endl;
        cout<<"Jenis Sim                : "<<x.JenisSim<<endl;
        cout<<"Tanggal Tes              : "<<x.tanggal_tes<<endl;
        cout<<"Alamat Rumah             : "<<x.alamat<<endl;
        cout<<"Alamat Samsat            : "<<x.alamat_samsat<<endl;
        x.status_pengajuan="SELAMAT MENGULANG TES"; */

    case 3:{
        clrscr();
        infotype_parent tmp;
        //z = findElm(LPa,tmp);
        cout<<"Nama                 : "<<info(PPP).Nama<<endl;
        cout<<"Jenis Kelamin        : "<<info(PPP).JenisKelamin<<endl;
        cout<<"Email                : "<<info(PPP).email<<endl;
        cout<<"No Handphone         : "<<info(PPP).NoHp<<endl;
        cout<<"Username             : "<<info(PPP).username<<endl;
        cout<<"0. Back"<<endl;
        int i;
        cin>>i;

        break;
    }
        //mainMenu();
    case 4:{
        address_child yyy;
        infotype_child xxx;
        cout<<"Masukkan ID Pengajuan: "<<endl;
        cin>>xxx.id_pengajuan;
        yyy = findElm(LCh,xxx);
        if (yyy == NULL){
            cout<<"ID tidak tersedia"<<endl;
            getch();
        }else{
            cout<<"Tempat, Tanggal Lahir            : ";cin>>info(yyy).TTL;
            cout<<"Tinggi                           : ";cin>>info(yyy).tinggi;
            cout<<"Pekerjaan                        : ";cin>>info(yyy).pekerjaan;
            cout<<"Golongan Darah                   : ";cin>>info(yyy).GolDarah;
            cout<<"Jenis Sim                        : ";cin>>info(yyy).JenisSim;
            cout<<"Tanggal Tes                      : ";cin>>info(yyy).tanggal_tes;
            cout<<"Alamat Rumah                     : ";cin>>info(yyy).alamat;
            cout<<"Alamat Samsat                    : ";cin>>info(yyy).alamat_samsat;

            cout<<"Edit berhasil"<<endl;
            getch();

        }
        menuUser();
        break;
    }

    case 5:{
       mainMenu();
       break;
    }
    }
}
/*void loginAdmin(){
    string uname,pass;
    cout<<"* * * L O G I N   A D M I N * * *"<<endl;
    cout<<"Username: "; cin>>uname;
    cout<<"Password: "; cin>>pass;

    if (uname == "admin"){
        if (pass == "12345"){
            cout<<"WELCOME ADMIN!"<<endl;
            menuAdmin();
        }
    }
    else{
        cout<<"YOU'RE NOT AN ADMIN"<<endl;
    }
}
*/
void menuAdmin(){ //List_parent &L1, List_child &L2
    int pil;
    clrscr();
    cout<<"1. Lihat Semua Pengajuan"<<endl;
    cout<<"2. Edit Status Pengajuan"<<endl;
    cout<<"3. Cari Pengajuan"<<endl;
    cout<<"4. Hapus Pengajuan"<<endl;
    cout<<"5. Log Out"<<endl;
    cin>>pil;
    switch (pil){
    case 1:
        clrscr();
        printInfo(LCh);
        getch();
        menuAdmin();
        break;
    case 2:{
        infotype_child xxx;
        address_child CCC;
        //clrscr();
        printInfo(LCh);
        cout<<"Masukkan ID Pengajuan: "; cin>>xxx.id_pengajuan;
        CCC = findElm(LCh,xxx);
        if (CCC == NULL){
            cout<<"Tidak ada pengajuan"<<endl;
            getch();
            menuAdmin();
        }
        else{
            cout<<"Status sekarang: "<<info(CCC).status_pengajuan<<endl;
            cout<<"Ganti status: "; cin>>info(CCC).status_pengajuan;
            cout<<"Berhasil";
            getch();
            menuAdmin();
        }
        break;
    }
    case 3:{
        clrscr();
        infotype_child xxx;
        address_child ccc;
        cout<<"Masukkan ID yang ingin dicari: "<<endl;
        cin>>xxx.id_pengajuan;
        ccc = findElm(LCh,xxx);
        getch();
        menuAdmin();
        break;
    }
    case 4:{
        clrscr();

        break;
    }
    case 5:
        //clrscr();
        mainMenu();
        //break;
        break;
    }
}
