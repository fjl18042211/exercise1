
#include <iostream>
#include <opencv.hpp>
#include <stdlib.h>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat	M1;
	cv::Mat	result1;
	cv::Mat	result2;
	cv::Mat	result3;
	cv::Mat	result4;
	cv::Mat srcMat = imread("D:\\4.png", 0);
	cv::threshold(srcMat, M1, 0, 255, THRESH_OTSU);
	Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
	morphologyEx(srcMat, result1, MORPH_ERODE, kernel);
	morphologyEx(srcMat, result2, MORPH_DILATE, kernel);
	morphologyEx(srcMat, result3, MORPH_OPEN, kernel);
	morphologyEx(srcMat, result4, MORPH_CLOSE, kernel);
	imshow("result1", result1);
	imshow("result2", result2);
	imshow("result3", result3);
	imshow("result4", result4);
	waitKey(0);
	return 0;

}