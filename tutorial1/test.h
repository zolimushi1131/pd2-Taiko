#ifndef TEST_H
#define TEST_H

#include <QObject>

class create: public QObject
{
    Q_OBJECT
public:
    create();
public slots:
    randombits();

};

#endif // TEST_H

