#include <iostream>
#include <vector>

using std::ostream;
using std::cout;
using std::endl;
using std::vector;

/**
 * @brief TyperErased Method
 *
 */
class TypeErasedLivingThing {
private:
    int i;

public:

    TypeErasedLivingThing(int i) :
    i(i){

    }

    template <typename T>
    TypeErasedLivingThing(T t) :
    TypeErasedLivingThing(MakeTypeErased(t)){

    }

    bool operator==(const TypeErasedLivingThing& other ){
        return i == other.i ;
    }

    friend ostream& operator<<(ostream& os, const TypeErasedLivingThing& t){
        os << "TypeErasedLivingThing(" << t.i  <<")\n";
        return os;
    }

    void print(){
         cout << "TypeErasedLivingThing(" << i  <<")\n";
    }
};

enum class fruit : int {
    APPLE,
    ORANGE,
    MANGO
};


enum class animal : int {
    CAT,
    DOG,
    HORSE
};


TypeErasedLivingThing MakeTypeErased(fruit f ){
    return TypeErasedLivingThing(static_cast<int>(f));
}

TypeErasedLivingThing MakeTypeErased(animal a ){
    return TypeErasedLivingThing(static_cast<int>(a));
}

/**
 * @brief Inheritance Method
 *
 */
class LivingThing {
private:
    int i;
public:
    LivingThing(int i):
    i(i){

    }
    bool operator==(const LivingThing& other ){
        return i == other.i ;
    }
};

class Fruit: public LivingThing {
    int i;
public:
    Fruit(int i):
    i(i), LivingThing(i){

    }
};

class Animal: public LivingThing{
    int i;
public:
    Animal(int i):
    i(i), LivingThing(i){

    }
};

int main()
{
    // type erased example
    fruit f = fruit::MANGO;
    TypeErasedLivingThing t (f);
    cout << t;

    animal a = animal::DOG;
    TypeErasedLivingThing t2 (a);
    cout << t2;

    cout << (t == t2) <<endl;

    //inheritance
    Animal A(static_cast<int>(animal::DOG));
    Animal A2(static_cast<int>(animal::DOG));
    Fruit F(static_cast<int>(fruit::MANGO));

    vector<LivingThing> l_vec = {A2, F};
    for (auto l : l_vec) {
        if (l == A){
            cout << "found the dog!" << endl;
        }
    }

    return 0;
}
