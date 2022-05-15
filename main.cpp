
//Bunga Laelatul Muna
// 21102010

#include <iostream>

using namespace std;

struct node{
    int data;
    string nama;
    node *next;
};

node *head, *tail, *baru, *bantu1;

void init ()
{
    head = NULL;
    tail = NULL;
}

int isEmpty()
{
    if(head == NULL){
        return 1;
    }else{
        return 0;
    }
}

void buatNode(string nama, int nim)
{
    baru = new node;
    baru->nama = nama;
    baru->data = nim;
    baru->next = NULL;
}

int hitungList()
{
    node *hitung;
    hitung = head;
    int jumlah = 0;
    while(hitung != NULL){
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

void insertDepan(string nama, int nim)
{
    buatNode(nama, nim);
    if(isEmpty() == 1){
        head = tail = baru;
        tail -> next = NULL;
    }else{
        baru -> next = head;
        head = baru;
    }
    cout << "==============================================" << endl ;
    cout << "Data " << nama << " Berhasil ditambahkan!" << endl ;
    cout << "==============================================" << endl;
}
void insertBelakang(string nama, int nim)
{
    buatNode(nama, nim);
    if(isEmpty() == 1){
        head = tail = baru;
        tail -> next = NULL;
    }else{
        tail -> next = baru;
        tail = baru;
    }
    cout << "==============================================" << endl;
    cout << "Data " << nama << " berhasil diinput!" << endl;
    cout << "==============================================" << endl;
}

void insertTengah(string nama, int nim, int posisi)
{
   if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
   }else if(posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
   }else{
        buatNode(nama, nim);
    }
        int nomor = 1;
        bantu1 = head;
        while (nomor < posisi - 1){
            bantu1 = bantu1->next;
            nomor++;
        }
        baru->next = bantu1->next;
        bantu1->next = baru;
        cout << "==============================================" << endl ;
    cout << "Data " << nama << " Berhasil ditambahkan!" << endl ;
    cout << "==============================================" << endl ;
}

void ubahDepan(string nama, int nim)
{
    if (isEmpty() == 0){
        cout << "=================================================" << endl;
        cout << "Data " << head -> nama << " telah diganti dengan " << nama << endl;
        cout << "=================================================" << endl;
        head -> nama = nama;
        head -> data = nim;
        cout << endl;
    }else{
        cout << "List masih kosong!" << endl;
    }
}

void ubahTengah(int posisi, string nama, int nim)
{
    node *bantu1;
    if (isEmpty() == 0){
        if(posisi < 1 || posisi > hitungList()){
            cout << "Posisi di luar jangkauan" << endl;
        }else if(posisi == 1){
        cout << "Posisi bukan posisi tengah" << endl;
        }else{
        bantu1 = head;
        int nomor = 1;
        while (nomor < posisi){
            bantu1 = bantu1 -> next;
            nomor++;
        }

        cout << "=================================================" << endl;
        cout << "Data " << bantu1 -> nama << " telah diganti dengan " << nama << endl;
        cout << "=================================================" << endl;
        bantu1 -> nama = nama;
        bantu1 -> data = nim;
        cout << endl;
        }
    }else{
        cout << "List masih kososng!" << endl;
    }
}

void ubahBelakang(string nama, int nim)
{
    if (isEmpty() == 0){
        cout << "=================================================" << endl;
        cout << "Data " << tail -> nama << " telah diganti dengan " << nama << endl;
        cout << "=================================================" << endl;
        tail -> nama = nama;
        tail -> data = nim;
        cout << endl;
    }else{
        cout << "List masih kosong" << endl;
        }
}

void DelFront()
  { cout << "==============================================" << endl ;
    cout << "Data " << head->nama << " Berhasil dihapus!" << endl ;
    cout << "==============================================" << endl << endl;
    node *baru=new node;
    baru=head;
    head=head->next;
    delete baru;
  }


void DelBack(){
    node *after=new node;
    node *before=new node;
    after=head;
    while(after->next!=NULL)
    {
      before=after;
      after=after->next;
    }
    tail=before;
    before->next=NULL;
    cout << "==============================================" << endl;
    cout << "Data " << after->nama << " Berhasil dihapus!" << endl;
    cout << "==============================================" << endl << endl;
    delete after;
}

void hapusTengah(){
        node  *posisi;
        int i, kounter, letak ;
        cout<<"Masukan Posisi yg Ingin dihapus: ";
        cin>>letak;
        posisi = head;
            while(posisi != NULL){

                posisi = posisi->next;
                kounter++;
            }
            if (letak> 0 && letak<= kounter){
                posisi = head;
                for (i = 1;i < letak;i++){
                    tail = posisi;
                    posisi = posisi->next;
                }
                cout << "==============================================" << endl;
                cout << "Data " << posisi->nama << " Berhasil dihapus!" << endl;
                cout << "==============================================" << endl;
                tail->next = posisi->next;

            }
            else{
                cout<<"Data yg ada hanya "<<kounter<<endl;
            }
    }

    void Display() {
	if (head == NULL) {
		cout << "Maaf, data masih kosong\n";
	}
	for (node* baru = head; baru != NULL; baru = baru->next)
		cout << "Nama   : " << baru->nama << "\n" << "NIM    : " << baru->data << "\n\n";
}

void cleaarList()
{
    node *bantu, *hapus;
    bantu = head;

    while (bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail =NULL;
    cout << "==============================================" << endl;
    cout << "List berhasil terhapus!" << endl;
    cout << "==============================================" << endl ;
}

int main()
{
    init();
    cout << "======== MENU ==========" << endl;
    cout << "========================" << endl ;
    cout << "| 1. Insert Depan      |\n";
    cout << "| 2. Insert Belakang   |\n";
    cout << "| 3. Insert Tengah     |\n";
    cout << "| 4. Ubah Depan        |\n";
    cout << "| 5. Ubah Belakang     |\n";
    cout << "| 6. Ubah Tengah       |\n";
    cout << "| 7. Hapus Depan       |\n";
    cout << "| 8. Hapus Belakang    |\n";
    cout << "| 9. Hapus Tengah      |\n";
    cout << "|10. Hapus List        |\n";
    cout << "|11. Tampilkan         |\n";
    cout << "| 0. Keluar            |\n";
    cout << "========================" << endl << endl;
    menu:
    int pilih,nim,posisi, data;
    string  nama1;
    cout << endl <<"Masukkan Pilihan = ";cin>>pilih; cout << endl;

        switch (pilih)
        {
          case 1: system ("cls");
                 cout << "==== TAMBAH DEPAN ====\n";
                 cout << "=======================\n\n";
                 cout << "Masukan jmlh data: "; cin >> data;
                 for (int i=0; i<data; i++){cout << endl;
                 cout <<"Nim   : "; cin  >> nim;
                 cout <<"Nama  : "; cin.ignore(); getline (cin,nama1);
                 insertDepan(nama1, nim); cout << endl;}
                  goto menu; break;

        case 2:  system ("cls");
                 cout << "==== TAMBAH BLKG ====\n";
                 cout << "=======================\n\n";
                 cout << "Masukan jmlh data: "; cin >> data;
                 for (int i=0; i<data; i++){ cout << endl;
                 cout <<"Nim   : "; cin >> nim;
                 cout <<"Nama  : "; cin.ignore(); getline (cin, nama1);
                 insertBelakang( nama1, nim);}
                 goto menu; break;

         case 3: system ("cls");
                 cout << "==== TAMBAH TENGAH ====\n";
                 cout << "=======================\n\n";
                 cout << "Posisi ke- ";cin >> posisi;
                 cout << "Nim  : "; cin >> nim;
                 cout << "Nama : "; cin.ignore(); getline (cin, nama1);
                 insertTengah(nama1, nim, posisi);
                 goto menu; break;

        case 4:
                system("cls");
                cout << "====   UBAH DEPAN  ====\n";
                cout << "=======================\n\n";
                cout << "Nim  : ";cin >> nim;
                cout << "Nama : ";cin.ignore(); getline (cin, nama1);
                ubahDepan(nama1, nim);goto menu;
                break;

        case 5:
                system ("cls");
                cout << "====   UBAH BLKG  ====\n";
                cout << "=======================\n\n";
                cout << "Nim  :"; cin >> nim;
                cout << "Nama : ";cin.ignore();getline (cin, nama1);
                ubahBelakang(nama1, nim);
                goto menu;break;

        case 6 :
                system ("cls");
                cout << "====   UBAH TENGAH  ====\n";
                cout << "=======================\n\n";
                cout << "Posisi ke- ";cin >> posisi;
                cout << "Nim   : ";cin >> nim;
                cout << "Nama  : ";cin.ignore();getline (cin, nama1);
                ubahTengah(posisi, nama1, nim);
                goto menu;break;

        case 7 :
                 cout << "===== HAPUS DEPAN ====\n";
                 cout << "=======================\n\n";
                 DelFront(); cout << "**** Data stlh di hapus **** " << endl;
                 Display();
                 goto menu; break;

       case 8:  cout << "==== HAPUS BLKG ====\n";
                 cout << "=======================\n\n";
                 DelBack(); cout << "**** Data stlh di hapus **** " << endl;
                 Display();
                 goto menu; break;

        case 9 : cout << "==== HAPUS TENGAH ====\n";
                 cout << "=======================\n\n";
                 hapusTengah();
                 Display();
                 goto menu;break;

        case 10: cleaarList(); goto menu;

        case 11: cout << "====  DATA MAHASISWA ====\n";
                 cout << "=========================\n\n";
                 Display();
                 goto menu; break;
        case 0: return 0;

        default: cout<<"Salah kode!\n\n"; goto menu;
    }
    return 0;
}



