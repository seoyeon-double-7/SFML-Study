#include <SFML/Graphics.hpp>
#include <iostream>

#define MOVE_PIXEL 9.f
#define MAX_ENEMY_COUNT 20

using namespace std;
using namespace sf;

float rand_number(int max)
{
	float num = (float)(rand() % max + 1);
	return num;
}

int main()
{
	Clock clock;
	float interval = 0;
	float rectx_p = 0, recty_p = 0;
	float rectx_n = 50, recty_n = 50;

	srand((unsigned int)time(NULL));

	RectangleShape rect_player;
	vector<RectangleShape> enemies;
	RectangleShape enemy_rect;

	rect_player.setSize(sf::Vector2f(15, 15));
	rect_player.setOutlineColor(sf::Color::Green);
	rect_player.setOutlineThickness(2);
	rect_player.setPosition(150, 400);

	for (int i = 0; i < MAX_ENEMY_COUNT; i++)
	{
		enemy_rect.setSize(Vector2f(rand_number(25), rand_number(25)));
		enemy_rect.setOutlineColor(sf::Color::Red);
		enemy_rect.setOutlineThickness(5);
		enemy_rect.setPosition(rand_number(500), recty_n);
		Vector2f rpos = enemy_rect.getPosition();
		cout << "rpos.x = " << rpos.x << "rpos.y = " << rpos.y << endl;
		enemies.push_back(enemy_rect);
	}

	cout << "게임 시작" << endl;

	RenderWindow app(VideoMode(504, 504), "Collision");
	app.setFramerateLimit(60);



	while (app.isOpen())
	{

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		interval += time;

		Event event;

		while (app.pollEvent(event))
		{
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "게임 종료" << endl;
			}

			if (Keyboard::isKeyPressed(Keyboard::Left))
				rect_player.move(-MOVE_PIXEL, 0);
			if (Keyboard::isKeyPressed(Keyboard::Right))
				rect_player.move(MOVE_PIXEL, 0);
			if (Keyboard::isKeyPressed(Keyboard::Up))
				rect_player.move(0, -MOVE_PIXEL);
			if (Keyboard::isKeyPressed(Keyboard::Down))
				rect_player.move(0, MOVE_PIXEL);

		}

		app.clear(Color::Black);

		if ((int)interval % 1 == 0)
		{
			vector<RectangleShape>::iterator iter;
			for (iter = enemies.begin(); iter != enemies.end(); iter++)
			{
				// 내려오는 속도를 랜덤하게 설정
				(*iter).move(0, rand_number(3));

				Vector2f pos = (*iter).getPosition();
				if (pos.y > 500)
					(*iter).setPosition(rand_number(400), recty_n);
			}
		}

		//상자들에 대한 글로벌 바운드 구하고, 플레이어 상자와 충돌 감지
		vector<RectangleShape>::iterator iter;
		for (int i = 0; i < enemies.size(); i++)
		{
			if ((enemies[i].getGlobalBounds()).intersects(rect_player.getGlobalBounds()))
			{
				enemies.erase(enemies.begin() + i);
				cout << i << "번째 상자와 충돌 발생!" << endl;
			}
		}
		
		//적 상자 그리기
		for (iter = enemies.begin(); iter != enemies.end(); iter++)
			app.draw(*iter);

		//플레이어 상자 그리기
		app.draw(rect_player);

		// 프레임을 스크린에 출력
		app.display();

		if (enemies.size() == 0)
		{
			cout << "충돌시험 끝남. 게임 종료." << endl;
			app.close();

			break;
		}
	}

	return 0;
}