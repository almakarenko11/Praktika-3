#include <iostream>
#include <memory>
#include <conio.h>


class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    virtual ~PaymentStrategy() = default;
};


class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid " << amount << " using Credit Card." << std::endl;
    }
};


class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid " << amount << " using PayPal." << std::endl;
    }
};


class Ticket {
    std::unique_ptr<PaymentStrategy> paymentStrategy;
public:
    void setPaymentStrategy(std::unique_ptr<PaymentStrategy> strategy) {
        paymentStrategy = std::move(strategy);
    }

    void pay(int amount) {
        if (paymentStrategy) {
            paymentStrategy->pay(amount);
        }
        else {
            std::cout << "Payment strategy is not set." << std::endl;
        }
    }
};

int main() {
    Ticket ticket;

    ticket.setPaymentStrategy(std::make_unique<CreditCardPayment>());
    ticket.pay(100);

    ticket.setPaymentStrategy(std::make_unique<PayPalPayment>());
    ticket.pay(200);
    
    return 0;
}