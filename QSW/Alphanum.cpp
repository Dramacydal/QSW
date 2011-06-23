/**
 * \file alphanum.cpp
 * \brief Description
 */



#include "Alphanum.h"

/*!
 *    \fn    compare - ���������� ��� ������.
 *    \param    l - ������ �����.
 *    \param    r - ������ ������.
 *
 *    \return 
 *        l<r - ������������� ��������;
 *        l>r - ������������� ��������;
 *        l=r - ����.
 */
int compare(QString l, QString r)
{
    enum Mode{STRING, NUMBER} mode = STRING;
    int size;
    if (l.size() < r.size())
        size = l.size();
    else
        size = r.size();

    int i = 0;
    
    // ����� �� ����� �������� � ����� �� ������� "size-1"
    while(i < size){
        if (mode == STRING){
            QChar lchar, rchar;
            bool ldigit, rdigit;
            while(i < size){
                lchar = l.at(i);
                rchar = r.at(i);
                ldigit = lchar.isDigit();
                rdigit = rchar.isDigit();
                // ���� ��� ������� �������� �������, �� ��������� � ����� �����
                if (ldigit && rdigit){
                    mode = NUMBER;
                    break;
                }
                if (ldigit) return -1;
                if (rdigit) return +1;
                // ��� ������� - �����
                if (lchar < rchar) return -1;
                if (lchar > rchar) return +1;
                // ��� ������� ����� ���� �����
                i++;
            }
        }else{//mode == NUMBER
            unsigned long long lnum = 0, rnum = 0;
            int li = i, ri = i; // ��������� �������
            int ld = 0, rd = 0; // �����
            
            // �������� ����� �����
            while(li < l.size()){
                ld = l.at(li).digitValue();
                if (ld < 0 ) break;
                lnum = lnum*10 + ld;
                li++;
            }
            
            // �������� ������ �����
            while(ri < r.size()){
                rd = r.at(ri).digitValue();
                if (rd < 0 ) break;
                rnum = rnum*10 + rd;
                ri++;
            }
            
            long long delta = lnum - rnum;
            if (delta) return delta;
            
            // ����� ���������
            mode = STRING;
            if (li <= ri)
                i=li;
            else
                i=ri;
        }
    }
    // ���� ������ ���� ��� ������ �� ������� "size-1" ���������
    if (i < r.size()) return -1;
    if (i < l.size()) return +1;
    
    // ��� ����� ��������� ���������
    return 0;    
}