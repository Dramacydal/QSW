#ifndef SIMPLEHISTORY_H
#define SIMPLEHISTORY_H

#include <list>
#include <QtGlobal>

class SimpleHistory
{
    typedef std::list<quint32> DataType;

public:
    SimpleHistory();

    quint32 const& back();
    quint32 const& forward();

    void clear();
    bool empty() const;
    quint32 const& current() const;

    bool currentValid() const;
    bool canGoForward() const;
    bool canGoBack() const;

    void addHistory(quint32 value);

private:
    /*typename*/ DataType::const_iterator curr;
    DataType data;
};

#endif // SIMPLEHISTORY_H
