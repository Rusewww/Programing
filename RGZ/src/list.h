/**
 * @file list.h
 * @brief Файл класу списку
 *
 * @author Zoulia I.
 * @date 20-may-2021
 * @version 1.0
 */

#include "watch.h"

#ifndef RGZ_LIST_H
#define RGZ_LIST_H

/**
 * list - клас списку
 */

class list {
private:
    vector<watch *> watches;
    int count{};
public:

    /**
     * Конструктор класу list за замовчуванням
     */

    list();

    /**
     * Конструктор класу list який копіює данні з іншого об’єкту
     * @param clone - об’єкт з якого копіюються данні
     */

    list(const list &clone);

    /**
     * Деструктор класу list
     */

    ~list();

    /**
     * setCount - сеттетер класу list, який записує данні у поле count
     * @param countCopy -  данні які будуть записані у поле count
     */

    void setCount(int countCopy);

    /**
     * getCount - гетер класу manufacturerStruct
     * @return Вміст поля count.
     */

    int getCount() const;

    /**
     * addLink - додає ланку до списку
     * @param watchLink - ланка яка буде додана до списку
     */

    void addLink(watch *watchLink);

    /**
     * getList - гетер класу list
     * @return Повертає вектор списку
     */

    vector<watch*> getList() const;

    /**
     * getLink - гетер класу list
     * @param index - позиція ланки
     * @return Ланку зі списку
     */

    watch *getLink(int index);

    /**
     * clearLink - видаляє ланку за індексом
     * @param index - позиція ланки
     */

    void deleteLink(int index);

    /**
     * clearList - видаляє увесь список
     */

    void clearList();

    /**
     * setLinks - копіює ланки з вектору до списку
     * @param watchesCopy - вектор з якого будуть копіюватись ланки
     */

    void setLinks(const vector<watch *>& watchesCopy);
};

#endif //RGZ_LIST_H
