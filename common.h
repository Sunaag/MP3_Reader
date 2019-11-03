#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

bool check_if_mp3(char *str);
int get_tag(char *file_name);
unsigned int reverse_byte(void * val);

#define ID3v3_0 1
#define ID3v3_1 2
#define ID3v3_2 3
#define ID3v2_0 4
#define ID3v2_1 5
#define ID3v2_2 6
#define ID3v1   7

#endif
