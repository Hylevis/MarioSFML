#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Level.h"
#include "CollisionManager.h"
#include "Enemy.h"
#include "Item.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    window.setFramerateLimit(60);
    Player player;
    player.getSprite().setPosition(500, 500);
    sf::Clock deltaClock;
    float ground_Height = 750;
    sf::View camera = window.getView();
    Level level1;
    //CollisionManager* collisionManager = new CollisionManager(&player, &level1);
    sf::Font font;
    font.loadFromFile("times.ttf");
    sf::Text game_Over_Text;
    game_Over_Text.setFont(font);
    game_Over_Text.setString("GAME OVER");
    game_Over_Text.setFillColor(sf::Color::Red);
    game_Over_Text.setCharacterSize(120);

    sf::Text you_Win_Text;
    you_Win_Text.setFont(font);
    you_Win_Text.setString("You Win");
    you_Win_Text.setFillColor(sf::Color::Red);
    you_Win_Text.setCharacterSize(120);


    sf::Text pointsText;
    pointsText.setFont(font);
    pointsText.setFillColor(sf::Color::White);
    pointsText.setCharacterSize(50);

    sf::Text worldText;
    worldText.setFont(font);
    worldText.setString("WORLD");
    worldText.setFillColor(sf::Color::White);
    worldText.setCharacterSize(50);

    sf::Text marioText;
    marioText.setFont(font);
    marioText.setString("MARIO");
    marioText.setFillColor(sf::Color::White);
    marioText.setCharacterSize(50);

    sf::Text oneDashOneText;
    oneDashOneText.setFont(font);
    oneDashOneText.setString("1-1");
    oneDashOneText.setFillColor(sf::Color::White);
    oneDashOneText.setCharacterSize(50);

    while (window.isOpen())
    {
        if (player.getLevelComplete())
        {

            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            you_Win_Text.setPosition(camera.getCenter().x - 350, camera.getCenter().y - 450);
            window.draw(you_Win_Text);
            window.display();
        }
        else if (!player.getIsDead())
        {
            deltaClock.restart();


            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && player.getSprite().getPosition().y >= ground_Height - 5 && player.getJumpClock().getElapsedTime().asMilliseconds() <= 100.f)
                {

                    player.setVelocityY(-20);
                    player.setIsJumping(true);
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
                {
                    level1.downPipe(player, true);
                }
                else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
                {
                    level1.downPipe(player, false);
                }
            }
            if (player.getSprite().getPosition().y >= 400)
            {
                camera.setCenter(player.getSprite().getPosition().x + 250, 400);
            }
            else if (player.getSprite().getPosition().y <= -800)
            {
                if (player.getSprite().getPosition().x > 2600)
                {
                    camera.setCenter(2600, -2300);
                }
                else if (player.getSprite().getPosition().x > 1400)
                {
                    camera.setCenter(player.getSprite().getPosition().x, -2300);
                }
                else
                {
                    camera.setCenter(1400, -2300);
                }
            }
            else
            {
                camera.setCenter(player.getSprite().getPosition().x + 250, player.getSprite().getPosition().y);
            }
           
            level1.Collision(ground_Height, player);
            player.PlayerUpdate(/*collisionManager,*/ deltaClock, ground_Height);
            if (player.getSprite().getPosition().y < -800)
            {
                window.clear(sf::Color::Black);
            }
            else
            {
                window.clear(sf::Color(0, 181, 226));
            }
            window.setView(camera);

            level1.drawLevel(window);
            //window.draw(player.m_Hitbox);
            //window.draw(player.getSprite());
            pointsText.setString(std::to_string(player.getPoints()));
            pointsText.setPosition(camera.getCenter().x - 400, camera.getCenter().y - 450);
            marioText.setPosition(camera.getCenter().x - 400, camera.getCenter().y - 500);
            worldText.setPosition(camera.getCenter().x + 100, camera.getCenter().y - 500);
            oneDashOneText.setPosition(camera.getCenter().x + 100, camera.getCenter().y - 450);

            window.draw(marioText);
            window.draw(worldText);
            window.draw(pointsText);
            window.draw(oneDashOneText);
            player.Draw(window);
            window.display();
        }
        else if (player.getIsDead() == true)
        {
            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            game_Over_Text.setPosition(camera.getCenter().x - 350, camera.getCenter().y - 250);
            window.draw(game_Over_Text);
            window.display();
        }


    }

    return 0;


}