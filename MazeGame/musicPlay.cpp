#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>

using namespace std;
using namespace sf;

void play_sound_detail(const std::string& filename)
{
	SoundBuffer buffer;
	// 오디오 파일 읽기
	if (!buffer.loadFromFile(filename))
	{
		cout << "loadFromFile 에러" << endl;
		return;
	}

	// 오디오 정보 출력
	cout << filename << "을 재생 중 : " << endl;
	cout << " " << buffer.getDuration().asSeconds() << "초" << endl;
	cout << " " << buffer.getSampleRate() << " sample / 초" << endl;
	cout << " " << buffer.getChannelCount() << " 채널" << endl;

	// 오디오 재생
	Sound sound(buffer);
	sound.play();

	// 소리가 재생되는 동안 루프
	while (sound.getStatus() == Sound::Playing)
	{
		sleep(sf::milliseconds(100));

		//재생 위치
		cout << "\r재생 중... " << sound.getPlayingOffset().asSeconds() << " 초   ";
		cout << flush;
	}
	cout << endl << endl;
}

int main()
{
	Clock clock;
	float interval = 0;

	SoundBuffer buffer;
	if (!buffer.loadFromFile("music/새삥.wav"))
	{
		cout << "loadFromFile 에러" << endl;
		return -1;
	}
	Sound sound(buffer);

	cout << "게임 시작" << endl;

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
				cout << "게임 종료" << endl;
			}
		}
			if (((int)interval % 5) == 0)
			{
				cout << "interval = " << interval << endl;
				play_sound_detail("music/bad.wav");

				cout << "music/새삥.wav 재생" << endl;
				sound.play();
			}
			app.clear(Color::Magenta);

			app.display();
		}
	return 0;
	}