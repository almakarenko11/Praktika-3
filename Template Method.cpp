#include <iostream>


class TicketPurchase {
public:
    void buyTicket() {
        selectTicket();
        makePayment();
        issueTicket();
    }

    virtual ~TicketPurchase() = default;

protected:
    virtual void selectTicket() = 0;
    virtual void makePayment() = 0;

    void issueTicket() {
        std::cout << "Ticket has been issued." << std::endl;
    }
};

class OnlineTicketPurchase : public TicketPurchase {
protected:
    void selectTicket() override {
        std::cout << "Selected ticket online." << std::endl;
    }

    void makePayment() override {
        std::cout << "Made payment online." << std::endl;
    }
};

class BoxOfficeTicketPurchase : public TicketPurchase {
protected:
    void selectTicket() override {
        std::cout << "Selected ticket at the box office." << std::endl;
    }

    void makePayment() override {
        std::cout << "Made payment at the box office." << std::endl;
    }
};

int main() {
    OnlineTicketPurchase onlinePurchase;
    onlinePurchase.buyTicket();

    BoxOfficeTicketPurchase boxOfficePurchase;
    boxOfficePurchase.buyTicket();

    return 0;
}