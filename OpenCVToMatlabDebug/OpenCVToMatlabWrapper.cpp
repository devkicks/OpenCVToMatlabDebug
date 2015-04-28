/* 
*			OpenCVToMatlab Wrapper functions - integrates OpenCV_matlab conversion routines by B. Schauerte
*			in wrapper functions that give direct access to a Matlab Engine.
*			
*
*
*			Brief description of the functionality provided:
*			--Data can be sent from within C++ code
*			--Matlab commands/scripts/functions can be executed from within C++ Code
*
*			More detail on Matlab Engine in C++ programs can be found here:
*			http://uk.mathworks.com/videos/matlab-for-cc-programmers-81699.html
*
*			Author: Muhammad Asad
*			Email: masad.801@gmail.com
*			Date: April 2015
*/

#include "OpenCVToMatlabWrapper.h"


OpenCVToMatlabWrapper::OpenCVToMatlabWrapper(void)
{	
	ep = engOpen(NULL);
}

void OpenCVToMatlabWrapper::clearWorkSpace(void)
{
	engEvalString(ep, "clear all");
}

void OpenCVToMatlabWrapper::closeAllWind(void)
{
	engEvalString(ep, "close all");
}

void OpenCVToMatlabWrapper::runCommandMatlab(char *inCommand)
{
	if(inCommand != " ")
		engEvalString(ep, inCommand);
	
}



void OpenCVToMatlabWrapper::changeWorkingDirectory(char *rootDir)
{
	char buffer[100];
	sprintf(buffer, "cd %s", rootDir);

	engEvalString(ep, buffer);
}

	

void OpenCVToMatlabWrapper::sendDoubleMat(const cv::Mat &inMat, char* matName)
{
	
	std::cout << " ********    Sending data to Matlab  ********** " << std::endl;

	mxArray *pmxImg;
	mwSize dimsMat[2];
	dimsMat[0] = inMat.rows;
	dimsMat[1] = inMat.cols;

	pmxImg = mxCreateNumericArray(2 /* nDims */, dimsMat, mxDOUBLE_CLASS, mxREAL);
	om::copyMatrixToMatlab<double>(inMat, (double*)mxGetPr(pmxImg));

	// data ready for transmitting to Matlab

	// send data to Matlab
	engPutVariable(ep, matName, pmxImg);

	// clear everything in memory
	mxDestroyArray(pmxImg);

	std::cout << " ********    Data Sent  ********** " << std::endl;


}

void OpenCVToMatlabWrapper::sendUCharMat(const cv::Mat &inMat, char* matName)
{

	std::cout << " ********    Sending data to Matlab  ********** " << std::endl;

	mxArray *pmxImg;
	mwSize dimsMat[2];
	dimsMat[0] = inMat.rows;
	dimsMat[1] = inMat.cols;

	pmxImg = mxCreateNumericArray(2 /* nDims */, dimsMat, mxUINT8_CLASS, mxREAL);
	om::copyMatrixToMatlab<uchar>(inMat, (uchar*)mxGetPr(pmxImg));

	// data ready for transmitting to Matlab

	// send data to Matlab
	engPutVariable(ep, matName, pmxImg);

	// clear everything in memory
	mxDestroyArray(pmxImg);
	std::cout << " ********    Data Sent  ********** " << std::endl;
}

void OpenCVToMatlabWrapper::sendFloatMat(const cv::Mat &inMat, char* matName)
{

	std::cout << " ********    Sending data to Matlab  ********** " << std::endl;

	mxArray *pmxImg;
	mwSize dimsMat[2];
	dimsMat[0] = inMat.rows;
	dimsMat[1] = inMat.cols;

	pmxImg = mxCreateNumericArray(2 /* nDims */, dimsMat, mxSINGLE_CLASS, mxREAL);
	om::copyMatrixToMatlab<float>(inMat, (float*)mxGetPr(pmxImg));

	// data ready for transmitting to Matlab

	// send data to Matlab
	engPutVariable(ep, matName, pmxImg);

	// clear everything in memory
	mxDestroyArray(pmxImg);
	std::cout << " ********    Data Sent  ********** " << std::endl;
}

OpenCVToMatlabWrapper::~OpenCVToMatlabWrapper(void)
{
		engClose(ep);
}
