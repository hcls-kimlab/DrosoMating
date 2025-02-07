#ifndef PATHINPUT_H
#define PATHINPUT_H

#include <windows.h>  // Windows API
#include <string>     // String class
#include<iostream>

using namespace std;

string mp4_file_path_choose();
string get_path(string& fileName);
bool check_mp4_extension(const string& fileName);
string get_filename_without_extension(const string& fileName);
string Lpcwstr2String(LPCWSTR lps);

#endif // PATHINPUT_H
