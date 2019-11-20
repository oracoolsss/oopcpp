//
// Created by oracool on 27.10.2019.
//

#ifndef LAB1_TRITSET_H
#define LAB1_TRITSET_H


#include <vector>
#include <cstdint>

namespace std {
    enum Trit{
        FALSE, UNKNOW, TRUE
    };

    class Tritset;

    class TritSetReference {
    private:
        Tritset* tritset_;
        int index_;

    public:
        TritSetReference(Tritset* trits, int ind);

        friend class Tritset;
    };

    class Tritset {
    private:
        vector<uint8_t> tritset_;
    public:
        Tritset(int capacity);
        int capacity();
        //Trit& operator []();

        Trit operator [](int index) const;
        TritSetReference operator[](const int index);
        Tritset& operator = (const Tritset& tritset);

        Tritset& operator&=(const Tritset& other);

        friend class TritSetReference;
    };

    Tritset operator & (Tritset& tritset1, Tritset& tritset2);
    Tritset operator | (Tritset& tritset1, Tritset& tritset2);


    Trit operator & (Trit trit1, Trit trit2);
    Trit operator | (Trit trit1, Trit trit2);
    Trit operator ! (Trit trit);
}



#endif //LAB1_TRITSET_H
