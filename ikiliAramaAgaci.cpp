#include <iomanip>
#include "IkiliAramaAgaci.hpp"
#include <iostream>
using namespace std;

IkiliAramaAgaci::IkiliAramaAgaci() {
    for(int i = 0; i < MAX; i++)
        hucreDurumlari[i] = HUCRE_BOS;
}

bool IkiliAramaAgaci::varmi(int aranan, Dugum* aktifDugum) {
    if (aktifDugum == nullptr) return false;

    if (aktifDugum->veri < aranan) {
        if (aktifDugum->sag)
            return varmi(aranan, aktifDugum->sag);
        return false;
    } else if (aktifDugum->veri > aranan) {
        if (aktifDugum->sol)
            return varmi(aranan, aktifDugum->sol);
        return false;
    } else {
        return true;
    }
}

void IkiliAramaAgaci::ekle(int veri, Dugum* aktifDugum) {
    if (aktifDugum == nullptr) return;

    if (aktifDugum->veri > veri) {
        if (aktifDugum->sol)
            ekle(veri, aktifDugum->sol);
        else
            aktifDugum->sol = new Dugum(veri);
    } else if (aktifDugum->veri < veri) {
        if (aktifDugum->sag)
            ekle(veri, aktifDugum->sag);
        else
            aktifDugum->sag = new Dugum(veri);
    } else {
        return; // Eşit değer varsa ekleme yapmıyoruz
    }
}
int IkiliAramaAgaci::enBuyuk(Dugum* aktifDugum){
    if(aktifDugum->sag)
        return enBuyuk(aktifDugum->sag);
    return aktifDugum->veri;
}
void IkiliAramaAgaci::sil(int aranan, Dugum* &aktifDugum) {
    if (aktifDugum == 0) return;

    if (aktifDugum->veri >aranan) 
        sil(aranan, aktifDugum->sol);      
    else if (aktifDugum->veri < aranan) {
            sil(aranan, aktifDugum->sag);

    } else {//silinecek düğüm bulundu aktif silinecek düğümü gösterir
        //aranan aktif işaretçisinin gösterdiği düğümdür
        //2 taraftada cocuk varsa
        if(aktifDugum->sag&&aktifDugum->sol){
            aktifDugum->veri=enBuyuk(aktifDugum->sol);
            sil(aktifDugum->veri,aktifDugum->sol);
        }
        //aranan düğümde 2 den az çocuk varsa
        else{
            Dugum* silinecek =aktifDugum;
            if(aktifDugum->sol==0)
                aktifDugum=aktifDugum->sag;
            else if(aktifDugum->sag==0)
                aktifDugum=aktifDugum->sol;
            else
                aktifDugum= 0;
            delete silinecek;
        }
    }
}

int IkiliAramaAgaci::yukseklik(Dugum* aktifDugum) {
    if (aktifDugum) {
        return 1 + max(yukseklik(aktifDugum->sol), yukseklik(aktifDugum->sag));
    }
    return -1;
}

void IkiliAramaAgaci::preOrder(Dugum* aktifDugum) {
    if (aktifDugum) {
        cout << aktifDugum->veri << " - ";
        preOrder(aktifDugum->sol);
        preOrder(aktifDugum->sag);
    }
}

void IkiliAramaAgaci::postOrder(Dugum* aktifDugum) {
    if (aktifDugum) {
        postOrder(aktifDugum->sol);
        postOrder(aktifDugum->sag);
        cout << aktifDugum->veri << " - ";
    }
}

void IkiliAramaAgaci::inOrder(Dugum* aktifDugum) {
    if (aktifDugum) {
        inOrder(aktifDugum->sol);
        cout << aktifDugum->veri << " - ";
        inOrder(aktifDugum->sag);
    }
}
