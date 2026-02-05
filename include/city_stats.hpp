#pragma once
#include <functional>

namespace citygame {

    class CityStats {
        public:
            CityStats();
            void addMoney(int toAdd);
            bool spendMoney(int toSpend);
            int& getMoneyReference();
            int& getHappinessReference();
            void addHappiness(int toAdd);
            void setMoney(int newMoney);
            void setHappiness(int newHappiness);
            int getHappiness() const;
            int& getTax();
            void addRound(int toAdd);
        private:
            int money;
            int happiness;
            int roundNumber;
            int tax;
    };
}