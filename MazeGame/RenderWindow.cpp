#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main(void)
{
	RectangleShape rectangle(Vector2f(200, 200));
	rectangle.setFillColor(Color::Blue);

	cout << "프로그램이 시작되었습니다." << endl;

	//화면 크기, 캡션 이름 설정
	RenderWindow app(VideoMode(504, 504), "mazeGame");
	app.setFramerateLimit(60);  //프레임 비율 설정

    //SFML 메인 루프 - 윈도우가 닫힐때 까지 반복
    while (app.isOpen())
    {
        Event event;

        //이벤트 처리
        while (app.pollEvent(event))
        {
            //프로그램 종료 이벤트 처리
            if (event.type == Event::EventType::Closed)
            {
                app.close();
                cout << "프로그램이 종료되었습니다." << endl;
            }
        }

        //배경화면을 흰색으로 clear
        app.clear(Color::White);

        //사각형 그리기
        app.draw(rectangle);

        //프레임을 스크린에 출력
        app.display();
    }

	return 0;
}