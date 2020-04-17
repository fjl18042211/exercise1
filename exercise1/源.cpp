
 #include <opencv.hpp>
#include <math.h>


 using namespace cv;
 using namespace std;


 int main()
 {
	 	Mat srcMat = imread("D:\\rim.png", 0);
	 	Mat dspMat = imread("D:\\rim.png");
	 	Mat binaryMat;


		 	Mat inversedMat = 255 - srcMat;
	 	threshold(inversedMat, binaryMat, 150, 255, THRESH_OTSU);
	

		 	Mat element = getStructuringElement(MORPH_RECT, Size(11, 12));
	 	morphologyEx(binaryMat, binaryMat, MORPH_OPEN, element);


		 	vector<vector<Point>> contours;
	 	findContours(binaryMat, contours, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_NONE, Point());
	

		

		 	float z[100];
	

		 	for (int i = 0; i < contours.size(); i++)
		 	{
		 		RotatedRect rect = minAreaRect(contours[i]);
		 		Point2f P[4];
		 		rect.points(P);
		 		 
			

					float Y = sqrt((P[0].y - P[1].y) * (P[0].y - P[1].y) + (P[0].x - P[1].x) * (P[0].x - P[1].x));
		 		float X = sqrt((P[1].y - P[2].y) * (P[1].y - P[2].y) + (P[1].x - P[2].x) * (P[1].x - P[2].x));
		 		z[i] = X / Y;
		

			

			 		if ((z[i] >= 0.90) and (z[i] <= 1.1))
					{
			 			for (int j = 0; j <= 3; j++)
							{
								line(dspMat, P[j], P[(j + 1) % 4], Scalar(255), 1);
						}
			 		}
		 	}
	 	imshow("srcMat", srcMat);
	 	imshow("dspMat", dspMat);
	 	imshow("binaryMat", binaryMat);
		waitKey(0);
	 	return 0;
	 }
