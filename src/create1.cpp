#include <stdio.h>
#include <cv.h>
#include <highgui.h>
#include <cxcore.h>

int main()
{
    //---生成标定图
    IplImage *img;
    int dx=10;      //棋盘格大小，像素为单位
    int dy1=7;       //棋盘格数目
    int dy2=7;
    img = cvCreateImage(cvSize(dx*dy1, dx*dy2), IPL_DEPTH_8U, 1);
    cvZero(img);
    int flag=0;
    for(int i=0;i<dy1;i++)
        for(int j=0;j<dy2;j++)
        {
            flag = (i+j)%2;
            if (flag == 0)
            {
                for (int m=i*dx; m<(i+1)*dx; m++)
                    for(int n=j*dx; n<(j+1)*dx; n++)
                        ((uchar *)(img->imageData + img->widthStep * n ))[m] = 255;
            }
        }
        //---END生成标定图
        cvSaveImage("/home/zc/project/Calibration/create_chessboard-master/2.jpg",img);
        cvNamedWindow("棋盘格", 1);
        cvShowImage("棋盘格",img);
        cvWaitKey(0);

        cvReleaseImage(&img);
        cvDestroyWindow("棋盘格");

        return 0;
}
