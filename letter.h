#ifndef LETTER_H
#define LETTER_H

#include <QHash>
#include <string>
#include <QVector>

class treeElement
{
private:
    char letter;
    treeElement *prev;
    QHash<char, treeElement*> connects;
    QVector<std::string> characteristic;
public:
    treeElement()
    {
        prev = nullptr;
        characteristic.append("Empty");
    }
    treeElement(const char &letter, treeElement *prev = nullptr, std::string characterictic = "Empty")
    {
        this->letter = letter;
        this->prev = prev;
        set_characteristic(characterictic);
    }
    void set_letter(const char &l)
    {
        letter = l;
    }
    char get_letter() const
    {
        return letter;
    }
    void set_prev(treeElement *p)
    {
        prev = p;
    }
    treeElement* get_prev_letter()
    {
        return prev;
    }
    void set_characteristic(const std::string &c)
    {
        if(characteristic.size() == 1 && characteristic[0] == "Empty")
        {
            characteristic.pop_front();
        }
        unsigned int i = 0;
        while(i < characteristic.size() && c != characteristic[i])
        {
            i++;
        }
        if(i == characteristic.size())
        {
            characteristic.append(c);
        }
    }
    QVector<std::string> get_characteristic()
    {
        return characteristic;
    }
    void add_connect(treeElement *el)
    {
        connects.insert(el->get_letter(), el);
    }
    treeElement* get_next_letter(const char &c)
    {
        return connects.value(c);
    }
};

#endif // LETTER_H
