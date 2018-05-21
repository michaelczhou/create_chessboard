#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

//#include <opencv2/highgui.hpp>
//#include <opencv2/core.hpp>
//隐藏控制台窗口
//#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

int main(int argc, char*argv[])
{
    int width = 100;//棋盘格宽度
    int height = 100;//棋盘格高度

    cv::Mat src(800,700,CV_8UC1,1);

    //cv::Mat src1=cv::imread("/home/zc/Pictures/1.png",0);
    for (int i = 0; i < src.rows; i++)
    {
        for (int j = 0; j < src.cols; j++)
        {
            if ((i / width + j / height) % 2 != 0)
            {
               // std::cout<<"channals?: "<<src.channels()<<std::endl;//1
                src.at<uchar>(i,j)=255;
                //src.data[i*src.step+j*src.channels()]=255;
                //src->imageData[i*src->widthStep + j*src->nChannels] = 255;
            }
        }
    }

    cv::imshow("src",src);
    cv::imwrite("ChessBoard.png", src);
    cv::waitKey(0);

    return 0;


}

