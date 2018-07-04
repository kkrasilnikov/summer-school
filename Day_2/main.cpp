#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
#include "vector"

using namespace cv;

int main(int argc, char* argv[]) {
	Ptr<LineSegmentDetector> ls = createLineSegmentDetector(LSD_REFINE_STD);
	std::vector<Vec4f> lines_std;
	std::vector<Vec4f> lines_long;
	VideoCapture cap("../videoplayback.mp4"); // open the video file for reading
	if ( !cap.isOpened() ) return -1;
	//cap.set(CV_CAP_PROP_POS_MSEC, 300);
	double fps = cap.get(CV_CAP_PROP_FPS);
	//start the video at 300ms
	//get the frames per seconds of the video
	std::cout << "Frame per seconds : " << fps << std::endl;
	namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
	while(1) {
		Mat frame;
		Mat gray_image;
		Mat edge;
		
		bool bSuccess = cap.read(frame); // read a new frame from video
		if (!bSuccess) {
			std::cout << "Cannot read the frame from video file" << std::endl;
			break;
		}
		
		cvtColor( frame, gray_image, COLOR_BGR2GRAY );
		Canny( gray_image, edge, 50, 150, 3);
		/*ls->detect(gray_image, lines_std);*/ // Detect the lines
		ls->detect(edge, lines_std);
		ls->drawSegments(frame, lines_std);
		cv::resize(frame,frame,cv::Size(1200,900));
		imshow("MyVideo", frame); //show the frame in "MyVideo" window
			
		/* imshow("MyVideo", frame); */ //show the frame in "MyVideo" window
		if(waitKey(30) == 27) {
			break;
		}	
	}
}
