#include "city_stats.hpp"

namespace citygame {

    CityStats::CityStats()
        : money(0), happiness(2) {

    }

    void CityStats::addMoney(int toAdd) {
        money += toAdd;
        onMoneyChanged(money);
    }

    bool CityStats::spendMoney(int toSpend) {
        if (money >= toSpend) {
            money -= toSpend;
            onMoneyChanged(money);
            return true;
        }
        
        return false;
    }

    void CityStats::setOnMoneyChanged(std::function<void(int)> callback) {
        onMoneyChanged = callback;
    }

    void CityStats::setOnHappinessChanged(std::function<void(int)> callback) {
        onHappinessChanged = callback;
    }



}