#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
	Clock clock;	//��� �ð��� ������ �� �ִ� Clock ��ü ����
	Clock ai_timer;
	float interval = 0, delay1 = 4.0;
	int count = 0;

	const Time ai_time = seconds(0.5f);

	cout << "���� ����" << endl;

	Texture color_off, color_on;
	Sprite sprite_off, sprite_on;

	// �̹��� ���� �б�
	color_on.loadFromFile("images/bg.png");
	color_off.loadFromFile("images/logo.png");

	// Sprite ����
	sprite_on.setTexture(color_on);
	// left top width height
	sprite_on.setTextureRect(IntRect(0, 0, 1500, 900));

	sprite_off.setTexture(color_off);
	sprite_off.setTextureRect(IntRect(-450, -100, 1500, 900));


	// ȭ�� ũ��, ĸ�� �̸� ����
	RenderWindow app(VideoMode(1500, 900), "Timer");
	app.setFramerateLimit(60);	//������ ���� ����

	// �ʴ� 60 ������ ����
	app.setFramerateLimit(60);

	// SFML ���� ���� - ������ ���������� �ݺ�

	while (app.isOpen())
	{
		// �ʴ����� ����ð��� ����
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		interval += time;

		Event event;
		// �̺�Ʈ ó��
		while (app.pollEvent(event)) {
			// ���α׷� ���� �̺�Ʈ ó��
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "���� ����" << endl;
			}
		}

		// 0.5�� ���� timer �����
		if (ai_timer.getElapsedTime() > ai_time)
		{
			ai_timer.restart();
			cout << "ai_timer �����" << endl;
		}

		// 4�� ������ interval �ʱ�ȭ, count +1 ����
		if (interval > delay1)
		{
			cout << "interval = " << interval << "count = " << count << endl;
			interval = 0;
			count++;
		}

		// 2�� ������ ���� ����
		//if (((int)interval % 1) == 0)
			app.draw(sprite_on);
		//else
			app.draw(sprite_off);

		// ������ ��ũ���� ���
		app.display();

	}
	return 0;
}