#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define CIRCLE_RADIUS 100.f

int main() {

	int x = 0, y = 0;

	// 마우스 이동시 따라 움직일 Circle 객체
	CircleShape circle_shape(CIRCLE_RADIUS);
	circle_shape.setFillColor(Color::Green);

	circle_shape.setRadius(CIRCLE_RADIUS);
	circle_shape.setOutlineColor(sf::Color::Red);
	circle_shape.setOutlineThickness(20);
	circle_shape.setPosition(x, y);

	cout << "프로그램이 시작되었습니다." << endl;

	RenderWindow app(VideoMode(504, 504), "mouse Event");
	app.setFramerateLimit(60);

	while (app.isOpen())
	{
		Event event;

		while (app.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "프로그램 종료" << endl;
			}

			// 마우스 버튼 눌림 이벤트
			if (event.type == Event::MouseButtonPressed)
			{
				switch (event.key.code)
				{
				case Mouse::Left:
				{
					circle_shape.setFillColor(Color::Yellow);
					Vector2i pos = Mouse::getPosition(app);
					cout << "왼쪽 버튼 눌림 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					break;
				}
				case Mouse::Right:
				{
					circle_shape.setFillColor(Color::Magenta);
					Vector2i pos = Mouse::getPosition(app);
					cout << "오른쪽 버튼 눌림 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					break;
				}
				case Mouse::Middle:
				{
					circle_shape.setFillColor(Color::Black);
					Vector2i pos = Mouse::getPosition(app);
					cout << "중간 버튼 눌림 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					break;
				}
				}

			}

			// 마우스 버튼 뗄 때 (Released) 이벤트
			if (event.type == Event::MouseButtonReleased)
			{
				switch (event.key.code)
				{
				case Mouse::Left:
				{
					Vector2i pos = Mouse::getPosition(app);
					cout << "왼쪽 버튼 눌림 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					circle_shape.setFillColor(Color::Green);
					break;
				}
				case Mouse::Right:
				{
					Vector2i pos = Mouse::getPosition(app);
					cout << "오른쪽 버튼 눌림 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					circle_shape.setFillColor(Color::Green);
					break;
				}
				case Mouse::Middle:
				{
					Vector2i pos = Mouse::getPosition(app);
					cout << "중간 버튼 눌림 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					circle_shape.setFillColor(Color::Green);
					break;
				}
				}
			}

			// 마우스 움직임 이벤트
			switch (event.type)
			{
			case Event::MouseMoved:
			{
				Vector2i pos = Mouse::getPosition(app);
				cout << "이동 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
				x = pos.x;
				y = pos.y;
				break;
			}

			// 마우스 휠 움직임 이벤트
			case Event::MouseWheelMoved:
			{
				Vector2i pos = Mouse::getPosition(app);
				cout << "췰 이동 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
				break;
			}

			//마우스 휠 스크롤 이벤트
			case Event::MouseWheelScrolled:
			{
				Vector2i pos = Mouse::getPosition(app);
				cout << "휠 스크롤 : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
				break;
			}
			}
		}

		app.clear(Color::White);

		circle_shape.setPosition(Vector2f(x - 100.f, y - 100.f));
		app.draw(circle_shape);

		app.display();
	}

	return 0;
}