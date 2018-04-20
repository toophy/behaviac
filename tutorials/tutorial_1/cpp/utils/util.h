#pragma once

#include <iostream>     
#include <string>     
#include <fstream>     
#include <windows.h> 

std::string GBKToUTF8(std::string& strGBK);

std::string UTF8ToGBK(const std::string& strUTF8);