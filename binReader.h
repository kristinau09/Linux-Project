/*
 * Filename:    binReader.h
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
  
  
