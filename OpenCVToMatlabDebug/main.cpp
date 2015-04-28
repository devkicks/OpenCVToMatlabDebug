#include <iostream>
#include "opencv2\highgui\highgui.hpp"
#include "opencv2\core\core.hpp"
#include "OpenCVToMatlabWrapper.h"



int main()
{
	cv::Mat inImage;

	// loading input image as grayscale
	inImage = cv::imread("baboon.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	cv::imshow("OutputWindow", inImage);

	OpenCVToMatlabWrapper dataDebug;
	dataDebug.clearWorkSpace();
	dataDebug.closeAllWind();
	dataDebug.changeWorkingDirectory("C:\\ResearchDocuments\\");
	dataDebug.sendUCharMat(inImage, "inImage");
	dataDebug.runCommandMatlab("imshow(inImage)");
	std::cout << "Testing other options" << std::endl;

	cv::Mat fImage;
	inImage.convertTo(fImage, CV_32FC1);
	
	dataDebug.sendFloatMat(fImage, "fImage");
	

	cv::Mat dImage;
	inImage.convertTo(dImage, CV_64FC1);
	
	dataDebug.sendDoubleMat(dImage, "dImage");

	cv::waitKey(0);


	return 1;
}
