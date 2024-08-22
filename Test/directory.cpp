#include "directory.h"
#include <iostream>
#include <algorithm>

void Directory::sortVector(vector<Empleado> empleados) {
    std::sort(empleados.begin(), empleados.end(), [](const Empleado& x, const Empleado& y) {
        return x.name < y.name;
    });
}

/*bool operator == (const Directory::Empleado object1, const Directory::Empleado object2) {
    if(object1.name == object2.name) {
        return true;
    }
    return false;
}*/

int Directory::searchByName(vector<Empleado> empleados, string inputName) {
    int low = 0;
    int high = empleados.size()-1;

    while (low <= high) {
        int mid = low + (high-low)/2;

        if(empleados[mid].name == inputName) {
            return mid;
        }
        if(empleados[mid].name <= inputName) {
            low = high + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}