#include "board.h"
int s1 = 15, s2 = 15;
int diffx = 0;
int diffy = 0;
int ss_threshold;
int x[15], y[4];
cv::Mat image;  // Added cv:: prefix

board::board() {
    dstTri.emplace_back(cv::Point2f(0, 0));
    dstTri.emplace_back(cv::Point2f(length, 0));
    dstTri.emplace_back(cv::Point2f(length, height));
    dstTri.emplace_back(cv::Point2f(0, height));
}

void trackBar(int, void*)
{
    diffx = s1 - 15;
    diffy = s2 - 15;
    x[0] = 0;
    y[0] = 36;
    for (int i = 1; i < 5; i++)
        x[i] = x[i - 1] + 66;
    x[5] = 333;
    for (int i = 6; i < 10; i++)
        x[i] = x[i - 1] + 66;
    x[10] = 666;
    for (int i = 11; i < 15; i++)
        x[i] = x[i - 1] + 66;
    for (int i = 1; i < 4; i++)
        y[i] = y[i - 1] + 66;
    for (int i = 1; i < 15; i++)
        x[i] += diffx;
    for (int i = 0; i < 4; i++)
        y[i] += diffy;

    cv::Mat img2;  // Added cv:: prefix
    img2 = image.clone();

    cv::Mat img_gray, img_black;  // Added cv:: prefix
    //    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
    std::vector<std::vector<cv::Point>> contours;  // Added cv:: prefix
    std::vector<cv::Vec4i> hierarchy;  // Added cv:: prefix

    img2 = image.clone();
    cv::cvtColor(image, img_gray, cv::COLOR_RGB2GRAY);  // Added cv:: prefix
    cv::medianBlur(img_gray, img_gray, 3);  // Added cv:: prefix
    cv::threshold(img_gray, img_black, ss_threshold, 255, cv::THRESH_BINARY);  // Added cv:: prefix
    //    cv::dilate(img_black, img_black, kernel);
    cv::findContours(img_black, contours, hierarchy, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);  // Added cv:: prefix
    std::vector<cv::RotatedRect> boundRect(contours.size());  // Added cv:: prefix
    std::vector<double> contArea(contours.size());

    for (size_t i = 0; i < contours.size(); i++)
    {
        //approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 3, true);
        boundRect[i] = cv::minAreaRect(cv::Mat(contours[i]));  // Added cv:: prefix
        contArea[i] = cv::contourArea(contours[i]);  // Added cv:: prefix
    }
    for (size_t i = 0; i < contours.size(); i++)
    {
        int t_area = boundRect[i].size.area();  // Added cv:: prefix
        if (t_area >= 14 && contArea[i] > 12 && contArea[i] < 8000) {
            cv::Scalar color = cv::Scalar(0, 255, 255);  // Added cv:: prefix
            cv::drawContours(img2, contours, i, color, 1);  // Added cv:: prefix
        }
    }

    for (int i = 0; i < 4; i++)
        cv::line(img2, cv::Point(0, y[i]), cv::Point(155 * 6, y[i]), cv::Scalar(0, 0, 255), 1);  // Added cv:: prefix
    for (int i = 0; i < 15; i++)
        cv::line(img2, cv::Point(x[i], 0), cv::Point(x[i], 270), cv::Scalar(0, 0, 255), 1);  // Added cv:: prefix
    //    std::cout << "threshold =" << ss_threshold << std::endl;
    cv::imshow("output2", img2);  // Added cv:: prefix
    //    cv::imshow("black", img_black);
}

void first() {
    diffx = s1 - 15;
    diffy = s2 - 15;
    x[0] = 0;
    y[0] = 36;
    for (int i = 1; i < 5; i++)
        x[i] = x[i - 1] + 66;
    x[5] = 333;
    for (int i = 6; i < 10; i++)
        x[i] = x[i - 1] + 66;
    x[10] = 666;
    for (int i = 11; i < 15; i++)
        x[i] = x[i - 1] + 66;
    for (int i = 1; i < 4; i++)
        y[i] = y[i - 1] + 66;
    for (int i = 1; i < 15; i++)
        x[i] += diffx;
    for (int i = 0; i < 4; i++)
        y[i] += diffy;

    cv::Mat img_gray, img_black, img2;  // Added cv:: prefix
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));  // Added cv:: prefix
    std::vector<std::vector<cv::Point>> contours;  // Added cv:: prefix
    std::vector<cv::Vec4i> hierarchy;  // Added cv:: prefix

    img2 = image.clone();
    cv::cvtColor(image, img_gray, cv::COLOR_RGB2GRAY);  // Added cv:: prefix
    cv::medianBlur(img_gray, img_gray, 3);  // Added cv:: prefix
    cv::threshold(img_gray, img_black, ss_threshold, 255, cv::THRESH_BINARY);  // Added cv:: prefix
    //    cv::dilate(img_black, img_black, kernel);
    cv::findContours(img_black, contours, hierarchy, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);  // Added cv:: prefix
    std::vector<cv::RotatedRect> boundRect(contours.size());  // Added cv:: prefix
    std::vector<double> contArea(contours.size());

    for (size_t i = 0; i < contours.size(); i++)
    {
        //approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 3, true);
        boundRect[i] = cv::minAreaRect(cv::Mat(contours[i]));  // Added cv:: prefix
        contArea[i] = cv::contourArea(contours[i]);  // Added cv:: prefix
    }
    for (size_t i = 0; i < contours.size(); i++)
    {
        int t_area = boundRect[i].size.area();  // Added cv:: prefix
        if (t_area >= 14 && contArea[i] > 12 && contArea[i] < 8000) {
            cv::Scalar color = cv::Scalar(0, 255, 255);  // Added cv:: prefix
            cv::drawContours(img2, contours, i, color, 1);  // Added cv:: prefix
        }
    }

    for (int i = 0; i < 4; i++)
        cv::line(img2, cv::Point(0, y[i]), cv::Point(155 * 6, y[i]), cv::Scalar(0, 0, 255), 1);  // Added cv:: prefix
    for (int i = 0; i < 15; i++)
        cv::line(img2, cv::Point(x[i], 0), cv::Point(x[i], 270), cv::Scalar(0, 0, 255), 1);  // Added cv:: prefix
    cv::imshow("output2", img2);  // Added cv:: prefix
}
void onMouse(int event, int x, int y, int flags, void* utsc)
{
    callbackP cp = *(callbackP*)utsc;  // 先转换类型，再取数据

    if (event == cv::EVENT_LBUTTONUP)      //响应鼠标左键事件
    {
        cv::circle((*(callbackP*)utsc).src, cv::Point(x, y), 2, cv::Scalar(0, 0, 255), 2);  //标记选中点
        //        cv::imshow("wait ", (*(callbackP*)utsc).src);
        (*(callbackP*)utsc).srcTri.emplace_back(cv::Point2f(x, y));
        std::cout << "x:" << x << " " << "y:" << y << std::endl;
        (*(callbackP*)utsc).clickTimes++;

        if ((*(callbackP*)utsc).clickTimes == 4)
        {
            std::cout << "按任意键继续！" << std::endl;
        }
    }
}

void onMouse_threshold(int event, int x, int y, int flags, void* utsc)
{
    callbackP cp = *(callbackP*)utsc;  // 先转换类型，再取数据

    if (event == cv::EVENT_LBUTTONUP)      //响应鼠标左键事件
    {
        cv::circle((*(callbackP*)utsc).src, cv::Point(x, y), 1, cv::Scalar(0, 0, 255), 2);  //标记选中点
        //        cv::imshow("wait ", (*(callbackP*)utsc).src);
        (*(callbackP*)utsc).srcTri.emplace_back(cv::Point2f(x, y));
        std::cout << "x:" << x << " " << "y:" << y << std::endl;
        (*(callbackP*)utsc).clickTimes++;

        if ((*(callbackP*)utsc).clickTimes == 3)
        {
            std::cout << "Press any key to continue!" << std::endl;
        }
    }
}

void board::set_speed(int speed) {
    for (int i = 0; i < 37; i++)
        flies[i].speed = speed;
}

void board::get_point(cv::Mat& img) {
    cv::namedWindow("src", 0);

    cv::resizeWindow("src", 1080, 1080);
    bool process1 = true;
    utsc.src = img.clone();
    while (process1) {
        cv::imshow("src", utsc.src);
        cv::setMouseCallback("src", onMouse, (void*)&utsc);  //类型转换
        if (utsc.clickTimes == 4) {
            //计算透视矩阵
            M = cv::findHomography(utsc.srcTri, dstTri, cv::RANSAC);
            //图像透视变换
            cv::warpPerspective(utsc.src, dst, M,
                cv::Size((length), (height)));
            //cv::imwrite("output.jpg", dst);
            break;
        }
        else {
            std::cout << "Starting from the top left corner, point the four corners of the rectangle clockwise in sequence! " << std::endl;
            std::cout <<  utsc.clickTimes << " times already." << std::endl;
        }
        key = cv::waitKey(1);
        if (key == 'q')
            break;
    }
    image = dst.clone();
    cv::destroyWindow("src");
}

//void board::adjust_lines() {
//    namedWindow("output2", 0);
//    resizeWindow("output2", 1280, 1080);
//    bool process2 = true;
//    ss_threshold = set_threshold + 28;
//    first();
//    while (process2) {
//        createTrackbar("diffx", "output2", &s1, 30, trackBar);
//        createTrackbar("diffy", "output2", &s2, 30, trackBar);
//        createTrackbar("threshold", "output2", &ss_threshold, 200, trackBar);
//        key = waitKey(1);
//        if (key == 'q')
//            break;
//    }
//    destroyWindow("output2");
//}

void board::adjust_lines() {
    cv::namedWindow("output2", 0);
    cv::resizeWindow("output2", 1280, 480);
    bool process2 = true;
    ss_threshold = set_threshold + 28;
    first();

    // Create trackbars once before the loop
    cv::createTrackbar("diffx", "output2", &s1, 30, trackBar);
    cv::createTrackbar("diffy", "output2", &s2, 30, trackBar);
    cv::createTrackbar("threshold", "output2", &ss_threshold, 200, trackBar);

    while (process2) {
        key = cv::waitKey(1);
        if (key == 13)
            break;
    }
    cv::destroyWindow("output2");
}

void board::reset_matcher() {
    cv::Mat tempsrc = utsc.src.clone();
    cv::Point center;
    for (int i = 0; i < 4; i++) {
        center = utsc.srcTri[i];
        if (center.x > 8 && center.y > 8) {
            matchimg.emplace_back(tempsrc(cv::Rect(center.x - 8, center.y - 8, 16, 16)).clone());
            matchcenter.emplace_back(center);
        }
    }
}

void board::reset_threshold() {
    cv::namedWindow("threshold", 0);
    cv::resizeWindow("threshold", 1080, 316);
    cv::Mat temp_src = image.clone();
    cv::Mat temp_gray;
    cv::imshow("threshold", temp_src);
    cv::cvtColor(temp_src, temp_gray, cv::COLOR_RGB2GRAY);
    bool process1 = true;
    int nums, maxnum;
    cv::Point fly_center;
    utsc1.src = image.clone();
    while (process1) {
        cv::imshow("threshold", utsc1.src);
        cv::setMouseCallback("threshold", onMouse_threshold, (void*)&utsc1);  //类型转换
        if (utsc1.clickTimes == 3) {
            break;
        }
        else {
            std::cout << "click flys" << std::endl;
            std::cout << utsc1.clickTimes << " times already" << std::endl;
        }
        key = cv::waitKey(1);
        if (key == 'q')
            break;
    }
    maxnum = 0;
    for (int i = 0; i < 3; i++) {
        fly_center = utsc1.srcTri[i];
        nums = temp_gray.ptr<uchar>(fly_center.y)[fly_center.x];
        printf("num = %d \n", nums);
        if (nums > maxnum)
            maxnum = nums;
    }
    std::cout << "min num =" << maxnum << std::endl;
    set_threshold = maxnum;
    cv::destroyWindow("threshold");
}

float calc(cv::Point2f rect[4]) {
    float length, width;
    length = sqrt((rect[0].x - rect[1].x) * (rect[0].x - rect[1].x) + (rect[0].y - rect[1].y) * (rect[0].y - rect[1].y));
    width = sqrt((rect[2].x - rect[1].x) * (rect[2].x - rect[1].x) + (rect[2].y - rect[1].y) * (rect[2].y - rect[1].y));
    if (width / length < 1.0)
        return length / width * 1.0;
    return width / length * 1.0;
}

bool dis_judge(cv::Point p1, cv::Point p2) {
    float dis;
    dis = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
    //    if (dis>8.0)
    //        std::cout<<"dis="<<dis<<std::endl;
    return dis <= 8.0;
}

void board::state(cv::Mat& img, int time) {
    int wid, heigh;
    cv::Mat img_gray, img_black;
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3), cv::Point(-1, -1));
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::Point2f rect[4];
    cv::Point leftup, rightdown, center;
    cv::Mat srcimg, dstimg;
    for (int i = 0; i < 4; i++) {
        center = matchcenter[i];
        if (center.x > 20)
            leftup.x = center.x - 20;
        else
            leftup.x = 0;
        if (center.y > 20)
            leftup.y = center.y - 20;
        else
            leftup.y = 0;
        if (center.x + 20 > img.cols)
            rightdown.x = img.cols;
        else
            rightdown.x = center.x + 20;
        if (center.y + 20 > img.rows)
            rightdown.y = img.rows;
        else
            rightdown.y = center.y + 20;
        wid = rightdown.x - leftup.x;
        heigh = rightdown.y - leftup.y;
        srcimg = img(cv::Rect(leftup.x, leftup.y, wid, heigh)).clone();
        cv::matchTemplate(srcimg, matchimg[i], dstimg, cv::TM_SQDIFF);
        cv::normalize(dstimg, dstimg, 0, 1, cv::NORM_MINMAX, -1, cv::Mat());
        double minvalue, maxvalue;
        cv::Point minLocat, maxLocat;
        cv::Point matchLocate, location;
        cv::minMaxLoc(dstimg, &minvalue, &maxvalue, &minLocat, &maxLocat, cv::Mat());
        matchLocate = minLocat;
        location.x = matchLocate.x + leftup.x + (int)matchimg[i].cols / 2;
        location.y = matchLocate.y + leftup.y + (int)matchimg[i].rows / 2;
        if (dis_judge(location, matchcenter[i])) {
            matchcenter[i] = location;
            //            matchimg[i]=img(Rect(location.x-3,location.y-3,6,6)).clone();
        }
        cv::rectangle(img, leftup, cv::Point(leftup.x + wid, leftup.y + heigh), cv::Scalar(0, 255, 0), 2);
        cv::circle(img, center, 2, cv::Scalar(255, 0, 0), 2);
        cv::rectangle(img, cv::Point(matchLocate.x + leftup.x, matchLocate.y + leftup.y),
            cv::Point(matchLocate.x + matchimg[i].cols + leftup.x, matchLocate.y + matchimg[i].rows + leftup.y),
            cv::Scalar(0, 0, 255), 2);
    }
    //cv::imshow("test", img);
    //cv::imwrite("img.jpg", img);
    cv::waitKey(1);
    M = cv::findHomography(matchcenter, dstTri, cv::RANSAC);
    cv::warpPerspective(img, dst, M, cv::Size((length), (height)));
    for (int i = 0; i < 37; i++) {
        P[i].clear();
        scale[i] = 0;
    }
    cv::cvtColor(dst, img_gray, cv::COLOR_RGB2GRAY);
    cv::medianBlur(img_gray, img_gray, 3);
    cv::threshold(img_gray, img_black, ss_threshold, 255, cv::THRESH_BINARY);
    //    cv::dilate(img_black, img_black, kernel);
    cv::findContours(img_black, contours, hierarchy, cv::RETR_LIST, cv::CHAIN_APPROX_SIMPLE);
    //    cv::imshow ("test2", img_black);
    //    cv::imwrite ("black.jpg",img_black);
    cv::waitKey(1);
    std::vector<cv::RotatedRect> boundRect(contours.size());
    std::vector<double> contArea(contours.size());
    for (size_t i = 0; i < contours.size(); i++) {
        //cv::approxPolyDP(cv::Mat(contours[i]), contours_poly[i], 3, true);
        boundRect[i] = cv::minAreaRect(cv::Mat(contours[i]));
        contArea[i] = cv::contourArea(contours[i]);
    }
    for (size_t i = 0; i < contours.size(); i++) {
        int t_area = boundRect[i].size.area();
        int t_x = boundRect[i].center.x;
        int t_y = boundRect[i].center.y;
        int add = 0;
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 4; k++) {
                if ((t_x > x[k] && t_x < x[k + 1]) && (t_y > y[j] && t_y < y[j + 1])) {
                    int index_num = j * 4 + k + 1;
                    if (t_area >= 14 && contArea[i] > 12 && contArea[i] < 8000) {
                        cv::Scalar color = cv::Scalar(0, 255, 255);
                        cv::drawContours(dst, contours, i, color, 1);
                        P[index_num].emplace_back(boundRect[i].center);
                        boundRect[i].points(rect);
                        float ca = calc(rect);
                        scale[index_num] = ca;
                        //                            std::cout<<"长宽比"<<ca<<std::endl;
                    }
                }
            }
        add = 12;
        for (int j = 0; j < 3; j++)
            for (int k = 5; k < 9; k++) {
                if ((t_x > x[k] && t_x < x[k + 1]) && (t_y > y[j] && t_y < y[j + 1])) {
                    int index_num = j * 4 + (k - 5) + 1 + add;
                    if (t_area >= 14 && contArea[i] > 12 && contArea[i] < 8000) {
                        cv::Scalar color = cv::Scalar(0, 255, 255);
                        cv::drawContours(dst, contours, i, color, 1);
                        P[index_num].emplace_back(boundRect[i].center);
                        boundRect[i].points(rect);
                        float ca = calc(rect);
                        scale[index_num] = ca;
                    }
                }
            }
        add = 24;
        for (int j = 0; j < 3; j++)
            for (int k = 10; k < 14; k++) {
                if ((t_x > x[k] && t_x < x[k + 1]) && (t_y > y[j] && t_y < y[j + 1])) {
                    int index_num = j * 4 + (k - 10) + 1 + add;
                    if (t_area >= 14 && contArea[i] > 12 && contArea[i] < 8000) {
                        cv::Scalar color = cv::Scalar(0, 255, 255);
                        cv::drawContours(dst, contours, i, color, 1);
                        P[index_num].emplace_back(boundRect[i].center);
                        boundRect[i].points(rect);
                        float ca = calc(rect);
                        scale[index_num] = ca;
                    }
                }
            }
    }

    cv::imshow("test3", dst);
    //cv::imwrite("dst.jpg", dst);
    cv::waitKey(1);
    for (int i = 0; i < 37; i++) {
        if (!P[i].empty() && P[i].size() < 3) { //有2个果蝇才处理
            flies[i].Trajectory(P[i]);
            flies[i].update_state(P[i], time);
            flies[i].update_scale(scale[i]);
            string text = " ";
            string text1 = to_string(i);
            //            if (flies[i].fly_state == 0)
            //                text = "0";
            //            if (flies[i].fly_state == 1)
            //                if (flies[i].is_court || flies[i].buff_time1/fps>3)
            //                    text = "Court";
            //                else
            //                    text = "MCourt";
            //            if (flies[i].fly_state == 2)
            //                text = "MMate";
            //            if (flies[i].fly_state == 3)
            //                text = "Mate";
            //            putText(dst, text, flies[i].fly2.back(), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 120, 255), 2);
            //            if (i==32){
            //                text=to_string(scale[i]);
            //                putText(dst, text, flies[i].fly2.back(), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 255, 0), 2);
            //            }
            //                if (flies[i].stop_judge(1))
            //                    putText(dst, "stop", flies[i].fly1.back(), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 255, 255), 2);
            //                else
            //                    putText(dst, "move", flies[i].fly1.back(), cv::FONT_HERSHEY_COMPLEX, 1, cv::Scalar(0, 255, 255), 2);
        }
    }
}
void board::csv_output(int pos, string file_name_no_ext) {
    cout << "output to csv" << endl;
    string file = file_name_no_ext + "_output_" + to_string(pos + 1) + ".csv";
    float CI;
    std::ofstream myfile;
    myfile.open(file);
    myfile << " ," << "courtship_duration(min)," << "mate_duration(min)," << "CI," << "court start time(min)," << "mate start time(min)," << "mate end time(min)" << endl;
    for (int i = 0; i < 37; i++)
    {
        if (flies[i].mate_start / flies[i].fps / 60 < 10 && flies[i].mate_start / flies[i].fps / 60 > 0)
            CI = (float)flies[i].courtship_time / (flies[i].mate_start - flies[i].court_start);
        else
            CI = (float)flies[i].courtship_time_10min / (10 * 60 * flies[i].fps);

        myfile << i << "," << flies[i].courtship_time / flies[i].fps / 60 << "," << flies[i].mate_time / flies[i].fps / 60 << "," << CI << "," << flies[i].court_start / flies[i].fps / 60 << "," << flies[i].mate_start / flies[i].fps / 60 << "," << (flies[i].mate_start + flies[i].mate_time) / flies[i].fps / 60 << endl;
    }
    myfile.close();
}
