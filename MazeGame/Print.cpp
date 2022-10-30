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

	cout << "게임 시작" << endl;

	Texture color_off, color_on;
	Sprite sprite_off, sprite_on;

	// 이미지 파일 읽기
	color_on.loadFromFile("images/bg.png");
	color_off.loadFromFile("images/logo.png");

	// Sprite 세팅
	sprite_on.setTexture(color_on);
	// left top width height
	sprite_on.setTextureRect(IntRect(0, 0, 1500, 900));

	sprite_off.setTexture(color_off);
	sprite_off.setTextureRect(IntRect(-450, -100, 1500, 900));


	// 화면 크기, 캡션 이름 설정
	RenderWindow app(VideoMode(1500, 900), "Timer");
	app.setFramerateLimit(60);	//프레임 비율 설정

	// 초당 60 프레임 설정
	app.setFramerateLimit(60);

	// SFML 메인 루프 - 윈도우 닫힐때까지 반복

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
				cout << "게임 종료" << endl;
			}
		}

		// 0.5초 마다 timer 재시작
		if (ai_timer.getElapsedTime() > ai_time)
		{
			ai_timer.restart();
			cout << "ai_timer 재시작" << endl;
		}

		// 4초 단위로 interval 초기화, count +1 증가
		if (interval > delay1)
		{
			cout << "interval = " << interval << "count = " << count << endl;
			interval = 0;
			count++;
		}

		// 2초 단위로 배경색 변경
		//if (((int)interval % 1) == 0)
			app.draw(sprite_on);
		//else
			app.draw(sprite_off);

		// 프레임 스크린에 출력
		app.display();

	}
	return 0;
}