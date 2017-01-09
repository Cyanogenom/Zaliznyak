#ifndef TREE_H
#define TREE_H

#include "letter.h"
#include <string.h>

class tree
{
private:
    QHash<char, treeElement*> mconnects;
public:
    void add_word(std::string word, std::string characteristic)
    {
        int i = word.length()-1;
        treeElement *curr_el = mconnects.value(word[i]);
        if(curr_el)
        {
            i--;
            treeElement *prev_el = nullptr;
            while(i >= 0 && curr_el)
            {
                prev_el = curr_el;
                curr_el = curr_el->get_next_letter(word[i--]);
            }
            curr_el = prev_el;
            i++;
        }
        else
        {
            treeElement *w = new treeElement(word[i]);
            mconnects.insert(word[i--], w);
            curr_el = w;
        }
        for(int j = i; j >= 0; --j)
        {
            treeElement *w = new treeElement(word[j], curr_el);
            curr_el->add_connect(w);
            curr_el = w;
        }
        curr_el->set_characteristic(characteristic);
    }
    QVector<std::string> get_characteristics(std::string word)
    {
        int i = word.length()-1;
        treeElement *curr_el = mconnects.value(word[i]);
        QVector<std::string> answer;
        while(i >= 0 && curr_el)
        {
            answer = curr_el->get_characteristic();
            i--;
            curr_el = curr_el->get_next_letter(word[i]);
        }
        return answer;
    }
};

#endif // TREE_H
