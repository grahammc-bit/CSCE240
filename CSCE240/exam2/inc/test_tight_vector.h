/* Copyright 2020 CSCE 240
 */


#include <inc/tight_vector.h>
#include <cassert>
// using assert
#include <cstdlib>
// using atoi
#include <iostream>


class TightVectorTester {
 public:
  /* tests for TightVector::Append both empty and with elements
   */
  bool TestAppendEmpty();
  bool TestAppendNotEmpty();
  
  /* tests for TightVector::Prepend both empty and with elements
   */
  bool TestPrependEmpty();
  bool TestPrependNotEmpty();

};
