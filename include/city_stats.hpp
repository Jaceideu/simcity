#pragma once
#include <functional>

namespace citygame {

    class CityStats {
        public:
            CityStats();
            void addMoney(int toAdd);
            bool spendMoney(int toSpend);
            int& getMoneyReference();
            void setOnMoneyChanged(std::function<void(int)> callback);
            void setOnHappinessChanged(std::function<void(int)> callback);
        private:
            int money;
            int happiness;
            std::function<void(int)> onMoneyChanged;
            std::function<void(int)> onHappinessChanged;
    };
}