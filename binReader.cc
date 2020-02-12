/*
 * Kristina
 * binReader.cc
 * Description: parses the binary file and fills the map
 * 
 */


 #include <iostream>
 #include <string>
 #include <map> 
 #include <stdio.h>
 #include <stdint.h>
 #include <stdlib.h>
 #include <bits/stdc++.h>
 #include <fstream>
 #include <iomanip>
 #include "binReader.h"
 #include <sstream>
 
 using namespace std;
 //max size of stringBuffer
// const int maxStr=20;
 //declare the map to fill after reading binary file
 map<int,string> binMap;
 
 
 void binParser(){ 
   //instantiate header and record class
   Header *header= new Header();
   Record record;//= new Record();
   //Record *record= new Record();
   //read the binary file
   fstream binFile("cs3377.bin",ios::in | ios::binary );
   binFile.read((char*)header, sizeof(Header));
   
   /*start parsing the bin file*/
   //get magic
   char *magicStr= new char[10];
   uint32_t magicInt=header->magicNumber;//get the magic number
   sprintf(magicStr,"%X",magicInt);//get it in hex format
   char *magicHexStr= new char[sizeof(magicStr)];
   strcpy(magicHexStr,magicStr);
   string strMagic(magicHexStr);
   //get version
   int versionNumber=header->versionNumber;
   stringstream ss1;//convert int to char*
   ss1<<versionNumber;
   //get numRecords
   int numRecords=header->numRecords;
   stringstream ss2;//convert int to char*
   ss2<<numRecords;
   
   //declare array of records to hold all the individual
   Record rA[20];
   //get all records
   int nRec=numRecords;
 
  
   binMap[1]="Magic: Ox"+strMagic;
   binMap[2]="Version: "+ss1.str();
   binMap[3]="NumRecords: "+ss2.str();
   //sart filling rest of map
 for(int i=0;i<nRec;i++){
     binFile.read((char*)&record, sizeof(Record));
     rA[i]=record;
     //binFile.read((char*)record, sizeof(Record));
     //rA[i]=*record;
   }
   int mapIndx=4;//start filling from fourth index
   for(int i=0;i<(nRec*2);i++){
     int sLength=rA[i].strLength;//grt the strlen
        stringstream ss3;//convert int to char*
        ss3<<sLength;
        binMap[mapIndx++]="strlen: "+ss3.str();
        
        char *sBuff=rA[i].stringBuffer;
        binMap[mapIndx++]=sBuff;
        
          
   }
   

 }

 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
