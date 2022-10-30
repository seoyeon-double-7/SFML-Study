#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

#define CIRCLE_RADIUS 100.f

int main() {

	int x = 0, y = 0;

	// ���콺 �̵��� ���� ������ Circle ��ü
	CircleShape circle_shape(CIRCLE_RADIUS);
	circle_shape.setFillColor(Color::Green);

	circle_shape.setRadius(CIRCLE_RADIUS);
	circle_shape.setOutlineColor(sf::Color::Red);
	circle_shape.setOutlineThickness(20);
	circle_shape.setPosition(x, y);

	cout << "���α׷��� ���۵Ǿ����ϴ�." << endl;

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
				cout << "���α׷� ����" << endl;
			}

			// ���콺 ��ư ���� �̺�Ʈ
			if (event.type == Event::MouseButtonPressed)
			{
				switch (event.key.code)
				{
				case Mouse::Left:
				{
					circle_shape.setFillColor(Color::Yellow);
					Vector2i pos = Mouse::getPosition(app);
					cout << "���� ��ư ���� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					break;
				}
				case Mouse::Right:
				{
					circle_shape.setFillColor(Color::Magenta);
					Vector2i pos = Mouse::getPosition(app);
					cout << "������ ��ư ���� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					break;
				}
				case Mouse::Middle:
				{
					circle_shape.setFillColor(Color::Black);
					Vector2i pos = Mouse::getPosition(app);
					cout << "�߰� ��ư ���� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					break;
				}
				}

			}

			// ���콺 ��ư �� �� (Released) �̺�Ʈ
			if (event.type == Event::MouseButtonReleased)
			{
				switch (event.key.code)
				{
				case Mouse::Left:
				{
					Vector2i pos = Mouse::getPosition(app);
					cout << "���� ��ư ���� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					circle_shape.setFillColor(Color::Green);
					break;
				}
				case Mouse::Right:
				{
					Vector2i pos = Mouse::getPosition(app);
					cout << "������ ��ư ���� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					circle_shape.setFillColor(Color::Green);
					break;
				}
				case Mouse::Middle:
				{
					Vector2i pos = Mouse::getPosition(app);
					cout << "�߰� ��ư ���� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
					circle_shape.setFillColor(Color::Green);
					break;
				}
				}
			}

			// ���콺 ������ �̺�Ʈ
			switch (event.type)
			{
			case Event::MouseMoved:
			{
				Vector2i pos = Mouse::getPosition(app);
				cout << "�̵� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
				x = pos.x;
				y = pos.y;
				break;
			}

			// ���콺 �� ������ �̺�Ʈ
			case Event::MouseWheelMoved:
			{
				Vector2i pos = Mouse::getPosition(app);
				cout << "�� �̵� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
				break;
			}

			//���콺 �� ��ũ�� �̺�Ʈ
			case Event::MouseWheelScrolled:
			{
				Vector2i pos = Mouse::getPosition(app);
				cout << "�� ��ũ�� : pos.x = " << pos.x << " pos.y = " << pos.y << endl;
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