#pragma once
#include "Student_Stoler.h"

class d1;
class d2;

class Starosta_Stoler : public Student_Stoler
{  
public:
    double rating;
    int phone_number;

    DECLARE_SERIAL(Starosta_Stoler)
    
    Starosta_Stoler();
    virtual ~Starosta_Stoler();
    void Serialize(CArchive& ar) override;
    void StrLen(int* aLen, CDC* pDC) override;
    void CDCDrow(CDC* pDC, int* aLeft, int& top, int lineHeight);
    void listb(d1* d);
    void addcap(d2* d);
    void change1(d2* d);
    void update1(d2* d);
};