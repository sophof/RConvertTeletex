#include <Rcpp.h>
using namespace Rcpp;

void convert(unsigned char*, unsigned char*);
void umlaut(unsigned char*, unsigned char*);
void grave(unsigned char*, unsigned char*);
void dot(unsigned char*, unsigned char*);

// [[Rcpp::export]]
RawVector convertTeletex(RawVector x) {
  int end = x.size();
  int i = 0;
  while(i < end){
    if (x[i] < 0xC0) i++;
    else {
      convert(&x[i], &x[i+1]);
      i++; i++;
    }
  }
  return x;
}

void convert(unsigned char* start, unsigned char *end){
  switch(*start)
  {
  case 0xc1 : grave(start, end); break;
  case 0xc7 : dot(start, end); break;
  case 0xC8 : umlaut(start, end); break;
  }
}

void umlaut(unsigned char* a, unsigned char* b){
  *a = 0xC3;
  switch(*b){
  case 0x61 : *b = 0xA4; break;//a
  case 0x65 : *b = 0xAB; break;//e
  }
}

void grave(unsigned char* a, unsigned char* b){
  *a = 0xC3;
  switch(*b){
  case 0x61 : *b = 0xA0; break;// a
  case 0x65 : *b = 0xA8; break;// e
  }
}

void dot(unsigned char* a, unsigned char* b){
  switch(*b){
  case 0x65 : *a = 0xC4; *b = 0x97; break;// e
  }
}
