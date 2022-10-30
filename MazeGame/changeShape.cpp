#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;



int print_text(Text& textMsg, Font& font, int size,
	float x, float y, const Color& color, const Color& outColor, string p);

int main()
{
	float timer = 0;
	Clock clock;
	Text text1;
	string msgStr = "Ready, Go! maincodes !!";
	float x = 200, y = 200;

	// Font 파일 로드
	Font font;
	font.loadFromFile("font/digital-7.ttf");

	// Text1
	print_text(text1, font, 80, 10, 10,
		Color::Black, Color::White, msgStr);

	//origin 설정
	text1.setOrigin(200.f, 200.f);
	text1.setPosition(text1.getOrigin());

	//키보드 입력 따라 움직일 RectangleShape 객체
	RectangleShape rect_shape(Vector2f(200, 200));

	//작은 사각형 5개
	RectangleShape small_rect_shape[5];

	rect_shape.setFillColor(Color::Green);
	rect_shape.setOutlineColor(sf::Color::Red);
	rect_shape.setOutlineThickness(20);
	rect_shape.setPosition(x, y);

	for (int i = 0; i < 5; i++) {
		small_rect_shape[i].setSize(Vector2f(10, 10));
		small_rect_shape[i].setFillColor(Color::Yellow);
		small_rect_shape[i].setOutlineColor(sf::Color::Blue);
		small_rect_shape[i].setOutlineThickness(20);
		small_rect_shape[i].setPosition(x+((i+1)*100),y);
	}

	cout << "프로그램 시작" << endl;

	RenderWindow app(VideoMode(1000, 1000), "change shape");
	app.setFramerateLimit(60);

	while (app.isOpen())
	{
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
		timer += time;

		Event event;

		while (app.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "게임 종료" << endl;
			}
		}

		// 키보드 눌림(Pressed) 이벤트
		if (event.type == Event::KeyPressed)
		{
			if (event.key.code == Keyboard::Space)
			{
				cout << "Space 키 눌림" << endl;

				float speed = 3;

				//작은 사각형 애니메이션 효과
				for (int i = 0; i < 50; i += speed)
				{
					small_rect_shape[0].move(speed * 1, speed * 1);
					app.draw(small_rect_shape[0]);
					app.display();
				}

				//적은 사각형 원 위치
				small_rect_shape[0].setPosition(Vector2f((float)x, (float)y));
				break;

			}
		}

		app.clear(Color::White);

		// rect_shape 위치 보정
		rect_shape.setPosition(Vector2f(x - 100.f, y - 100.f));
		app.draw(rect_shape);

		// 텍스트 이동
		text1.move(1.f, 1.f);

		// 글자 위치 재설정
		if (text1.getPosition().x == 1000 || text1.getPosition().y == 1000)
			text1.setPosition(10, 10);
		// 타이머에 맞춰 글자 크기 확대
		text1.setScale(timer * 1.5f, timer * 1.2f);

		// 글자 크기 재설정
		if (text1.getScale().x == 100 || text1.getScale().y == 100)
			text1.setScale(1.0f, 1.0f);

		// 글자 로테이션 설정
		text1.setRotation(timer * 100);
		app.draw(text1);

		// 작은 사각형 이동
		for (int i = 0; i < 5; i++)
		{
			small_rect_shape[i].move(0, 5.f);
			if (small_rect_shape[i].getPosition().y == 1000)
				small_rect_shape[i].setPosition(x + ((i + 1) * 100), y);

			app.draw(small_rect_shape[i]);
		}

		//큰 사각형 로테이션
		rect_shape.setRotation(timer * 150);
		app.draw(rect_shape);
		
		//약 5초 후에는 타이머 재설정
		if(timer> 5)
			timer= 0;
		cout<< "timerRotate = " << timer<< endl;

		//프레임을 스크린에 출력
		app.display();
	}

	return 0;

}

// Text 설정 함수
int print_text(Text& textMsg, Font& font, int size,
	float x, float y, const Color& color, const Color& outColor, string p)
{
	textMsg.setFont(font); //폰트
	textMsg.setCharacterSize(size); //크기 
	textMsg.setPosition(x, y); //x, y 위치
	textMsg.setFillColor(color); //색
	textMsg.setOutlineColor(outColor); //글자 테두리 색
	textMsg.setOutlineThickness(1.f); //글자 테두리 굵기
	textMsg.setString(p); //출력할 문자열

	return 0;
}