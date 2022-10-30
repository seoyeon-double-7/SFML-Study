#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define CIRCLE_RADIUS 100.f

int main()
{
	float x = 0, y = 0;

	RectangleShape rect_shape(Vector2f(200, 200));
	RectangleShape small_rect_shape(Vector2f(10, 10));

	rect_shape.setFillColor(Color::Green);
	rect_shape.setOutlineColor(sf::Color::Red);
	rect_shape.setOutlineThickness(20);
	rect_shape.setPosition(x, y);

	small_rect_shape.setFillColor(Color::Yellow);
	small_rect_shape.setOutlineColor(sf::Color::Blue);
	small_rect_shape.setOutlineThickness(20);
	small_rect_shape.setPosition(x, y);

	cout << "게임 시작" << endl;

	RenderWindow app(VideoMode(504, 504), "keyboard");
	app.setFramerateLimit(60);



	while (app.isOpen())
	{
		Event event;

		while (app.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "게임 종료" << endl;
			}


			// 키보드 눌림(Pressed) 이벤트
			if (event.type == Event::KeyPressed)
			{
				switch (event.key.code)
				{
				case Keyboard::Left:
				{
					cout << "Left 키 눌림" << endl;
					x -= 10;
					break;
				}
				case Keyboard::Right:
				{
					cout << "Right 키 눌림" << endl;
					x += 10;
					break;
				}
				case Keyboard::Up:
				{
					cout << "Up 키 눌림" << endl;
					y -= 10;
					break;
				}
				case Keyboard::Down:
				{
					cout << "Down 키 눌림" << endl;
					y += 10;
					break;
				}
				case Keyboard::Space:
				{
					cout << "Space 키 눌림" << endl;
					float speed = 3;

					// 작은 사각형 애니메이션 효과
					for (int i = 0; i < 50; i += speed)
					{
						small_rect_shape.move(speed * 1, speed * 1);
						app.draw(small_rect_shape);
						app.display();
					}

					// 작은 사각형 원 위치
					small_rect_shape.setPosition(Vector2f((float)x, (float)y));

					break;
				}
				default:
					cout << "키 눌림((key.code) = " << event.key.code << endl;
					break;
				}
			}

			if (event.type == Event::KeyReleased)
				cout << "키 떼임((key.code) = " << event.key.code << endl;
			
		}
		
		app.clear(Color::White);

		rect_shape.setPosition(Vector2f(x - 100.f, y - 100.f));
		app.draw(rect_shape);

		app.draw(small_rect_shape);

		// 프레임을 스크린에 출력
		app.display();
	}

	return 0;
}