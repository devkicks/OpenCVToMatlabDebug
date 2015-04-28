/*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


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

#pragma once
#include "math_common.hpp"
#include "opencv_matlab.hpp"
#include "engine.h"
#include <iostream>
#include <stdio.h>

class OpenCVToMatlabWrapper
{
private:
	Engine *ep;
public:
	OpenCVToMatlabWrapper(void);
	void clearWorkSpace(void);
	void closeAllWind(void);
	void runCommandMatlab(char *inCommand = " ");
	void changeWorkingDirectory(char *rootDir = "\\");
	void sendDoubleMat(const cv::Mat &inMat, char* matName = "fromCPP");
	void sendUCharMat(const cv::Mat &inMat, char* matName = "fromCPP");
	void sendFloatMat(const cv::Mat &inMat, char* matName = "fromCPP");

	~OpenCVToMatlabWrapper(void);
};

