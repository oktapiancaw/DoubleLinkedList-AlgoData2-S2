#include <iostream>
using namespace std;

struct Node {
    int INFO;
    Node* LINK;
};

Node* FIRST = nullptr;
Node* LAST = nullptr;

void tambah_depan() {
    Node* newNode = new Node;
    cout << "Input nilai: ";
    cin >> newNode->INFO;
    newNode->LINK = nullptr;
    
    if (!FIRST) {
        FIRST = newNode;
        LAST = newNode;
    } else {
        newNode->LINK = FIRST;
        FIRST = newNode;
    }
}

void tambah_belakang() {
    Node* newNode = new Node;
    cout << "Input nilai: ";
    cin >> newNode->INFO;
    newNode->LINK = nullptr;

    if (!FIRST) {
        FIRST = newNode;
        LAST = newNode;
    } else {
        LAST->LINK = newNode;
        LAST = newNode;
    }
}

void hapus_depan() {
    if (FIRST) {
        Node* temp = FIRST;
        FIRST = FIRST->LINK;
        delete temp;
    }
}

void hapus_belakang() {
    if (FIRST) {
        if (FIRST == LAST) {
            delete FIRST;
            FIRST = nullptr;
            LAST = nullptr;
        } else {
            Node* temp = FIRST;
            while (temp->LINK != LAST) {
                temp = temp->LINK;
            }
            delete LAST;
            LAST = temp;
            LAST->LINK = nullptr;
        }
    }
}

void tampil() {
    if (!FIRST) {
        cout << "Kosong";
    } else {
        Node* current = FIRST;
        while (current) {
            cout << "  " << current->INFO;
            current = current->LINK;
        }
    }
}

int main() {
    int pil;
    do {
        system("clear"); // Ganti dengan "clear" jika Anda berada di sistem Unix/Linux.
        cout << "MENU SINGLE LINKED LIST" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Hapus Depan" << endl;
        cout << "4. Hapus Belakang" << endl;
        cout << "5. Tampilkan" << endl;
        cout << "6. Selesai" << endl;
        cout << "Pilihan Anda: ";
        cin >> pil;

        switch (pil) {
            case 1:
                tambah_depan();
                break;
            case 2:
                tambah_belakang();
                break;
            case 3:
                hapus_depan();
                break;
            case 4:
                hapus_belakang();
                break;
            case 5:
                tampil();
                break;
            case 6:
                cout << "Selesai";
                break;
            default:
                cout << "Pilihan tidak valid!";
                break;
        }
        cin.get(); // Menunggu input enter sebelum membersihkan layar.
    } while (pil != 6);

    return 0;
}