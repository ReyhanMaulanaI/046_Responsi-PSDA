#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct TempatPariwisata {
    string nama;
    string deskripsi;
    string lokasi;
    string rating;
};

vector<TempatPariwisata> tempat_pariwisata;

void tambahTempat(){
    TempatPariwisata tempat;
    cout << "Masukkan informasi tempat pariwisata:"<<endl;
    cout << "Nama Tempat : ";
    getline(cin >> ws, tempat.nama);
    cout << "Deskripsi Tempat : ";
    getline(cin >> ws, tempat.deskripsi);
    cout << "Lokasi : ";
    getline(cin >> ws, tempat.lokasi);
    cout << "Rating : ";
    getline(cin >> ws, tempat.rating);
    tempat_pariwisata.push_back(tempat);
    cout << "Tempat pariwisata berhasil ditambahkan!" << endl;
}

void cariTempat(const vector<string>& kataKUnci){
    bool ditemukan =false;
    for (const auto& tempat : tempat_pariwisata){
        bool semuaKataKunciDitemukan = true;
        for (const auto& keyword : kataKUnci){
            if(tempat.deskripsi.find(keyword)== string::npos){
                semuaKataKunciDitemukan = false;
                break;
            }
        }
        if (semuaKataKunciDitemukan){
            ditemukan = true;
            cout << "Nama Tempat : " << tempat.nama << endl;        
            cout << "Deskripsi Tempat : " << tempat.deskripsi << endl;        
            cout << "Lokasi : " << tempat.lokasi << endl;        
            cout << "Rating : " << tempat.rating << endl << endl;       \

            }
        }
        if (!ditemukan){
            cout << " Tidak ada tempat pariwisata yang cocok dengan kata kunci tersebut" << endl << endl;

        }
    }
int main(){
    while (true){
        cout<< "Menu :"<< endl;
        cout<< "1. Tambahkan Tempat pariwisata "<< endl;
        cout<< "2. Cari Tempat Pariwisata "<< endl;
        cout<< "3. Keluar "<< endl;
        cout<< "Pilih menu : "<< endl;
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        switch (pilihan){
            case 1 :
            tambahTempat();
            break;
            case 2 : {
                cout << "Masukkan kata kunci pencarian: ";
                string input;
                getline(cin, input);
                vector<string> kataKunci;
                size_t pos = 0;
                string token;
                while ((pos = input.find(" ")) != string::npos){
                    token = input.substr(0, pos);
                    kataKunci.push_back(token);
                    input.erase(0, pos + 1);
                }
                kataKunci.push_back(input);
                cariTempat(kataKunci);
                break;
            }
            case 3:
            cout << "Terima kasih telah menggunakan program ini" << endl;
            return 0;
            default:
            cout << "Menu tidak valid. Silahkan coba lagi" << endl;
            break;       
        
        }

    }

}
