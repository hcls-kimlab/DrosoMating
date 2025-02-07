#include<opencv2/opencv.hpp>
#include "state.h"
#include <fstream>
#include "board.h"
#include "pathinput.h"

//using namespace cv;
using namespace std;
int main() {
    string file_name = "";
    string path_image = mp4_file_path_choose();
    string file_name_no_ext = get_filename_without_extension(path_image); // 获取不带后缀的文件名
    cout << "File Path: " << path_image << endl;
    cout << "File Name: " << file_name_no_ext << endl;

    board bo[4];
    //cv::VideoWriter writer("output.avi", cv::CAP_OPENCV_MJPEG, 30.0, cv::Size(155 * 6, 270));
    cv::VideoCapture video(path_image);
    float fps = (float)video.get(cv::CAP_PROP_FPS);
    double all_length = video.get(cv::CAP_PROP_FRAME_COUNT);
    int index, i, board_num;
    int write = 0;
    int speed = 4;

    //mihao

    for (index = 0; index < 4; index++) {  // 初始化帧率
        for (i = 0; i < 37; i++)
            bo[index].flies[i].set_fps(fps);
        bo[index].fps = fps;
        bo[index].set_speed(speed);
    }

    cv::Mat dst, src, gray;
    bool resize_flag = false;
    int video_count = 0;
    cv::Mat M, tempsrc;
    cv::Mat mid;
    video >> mid;
    cv::Size dsize;
    if (!(mid.rows == 1280 || mid.cols == 1280)) // 1080p 就不用 resize 了
        resize_flag = true;
    if (mid.rows > mid.cols)
        dsize = cv::Size(int(mid.cols * 1280 / mid.rows), 1280);
    else
        dsize = cv::Size(1280, int(mid.rows * 1280 / mid.cols));
    if (resize_flag)
        cv::resize(mid, src, dsize);
    else
        src = mid.clone();
    cout << src.size << endl;
    tempsrc = src.clone();
    cout << "input the num of board" << endl;   // 有几块板
    cin >> board_num;
    //cout << "choose write the video num" << endl; // 选择输出哪块板子的视频，输入 0 就是不输出视频
    //cin >> write;
    cout << "Select processing speed - every few frames (4): " << endl; // 选择输出哪块板子的视频，输入 0 就是不输出视频
    cin >> speed;
    for (index = 0; index < board_num; index++) {
        bo[index].get_point(src);  // 用鼠标点四个柱子
        bo[index].reset_matcher();  // 初始化模板匹配
        bo[index].reset_threshold();
        bo[index].adjust_lines();  // 调整网格
    }

    while (video_count < (all_length)) {
        video >> mid;
        if (mid.empty())
            break;
        if (resize_flag)
            cv::resize(mid, src, dsize);
        else
            src = mid.clone();
        video_count++;
        if (video_count == static_cast<int>(10 * 60 * fps))
        {
            for (index = 0; index < board_num; index++) {
                for (int i = 0; i < 37; i++)
                    bo[index].flies[i].courtship_time_10min = bo[index].flies[i].courtship_time;
            }
        }
        if (video_count % speed != 0)
            continue;
        for (index = 0; index < board_num; index++) {
            bo[index].state(src, video_count);  // 状态更新
            string text = "ouput" + to_string(index);
            //cv::imshow(text, bo[index].dst);
            if (write)
                text = "ouput" + to_string(index) + ".avi";
            //if (index == write - 1)
                //writer << bo[index].dst;
            cv::waitKey(1);
        }
        cout << "done=" << video_count / (all_length) * 100 << "%" << endl;
    }
    for (index = 0; index < board_num; index++) {
        for (int i = 0; i < 37; i++)
            if (bo[index].flies[i].fly_state == 3)
                bo[index].flies[i].mate_time = -999999;
        bo[index].csv_output(index, file_name_no_ext); // 输出板子对应的结果
    }
    return 0;
}