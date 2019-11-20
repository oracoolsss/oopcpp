//
// Created by oracool on 27.10.2019.
//

#include "tritset.h"
#include <cmath>
#include <algorithm>
#define TRITSINUINT 4

using namespace std;

Tritset::Tritset(int capacity) {
    tritset_.clear();
    uint8_t newTrit = 0;
    for (int i = 0; i < uint8_t (floor(double(capacity)/double(TRITSINUINT))); ++i) {
        tritset_.push_back(newTrit);
    }
}

int Tritset::capacity() {
    return tritset_.size()*TRITSINUINT;
}

Trit Tritset::operator [] (int index) const {
    int tritSubSet = int((floor(double(index)/double(TRITSINUINT))));
    index -= (index/TRITSINUINT)*TRITSINUINT - 1;

    uint8_t retValue = tritset_[tritSubSet]>>(2*(index));
    if(retValue == 0) {
        return FALSE;
    }
    else if (retValue == 2) {
        return TRUE;
    }
    else {
        return UNKNOW;
    }
}

TritSetReference Tritset::operator [] (const int index) {
    return TritSetReference(this, index);
}

Tritset &Tritset::operator = (const Tritset &tritset) {
    this->tritset_.clear();
    this->tritset_ = tritset.tritset_;
    return *this;
}

Trit operator & (Trit trit1, Trit trit2) {
    if(trit1 == TRUE && trit2 == TRUE) {
        return TRUE;
    }
    else if(trit1 == FALSE || trit2 == FALSE) {
        return FALSE;
    }
    else {
        return UNKNOW;
    }
}

Trit operator | (Trit trit1, Trit trit2) {
    if(trit1 == FALSE && trit2 == FALSE) {
        return FALSE;
    }
    else if(trit1 == TRUE || trit2 == TRUE) {
        return TRUE;
    }
    else {
        return UNKNOW;
    }
}

Trit operator ! (Trit trit) {
    if(trit == FALSE) {
        return TRUE;
    }
    else if(trit == TRUE) {
        return FALSE;
    }
    else {
        return UNKNOW;
    }
}

TritSetReference::TritSetReference(Tritset *trits, int ind) {
    tritset_ = trits;
    index_ = ind;
}

Tritset operator & (Tritset& tritset1, Tritset& tritset2) {
    int maxCapacity = max(tritset1.capacity(), tritset2.capacity());

}