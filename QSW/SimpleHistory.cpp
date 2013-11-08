#include "SimpleHistory.h"
#include "SWDefines.h"

/*template <class T>
SimpleHistory<T>::SimpleHistory()
{
    curr = data.end();
}*/

SimpleHistory::SimpleHistory()
{
    curr = data.end();
}

quint32 const& SimpleHistory::back()
{
    if (!currentValid())
        return (quint32)NULL;

    if (!canGoBack())
        return *curr;

    return *--curr;
}

quint32 const& SimpleHistory::forward()
{
    if (!currentValid())
        return (quint32)NULL;

    if (!canGoForward())
        return *curr;

    return *++curr;
}

void SimpleHistory::clear()
{
    data.clear();
    curr = data.end();
}

bool SimpleHistory::empty() const
{
    return data.empty();
}

quint32 const& SimpleHistory::current() const
{
    if (!currentValid())
        return (quint32)NULL;

    return *curr;
}

bool SimpleHistory::currentValid() const
{
    return !data.empty() && curr != data.end();
}

bool SimpleHistory::canGoForward() const
{
    if (!currentValid())
        return false;

    DataType::const_iterator itr = curr;
    return ++itr != data.end();
}

bool SimpleHistory::canGoBack() const
{
    if (!currentValid())
        return false;

    return curr != data.begin();
}

void SimpleHistory::addHistory(quint32 value)
{
    if (currentValid())
        data.erase(++curr, data.end());

    data.push_back(value);
    curr = --data.end();
}
