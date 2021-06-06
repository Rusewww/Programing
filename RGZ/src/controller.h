#ifndef RGZ_CONTROLLER_H
#define RGZ_CONTROLLER_H

#include "list.h"

/**
 * controller - клас контроллеру
 */

class controller {
public:
    list watchList;

    /**
     * Конструктор класу controller за замовчуванням
     */

    controller();

    /**
     * Деструктор класу controller
     */

    ~controller();

    /**
     * setList - сеттетер класу controller, який записує данні у список watchList
     * @param watchListCopy
     */

    void setList(list *watchListCopy);

    /**
     * showList - виводить вміст списку
     */

    void showList() const;

    /**
     * sorting - сортує список відповідно до вхідних параметрів
     * @param way - напрямок сортування
     * @param criterion - критерій сортування
     */

    void sorting(char way, int criterion);

    /**
     * find - знаходить ланку відповідно до критеріїв
     * @param criterion - критерій пошуку
     * @return Вектор необхідної ланки
     */

    vector<watch *> find(int criterion) const;

    /**
     * readFromFile - зчитує данні з файлу
     * @param path - шлях до файлу з якого необхідно зчитати данні
     */

    void readFromFile(const string &path);

    /**
     * writeToFile - записує данні до файлу
     * @param path - шлях до файлу в який необхідно записати данні
     */

    void writeToFile(const string &path);
};


#endif //RGZ_CONTROLLER_H
