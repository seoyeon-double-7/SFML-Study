#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int textPrint(Text& textMsg, Font& font, int size,
	float x, float y, const Color& color, const Color& outColor, string p)
{
	textMsg.setFont(font);
	textMsg.setCharacterSize(size);
	textMsg.setPosition(x, y);
	textMsg.setFillColor(color);
	textMsg.setOutlineColor(outColor);
	textMsg.setOutlineThickness(1.f);
	textMsg.setString(p);	

	return 0;
}

int main()
{
	Text text1, text2, text3;
	Uint8 r = 0, g = 0, b = 0;
	string msgStr = "Ready, Go! maincodes !!";
	int x = 0, y = 0;

	Clock clock;
	float interval = 0;

	cout << "프로그램 시작" << endl;

	RenderWindow app(VideoMode(1200, 504), "font");
	app.setFramerateLimit(60);

	Font font;
	font.loadFromFile("font/digital-7.ttf");

	textPrint(text1, font, 30, 0, 110,
		Color::White, Color::White,
		msgStr);
	textPrint(text2, font, 100, 0, 0,
		Color::White, Color::Magenta,
		msgStr);
	textPrint(text3, font, 150, 0, 110,
		Color::Cyan, Color::White,
		msgStr);

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
		}

		app.clear(Color::Black);

		/*if (((int)interval % 2) == 0)
		{
			x += 1.0;
			y += 1.0;
			text1.setPosition(x, y);
			Vector2f pos = text1.getPosition();
			cout << "pos.x = " << pos.x << " pos.y = " << pos.y << endl;
		}*/

		app.draw(text1);
		app.draw(text2);
		app.draw(text3);

		app.display();
	}
	return 0;
}