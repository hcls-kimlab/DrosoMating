#ifndef FLY_STATE_STATE_H
#define FLY_STATE_STATE_H
#include<opencv2/opencv.hpp>
#include <queue>
#include <iostream>
//using namespace cv;
using namespace std;

// 状态机：状态：无反应阶段 求偶缓冲阶段 求偶阶段 交配缓冲阶段 交配阶段 结束
class State {
public:
    int fly_state;
    int courtship_time;
    int courtship_time_10min;
    int mate_time;
    int buff_time1, buff_time2, buff_time3;
    int stop_time1, stop_time2;
    int average1_x, average1_y, average2_x, average2_y, num;
    int court_start, mate_start, mate_end;
    int threshold_num;
    int first_court;
    bool first_court1;
    int may_mate;
    float fps;
    void update_state(vector<cv::Point> p, int index);  // 修改这里
    void update_scale(float scale);
    void Trajectory(vector<cv::Point> p);  // 修改这里
    queue<cv::Point> fly1, fly2;  // 修改这里
    queue<cv::Point> av_center2, av_center1;  // 修改这里
    bool stop_judge(int num);  //判断果蝇是否移动
    bool matestop_judge(int num);
    int chasetimes = 0;
    int is_court;
    int size2_time;
    int size1_time;
    int once1, once2;
    int mate_from_start, mate_from_start_flag;
    int speed;
    float sca;
    State();
    void set_fps(float video_fps);

private:
    cv::Point fly1_now, fly2_now; //果蝇当前坐标  // 修改这里
    int fly_move;

    bool chase_judge();
    float dis(cv::Point p1, cv::Point p2);  // 修改这里
};


#endif //FLY_STATE_STATE_H
