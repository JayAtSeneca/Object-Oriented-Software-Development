// Multiple Inheritance - Cube
 // Cube.cpp

 #include "Cube.h"

 Cube::Cube(double l) : len(l) {} 

 double Cube::volume() const {
     return len * len * len;
 }

// Multiple Inheritance - LitObj
 // LitObj.cpp

 #include "LitObj.h"

 LitObj::LitObj(ulong c) :
  color(c) {} 

 ulong LitObj::emission() const {
     return color;
 }