/*
7.a: psudocode
Start
Declare an double variable `radius`.
Declare an double variable `height`.

function 'cylinder volume'
pass in: radius
pass in: height
pass out: pi * radius * radius * height
Endfunction

function 'sphere volume'
pass in: radius
pass out: (4/3) * pi * radius * radius * radius
end

7.b: inputs
r = 1, h = 2, output = 2pi
r = 2, h = 1, output = 4pi

r = 2, output = 8pi
r = 4, output = 64pi
*/
// 7.c: asserts, 7.d: code
#include <iostream>
#include <cmath>
#include <cassert>

double calculateCylindricalVolume(double radius, double height) {
    return M_PI * radius * radius * height;
}

double calculateSphericalVolume(double radius) {
    return (4/3) * M_PI * radius * radius * radius;
}

int main(){
    assert(calculateCylindricalVolume(1,2) == 2*M_PI);
    assert(calculateCylindricalVolume(2,1) == 4*M_PI);
    assert(calculateSphericalVolume(2) == 8*M_PI);
    assert(calculateSphericalVolume(4) == 64*M_PI);
}

