#include "/opt/opencv/modules/highgui/include/opencv2/highgui/highgui.hpp"
#include "/opt/opencv/include/opencv2/opencv.hpp"
using namespace cv;

int main(int argc, char* argv[]) {
	VideoCapture cap("../Dogfight.mp4"); // open the video file for reading
	if ( !cap.isOpened() ) return -1;
	//cap.set(CV_CAP_PROP_POS_MSEC, 300);
	double fps = cap.get(CV_CAP_PROP_FPS);
	//start the video at 300ms
	//get the frames per seconds of the video
	std::cout << "Frame per seconds : " << fps << std::endl;
	namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"
	while(1) {
		Mat frame;
		bool bSuccess = cap.read(frame); // read a new frame from video
		if (!bSuccess) {
			std::cout << "Cannot read the frame from video file" << std::endl;
			break;
		}
		imshow("MyVideo", frame); //show the frame in "MyVideo" window
		if(waitKey(30) == 27) {
			break;
		}	
	}
}
