
#include <iostream>
#include <opencv.hpp>
#include <stdlib.h>
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap;
	cap.open(0);
	if (!cap.isOpened())
	{
		std::cout << "不能打开视频文件" << std::endl;
		return -1;
	}
	double fps = cap.get(CAP_PROP_FPS);
	std::cout << "fps" << fps << std::endl;
	while (1)
	{
		cv::Mat frame;
		cv::Mat dst1;
		cv::Mat dst2;
		cv::Mat dx;
		cv::Mat abs_dx;
		cv::Mat dy;
		cv::Mat abs_dy;
		bool rSucess = cap.read(frame);
		if (!rSucess)
		{
			std::cout << "不能从视频文件中读取帧" << std::endl;
			break;
		}
		else
		{

			Sobel(frame, dx, CV_16SC1, 1, 0, 3);
			convertScaleAbs(dx, abs_dx);
			Sobel(frame, dy, CV_16SC1, 0, 1, 3);
			convertScaleAbs(dy, abs_dy);
			Canny(dx, dy, dst1, 20, 60);
			cv::imshow("dst1", dst1);
			Canny(frame, dst2, 20, 60);
			cv::imshow("dst2", dst2);

		}
		waitKey(30);
	}

	return 0;
}