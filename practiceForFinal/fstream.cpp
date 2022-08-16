// Multiple Inheritance - Cube
 // Cube.h

 #include "Shape.h"

 class Cube : public Shape {
     double len;
 public:
     Cube(double);
     double volume() const;
 };

 // Multiple Inheritance - LitObj
 // LitObj.h

 #include "Emitter.h"

 class LitObj : public Emitter {
     ulong color;
 public:
     LitObj(ulong c);
     ulong emission() const; 
 };