#include "Level.h"
#include <iostream>
#include "Blocks.h"
#include "Platforms.h"
#include "Pipe.h"
#include "Staircase.h"
#include "Enemy.h"
#include "Item.h"
#include <fstream>
#include <string>

Level::Level()
{
	using namespace std;
	m_GroundTexture = new sf::Texture();
	m_HitBlockTexture = new sf::Texture();
	if (!m_GroundTexture->loadFromFile("groundtexture.jpg"))
	{
		std::cout << "Failed to load ground sprite" << std::endl;
	}

	if (!m_HitBlockTexture->loadFromFile("hitblock.jpg"))
	{
		std::cout << "Failed to load ground sprite" << std::endl;
	}






	fstream newfile;
	newfile.open("Level1.txt", ios::in); //open a file to perform read operation using file object
	if (newfile.is_open()) {   //checking whether the file is open
		string tp;
		std::string delimiter = "|";
		unsigned int i = 0;
		bool isBlock = false;
		float width = 0;
		float height = 0;
		float posX = 0;
		float posY = 0;
		while (getline(newfile, tp))
		{ //read data from file object and put it into string.
			//cout << tp << "\n"; //print the data of the string
			size_t pos = 0;
			std::string token;

			while ((pos = tp.find(delimiter)) != std::string::npos) {
				token = tp.substr(0, pos);
				i++;

				if (token == "itemblock")
				{
					i = 1;
				}
				else if (token == "true" || token == "false")
				{
					if (token == "true")
					{
						isBlock = true;
					}
					else
					{
						isBlock = false;
					}
				}
				else if (i == 3)
				{
					width = stof(token);
				}
				else if (i == 4)
				{
					height = stof(token);
				}
				else if (i == 5)
				{
					posX = stof(token);
				}
				else if (i == 6)
				{
					posY = stof(token);
					i = 0;
					Blocks* itemblock1 = new Blocks(isBlock, sf::Vector2f(width, height));
					itemblock1->getPlatform().setPosition(posX, posY);
					m_Platforms.push_back(itemblock1);
				}

				if (token == "platform")
				{
					i = 7;
				}
				else if (token == "true" || token == "false")
				{
					if (token == "true")
					{
						isBlock = true;
					}
					else
					{
						isBlock = false;
					}
				}
				else if (i == 9)
				{
					width = stof(token);
				}
				else if (i == 10)
				{
					height = stof(token);
				}
				else if (i == 11)
				{
					posX = stof(token);
				}
				else if (i == 12)
				{
					posY = stof(token);
					i = 0;
					Platforms* platform = new Platforms(sf::RectangleShape(sf::Vector2f(width, height)), isBlock);
					platform->getPlatform().setPosition(posX, posY);
					platform->getPlatform().setTexture(m_GroundTexture);
					m_Platforms.push_back(platform);

				}

				if (token == "pipe")
				{
					i = 13;
				}
				else if (i == 14)
				{
					width = stof(token);
				}
				else if (i == 15)
				{
					height = stof(token);
				}
				else if (i == 16)
				{
					posX = stof(token);
				}
				else if (i == 17)
				{
					posY = stof(token);
					i = 0;
					Pipe* Pipe1 = new Pipe(sf::Vector2f(width, height));
					Pipe1->getPlatform().setPosition(posX, posY);
					m_Platforms.push_back(Pipe1);

				}

				if (token == "enemy")
				{
					i = 18;
				}
				else if (token == "true" || token == "false")
				{
					if (token == "true")
					{
						isBlock = true;
					}
					else
					{
						isBlock = false;
					}
				}
				else if (i == 20)
				{
					width = stof(token);
				}
				else if (i == 21)
				{
					height = stof(token);
				}
				else if (i == 22)
				{
					posX = stof(token);
				}
				else if (i == 23)
				{
					posY = stof(token);
					i = 0;
					Enemy* goomba1 = new Enemy(width, height, isBlock);
					goomba1->getSprite().setPosition(posX, posY);
					m_Enemies.push_back(goomba1);
				}

				if (token == "stairblock")
				{
					i = 24;
				}
				else if (token == "true" || token == "false")
				{
					if (token == "true")
					{
						isBlock = true;
					}
					else
					{
						isBlock = false;
					}
				}
				else if (i == 26)
				{
					width = stof(token);
				}
				else if (i == 27)
				{
					height = stof(token);
				}
				else if (i == 28)
				{
					posX = stof(token);
				}
				else if (i == 29)
				{
					posY = stof(token);
					i = 0;
					Staircase* stairblock1 = new Staircase(sf::Vector2f(width, height));
					stairblock1->getPlatform().setPosition(posX, posY);
					stairblock1->getIsBrickBlock() = isBlock;
					m_Platforms.push_back(stairblock1);
				}

				if (token == "flag")
				{
					i = 30;
				}
				else if (token == "true" || token == "false")
				{
					if (token == "true")
					{
						isBlock = true;
					}
					else
					{
						isBlock = false;
					}
				}
				else if (i == 32)
				{
					width = stof(token);
				}
				else if (i == 33)
				{
					height = stof(token);
				}
				else if (i == 34)
				{
					posX = stof(token);
				}
				else if (i == 35)
				{
					posY = stof(token);
					i = 0;
					sf::Texture* m_FlagTexture = new sf::Texture();
					if (!m_FlagTexture->loadFromFile("Flag.png"))
					{
						std::cout << "Failed to load flag sprite" << std::endl;
					}
					sf::RectangleShape flag(sf::Vector2f(width, height));
					flag.setTexture(m_FlagTexture);
					Platforms* flagPole = new Platforms(flag, false);
					flagPole->getPlatform().setPosition(posX, posY);
					flagPole->getIsFlag() = isBlock;
					m_Platforms.push_back(flagPole);
				}

				if (token == "hole")
				{
					i = 36;
				}
				else if (i == 37)
				{
					width = stof(token);
				}
				else if (i == 38)
				{
					height = stof(token);
				}
				else if (i == 39)
				{
					posX = stof(token);
				}
				else if (i == 40)
				{
					posY = stof(token);
					i = 0;
					sf::RectangleShape* koopaHole = new sf::RectangleShape(sf::Vector2f(width, height));
					koopaHole->setPosition(posX, posY);
					m_Holes.push_back(koopaHole);
				}
				tp.erase(0, pos + delimiter.length());
			}

		}

		newfile.close(); //close the file object.
	}

	//Blocks* itemblock1= new Blocks(true, sf::Vector2f(100, 100));
	//itemblock1->getPlatform().setPosition(1500, 400);
	//m_Platforms.push_back(itemblock1);

	//Blocks* brickblock1= new Blocks(false, sf::Vector2f(100, 100));
	//brickblock1->getPlatform().setPosition(2000, 400);
	//m_Platforms.push_back(brickblock1);

	//Blocks* itemblock2= new Blocks(true, sf::Vector2f(100, 100));
	//itemblock2->getPlatform().setPosition(2100, 400);
	//m_Platforms.push_back(itemblock2);



	//Blocks* brickblock2= new Blocks(false, sf::Vector2f(100, 100));
	//brickblock2->getPlatform().setPosition(2200, 400);
	//m_Platforms.push_back(brickblock2);

	//Blocks* itemblock3= new Blocks(true, sf::Vector2f(100, 100));
	//itemblock3->getPlatform().setPosition(2300, 400);
	//m_Platforms.push_back(itemblock3);

	//Blocks* brickblock3= new Blocks(false, sf::Vector2f(100, 100));
	//brickblock3->getPlatform().setPosition(2400, 400);
	//m_Platforms.push_back(brickblock3);

	//Blocks* itemblock4= new Blocks(true, sf::Vector2f(100, 100));
	//itemblock4->getPlatform().setPosition(2200, 100);
	//m_Platforms.push_back(itemblock4);

	//Pipe* Pipe1= new Pipe(sf::Vector2f(200, 200));
	//Pipe1->getPlatform().setPosition(3000, 550);
	//m_Platforms.push_back(Pipe1);

	//Pipe* Pipe2= new Pipe(sf::Vector2f(200, 300));
	//Pipe2->getPlatform().setPosition(4250, 450);
	//m_Platforms.push_back(Pipe2);

	//Enemy* goomba2 = new Enemy(4450, 5250, true);
	//goomba2->getSprite().setPosition(4450, 740);
	//m_Enemies.push_back(goomba2);

	//Pipe* Pipe3= new Pipe(sf::Vector2f(200, 350));
	//Pipe3->getPlatform().setPosition(5250, 400);
	//m_Platforms.push_back(Pipe3);

	//Enemy* goomba3 = new Enemy(5450, 6500, true);
	//goomba3->getSprite().setPosition(5700, 740);
	//m_Enemies.push_back(goomba3);

	//Enemy* goomba4 = new Enemy(5450, 6500, true);
	//goomba4->getSprite().setPosition(5900, 740);
	//m_Enemies.push_back(goomba4);

	//Pipe* Pipe4= new Pipe(sf::Vector2f(200, 350));
	//Pipe4->getPlatform().setPosition(6500, 400);
	//m_Platforms.push_back(Pipe4);


	
	//for (unsigned int i = 0; i < 8; i++)
	//{
		//Platforms* platform = new Platforms(sf::RectangleShape(sf::Vector2f(1000, 400)), true);
		//platform->getPlatform().setPosition(200.f + 1000 * i, 750);
		//platform->getPlatform().setTexture(m_GroundTexture);
		//m_Platforms.push_back(platform);

	//}

	//for (unsigned int i = 0; i < 2; i++)
	//{
		//Platforms* platform = new Platforms(sf::RectangleShape(sf::Vector2f(1000, 400)), true);
		//platform->getPlatform().setPosition(8400.f + 1000 * i, 750);
		//platform->getPlatform().setTexture(m_GroundTexture);
		//m_Platforms.push_back(platform);

	//}

	//Blocks* brickblock4= new Blocks(false, sf::Vector2f(100, 100));
	//brickblock4->getPlatform().setPosition(9400, 400);
	//m_Platforms.push_back(brickblock4);


	//Blocks* itemblock5= new Blocks(true, sf::Vector2f(100, 100));
	//itemblock5->getPlatform().setPosition(9500, 400);
	//m_Platforms.push_back(itemblock5);

	//Blocks* brickblock5= new Blocks(false, sf::Vector2f(100, 100));
	//brickblock5->getPlatform().setPosition(9600, 400);
	//m_Platforms.push_back(brickblock5);

	//for (unsigned int i = 0; i < 10; i++)
	//{
	//	Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
	//	blockrow->getPlatform().setPosition(9700.f + 100*i, 25);
	//	m_Platforms.push_back(blockrow);
	//}

	//Enemy* goomba5 = new Enemy(9700, 10700, true);
	//goomba5->getSprite().setPosition(9800, 10);
	//m_Enemies.push_back(goomba5);

	//Enemy* goomba6 = new Enemy(9700, 10700, true);
	//goomba6->getSprite().setPosition(10000, 10);
	//m_Enemies.push_back(goomba6);


	/*for (unsigned int i = 0; i < 8; i++)
	{
		Platforms* platform = new Platforms(sf::RectangleShape(sf::Vector2f(1000, 400)), true);
		platform->getPlatform().setPosition(10600.f + 1000 * i, 750);
		platform->getPlatform().setTexture(m_GroundTexture);
		m_Platforms.push_back(platform);

	}
	*/
	/*
	sf::RectangleShape* koopaHole = new sf::RectangleShape(sf::Vector2f(200, 1000));
	koopaHole->setPosition(10400, 650);
	m_Holes.push_back(koopaHole);
	*/
	/*for (unsigned int i = 0; i < 3; i++)
	{
		Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
		blockrow->getPlatform().setPosition(11000.f + 100 * i, 25);
		m_Platforms.push_back(blockrow);
	}
	*/
	//Blocks* itemblock6= new Blocks(true, sf::Vector2f(100, 100));
	//itemblock6->getPlatform().setPosition(11300, 25);
	//m_Platforms.push_back(itemblock6);

	//Blocks* brickblock6= new Blocks(false, sf::Vector2f(100, 100));
	//brickblock6->getPlatform().setPosition(11300, 400);
	//m_Platforms.push_back(brickblock6);



	//Enemy* goomba7 = new Enemy(10600, 16200, true);
	//goomba7->getSprite().setPosition(11000, 740);
	//m_Enemies.push_back(goomba7);

	//Enemy* goomba8 = new Enemy(10600, 16200, true);
	//goomba8->getSprite().setPosition(11200, 740);
	//m_Enemies.push_back(goomba8);

	/*for (unsigned int i = 0; i < 2; i++)
	{
		Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
		blockrow->getPlatform().setPosition(12000.f + 100 * i, 400);
		m_Platforms.push_back(blockrow);
	}
	*/
	//Enemy* koopa = new Enemy(10600, 16200, false);
	//koopa->getSprite().setPosition(12000, 740);
	//m_Enemies.push_back(koopa);

	//for (unsigned int i = 0; i < 3; i++)
	//{
	//	Blocks* itemblockrow = new Blocks(true, sf::Vector2f(100, 100));
	//	itemblockrow->getPlatform().setPosition(13000.f + 300 * i, 400);
	//	m_Platforms.push_back(itemblockrow);
	//}

	//Enemy* goomba9 = new Enemy(10600, 16200, true);
	//goomba9->getSprite().setPosition(13900, 740);
	//m_Enemies.push_back(goomba9);

	//Enemy* goomba10 = new Enemy(10600, 16200, true);
	//goomba10->getSprite().setPosition(14100, 740);
	//m_Enemies.push_back(goomba10);

	//Blocks* itemblock7= new Blocks(true, sf::Vector2f(100, 100));
	//itemblock7->getPlatform().setPosition(13300, 25);
	//m_Platforms.push_back(itemblock7);

	//Blocks* brickblock7= new Blocks(false, sf::Vector2f(100, 100));
	//brickblock7->getPlatform().setPosition(14600, 400);
	//m_Platforms.push_back(brickblock7);

	/*for (unsigned int i = 0; i < 3; i++)
	{
		Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
		blockrow->getPlatform().setPosition(14800.f + 100 * i, 25);
		m_Platforms.push_back(blockrow);
	}
	*/
	/*Enemy* goomba11 = new Enemy(10600, 16200, true);
	goomba11->getSprite().setPosition(14500, 740);
	m_Enemies.push_back(goomba11);

	Enemy* goomba12 = new Enemy(10800, 16200, true);
	goomba12->getSprite().setPosition(14700, 740);
	m_Enemies.push_back(goomba12);

	Enemy* goomba13 = new Enemy(10800, 16200, true);
	goomba13->getSprite().setPosition(14900, 740);
	m_Enemies.push_back(goomba13);

	Enemy* goomba14 = new Enemy(10800, 16200, true);
	goomba14->getSprite().setPosition(15100, 740);
	m_Enemies.push_back(goomba14);
	*/
	//Blocks* brickblock8= new Blocks(false, sf::Vector2f(100, 100));
	//brickblock8->getPlatform().setPosition(15500, 25);
	//m_Platforms.push_back(brickblock8);

	/*for (unsigned int i = 0; i < 2; i++)
	{
		Blocks* itemblockrow = new Blocks(true, sf::Vector2f(100, 100));
		itemblockrow->getPlatform().setPosition(15600.f + 100 * i, 25);
		m_Platforms.push_back(itemblockrow);
	}
	*/
	/*for (unsigned int i = 0; i < 2; i++)
	{
		Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
		blockrow->getPlatform().setPosition(15600.f + 100 * i, 400);
		m_Platforms.push_back(blockrow);
	}*/
	//Blocks* brickblock9= new Blocks(false, sf::Vector2f(100, 100));
	//brickblock9->getPlatform().setPosition(15800, 25);
	//m_Platforms.push_back(brickblock9);

	/*for (unsigned int i = 0; i < 4; i++)
	{
		Staircase* stairblock= new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(16200.f + 100 * i, 650);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 3; i++)
	{
		Staircase* stairblock= new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(16300.f + 100 * i, 550);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 2; i++)
	{
		Staircase* stairblock= new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(16400.f + 100 * i, 450);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	Staircase* stairblock1= new Staircase(sf::Vector2f(100, 100));
	stairblock1->getPlatform().setPosition(16500.f, 350);
	stairblock1->getIsBrickBlock() = true;
	m_Platforms.push_back(stairblock1);
	*/

	/*for (unsigned int i = 0; i < 4; i++)
	{
		Staircase* stairblock= new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(16900.f + 100 * i, 650);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 3; i++)
	{
		Staircase* stairblock= new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(16900.f + 100 * i, 550);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 2; i++)
	{
		Staircase* stairblock= new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(16900.f + 100 * i, 450);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	Staircase* stairblock2= new Staircase(sf::Vector2f(100, 100));
	stairblock2->getPlatform().setPosition(16900.f, 350);
	stairblock2->getIsBrickBlock() = true;
	m_Platforms.push_back(stairblock2);
	*/
	/*for (unsigned int i = 0; i < 5; i++)
	{
		Staircase* stairblock= new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(18100.f + 100 * i, 650);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 4; i++)
	{
		Staircase* stairblock= new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(18200.f + 100 * i, 550);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 3; i++)
	{
		Staircase* stairblock= new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(18300.f + 100 * i, 450);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}

	for (unsigned int i = 0; i < 2; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(18400.f + 100 * i, 350);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	*/
	/*for (unsigned int i = 0; i < 8; i++)
	{
		Platforms* platform = new Platforms(sf::RectangleShape(sf::Vector2f(1000, 400)), true);
		platform->getPlatform().setPosition(18800.f + 1000 * i, 750);
		platform->getPlatform().setTexture(m_GroundTexture);
		m_Platforms.push_back(platform);

	}
	*/

	/*for (unsigned int i = 0; i < 4; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(18800.f + 100 * i, 650);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 3; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(18800.f + 100 * i, 550);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 2; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(18800.f + 100 * i, 450);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	Staircase* stairblock3 = new Staircase(sf::Vector2f(100, 100));
	stairblock3->getPlatform().setPosition(18800.f, 350);
	stairblock3->getIsBrickBlock() = true;
	m_Platforms.push_back(stairblock3);
	*/
	//Pipe* Pipe5 = new Pipe(sf::Vector2f(200, 200));
	//Pipe5->getPlatform().setPosition(19700, 550);
	//m_Platforms.push_back(Pipe5);
	/*
	for (unsigned int i = 0; i < 2; i++)
	{
		Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
		blockrow->getPlatform().setPosition(20500.f + 100 * i, 400);
		m_Platforms.push_back(blockrow);
	}

	Blocks* itemblock8 = new Blocks(true, sf::Vector2f(100, 100));
	itemblock8->getPlatform().setPosition(20700, 400);
	m_Platforms.push_back(itemblock8);

	Blocks* brickblock10 = new Blocks(false, sf::Vector2f(100, 100));
	brickblock10->getPlatform().setPosition(20800, 400);
	m_Platforms.push_back(brickblock10);
	*/
/*
	Enemy* goomba15 = new Enemy(19900, 21800, true);
	goomba15->getSprite().setPosition(21000, 740);
	m_Enemies.push_back(goomba15);

	Enemy* goomba16 = new Enemy(19900, 21800, true);
	goomba16->getSprite().setPosition(21200, 740);
	m_Enemies.push_back(goomba16);

	Pipe* Pipe6 = new Pipe(sf::Vector2f(200, 200));
	Pipe6->getPlatform().setPosition(21800, 550);
	m_Platforms.push_back(Pipe6);
	*/
/*
	for (unsigned int i = 0; i < 9; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(22000.f + 100 * i, 650);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 8; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(22100.f + 100 * i, 550);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 7; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(22200.f + 100 * i, 450);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 6; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(22300.f + 100 * i, 350);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 5; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(22400.f + 100 * i, 250);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 4; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(22500.f + 100 * i, 150);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 3; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(22600.f + 100 * i, 50);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	for (unsigned int i = 0; i < 2; i++)
	{
		Staircase* stairblock = new Staircase(sf::Vector2f(100, 100));
		stairblock->getPlatform().setPosition(22700.f + 100 * i, -50);
		stairblock->getIsBrickBlock() = true;
		m_Platforms.push_back(stairblock);
	}
	*/
/*
	Staircase* flagBase = new Staircase(sf::Vector2f(100, 100));
	flagBase->getPlatform().setPosition(24000, 650);
	flagBase->getIsBrickBlock() = true;
	m_Platforms.push_back(flagBase);
*/

for (unsigned int i = 0; i < 20; i++)
{
	Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
	blockrow->getPlatform().setPosition(900.f, -1900.f - 100*i);
	blockrow->getPlatform().setFillColor(sf::Color::Green);
	m_Platforms.push_back(blockrow);
}

for (unsigned int i = 0; i < 4; i++)
{
	Platforms* platform = new Platforms(sf::RectangleShape(sf::Vector2f(1000, 400)), true);
	platform->getPlatform().setPosition(1000.f * i, -1900.f);
	platform->getPlatform().setTexture(m_GroundTexture);
	platform->getPlatform().setFillColor(sf::Color::Green);
	m_Platforms.push_back(platform);

}

for (unsigned int i = 0; i < 10; i++)
{
	Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
	blockrow->getPlatform().setPosition(1400.f + 100 * i, -2000);
	blockrow->getPlatform().setFillColor(sf::Color::Green);
	m_Platforms.push_back(blockrow);
}
for (unsigned int i = 0; i < 10; i++)
{
	Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
	blockrow->getPlatform().setPosition(1400.f + 100 * i, -2100);
	blockrow->getPlatform().setFillColor(sf::Color::Green);
	m_Platforms.push_back(blockrow);
}
for (unsigned int i = 0; i < 10; i++)
{
	Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
	blockrow->getPlatform().setPosition(1400.f + 100 * i, -2200);
	blockrow->getPlatform().setFillColor(sf::Color::Green);
	m_Platforms.push_back(blockrow);
}

for (unsigned int i = 0; i < 10; i++)
{
	Blocks* blockrow = new Blocks(false, sf::Vector2f(100, 100));
	blockrow->getPlatform().setPosition(1400.f + 100 * i, -2200);
	blockrow->getPlatform().setFillColor(sf::Color::Green);
	m_Platforms.push_back(blockrow);
}
Pipe* Pipe7 = new Pipe(sf::Vector2f(200, 2300));
Pipe7->getPlatform().setPosition(2900, -4200);
m_Platforms.push_back(Pipe7);

Pipe* Pipe6 = new Pipe(sf::Vector2f(200, 200));
Pipe6->getPlatform().setPosition(2800, -1880);
Pipe6->getPlatform().setRotation(270);
m_Platforms.push_back(Pipe6);

for (unsigned int i = 0; i < 7; i++)
{
	Item* coin = new Item(false);
	coin->getSprite().setPosition(1450.f + 150*i, -2300);
	coin->m_IsStaticCoin = true;
	coin->getSprite().setScale(.15f, .15f);
	m_Items.push_back(coin);

}

for (unsigned int i = 0; i < 7; i++)
{
	Item* coin = new Item(false);
	coin->getSprite().setPosition(1450.f + 150 * i, -2450);
	coin->m_IsStaticCoin = true;
	coin->getSprite().setScale(.15f, .15f);
	m_Items.push_back(coin);

}

for (unsigned int i = 0; i < 5; i++)
{
	Item* coin = new Item(false);
	coin->getSprite().setPosition(1600.f + 150 * i, -2600);
	coin->m_IsStaticCoin = true;
	coin->getSprite().setScale(.15f, .15f);
	m_Items.push_back(coin);

}



}


void Level::Collision(float& ground_Height, Player& player1)
{
	for (int i = 0; i < m_Enemies.size(); i++)
	{
	


		if (player1.getHitbox().getGlobalBounds().intersects(m_Enemies[i]->getHitbox().getGlobalBounds()) && player1.getSprite().getPosition().y < m_Enemies[i]->getHitbox().getPosition().y - 50)
		{

			player1.setVelocityY(-10);
			if (m_Enemies[i]->getIsGoomba())
			{
				m_Enemies[i]->getIsDead() = true;
				player1.increasePoints(100);
			}
			else if (!m_Enemies[i]->getIsGoomba())
			{
				m_Enemies[i]->getShellSprite().setPosition(m_Enemies[i]->getSprite().getPosition());
				m_Enemies[i]->setVelocityX(0);
				m_Enemies[i]->getIsShell() = true;
				if (m_Enemies[i]->getShellHitCD().getElapsedTime().asSeconds() > 2)
				{
					m_Enemies[i]->getShellHitCD().restart();
				}
				m_Enemies[i]->getSprite() = m_Enemies[i]->getShellSprite();
			}
		}


		if (player1.getHitbox().getGlobalBounds().intersects(m_Enemies[i]->getHitbox().getGlobalBounds()) && player1.getSprite().getPosition().x < m_Enemies[i]->getHitbox().getPosition().x
			&& m_Enemies[i]->getIsShell() && m_Enemies[i]->getShellHitCD().getElapsedTime().asSeconds() >= .5 && m_Enemies[i]->getVelocityX() == 0)
		{
			m_Enemies[i]->setVelocityX(6);
			m_Enemies[i]->getShellHitBoxCD().restart();
		}
		else if (player1.getHitbox().getGlobalBounds().intersects(m_Enemies[i]->getHitbox().getGlobalBounds()) && player1.getSprite().getPosition().x > m_Enemies[i]->getHitbox().getPosition().x
			&& m_Enemies[i]->getIsShell() && m_Enemies[i]->getShellHitCD().getElapsedTime().asSeconds() >= .5 && m_Enemies[i]->getVelocityX() == 0)
		{
			m_Enemies[i]->setVelocityX(-6);
			m_Enemies[i]->getShellHitBoxCD().restart();
		}


		for (Enemy* x : m_Enemies)
		{
			if (m_Enemies[i]->getHitbox().getGlobalBounds().intersects(x->getHitbox().getGlobalBounds()) && m_Enemies[i]->getIsShell() && m_Enemies[i]->getVelocityX() != 0 && x != m_Enemies[i])
			{
				x->getIsDead() = true;
				player1.increasePoints(100);
			}
		}

	}
	for (int i = 0; i < m_Platforms.size(); i++)
	{
		if (m_Platforms[i]->getIsItemBlock() || m_Platforms[i]->getIsBrickBlock())
		{
			//top collision
			if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) && player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y && !player1.getIsBig())
			{
				player1.getSprite().setPosition(player1.getSprite().getPosition().x, m_Platforms[i]->getPlatform().getPosition().y - 45);
				ground_Height = m_Platforms[i]->getPlatform().getPosition().y - 40;
				player1.setIsJumping(false);
				if (player1.getVelocityY() > 6)
				{
					player1.setVelocityY(6);
				}
				player1.getJumpClock().restart();
			}
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) && player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y 
				&& player1.getIsBig())
			{
				player1.getSprite().setPosition(player1.getSprite().getPosition().x, m_Platforms[i]->getPlatform().getPosition().y - 65);
				ground_Height = m_Platforms[i]->getPlatform().getPosition().y - 55;
				player1.setIsJumping(false);
				player1.getJumpClock().restart();
			}
			//left collsion
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) && player1.getSprite().getPosition().x <= m_Platforms[i]->getPlatform().getPosition().x 
				&& player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y + 100)
			{
				player1.getSprite().setPosition(m_Platforms[i]->getPlatform().getPosition().x - 47, player1.getSprite().getPosition().y);
				player1.setVelocityX(0);;
				player1.setVelocityY(5);;
			}
			//right collsion
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) && player1.getSprite().getPosition().x >= m_Platforms[i]->getPlatform().getPosition().x 
				&& player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y + 100)
			{
				player1.getSprite().setPosition(m_Platforms[i]->getPlatform().getPosition().x + 147, player1.getSprite().getPosition().y);
				player1.setVelocityX(0);
				player1.setVelocityY(5);
			}
			//bottom collision
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) && player1.getSprite().getPosition().y > m_Platforms[i]->getPlatform().getPosition().y + 5)
			{
				player1.getSprite().setPosition(player1.getSprite().getPosition().x, player1.getSprite().getPosition().y + 5);
				player1.setVelocityY(0);

				if (m_Platforms[i]->getIsItemBlock())
				{

					sf::RectangleShape temp(m_Platforms[i]->getPlatform().getSize());
					temp.setTexture(m_HitBlockTexture);
					temp.setPosition(m_Platforms[i]->getPlatform().getPosition());
					m_Platforms[i]->getPlatform() = temp;

					//std::cout << "colling with %i" << i << std::endl;
					if (i == 2 || i == 22 || i == 52)
					{
						if (m_Platforms[i]->getIsItemBlock() == true)
						{
							Item* mushroom = new Item(true);
							mushroom->getSprite().setPosition(m_Platforms[i]->getPlatform().getPosition().x + 50, m_Platforms[i]->getPlatform().getPosition().y);
							m_Items.push_back(mushroom);
							m_Platforms[i]->getIsItemBlock() = false;
						}
					}
					else
					{
						Item* coin = new Item(false);
						coin->getSprite().setPosition(m_Platforms[i]->getPlatform().getPosition().x + 50, m_Platforms[i]->getPlatform().getPosition().y);
						m_Items.push_back(coin);
						m_Platforms[i]->getIsItemBlock() = false;
						player1.increasePoints(50);
					}

				}
			}
		}
		else if (m_Platforms[i]->getIsGround() == true)
		{
			//top collision
			if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds())
				&& player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y && !player1.getIsBig())
			{
				player1.getSprite().setPosition(player1.getSprite().getPosition().x, m_Platforms[i]->getPlatform().getPosition().y - 35);
				ground_Height = m_Platforms[i]->getPlatform().getPosition().y - 35;
				player1.setIsJumping(false);
				player1.getJumpClock().restart();
			}
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) 
				&& player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y && player1.getIsBig())
			{
				player1.getSprite().setPosition(player1.getSprite().getPosition().x, m_Platforms[i]->getPlatform().getPosition().y - 55);
				ground_Height = m_Platforms[i]->getPlatform().getPosition().y - 55;
				player1.setIsJumping(false);
				player1.getJumpClock().restart();
			}
			//left collsion
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) 
				&& player1.getSprite().getPosition().x <= m_Platforms[i]->getPlatform().getPosition().x && player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y + 400)
			{
				player1.getSprite().setPosition(m_Platforms[i]->getPlatform().getPosition().x - 47, player1.getSprite().getPosition().y);
				player1.setVelocityX(0);
				player1.setVelocityY(5);
			}
			//right collsion
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) 
				&& player1.getSprite().getPosition().x >= m_Platforms[i]->getPlatform().getPosition().x && player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y + 400)
			{
				player1.getSprite().setPosition(m_Platforms[i]->getPlatform().getPosition().x + 1047, player1.getSprite().getPosition().y);
				player1.setVelocityX(0);
				player1.setVelocityY(5);
			}
			//bottom collision
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) 
				&& player1.getSprite().getPosition().y > m_Platforms[i]->getPlatform().getPosition().y + 5)
			{
				player1.getSprite().setPosition(player1.getSprite().getPosition().x, player1.getSprite().getPosition().y + 5);
				player1.setVelocityY(0);
			}
		}
		else if (m_Platforms[i]->getIsPipe() == true)
		{
			//top collision
			if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds())
				&& player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y && !player1.getIsBig())
			{

				player1.getSprite().setPosition(player1.getSprite().getPosition().x, m_Platforms[i]->getPlatform().getPosition().y - 45);
				ground_Height = m_Platforms[i]->getPlatform().getPosition().y - 35;
				player1.setIsJumping(false);
				player1.getJumpClock().restart();

			}
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) 
				&& player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y && player1.getIsBig())
			{
				player1.getSprite().setPosition(player1.getSprite().getPosition().x, m_Platforms[i]->getPlatform().getPosition().y - 55);
				ground_Height = m_Platforms[i]->getPlatform().getPosition().y - 65;
				player1.setIsJumping(false);
				player1.getJumpClock().restart();
			}
			//left collsion
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) 
				&& player1.getSprite().getPosition().x <= m_Platforms[i]->getPlatform().getPosition().x && player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y + m_Platforms[i]->getPlatform().getSize().y)
			{
				player1.getSprite().setPosition(m_Platforms[i]->getPlatform().getPosition().x - 47, player1.getSprite().getPosition().y);
				player1.setVelocityX(0);
				player1.setVelocityY(5);
			}
			//right collsion
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) 
				&& player1.getSprite().getPosition().x >= m_Platforms[i]->getPlatform().getPosition().x && player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y + 200 + m_Platforms[i]->getPlatform().getSize().y)
			{
				player1.getSprite().setPosition(m_Platforms[i]->getPlatform().getPosition().x + 247, player1.getSprite().getPosition().y);
				player1.setVelocityX(0);
				player1.setVelocityY(5);
			}
			//bottom collision
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds()) 
				&& player1.getSprite().getPosition().y > m_Platforms[i]->getPlatform().getPosition().y + 5)
			{
				player1.getSprite().setPosition(player1.getSprite().getPosition().x, player1.getSprite().getPosition().y + 5);
				player1.setVelocityY(0);
			}



		}

		for (Enemy* x : m_Enemies)
		{
			if (m_Holes[0]->getGlobalBounds().intersects(x->getHitbox().getGlobalBounds()) && x->getIsShell())
			{
				if (x->getShellHitCD().getElapsedTime().asSeconds() > .4)
				{
					x->setVelocityY(4);
					x->setVelocityX(4);
					x->getShellHitCD().restart();
				}
				else
				{
					x->setVelocityX(-4);
				}
			}

			if (x->getSprite().getGlobalBounds().intersects(player1.getSprite().getGlobalBounds()) && player1.getSprite().getPosition().y >= x->getSprite().getPosition().y - 50)
			{
				if (!x->getIsShell() && player1.getInvicibilityFramesClock().getElapsedTime().asSeconds() > 2 || x->getIsShell() && x->getVelocityX() != 0 && x->getShellHitBoxCD().getElapsedTime().asSeconds() > 1 && player1.getInvicibilityFramesClock().getElapsedTime().asSeconds() > 2)
				{
					player1.damagePlayer();
					player1.getInvicibilityFramesClock().restart();
				}
			}
		}

		for (Item* x : m_Items)
		{
			if (x->getSprite().getGlobalBounds().intersects(player1.getSprite().getGlobalBounds()) && x->getIsMushroom() && x->getIsDead() == false)
			{
				x->getIsDead() = true;

				player1.setIsBig(true);
				player1.setHealth(2);
				player1.increasePoints(500);
			}

			if (x->getSprite().getGlobalBounds().intersects(player1.getSprite().getGlobalBounds()) && x->m_IsStaticCoin && x->getIsDead() == false)
			{
				x->getIsDead() = true;
				player1.increasePoints(100);
			}

			if (m_Platforms[i]->getPlatform().getGlobalBounds().intersects(x->getSprite().getGlobalBounds()) && x->getSpawnTimer().getElapsedTime().asSeconds() > 1 && x->getSprite().getPosition().y - 15 < m_Platforms[i]->getPlatform().getPosition().y)
			{
				x->getSprite().setPosition(x->getSprite().getPosition().x, m_Platforms[i]->getPlatform().getPosition().y - 15);
			}
			else if (m_Platforms[i]->getPlatform().getGlobalBounds().intersects(x->getSprite().getGlobalBounds()) && x->getSpawnTimer().getElapsedTime().asSeconds() > 1 && m_Platforms[i]->getIsPipe())
			{
				x->setVelocityX(2);
			}
			else if (m_Platforms[i]->getPlatform().getGlobalBounds().intersects(x->getSprite().getGlobalBounds()) && x->getSpawnTimer().getElapsedTime().asSeconds() > 1)
			{
				x->setVelocityX(-2);
			}

		}

		if (player1.getSprite().getPosition().x >= m_Platforms[i]->getPlatform().getPosition().x + 50 && m_Platforms[i]->getIsFlag())
		{
			player1.setLevelComplete(true);
		}



	}
	if (player1.getSprite().getPosition().y > 1200)
	{
		player1.setIsDead(true);
	}

	for (int i = 0; i < m_Enemies.size(); i++)
	{
		if (m_Enemies[i]->getIsDead())
		{
			delete m_Enemies[i];
			m_Enemies[i] = nullptr;
			m_Enemies.erase(m_Enemies.begin() + i);
		}
	}


	for (int i = 0; i < m_Items.size(); i++)
	{
		if (m_Items[i]->getIsDead())
		{
			delete m_Items[i];
			m_Items[i] = nullptr;
			m_Items.erase(m_Items.begin() + i);
		}
	}
	
}

void Level::drawLevel(sf::RenderWindow& window)
{

	for (Platforms* x : m_Platforms)
	{
		window.draw(x->getPlatform());
		//window.draw(x->getHitbox());
	}

	for (Enemy* x : m_Enemies)
	{
		x->Update();
		//window.draw(x->getHitbox());
		window.draw(x->getSprite());
	}
	for (Item* x : m_Items)
	{
		x->Update(m_Platforms);
		//window.draw(x->getHitbox());
		window.draw(x->getSprite());
	}

}

Level::~Level()
{
	for (Platforms* x : m_Platforms)
	{
		delete x;
		x = nullptr;
	}

	for (Enemy* x : m_Enemies)
	{
		delete x;
		x = nullptr;
	}

	for (Item* x : m_Items)
	{
		delete x;
		x = nullptr;
	}
}

void Level::downPipe(Player& player1, bool isDown)
{
	for (int i = 0; i < m_Platforms.size(); i++)
	{
		if (m_Platforms[i]->getIsPipe() == true)
		{
			
			if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds())
				&& player1.getSprite().getPosition().y < m_Platforms[i]->getPlatform().getPosition().y && i == 16 && isDown)
			{
				player1.getSprite().setPosition(1000, -2800);

			}
			else if (player1.getSprite().getGlobalBounds().intersects(m_Platforms[i]->getPlatform().getGlobalBounds())
				&& player1.getSprite().getPosition().y > -2900 && i == 232 && !isDown)
			{
				player1.getSprite().setPosition(19700, 450);
			}
		}
	}

}