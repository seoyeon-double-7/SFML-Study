#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main(void)
{
	RectangleShape rectangle(Vector2f(200, 200));
	rectangle.setFillColor(Color::Blue);

	cout << "���α׷��� ���۵Ǿ����ϴ�." << endl;

	//ȭ�� ũ��, ĸ�� �̸� ����
	RenderWindow app(VideoMode(504, 504), "mazeGame");
	app.setFramerateLimit(60);  //������ ���� ����

    //SFML ���� ���� - �����찡 ������ ���� �ݺ�
    while (app.isOpen())
    {
        Event event;

        //�̺�Ʈ ó��
        while (app.pollEvent(event))
        {
            //���α׷� ���� �̺�Ʈ ó��
            if (event.type == Event::EventType::Closed)
            {
                app.close();
                cout << "���α׷��� ����Ǿ����ϴ�." << endl;
            }
        }

        //���ȭ���� ������� clear
        app.clear(Color::White);

        //�簢�� �׸���
        app.draw(rectangle);

        //�������� ��ũ���� ���
        app.display();
    }

	return 0;
}