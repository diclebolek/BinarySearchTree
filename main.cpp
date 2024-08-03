#include <iostream>
#include "IkiliAramaAgaci.hpp"

using namespace std;

int main() {
    IkiliAramaAgaci agac;
    Dugum* kok = nullptr;

    int secim, veri;
    while (true) {
        cout << "\n1. Add\n2. Search\n3. Delete\n4. InOrder Traversal\n5. PreOrder Traversal\n6. PostOrder Traversal\n7. Exit\nYour choice: ";
        cin >> secim;

        switch (secim) {
            case 1:
                cout << "Enter the value to add: ";
                cin >> veri;
                if (kok == nullptr) {
                    kok = new Dugum(veri);
                } else {
                    agac.ekle(veri, kok);
                }
                break;
            case 2:
                cout << "Enter the value to search: ";
                cin >> veri;
                if (agac.varmi(veri, kok)) {
                    cout << veri << " is found in the tree.\n";
                } else {
                    cout << veri << " is not found in the tree.\n";
                }
                break;
            case 3:
                cout << "Enter the value to delete: ";
                cin >> veri;
                agac.sil(veri, kok);
                break;
            case 4:
                cout << "InOrder Traversal: ";
                agac.inOrder(kok);
                cout << endl;
                break;
            case 5:
                cout << "PreOrder Traversal: ";
                agac.preOrder(kok);
                cout << endl;
                break;
            case 6:
                cout << "PostOrder Traversal: ";
                agac.postOrder(kok);
                cout << endl;
                break;
            case 7:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
