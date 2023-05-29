// 290523 part 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

//Solid
// S-single responsibility principle
// Если в классе всего 1 метод, то он соответствует букве  S
//class ClientServer {
//public:
//    void ShowClients(std::vector<Client*> clients) {
//        for (const auto& it : clients)
//            it->Pay();
//    }
//};

//O=open-closed principle
//ф-ция должна быть открыта для расширения но закрыта для модификации

class Animal {
private:
    std::string _type;
public:
    Animal(std::string type) :_type(type) {}
   /* std::string GetType() const {
        return _type;
    }*/
    virtual std::string GetSound() = 0;

};

class Cow : public Animal {
public:
    Cow() :Animal("Cow") {
    }
        std::string GetSound()  override {
        
            return "MYYYY";
        }
    
};
class Dog : public Animal {
public:
    Dog():Animal("Dog"){}
    std::string GetSound() override {
        return "Gav";
}
};
class Cat: public Animal {
public:
    Cat() :Animal("Cat") {}
    std::string GetSound() override {
        return "MRRRR";
    }
};



/*void AnimalSound(Animal& animal) {
    if (animal.GetType() == "Lion")
        std::cout << "RRRR";
    else if(animal.GetType()=="Dog")
        std::cout << "Gav";
    else if (animal.GetType() == "Cow")
        std::cout << "MYYYY";
    else if (animal.GetType() == "Cat")
        std::cout << "MR";
}*/

void AnimalSound(Animal& animal) {
    std::cout << animal.GetSound() <<"\n\n";
    
}

class Vector {
private:
    int _size;
    int* _massivptr;
public:
    Vector() {
        _size = 0;
        _massivptr = nullptr;
    }
    void Push_Back(int element) {
        _size++;
        int* newMassiv = new int[_size];
        if (_massivptr == nullptr) {
            newMassiv[0] = element;
            _massivptr = newMassiv;
            return;
        }
        for (int i = 0; i < _size - 1; i++)
            newMassiv[i] = _massivptr[i];
        newMassiv[_size - 1] = element;

        int* temp = _massivptr;
        _massivptr = newMassiv;
        delete[]temp;
        
    }

    void ShowElements() {
        for (int i = 0; i < _size; i++)
            std::cout << i << " elements: " << _massivptr[i] << '\n';
    }
};

int main()
{
    Cat* cat = new Cat();
    Cow* cow = new Cow();
    Dog* dog = new Dog();
    AnimalSound(*cat);
    AnimalSound(*cow);
    AnimalSound(*dog);

    Vector* vector = new Vector();
    vector->Push_Back(20);
    vector->Push_Back(35);
    vector->Push_Back(50);
    vector->Push_Back(15);
    vector->Push_Back(32);
    vector->ShowElements();



    return 0;
}



