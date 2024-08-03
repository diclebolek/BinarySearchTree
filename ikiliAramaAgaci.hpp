#ifndef IKILIARAMAAGACI_HPP
#define IKILIARAMAAGACI_HPP

#include "dugum.hpp"

class IkiliAramaAgaci {
public:
    IkiliAramaAgaci();
    
    bool varmi(int aranan, Dugum* aktifDugum);
    void ekle(int veri, Dugum* aktifDugum);
    int yukseklik(Dugum* aktifDugum);
    void preOrder(Dugum* aktifDugum);
    void postOrder(Dugum* aktifDugum);
    void inOrder(Dugum* aktifDugum);
    void sil(int aranan, Dugum* &aktifDugum);
    int enBuyuk(Dugum* aktifDugum);

private:
    static const int MAX = 100;
    enum HucreDurumu { HUCRE_BOS, HUCRE_DOLU } hucreDurumlari[MAX];
};

#endif // IKILIARAMAAGACI_HPP
