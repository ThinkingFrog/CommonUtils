#include "Buyer.h"
#include "Store.h"

int main() {
    Store store;

    IObserver* buyer1 = new Buyer();
    IObserver* buyer2 = new Buyer();

    store.addSub(buyer1);
    std::cout << "With 1 observer:" << std::endl;
    store.newPhoneArrived();

    store.addSub(buyer2);
    std::cout << "With 2 observers:" << std::endl;
    store.newPhoneArrived();

    store.deleteSub(buyer1);
    std::cout << "With 1 observer again:" << std::endl;
    store.newPhoneArrived();

    delete buyer1;
    delete buyer2;
    return 0;
}