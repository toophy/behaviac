#pragma once

#include <iostream>     
#include <string>     
#include <fstream>     
#include <windows.h> 
#include <chrono>
#include <ctime>  


int Rand_int(int nMin, int nMax);

int Rand_int_mirror(int nMin, int nMax);




std::string GBKToUTF8(std::string& strGBK);

std::string UTF8ToGBK(const std::string& strUTF8);


