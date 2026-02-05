#include "city_stats.hpp"
#include <cmath>

namespace citygame {

    CityStats::CityStats()
        : money(10), happiness(0), roundNumber(1), tax(0) {

    }

    void CityStats::addMoney(int toAdd) {
        money += toAdd;
    }

    bool CityStats::spendMoney(int toSpend) {
        if (money >= toSpend) {
            money -= toSpend;
            return true;
        }
        
        return false;
    }

    int& CityStats::getMoneyReference() {
        return money;
    }

    int&  CityStats::getHappinessReference() {
        return happiness;
    }

    void CityStats::setMoney(int newMoney) {
        money = newMoney;
    }

    void CityStats::addHappiness(int toAdd) {
        happiness += toAdd;
    }

    void CityStats::setHappiness(int newHappiness) {
        happiness = newHappiness;
    }

    int CityStats::getHappiness() const {
        return happiness;
    }

    int& CityStats::getTax() {
        return tax;
    }

    void CityStats::addRound(int toAdd) {
        roundNumber += toAdd;
        double taxReal = roundNumber * log10(roundNumber);
        tax = floor(taxReal);
    }

}