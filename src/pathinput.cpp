#include "pathinput.h"
#include<windows.h>

using namespace std;

static string path_image = "";
static string file_name = "";


string mp4_file_path_choose()
{
    while (true) {
        cout << "Choose mp4 File: " << endl;
        path_image = get_path(file_name); // 获取文件路径和文件名

        if (path_image.empty()) {
            cout << "No file Chosen!!!" << endl;
            break; // 没有选择文件时退出循环
        }

        if (check_mp4_extension(file_name)) {
            break; // 文件是mp4时，输出并退出循环
        }
        else {
            cout << "ERROR, mp4 is needed!" << endl;
        }
    }

    return path_image;

}

string Lpcwstr2String(LPCWSTR lps)//实现文件路径转化为字符串
{
    int len = WideCharToMultiByte(CP_ACP, 0, lps, -1, NULL, 0, NULL, NULL);
    if (len <= 0)
    {
        return "";
    }
    else
    {
        char* dest = new char[len];
        WideCharToMultiByte(CP_ACP, 0, lps, -1, dest, len, NULL, NULL);
        dest[len - 1] = 0;
        string str(dest);
        delete[] dest;
        return str;
    }
}

string get_path(string& file_name)//打开文件对话框，选择文件之后以字符串形式返回，并传递文件名
{
    OPENFILENAME ofn;
    WCHAR szFile[300];
    WCHAR szFileTitle[300];
    ZeroMemory(&ofn, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = NULL;
    ofn.lpstrFile = szFile;
    ofn.lpstrFile[0] = '\0';
    ofn.nMaxFile = sizeof(szFile) / sizeof(WCHAR);
    ofn.lpstrFileTitle = szFileTitle;
    ofn.nMaxFileTitle = sizeof(szFileTitle) / sizeof(WCHAR);
    ofn.lpstrFilter = L"ALL\0*.*\0Text\0*.TXT\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrInitialDir = NULL;
    ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
    string path_image = "";

    if (GetOpenFileName(&ofn))
    {
        path_image = Lpcwstr2String(ofn.lpstrFile); // 文件路径转化为字符串
        file_name = Lpcwstr2String(ofn.lpstrFileTitle); // 获取文件名
        return path_image;
    }
    else
    {
        return "";
    }
}

bool check_mp4_extension(const string& file_name) // 检查文件后缀是否为mp4
{
    if (file_name.length() >= 4 && file_name.substr(file_name.length() - 4) == ".mp4")
    {
        return true;
    }
    return false;
}

string get_filename_without_extension(const string& path_image) // 通过路径获取不带后缀的文件名
{
    size_t last_slash = path_image.find_last_of("\\/");
    size_t last_dot = path_image.find_last_of(".");

    // 如果路径中存在文件名，且存在扩展名，则提取不带后缀的文件名
    if (last_slash != string::npos && last_dot != string::npos && last_dot > last_slash)
    {
        return path_image.substr(last_slash + 1, last_dot - last_slash - 1);
    }

    // 如果没有找到扩展名，返回路径中的文件名部分
    if (last_slash != string::npos)
    {
        return path_image.substr(last_slash + 1);
    }

    // 返回路径本身
    return path_image;
}