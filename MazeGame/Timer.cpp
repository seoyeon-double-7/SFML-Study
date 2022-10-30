#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
	Clock clock;	//경과 시간을 측정할 수 있는 Clock 객체 선언
	Clock ai_timer;
	float interval = 0, delay1 = 4.0;
	int count = 0;

	const Time ai_time = seconds(0.5f);

	cout << "프로그램이 시작되었습니다." << endl;

	// 화면 크기, 캡션 이름 설정
	RenderWindow app(VideoMode(504, 504), "Timer");
	app.setFramerateLimit(60);	//프레임 비율 설정

	while (app.isOpen())
	{
		// 초단위로 경과시간을 구함
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		interval += time;

		Event event;
		// 이벤트 처리
		while (app.pollEvent(event)) {
			// 프로그램 종료 이벤트 처리
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "프로그램이 종료되었습니다." << endl;
			}
		}

		// 0.5초 마다 timer 재시작
		if (ai_timer.getElapsedTime() > ai_time)
		{
			ai_timer.restart();
			cout << "ai_tier..." << endl;
		}

		// 4초 단위로 interval 초기화, count +1 증가
		if (interval > delay1)
		{
			cout << "interval = " << interval << "count = " << count << endl;
			interval = 0;
			count++;
		}

		// 2초 단위로 배경색 변경
		if (((int)interval % 2) == 0)
			app.clear(Color::Magenta);
		else
			app.clear(Color::Blue);

		// 윈도우 화면 출력
		app.display();

	}
	return 0;
}