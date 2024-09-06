#include "pch.h"
#include "opencv2/objdetect.hpp" // 객체 탐지
#include "opencv2/highgui.hpp" // High GUI
#include "opencv2/imgproc.hpp" // 이미지 처리
#include "opencv2/videoio.hpp" //비디오 입출력
#include <iostream>

using namespace std;
using namespace cv;

void detectAndDraw(Mat& img, CascadeClassifier& cascade,
    CascadeClassifier& nestedCascade,
    double scale, bool tryflip);

string cascadeName; // 얼굴 감지에 사용할 Haar Cascade XML 파일 이름
string nestedCascadeName; // 눈 감지에 사용할 Haar Cascade XML 파일 이름

int facedetect_image(void)
{
    Mat frame, image; // 이미지 및 비디오 프레임 저장용 변수
    string inputName; // 사용자로부터 선택된 이미지 파일 이름
    bool tryflip = false; // 이미지 좌우 반전 여부
    CascadeClassifier cascade, nestedCascade; // 얼굴 및 눈 감지용 분류기
    double scale; // 이미지 크기 조정 비율

    // 파일 열기
    static TCHAR BASED_CODE szFilter[] = _T("이미지 파일(*.BMP, *.GIF, *.JPG, *.PNG) | *.BMP;*.GIF;*.JPG;*.PNG;*.bmp;*.jpg;*.gif;*.png | 모든파일(*.*) | *.* || ");

    CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, szFilter);

    if (IDOK == dlg.DoModal())
    {
        CString pathName = dlg.GetPathName();
        CT2CA pszConvertedAnsiString(pathName);
        inputName = string(pszConvertedAnsiString);

    }

    // Haar Cascade XML 파일 경로 설정
    cascadeName = "haarcascade_frontalface_alt.xml"; // 얼굴 감지
    nestedCascadeName = "haarcascade_eye_tree_eyeglasses.xml"; // 눈 감지
    
    scale = 1; // 이미지 크기 조정 비율 설정

    // Haar Cascade XML 파일 로드
    if (!nestedCascade.load(nestedCascadeName)) {
        cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;
    }
    
    if (!cascade.load(cascadeName))
    {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        return -1;
    }

    // 선택된 이미지 파일이 있는 경우
    if (!inputName.empty())
    {
        image = imread(inputName, IMREAD_COLOR); // 이미지 파일 읽기

        if (image.empty())
        {
            cout << "Couldn't read lena.jpg" << endl;
            return 1;
        }
    }

    cout << "Detecting face(s) in " << inputName << endl;

    if (!image.empty())
    {
        detectAndDraw(image, cascade, nestedCascade, scale, tryflip); // 얼굴 감지 및 그리기 함수 호출
        waitKey(0);
    }

    return 0;
}


int facedetect_video(int camera)
{
    VideoCapture capture; // 비디오 캡처 객체
    Mat frame, image; // 비디오 프레임 및 이미지 저장용 변수
    bool tryflip = false; // 이미지 좌우 반전 여부
    CascadeClassifier cascade, nestedCascade; // 얼굴 및 눈 감지용 분류기
    double scale; // 이미지 크기 조정 비율

    // Haar Cascade XML 파일 경로 설정
    cascadeName = "haarcascade_frontalface_alt.xml";
    nestedCascadeName = "haarcascade_eye_tree_eyeglasses.xml";
    
    scale = 1; // 이미지 크기 조정 비율 설정

    // Haar Cascade XML 파일 로드
    if (!nestedCascade.load(nestedCascadeName)) {
        cerr << "WARNING: Could not load classifier cascade for nested objects" << endl;
    }

    if (!cascade.load(cascadeName))
    {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        return -1;
    }

    // 비디오 캡처 열기
    if (!capture.open(camera))
    {
        cout << "Capture from camera #" << camera << " didn't work" << endl;
        return 1;
    }

    // 비디오 캡처가 열린 경우
    if (capture.isOpened()) {
        while (true) {
            capture >> frame; // 비디오 프레임 읽기
            if (frame.empty()) {
                cout << "End of video stream or empty frame" << endl;
                break;
            }

            Mat frame1 = frame.clone(); // 프레임 복제
            detectAndDraw(frame1, cascade, nestedCascade, scale, tryflip); // 얼굴 감지 및 그리기 함수 호출

            char c = (char)waitKey(30); //비디오가 초당 30프레임의 속도로 재생
            if (c == 27 || c == 'q' || c == 'Q') // ESC, Q, q 누르면 종료
                break;
        }
        capture.release(); // 비디오 캡처 객체 해제
        destroyAllWindows(); // 모든 OpenCV 창 닫기
    }

    return 0;
}


void detectAndDraw(Mat& img, CascadeClassifier& cascade, CascadeClassifier& nestedCascade, double scale, bool tryflip)
{
    double t = 0; // 시간 측정을 위한 변수
    vector<Rect> faces, faces2; // 얼굴 및 감지된 얼굴 좌표 저장 벡터
    const static Scalar colors[] =
    {
        Scalar(255,0,0), // 빨간색
        Scalar(255,128,0), // 주황색
        Scalar(255,255,0), // 노란색
        Scalar(0,255,0), // 초록색
        Scalar(0,128,255), // 하늘색
        Scalar(0,255,255), // 청록색
        Scalar(0,0,255), // 파란색
        Scalar(255,0,255) // 보라색
    };
    Mat gray, smallImg;// 회색조 이미지 및 축소된 이미지

    cvtColor(img, gray, COLOR_BGR2GRAY); // 이미지를 회색조로 변환
    double fx = 1 / scale; // 이미지 크기 조정 비율 계산
    resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);// 이미지 축소
    equalizeHist(smallImg, smallImg); // 히스토그램 평활화

    t = (double)getTickCount(); // 현재 시간 기록
    cascade.detectMultiScale(smallImg, faces,
        1.1, 2, 0 // 얼굴 감지 파라미터
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        | CASCADE_SCALE_IMAGE,
        Size(30, 30)); // 얼굴 크기 최소값 설정

    // 이미지 좌우 반전 감지 여부 확인
    if (tryflip)
    {
        flip(smallImg, smallImg, 1); // 이미지 좌우 반전
        cascade.detectMultiScale(smallImg, faces2,
            1.1, 2, 0
            //|CASCADE_FIND_BIGGEST_OBJECT
            //|CASCADE_DO_ROUGH_SEARCH
            | CASCADE_SCALE_IMAGE,
            Size(30, 30)); // 좌우 반전된 이미지에서 얼굴 감지

        for (vector<Rect>::const_iterator r = faces2.begin(); r != faces2.end(); ++r)
        {
            faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height)); // 좌우 반전된 얼굴 좌표 조정
        }
    }

    t = (double)getTickCount() - t; // 얼굴 감지 시간 측정
    printf("detection time = %g ms\n", t * 1000 / getTickFrequency()); // 감지 시간 출력
    
    // 감지된 얼굴에 원 또는 사각형 그리기
    for (size_t i = 0; i < faces.size(); i++)
    {
        Rect r = faces[i]; // 얼굴 좌표
        Mat smallImgROI; // 얼굴 부분 이미지
        vector<Rect> nestedObjects; // 감지된 눈 좌표
        Point center; // 원의 중심
        Scalar color = colors[i % 8]; // 색상 설정
        int radius; // 원의 반지름

        double aspect_ratio = (double)r.width / r.height; // 얼굴 비율 계산

        if (0.75 < aspect_ratio && aspect_ratio < 1.3)
        {
            center.x = cvRound((r.x + r.width * 0.5) * scale); // 원의 중심 X 좌표
            center.y = cvRound((r.y + r.height * 0.5) * scale); // 원의 중심 Y 좌표
            radius = cvRound((r.width + r.height) * 0.25 * scale); // 원의 반지름
            circle(img, center, radius, color, 3, 8, 0); // 원 그리기
        }
        else {
            rectangle(img, Point(cvRound(r.x * scale), cvRound(r.y * scale)),
                Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)),
                color, 3, 8, 0); // 사각형 그리기
        }
            
        if (nestedCascade.empty()) { // 눈 감지기 비어 있는 경우
            continue;
        }
            
        smallImgROI = smallImg(r); // 얼굴 부분 이미지
        nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
            1.1, 2, 0
            //|CASCADE_FIND_BIGGEST_OBJECT
            //|CASCADE_DO_ROUGH_SEARCH
            //|CASCADE_DO_CANNY_PRUNING
            | CASCADE_SCALE_IMAGE,
            Size(30, 30)); // 눈 감지

        for (size_t j = 0; j < nestedObjects.size(); j++)
        {
            Rect nr = nestedObjects[j]; // 눈 좌표
            center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale); // 눈 중심 X 좌표
            center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale); // 눈 중심 Y 좌표
            radius = cvRound((nr.width + nr.height) * 0.25 * scale); // 눈의 반지름
            circle(img, center, radius, color, 3, 8, 0); // 눈에 원 그리기
        }
    }
    imshow("result", img); // 결과 이미지를 화면에 표시
}

/*<detectAndDraw 함수>
입력 이미지를 회색조로 변환하고 크기를 조정합니다.
얼굴을 감지하고, 감지된 얼굴에 원 또는 사각형을 그립니다.
눈이 감지되면, 눈 주변에도 원을 그립니다.
최종 결과를 화면에 표시합니다.*/