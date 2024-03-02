#pragma once
#include "Student_Stoler.h"

class Starosta_Stoler : public Student_Stoler
{
protected:
    double rating;
    int phone_number;
public:
    DECLARE_SERIAL(Starosta_Stoler)
    Starosta_Stoler();
    virtual ~Starosta_Stoler();
    void Serialize(CArchive& ar) override;
    void StrLen(int* aLen, CDC* pDC) override;
    void CDCDrow(CDC* pDC, int* aLeft, int& top, int lineHeight);

};