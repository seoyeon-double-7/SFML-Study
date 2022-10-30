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

	cout << "���α׷��� ���۵Ǿ����ϴ�." << endl;

	// ȭ�� ũ��, ĸ�� �̸� ����
	RenderWindow app(VideoMode(504, 504), "Timer");
	app.setFramerateLimit(60);	//������ ���� ����

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
				cout << "���α׷��� ����Ǿ����ϴ�." << endl;
			}
		}

		// 0.5�� ���� timer �����
		if (ai_timer.getElapsedTime() > ai_time)
		{
			ai_timer.restart();
			cout << "ai_tier..." << endl;
		}

		// 4�� ������ interval �ʱ�ȭ, count +1 ����
		if (interval > delay1)
		{
			cout << "interval = " << interval << "count = " << count << endl;
			interval = 0;
			count++;
		}

		// 2�� ������ ���� ����
		if (((int)interval % 2) == 0)
			app.clear(Color::Magenta);
		else
			app.clear(Color::Blue);

		// ������ ȭ�� ���
		app.display();

	}
	return 0;
}