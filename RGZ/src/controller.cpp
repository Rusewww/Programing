/**
 * @file controller.cpp
 * @brief Код функцій задекларованих у controller.h
 *
 * @author Zozulia Igor.
 * @date 20-may-2021
 * @version 1.0
 */

#include "controller.h"

void controller::setList(list *watchListCopy) {
    this->watchList = *watchListCopy;
}

void controller::showList() const {
    auto tmp = watchList.getList();
    for (unsigned long i = 0; i < (unsigned long) this->watchList.getCount(); ++i) {
        tmp[i]->show();
        cout << endl;
    }
}

/**
 * functorLessCost - функтор сортування за ціною (від більшого до меншого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorLessCost(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getCost() > tempTwo->getCost()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorMoreCost - функтор сортування за ціною (від меншого до більшого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorMoreCost(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getCost() < tempTwo->getCost()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorLessWaterproof - функтор сортування за вологостійкістю (від меншого до більшого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorLessWaterproof(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getWaterproof() > tempTwo->getWaterproof()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorMoreWaterproof - функтор сортування за вологостійкістю (від більшого до меншого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorMoreWaterproof(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getWaterproof() < tempTwo->getWaterproof()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorLessModel - функтор сортування за моделлю (від меншого до більшого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorLessModel(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getModel() > tempTwo->getModel()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorMoreModel - функтор сортування за моделлю (від більшого до меншого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorMoreModel(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getModel() < tempTwo->getModel()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorLessFirm - функтор сортування за фірмою (від меншого до більшого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorLessFirm(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getManufacturer().getFirm() > tempTwo->getManufacturer().getFirm()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorMoreFirm - функтор сортування за фірмою (від більшого до меншого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorMoreFirm(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getManufacturer().getFirm() < tempTwo->getManufacturer().getFirm()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorLessCountry - функтор сортування за країною (від меншого до більшого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorLessCountry(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getManufacturer().getCountry() > tempTwo->getManufacturer().getCountry()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorMoreCountry - функтор сортування за країною (від більшого до меншого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorMoreCountry(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getManufacturer().getCountry() < tempTwo->getManufacturer().getCountry()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorLessStyle - функтор сортування за стилем (від меншого до більшого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorLessStyle(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getStyle() > tempTwo->getStyle()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

/**
 * functorMoreStyle - функтор сортування за стилем (від більшого до меншого)
 * @param one - перший обєкт порівняння
 * @param two - другий обєкт порівняння
 * @return Результат порівняння.
 */

bool functorMoreStyle(watch *one, watch *two) {
    bool result = false;
    auto *tempOne = (watch *) one->copy();
    auto *tempTwo = (watch *) two->copy();
    if (tempOne->getStyle() < tempTwo->getStyle()) {
        result = true;
        delete tempOne;
        delete tempTwo;
    }
    return result;
}

void controller::sorting(char way, int criterion) {
    auto tmp = watchList.getList();
    switch (criterion) {
        case 1:
            if (way == '<') {
                sort(tmp.begin(), tmp.end(), functorMoreWaterproof);
            } else {
                sort(tmp.begin(), tmp.end(), functorLessWaterproof);
            }
            break;
        case 2:
            if (way == '<') {
                sort(tmp.begin(), tmp.end(), functorMoreCost);
            } else {
                sort(tmp.begin(), tmp.end(), functorLessCost);
            }
            break;
        case 3:
            if (way == '<') {
                sort(tmp.begin(), tmp.end(), functorMoreModel);
            } else {
                sort(tmp.begin(), tmp.end(), functorLessModel);
            }
            break;
        case 4:
            if (way == '<') {
                sort(tmp.begin(), tmp.end(), functorMoreFirm);
            } else {
                sort(tmp.begin(), tmp.end(), functorLessFirm);
            }
            break;
        case 5:
            if (way == '<') {
                sort(tmp.begin(), tmp.end(), functorMoreCountry);
            } else {
                sort(tmp.begin(), tmp.end(), functorLessCountry);
            }
            break;
        case 6:
            if (way == '<') {
                sort(tmp.begin(), tmp.end(), functorMoreStyle);
            } else {
                sort(tmp.begin(), tmp.end(), functorLessStyle);
            }
            break;
        default:
            cout << ("| Incorrect variant!!!") << endl;
            break;
    }
    this->watchList.setLinks(tmp);
}

/**
 * findPriceHelp - Допоміжна функція пошуку за ціною
 * @param one - обєкт для перевірки
 * @return Результат відповідності
 */

bool findPriceHelp(watch *one) {
    auto *temp = (watch *) one->copy();
    if (temp->getCost() <= 400) {
        delete temp;
        return true;
    } else {
        delete temp;
        return false;
    }
}

/**
 * findClassicHelp - Допоміжна функція пошуку класичних годинників
 * @param one - обєкт для перевірки
 * @return Результат відповідності
 */


bool findClassicHelp(watch *one) {
    auto *temp = (watch *) one->copy();
    if (temp->getStyle() == CLASSIC) {
        delete temp;
        return true;
    } else {
        delete temp;
        return false;
    }
}

/**
 * findSwitzerlandWithSkeletonHelp - Допоміжна функція пошуку годинників зі скалетоном із Швейцарії
 * @param one - обєкт для перевірки
 * @return Результат відповідності
 */

bool findSwitzerlandWithSkeletonHelp(watch *one) {
    auto *temp = (mechanicalWatches *) one->copy();
    if (temp->getManufacturer().getCountry() == "Switzerland" && temp->getSkeleton()) {
        delete temp;
        return true;
    } else {
        delete temp;
        return false;
    }
}

vector<watch *> controller::find(int criterion) const {
    vector<watch *> result;
    vector<watch *> tmp = this->watchList.getList();
    bool flag = true;
    auto iter = tmp.begin();
    while (true) {
        switch (criterion) {
            case 1:
                iter = find_if(iter, tmp.end(), findPriceHelp);
                break;
            case 2:
                iter = find_if(iter, tmp.end(), findClassicHelp);
                break;
            case 3:
                iter = find_if(iter, tmp.end(), findSwitzerlandWithSkeletonHelp);
                break;
            default:
                cout << ("| Criterion entered incorrectly!!!") << endl;
                return result;
        }
        if (iter == tmp.end()) {
            break;
        }
        flag = false;
        result.push_back((mechanicalWatches *) *iter);
        ((mechanicalWatches *) *iter)->show();
        cout << endl;
        iter++;
    }
    if (flag) {
        cout << "|There are no suitable watches!" << endl;
    }
    while (!tmp.empty()) {
        tmp.pop_back();
    }
    tmp.clear();
    tmp.shrink_to_fit();
    return result;
}

void controller::readFromFile(const string &path) {
    bool checker = false;
    cout << endl;
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) {
        cout << "ERROR: The file did not open!" << endl;
        cout << "Try again.." << endl << endl;
        checker = true;
    } else {
        char type;
        bool WP;
        string Model;
        int Cost;
        int Style;
        string Firm;
        string Country;
        int fieldOne;
        int fieldSecond;
        stringstream buffer;

        while (!fin.eof()) {
            fin >> type;
            fin >> WP;
            fin >> Model;
            fin >> Cost;
            fin >> Style;
            fin >> Firm;
            fin >> Country;
            fin >> fieldOne;
            fin >> fieldSecond;
            regex regular("^[0-1] [A-Z][a-z]* [0-9]{1,5} [0-2] [A-Z][a-zA-Z]* [A-Z][a-zA-Z]* [0-2] [0-9]{1,3}$");
            buffer << WP << " " << Model << " " << Cost << " " << Style << " " << Firm << " " << Country << " "
                   << fieldOne << " " << fieldSecond;
            if (regex_match(buffer.str(), regular)) {
                if (type == 'M') {
                    mechanicalWatches mWatch(WP, Model, Cost, manufacturerStruct(Firm, Country), (watchStyle) Style,
                                             fieldOne,
                                             fieldSecond);
                    watchList.addLink(&mWatch);
                }

                if (type == 'Q') {
                    quartzWatches qWatch(WP, Model, Cost, manufacturerStruct(Firm, Country), (watchStyle) Style,
                                         (batteryType) fieldOne,
                                         fieldSecond);
                    watchList.addLink(&qWatch);
                }
            }
            buffer.str("");
        }
    }
    fin.close();
}

/**
 * toString - перетворює обєкт в строку для запису у файл
 * @param watches - обєкт для перетворення
 * @return Інформаційна строка обєкту
 */

string toString(watch *watches) {
    stringstream buffer;
    auto *tmp = (watch *) watches->copy();
    buffer << tmp->getWaterproof() << " " << tmp->getModel() << " " << tmp->getCost() << " "
           << tmp->getManufacturer().getFirm()
           << " " << tmp->getManufacturer().getCountry() << " " << tmp->getStyle() << " " << endl;
    delete tmp;
    return buffer.str();
}

void controller::writeToFile(const string &path) {
    ofstream fOut;
    fOut.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    fOut.open(path, std::ios_base::out);
    if (!fOut.is_open()) {
        cout << "ERROR: The file did not open!" << endl;
    } else {
        for (int i = 0; i < (int) watchList.getList().size(); ++i) {
            fOut << toString(watchList.getLink(i));
        }

    }
    fOut.close();
}

controller::~controller() = default;

controller::controller() = default;
