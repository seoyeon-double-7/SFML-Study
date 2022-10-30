#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>

using namespace std;
using namespace sf;

void play_sound_detail(const std::string& filename)
{
	SoundBuffer buffer;
	// ����� ���� �б�
	if (!buffer.loadFromFile(filename))
	{
		cout << "loadFromFile ����" << endl;
		return;
	}

	// ����� ���� ���
	cout << filename << "�� ��� �� : " << endl;
	cout << " " << buffer.getDuration().asSeconds() << "��" << endl;
	cout << " " << buffer.getSampleRate() << " sample / ��" << endl;
	cout << " " << buffer.getChannelCount() << " ä��" << endl;

	// ����� ���
	Sound sound(buffer);
	sound.play();

	// �Ҹ��� ����Ǵ� ���� ����
	while (sound.getStatus() == Sound::Playing)
	{
		sleep(sf::milliseconds(100));

		//��� ��ġ
		cout << "\r��� ��... " << sound.getPlayingOffset().asSeconds() << " ��   ";
		cout << flush;
	}
	cout << endl << endl;
}

int main()
{
	Clock clock;
	float interval = 0;

	SoundBuffer buffer;
	if (!buffer.loadFromFile("music/����.wav"))
	{
		cout << "loadFromFile ����" << endl;
		return -1;
	}
	Sound sound(buffer);

	cout << "���� ����" << endl;

	RenderWindow app(VideoMode(504, 504), "music Play");
	app.setFramerateLimit(60);

	while(app.isOpen())
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
				cout << "���� ����" << endl;
			}
		}
			if (((int)interval % 5) == 0)
			{
				cout << "interval = " << interval << endl;
				play_sound_detail("music/bad.wav");

				cout << "music/����.wav ���" << endl;
				sound.play();
			}
			app.clear(Color::Magenta);

			app.display();
		}
	return 0;
	}