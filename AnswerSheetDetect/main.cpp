#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

//void salt(Mat &img, int n);
int main()
{
    int pixel_x = 92;
    int pixel_y = 124;
    int score = 0;
    int total_score = 0;

    Mat answer = imread("answersheet.jpg", 0);

    Mat templateSheet = imread("template.jpg", CV_LOAD_IMAGE_GRAYSCALE);

//    if(!img.data)
//            cout << "Problem loading image!!!" << endl;


    for(int i = 0; i < 10; i ++){
        for(int j = 1; j < 6; j++){
//                rectangle(
//                        answer,
//                        Point(pixel_x, pixel_y),
//                        Point(pixel_x+10, pixel_y+10),
//                        Scalar(0, 0, 0)
//                    );
            score = 0;

                        Rect crop_choice = Rect(pixel_x, pixel_y, 10, 10);
                        Mat check_template = templateSheet(crop_choice);
                        Mat check_ans = answer(crop_choice);
                        threshold(check_template, check_template, 200, 255, THRESH_BINARY);
                        threshold(check_ans, check_ans, 200, 255, THRESH_BINARY);
                            vector<Point> white_pixels_ans;
                            vector<Point> white_pixels_template;
                            cv::findNonZero(check_ans, white_pixels_ans);
                            cv::findNonZero(check_template, white_pixels_template);
                            if(white_pixels_ans.size() < 100 && white_pixels_template.size() < 100){

                            score = 1;
                            total_score += 1;
                            break;

                            }


            pixel_x += 40;
        }
        cout << i+1 << ". score: " << score << endl;
        pixel_x = 92;
        pixel_y += 47;
     }
    cout << "Total score : " << total_score << endl;


//        cv::namedWindow("AnswerSheetDetect");
//        cv::imshow("AnswerSheetDetect", answer);
//        cv::waitKey(0);

}

