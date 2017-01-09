#include <QCoreApplication>
#include <tree.h>
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    tree t;
    t.add_word("first", "NIS");
    t.add_word("firsts", "NIP");
    t.add_word("second", "CHIS");
    t.add_word("third", "CHJP");
    t.add_word("sekird", "haha");
    QVector<std::string> answer = t.get_characteristics("sekird");
    if(!answer.size() || answer[0] == "Empty")
    {
        std::cout<<"I dont't know this word";
    }
    else
    {
        for(int i = 0; i < answer.size(); ++i)
        {
            std::cout<<answer[i];
        }
    }

    return a.exec();
}
