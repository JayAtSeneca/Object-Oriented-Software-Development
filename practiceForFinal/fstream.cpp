#ifndef SHAPE_H
 #define SHAPE_H
 // Multiple Inheritance - Shape
 // Shape.h

 class Shape {
   public:
     virtual double volume()
      const = 0; 
 };
 #endif

#ifndef EMITTER_H
 #define EMITTER_H
 // Multiple Inheritance - Emitter
 // Emitter.h

 typedef unsigned long int ulong;

 class Emitter {
   public:
     virtual ulong emission()
      const = 0; 
 };
 #endif