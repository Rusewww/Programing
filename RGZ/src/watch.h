/**
 * @file watch.h
 * @brief Файл базового класу
 *
 * @author Zoulia I.
 * @date 20-may-2021
 * @version 1.0
 */

#ifndef RGZ_WATCH_H
#define RGZ_WATCH_H

#include <string>
#include <cstring>
#include <iostream>
#include <utility>
#include <sstream>
#include <fstream>
#include <regex>
#include <vector>
#include <set>
#include <list>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::ifstream;
using std::istream;
using std::move;
using std::ofstream;
using std::ostream;
using std::regex;
using std::regex_match;
using std::stoi;
using std::string;
using std::stringstream;
using std::vector;
using std::map;
using std::set;
using std::sort;
using std::find_if;
using std::for_each;
using std::pair;

/**
 * watchStyle - стилі годинників
 */

enum watchStyle {
    ARMOURED, CLASSIC, SPORT
};

/**
 * batteryType - види акумуляторів
 */

enum batteryType {
    GRAPHENE, LI_ION, SOLAR
};

/**
 * manufacturerStruct - клас який описує виробника
 */

class manufacturerStruct {
private:
    string firm;
    string country;

public:

    /**
     * Конструктор класу manufacturerStruct за замовчуванням
     */

    manufacturerStruct();

    /**
     * Конструктор класу manufacturerStruct з вхідними параметрами
     * @param firmClone - Фірма, яка буде записана в структуру;
     * @param countryClone - Країна походження фірми, яка буде записана в структуру;
     */

    manufacturerStruct(string firmClone, string countryClone);

    /**
     * Конструктор класу manufacturerStruct який копіює данні з іншого об’єкту
     * @param clone - об’єкт з якого копіюються данні
     */

    manufacturerStruct(const manufacturerStruct &clone);

    /**
     * Деструктор класу manufacturerStruct
     */

    virtual ~manufacturerStruct();

    /**
     * getFirm - гетер класу manufacturerStruct
     * @return Вміст поля firm.
     */

    string getFirm() const;

    /**
     * getCountry - гетер класу manufacturerStruct
     * @return Вміст поля country.
     */

    string getCountry() const;

    /**
     * setFirm - сеттетер класу manufacturerStruct, який записує данні у поле firm
     * @param firmClone - данні які будуть записані у поле firm
     */

    void setFirm(const string &firmClone);

    /**
     * setCountry - сеттетер класу manufacturerStruct, який записує данні у поле country
     * @param countryClone - данні які будуть записані у поле country
     */

    void setCountry(const string &countryClone);

    /**
     * showManufacturer - виводить вміст полів данних об’єкту
     */

    void showManufacturer();
};

/**
 * watch - базовий клас типу годинник
 */

class watch {
public:

    /**
     * getWaterproof - гетер класу watch
     * @return Вміст поля waterproof.
     */

    virtual bool getWaterproof() = 0;

    /**
     * getModel - гетер класу watch
     * @return Вміст поля model.
     */

    virtual string getModel() = 0;

    /**
     * getCost - гетер класу watch
     * @return Вміст поля cost.
     */

    virtual int getCost() = 0;

    /**
     * getManufacturer - гетер класу watch
     * @return Вміст поля manufacturer.
     */

    virtual manufacturerStruct getManufacturer() = 0;

    /**
     * getStyle - гетер класу watch
     * @return Вміст поля style.
     */

    virtual watchStyle getStyle() = 0;

    /**
     * copy - функція копіювання одного об’єкту до іншого
     * @return Копію об’єкту.
     */

    virtual watch *copy() = 0;

    /**
     * show - виводить вміст об’єкту базового класу
     */

    virtual void show() = 0;

    /**
     * ~watch - деструктор класу watch
     */

    virtual ~watch();
};

/**
 * mechanicalWatches - спадкоємець класу watch, який являє собою механічні годинники.
 */

class mechanicalWatches : public watch {
private:
    bool waterproof{};
    string model;
    int cost{};
    manufacturerStruct manufacturer;
    watchStyle style;
    bool selfWinding{};
    bool skeleton{};

public:

    /**
     * Конструктор класу mechanicalWatches за замовчуванням
     */

    mechanicalWatches();

    /**
     * Конструктор класу mechanicalWatches з вхідними параметрами
     * @param waterproofClone - інформація, яка буде записана в поле waterproof
     * @param modelClone - модель, яка буде записана в поле model
     * @param costClone - вартість, яка буде записана в поле cost
     * @param manufacturerClone - вирбник, який буде записаний в поле manufacturer
     * @param styleClone - стиль годинника, який буде записаний в поле style
     * @param selfWindingClone - інформація, яка буде записана в поле selfWinding
     * @param skeletonClone - інформація, яка буде записана в поле skeleton
     */

    mechanicalWatches(bool waterproofClone, string modelClone, int costClone,
                      const manufacturerStruct &manufacturerClone, watchStyle styleClone,
                      bool selfWindingClone, bool skeletonClone);

    /**
     * Конструктор класу mechanicalWatches який копіює данні з іншого об’єкту
     * @param clone - об’єкт з якого копіюються данні
     */

    mechanicalWatches(mechanicalWatches &clone);

    /**
     * ~mechanicalWatches - деструктор класу mechanicalWatches
     */

    ~mechanicalWatches() override;

    /**
     * getWaterproof - гетер класу mechanicalWatches
     * @return Вміст поля waterproof.
     */

    bool getWaterproof() override;

    /**
     * getModel - гетер класу mechanicalWatches
     * @return Вміст поля model.
     */

    string getModel() override;

    /**
     * getCost - гетер класу mechanicalWatches
     * @return Вміст поля cost.
     */

    int getCost() override;

    /**
     * getManufacturer - гетер класу mechanicalWatches
     * @return Вміст поля manufacturer.
     */

    manufacturerStruct getManufacturer() override;

    /**
     * getStyle - гетер класу mechanicalWatches
     * @return Вміст поля style.
     */

    watchStyle getStyle() override;

    /**
     * setWaterproof - сеттетер класу mechanicalWatches, який записує данні у поле waterproof
     * @param waterproofClone - інформація, яка буде записана в поле waterproof
     */

    void setWaterproof(const bool &waterproofClone);

    /**
     * setModel - сеттетер класу mechanicalWatches, який записує данні у поле model
     * @param modelClone - інформація, яка буде записана в поле model
     */

    void setModel(const string &modelClone);

    /**
     * setCost - сеттетер класу mechanicalWatches, який записує данні у поле cost
     * @param costClone - інформація, яка буде записана в поле cost
     */

    void setCost(const int &costClone);

    /**
     * setManufacturer - сеттетер класу mechanicalWatches, який записує данні у поле manufacturer
     * @param manufacturerClone - інформація, яка буде записана в поле manufacturer
     */

    void setManufacturer(manufacturerStruct *manufacturerClone);

    /**
     * setStyle - сеттетер класу mechanicalWatches, який записує данні у поле style
     * @param styleClone - інформація, яка буде записана в поле style
     */

    void setStyle(const watchStyle &styleClone);

    /**
     * getSelfWinding - гетер класу mechanicalWatches
     * @return Вміст поля selfWinding.
     */

    bool getSelfWinding() const;

    /**
     * getSkeleton - гетер класу mechanicalWatches
     * @return Вміст поля skeleton.
     */

    bool getSkeleton() const;

    /**
     * setSelfWinding - сеттетер класу mechanicalWatches, який записує данні у поле selfWinding
     * @param selfWindingClone - інформація, яка буде записана в поле selfWinding
     */

    void setSelfWinding(bool selfWindingClone);

    /**
     * setSelfWinding - сеттетер класу mechanicalWatches, який записує данні у поле skeleton
     * @param skeletonClone -  інформація, яка буде записана в поле skeleton
     */

    void setSkeleton(bool skeletonClone);

    /**
     * show - виводить вміст об’єкту класу mechanicalWatches
     */

    void show() override;

    /**
     * copy - функція копіювання одного об’єкту до іншого
     * @return Копію об’єкту.
     */

    watch *copy() override;
};

/**
 * quartzWatches - спадкоємець класу watch, який являє собою кварцові годинники.
 */

class quartzWatches : public watch {
private:
    bool waterproof{};
    string model;
    int cost{};
    manufacturerStruct manufacturer;
    watchStyle style;
    batteryType battery;
    int capacity{};

public:

    /**
    * Конструктор класу quartzWatches за замовчуванням
    */

    quartzWatches();

    /**
     * Конструктор класу quartzWatches з вхідними параметрами
     * @param waterproofClone - інформація, яка буде записана в поле waterproof
     * @param modelClone - модель, яка буде записана в поле model
     * @param costClone - вартість, яка буде записана в поле cost
     * @param manufacturerClone - вирбник, який буде записаний в поле manufacturer
     * @param styleClone - стиль годинника, який буде записаний в поле style
     * @param batteryClone - інформація, яка буде записана в поле battery
     * @param capacityClone - ємність, яка буде записана в поле capacity
     */

    quartzWatches(bool waterproofClone, string modelClone, int costClone, const manufacturerStruct &manufacturerClone,
                  watchStyle styleClone,
                  batteryType batteryClone, int capacityClone);

    /**
     * Конструктор класу mechanicalWatches який копіює данні з іншого об’єкту
     * @param clone - об’єкт з якого копіюються данні
     */

    quartzWatches(quartzWatches &clone);

    /**
     * ~quartzWatches - деструктор класу quartzWatches
     */

    ~quartzWatches() override;

    /**
     * getWaterproof - гетер класу quartzWatches
     * @return Вміст поля waterproof.
     */

    bool getWaterproof() override;

    /**
     * getModel - гетер класу quartzWatches
     * @return Вміст поля model.
     */

    string getModel() override;

    /**
     * getCost - гетер класу quartzWatches
     * @return Вміст поля cost.
     */

    int getCost() override;

    /**
     * getManufacturer - гетер класу quartzWatches
     * @return Вміст поля manufacturer.
     */

    manufacturerStruct getManufacturer() override;

    /**
     * getStyle - гетер класу quartzWatches
     * @return Вміст поля style.
     */

    watchStyle getStyle() override;

    /**
     * setWaterproof - сеттетер класу quartzWatches, який записує данні у поле waterproof
     * @param waterproofClone - інформація, яка буде записана в поле waterproof
     */

    void setWaterproof(const bool &waterproofClone);

    /**
     * setModel - сеттетер класу quartzWatches, який записує данні у поле model
     * @param modelClone - інформація, яка буде записана в поле model
     */

    void setModel(const string &modelClone);

    /**
     * setCost - сеттетер класу quartzWatches, який записує данні у поле cost
     * @param costClone - інформація, яка буде записана в поле cost
     */

    void setCost(const int &costClone);

    /**
     * setManufacturer - сеттетер класу quartzWatches, який записує данні у поле manufacturer
     * @param manufacturerClone - інформація, яка буде записана в поле manufacturer
     */

    void setManufacturer(manufacturerStruct *manufacturerClone);

    /**
     * setStyle - сеттетер класу quartzWatches, який записує данні у поле style
     * @param styleClone - інформація, яка буде записана в поле style
     */

    void setStyle(const watchStyle &styleClone);

    /**
     * getBattery - гетер класу quartzWatches
     * @return Вміст поля battery.
     */

    batteryType getBattery() const;

    /**
     * getCapacity - гетер класу quartzWatches
     * @return Вміст поля capacity.
     */

    int getCapacity() const;

    /**
     * setBattery - сеттетер класу quartzWatches, який записує данні у поле battery
     * @param batteryTypeClone - інформація, яка буде записана в поле battery
     */

    void setBattery(batteryType batteryTypeClone);

    /**
     * setCapacity - сеттетер класу quartzWatches, який записує данні у поле capacity
     * @param capacityClone - інформація, яка буде записана в поле capacity
     */

    void setCapacity(int capacityClone);

    /**
     * show - виводить вміст об’єкту класу quartzWatches
     */

    void show() override;

    /**
     * copy - функція копіювання одного об’єкту до іншого
     * @return Копію об’єкту.
     */

    watch *copy() override;
};

/**
 * Оператор порівняння двох типів годинників.
 * @param watch1 - перший годинник для порівняння
 * @param watch2 - другий годинник для порівняння
 * @return Результат порівняння
 */

bool operator==(watch &watch1, watch &watch2);

/**
 * Оператор виведення для классу quartzWatches
 * @param output - поток виведення
 * @param watch1 - об’єкт який виводится
 * @return Виведений об’єкт
 */

ostream &operator<<(ostream &output, quartzWatches &watch1);

/**
 * Оператор введення для классу quartzWatches
 * @param input  - поток введення
 * @param watch1  - об’єкт який вводиться
 * @return Введений об’єкт
 */

istream &operator>>(istream &input, quartzWatches &watch1);

/**
 * Оператор виведення для классу mechanicalWatches
 * @param output - поток виведення
 * @param watch1 - об’єкт який виводится
 * @return Виведений об’єкт
 */

ostream &operator<<(ostream &output, mechanicalWatches &watch1);

/**
 * Оператор введення для классу mechanicalWatches
 * @param input  - поток введення
 * @param watch1  - об’єкт який вводиться
 * @return Введений об’єкт
 */

istream &operator>>(istream &input, mechanicalWatches &watch1);

#endif //RGZ_WATCH_H
