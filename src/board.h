//
// Created by jf on 2021/9/30.
//

#ifndef FLY_STATE_NEW_BOARD_H
#define FLY_STATE_NEW_BOARD_H
#include <opencv2/opencv.hpp>
#include "state.h"
#include <fstream>
using namespace std;

struct callbackP {
    cv::Mat src;                 // Use cv::Mat for OpenCV matrix
    int clickTimes = 0;         // Number of clicks on the image
    vector<cv::Point2f> srcTri; // Vector of source triangle points
};

class board {
public:
    board();
    cv::Mat img;                   // Use cv::Mat for OpenCV matrix
    vector<cv::Mat> matchimg;     // Vector of matched images
    vector<cv::Point> matchcenter; // Vector of match centers
    State flies[37];              // Array of fly states
    vector<cv::Point> P[37];      // Vector of points for each fly
    vector<cv::Point2f> dstTri;    // Destination triangle points
    float scale[37];              // Scale factors for each fly

    void get_point(cv::Mat& img); // Function to get points
    void adjust_lines();           // Function to adjust lines
    void reset_matcher();         // Function to reset matcher
    void reset_threshold();        // Function to reset threshold
    void state(cv::Mat& img, int time); // Function to update the state
    void csv_output(int pos, string file_name_no_ext);      // Function to output to CSV
    void set_speed(int speed);     // Function to set speed
    float fps;                    // Frames per second
    cv::Mat dst, M;               // Destination and transformation matrices

private:
    callbackP utsc;               // Callback structure for first state
    callbackP utsc1;              // Callback structure for second state
    int set_threshold;            // Threshold value
    int length = 155 * 6;        // Length for processing
    int height = 45 * 6;         // Height for processing
    char key;                    // Key for input
};

#endif //FLY_STATE_NEW_BOARD_H
