#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

int checkAnswer(Mat &templateSheet,Mat &answer,int pixel_x, int pixel_y, int round){
    int total_score = 0;

    for(int i = 0; i < 10; i ++){

        int score = 0;
        for(int j = 1; j < 6; j++){
            Rect crop_choice = Rect(pixel_x, pixel_y, 10, 10);
            Mat check_template = templateSheet(crop_choice);
            Mat check_ans = answer(crop_choice);
            threshold(check_template, check_template, 200, 255, THRESH_BINARY_INV);
            threshold(check_ans, check_ans, 200, 255, THRESH_BINARY_INV);
            vector<Point> white_pixels_ans;
            vector<Point> white_pixels_template;
            findNonZero(check_ans, white_pixels_ans);
            findNonZero(check_template, white_pixels_template);


            if(white_pixels_ans.size() > 0 && white_pixels_template.size() > 0){
                score = 1;

            }else if(white_pixels_ans.size() == 0 && white_pixels_template.size() == 0){
                score = 1;
            }
            else{
                score = 0;
                break;
            }

            pixel_x += 40;
        }

            total_score += score;

        cout << round << ". score: " << score << endl;
        if(round < 10){
            pixel_x = 92;
        }else{
            pixel_x = 376;
        }
        round += 1;
        pixel_y += 47;
     }
    return total_score;
}
int main()
{
    int pixel_x = 92;
    int pixel_y = 124;
    int total_score = 0;
    int round = 1;


    Mat answer = imread("answersheet.jpg", 0);

    Mat templateSheet = imread("template.jpg", CV_LOAD_IMAGE_GRAYSCALE);

    if(!answer.data && !templateSheet.data )
            cout << "Problem loading image!!!" << endl;

    total_score += checkAnswer(templateSheet,answer,pixel_x, pixel_y, round);
    pixel_x = 376;
    pixel_y = 124;
    round += 10;
    total_score += checkAnswer(templateSheet,answer,pixel_x,pixel_y, round);
    cout << "Total score : " << total_score << endl;
    namedWindow("AnswerSheetDetect");
    imshow("AnswerSheetDetect", answer);
    waitKey(0);

}





