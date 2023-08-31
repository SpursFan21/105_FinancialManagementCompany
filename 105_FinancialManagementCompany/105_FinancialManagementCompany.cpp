
#include <iostream>
#include <string>

class ClientProfolio {
public:
    // Interface Inheritance: ClientPortfolio Interface
    virtual double calculateReturns() const = 0;
    virtual void adjustRiskProfile() const = 0;
    virtual double getProfolioValue() const = 0;
};

//Implementation of Inheritance for Account class
class Account {
protected:
    double balance;
public:
    Account(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            std::cout << "Insufficient balance." << std::endl;
        }
    }
};

// Implementation Inheritance: Derived Account Classes
class SavingsAccount : public Account {
public:
    SavingsAccount(double initialBalance) : Account(initialBalance) {}
};

class RetirementAccount : public Account {
public:
    RetirementAccount(double initialBalance) : Account(initialBalance) {}
    void withdraw(double amount) override {
        std::cout << "Withdrawal from retirement account is subject to penalties." << std::endl;
    }
};

// Implementation Inheritance: FinancialAdvisor Class
class FinancialAdvisor {
public:
    virtual void provideInvestmentRecommendation() const = 0;
    virtual void evaluateRiskTolerance() const = 0;
    virtual void createFinancialPlan() const = 0;
};

// Implementation Inheritance: Derived FinancialAdvisor Classes
class InvestmentAdvisor : public FinancialAdvisor {
public:
    void provideInvestmentRecommendation() const override {
        std::cout << "Providing investment recommendation based on market analysis." << std::endl;
    }

    void evaluateRiskTolerance() const override {
        std::cout << "Evaluating client's risk tolerance to determine suitable investments." << std::endl;
    }

    void createFinancialPlan() const override {
        std::cout << "Creating a comprehensive financial plan for the client's investment goals." << std::endl;
    }

    void monitorPortfolio() const {
        std::cout << "Monitoring the client's investment portfolio for performance." << std::endl;
    }
};

class RetirementPlanner : public FinancialAdvisor {
public:
    void provideInvestmentRecommendation() const override {
        // Provide retirement-specific investment recommendation logic
    }
    void evaluateRiskTolerance() const override {
        // Evaluate risk tolerance for retirement planning
    }
    void createFinancialPlan() const override {
        // Create retirement-specific financial plan
    }
    // Additional methods or features specific to RetirementPlanner
};

int main() {
    SavingsAccount savings(5000.0);
    RetirementAccount retirement(100000.0);

    int choice;
    double amount;
mainMenu: // Label for the main menu
    while (true) {
        std::cout << "Welcome To Your Account\n" << std::endl;
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Deposit into savings account" << std::endl;
        std::cout << "2. Withdraw from retirement account" << std::endl;
        std::cout << "3. Financial Advisor" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            savings.deposit(amount);
            break;
        case 2:
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            retirement.withdraw(amount);
            break;
        case 3: {
            std::cout << "Financial Advisor" << std::endl;
            InvestmentAdvisor investmentAdvisor;

            int choose;

            while (true) {
                std::cout << "Choose an option:" << std::endl;
                std::cout << "1. Provide Investment Recommendation" << std::endl;
                std::cout << "2. Evaluate Risk Tolerance" << std::endl;
                std::cout << "3. Create Financial Plan" << std::endl;
                std::cout << "4. Monitor Portfolio" << std::endl;
                std::cout << "5. Exit" << std::endl;
                std::cout << "Enter your choice: ";
                std::cin >> choose;

                switch (choose) {
                case 1:
                    investmentAdvisor.provideInvestmentRecommendation();
                    break;
                case 2:
                    investmentAdvisor.evaluateRiskTolerance();
                    break;
                case 3:
                    investmentAdvisor.createFinancialPlan();
                    break;
                case 4:
                    investmentAdvisor.monitorPortfolio();
                    break;
                case 5:
                    std::cout << "Returning to the main menu." << std::endl;
                    goto mainMenu; // Return to the main menu using goto
                default:
                    std::cout << "Invalid choice. Please select a valid option." << std::endl;
                }
            }
        }
              break;
        case 4:
            std::cout << "Exiting the program." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }
    return 0;
}