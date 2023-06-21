#include <iostream>

using namespace std;

struct Paket_Internet
{
    string nama_paket, kartu, jumlah_kuota;
    int harga, umur;

    Paket_Internet *next;
};

Paket_Internet *cur, *head, *tail, *newNode, *del, *before;

int Count()
{
    cur = head;
    int jumlah = 0;
    while (cur != NULL)
    {
        jumlah++;
        cur = cur->next;
    }
    return jumlah;
}

void CreatSLL(string nama_paket, string kartu, string jumlah_kuota, int umur, int harga)
{
    head = new Paket_Internet();
    head->nama_paket = nama_paket;
    head->umur = umur;
    head->jumlah_kuota = jumlah_kuota;
    head->kartu = kartu;
    head->harga = harga;
    head->next = NULL;
    tail = head;
}

void AddFirst(string nama_paket, string kartu, string jumlah_kuota, int umur, int harga)
{
    newNode = new Paket_Internet();
    newNode->nama_paket = nama_paket;
    newNode->umur = umur;
    newNode->jumlah_kuota = jumlah_kuota;
    newNode->kartu = kartu;
    newNode->harga = harga;
    newNode->next = head;
    head = newNode;
}

void AddMid(string nama_paket, string kartu, string jumlah_kuota, int umur, int harga, int posisi)
{
    if (posisi<1 | posisi> Count())
    {
        cout << "di luar jangkauan, gagal menambah data" << endl;
    }
    else if (posisi == 1 | posisi == Count())
    {
        cout << "bukan posisia awal, gagal menambah data" << endl;
    }
    else
    {

        newNode = new Paket_Internet();
        newNode->nama_paket = nama_paket;
        newNode->jumlah_kuota = jumlah_kuota;
        newNode->kartu = kartu;
        newNode->umur = umur;
        newNode->harga = harga;

        cur = head;
        for (int i = 1; i < posisi - 1; i++)
        {
            cur = cur->next;
        }

        newNode->next = cur->next;
        cur->next = newNode;
    }
}

void AddLast(string nama_paket, string kartu, string jumlah_kuota, int umur, int harga)
{
    newNode = new Paket_Internet();
    newNode->nama_paket = nama_paket;
    newNode->jumlah_kuota = jumlah_kuota;
    newNode->kartu = kartu;
    newNode->umur = umur;
    newNode->harga = harga;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
}

void changeFirst(string nama_paket, string kartu, string jumlah_kuota, int umur, int harga)
{
    head->nama_paket = nama_paket;
    head->jumlah_kuota = jumlah_kuota;
    head->kartu = kartu;
    head->umur = umur;
    head->harga = harga;
}

void changeMid(string nama_paket, string kartu, string jumlah_kuota, int umur, int harga, int posisi)
{
    if (posisi<1 | posisi> Count())
    {
        cout << "di luar jangkauan, gagal mengubah" << endl;
    }
    else if (posisi == 1 | posisi == Count())
    {
        cout << "bukan posisia awal, gagal mengubah" << endl;
    }
    else
    {
        cur = head;
        for (int i = 1; i < posisi; i++)
        {
            cur = cur->next;
        }
        cur->nama_paket = nama_paket;
        head->jumlah_kuota = jumlah_kuota;
        head->kartu = kartu;
        cur->umur = umur;
        cur->harga = harga;
    }
}

void changeLast(string nama_paket, string kartu, string jumlah_kuota, int umur, int harga)
{
    tail->nama_paket = nama_paket;
    head->jumlah_kuota = jumlah_kuota;
    head->kartu = kartu;
    tail->umur = umur;
    tail->harga = harga;
}

void DellFirst()
{
    del = head;
    head = head->next;
    delete del;
}

void delMid(int posisi)
{
    if (posisi<1 | posisi> Count())
    {
        cout << "di luar jangkauan, gagal DELETE" << endl;
    }
    else if (posisi == 1 | posisi == Count())
    {
        cout << "bukan posisia awal, gagal DELETE" << endl;
    }
    else
    {
        cur = head;
        for (int i = 1; i <= posisi; i++)
        {
            if (i == posisi - 1)
            {
                before = cur;
            }
            if (i == posisi)
            {
                del = cur;
            }
            cur = cur->next;
        }
        before->next = cur;
        delete del;
    }
}

void DellLast()
{
    del = tail;
    cur = head;
    while (cur->next != tail)
    {
        cur = cur->next;
    }
    tail = cur;
    tail->next = NULL;
    delete del;
}

void ReadSLL()
{
    cur = head;
    while (cur != NULL)
    {
        cout << "Nama Paket\t: " << cur->nama_paket << endl;
        cout << "kartu\t\t: " << cur->kartu << endl;
        cout << "jumlah kuota\t: " << cur->jumlah_kuota << endl;
        cout << "Masa berlaku\t: " << cur->umur << " hari" << endl;
        cout << "Harga\t\t: "
             << "Rp " << cur->harga << endl
             << endl;
        cur = cur->next;
    }

    cout << "jumlah data: " << Count() << endl;
    cout << "_________________________________________________" << endl;
}

int main(int argc, char const *argv[])
{
    CreatSLL("Paket Ramadhan", "Telkomsel", "15 GB", 30, 30000);
    AddFirst("Paket Sahur", "Indosat", "10 GB", 30, 20000);
    AddLast("Paket BukBer", "Telkomsel", "21 GB", 30, 45000);
    AddMid("Paket Malam", "Telkomsel", "50 GB", 30, 59999, 2);
    AddMid("Paket Malam", "Indosat", "100 GB", 30, 80000, 3);
    ReadSLL();

    return 0;
}
