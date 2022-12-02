
// Умный динамический массив
//1.	Добавлять элемент в конец.              .append
//2.	Выдавать текущее количество элементов.  .length
//3.	Выдавать элемент по индексу.            .value 
//4.	Изменять элемент по индексу.            .change
//5.	Удалять элемент по индексу.             .remove
//6.	Вставлять элемент по индексу.           .add   
//

#include <iostream>

using namespace std;

class clevermass {
private:
    int mass_length = 0;
    int* mass = new int[mass_length];

public:
    clevermass() {
        cout << "Mass initiated\n";
    };

    ~clevermass() {
        cout << "\nDestroyed\n";
        delete[] mass;
    };

    void add(int index, int value) {
        if (index < 0) {
            cout << "Negative Index!\n";
        }
        else {
            if (index > mass_length) {
                int new_mass_length = mass_length;
                mass_length = index + 1;
                int* tmp = new int[mass_length];

                memcpy(tmp, mass, new_mass_length * 4);
                tmp[index] = value;

                delete[] mass;
                mass = tmp;
            }
            else {
                mass_length = mass_length + 1;
                int* tmp = new int[mass_length];

                memcpy(tmp, mass, index * 4);
                memcpy(tmp + index + 1, mass + index, (mass_length - index) * 4);
                tmp[index] = value;

                delete[] mass;
                mass = tmp;
            }
        }
    };
    void append(int value) {
        mass_length += 1;
        int* tmp = new int[mass_length];

        memcpy(tmp, mass, (mass_length - 1) * 4);
        tmp[mass_length - 1] = value;

        delete[] mass;
        mass = tmp;
    };

    int length() {
        return mass_length;
    };

    int value(int index) {
        if (index < 0) {
            cout << "Negative Index!\n";
            /*std::cout.setstate(std::ios_base::badbit);
            std::cout.clear(ios_base::goodbit);*/
        }
        else if (index > mass_length) {
            cout << "Out of range! " << "mass length - " << mass_length << endl;
        }
        else {
            return mass[index];
        }
    };

    void change(int index, int value) {
        if (index < 0) {
            cout << "Negative Index!\n";
        }
        else if (index > mass_length) {
            cout << "Out of range! " << "mass length - " << mass_length << endl;
        }
        else {
            mass[index] = value;
        }
    };

    void remove(int index) {
        if (index < 0) {
            cout << "Negative Value!\n";
        }
        else if (index > mass_length) {
            cout << "Out of range! " << "mass length - " << mass_length << endl;
        }
        else {
            int* tmp = new int[mass_length - 1];

            memcpy(tmp, mass, index * 4);
            memcpy(tmp + index, mass + index + 1, (mass_length - index - 1) * 4);

            mass_length -= 1;

            delete[] mass;
            mass = tmp;
        }
    };

    
};

int main()
{
    clevermass mas;
    cout << mas.length() << endl;
    mas.append(22);
    mas.append(33);
    mas.append(55);
    mas.append(99);
    cout << mas.length() << endl;
    cout << mas.value(0) << endl;

    for (int i = 0;i<mas.length(); i++)
    {
        cout << mas.value(i) << endl;
    }
    cout << "\n\n";
    mas.add(6, 333);
    for (int i = 0; i < mas.length(); i++)
    {
        cout << mas.value(i) << endl;
    }
    cout << "\n\n";
    mas.remove(5);
    mas.change(4, 666);
    for (int i = 0; i < mas.length(); i++)
    {
        cout << mas.value(i) << endl;
    }
    cout << mas.value(-6);
    cout << mas.value(-68);
}