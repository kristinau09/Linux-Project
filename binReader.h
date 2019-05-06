/*
 * Filename        binReader.h
 * Date            05/04/2019
 * Author          Kristina Upadhaya
 * Email           kxu160730@utdallas.edu
 * Course          CS 3377.502
 * Version         1.0
 * Copyright 2019, All Rights Reserved
 * 
 * Description: header file
 * 
 */

   #include <map>
   #include <string>
   #include <stdlib.h>
   #include <bits/stdc++.h>
   #include <stdint.h>
   using namespace std;
    const int maxStr=25;
    extern map<int,string> binMap;
    void binParser(); 
 
 
   class Header
   {
    public:
   
    uint32_t magicNumber; /*Should be OxFEEDFACE */
    uint32_t versionNumber;
    uint64_t numRecords;
   };

  class Record
  {
    public:
  
    uint8_t strLength;
    char stringBuffer[maxStr];
  };
  
  
