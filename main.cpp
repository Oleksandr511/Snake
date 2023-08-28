#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <iostream>
#include<ctime>
#include<vector>
#include<fstream>
//#pragma warning(disable : 4996)
using namespace std;
using namespace sf;
struct Position
{
    float px;
    float py;
};
enum game {
    GAME,
    GAME_OVER,
};
void end(float& dx, float& dy, int& m, vector<Position>& v,game &state) {
    dx = 189;
    dy = 210;
    m = 0;
    v.resize(1);


    state = GAME_OVER;
    
}
void r(int& a) {
    while (a%21!=0) {
        a = rand() % 350;   
    }
}
 

int main()
{
    
    Font font;
    font.loadFromFile("C:\\programmingC++\\game\\sfml_project\\Project1\\arialceb.ttf");

    Text text("", font, 15);
    text.setFillColor(Color::Black);
    text.setStyle(Text::Bold);

    game state = GAME;
   
    int tx = 21, ty = 21;
    float x=0, y=0;
    float dx=42.f, dy=42.f;
    float dxx = 42.f, dyy = 42.f;
    sf::RenderWindow window(sf::VideoMode(400, 400), "Snake");
    sf::CircleShape shape(10.f);
    shape.setFillColor(sf::Color::Red);
    int a = 84;
    shape.setPosition(a,a);
    

    sf::RectangleShape rectangle(sf::Vector2f(20.f, 20.f));
    rectangle.setFillColor(sf::Color::Yellow);
    rectangle.setPosition(dx, dy);
    sf::RectangleShape rectangle3(sf::Vector2f(20.f, 20.f));
    rectangle3.setFillColor(sf::Color::Blue);
    int c = 0;
    int size1 = 20, size2 = 20;
    sf::RectangleShape rectangle2(sf::Vector2f(size1, size2));
    rectangle2.setFillColor(sf::Color::Green);
    int score  = 0;
    srand(time(NULL));
    vector<Position>v(1);
    //font.loadFromFile("C:\\programmingC++\\game\\sfml_project\\Project1\\ARIALNBI.TTF");

    while (window.isOpen())
    {
        switch (state) {
        case GAME:
            //Normal processing you have now
            break;
        case GAME_OVER:

            //Process what you need for pause/game over state
            while (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {


            }
            state = GAME;
            break;
        }
        
        sf::Event event;
        c++;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            
            x = 21;
            y = 0;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            y = 0;
            x = -21;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            x = 0;
            y = -21;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            x = 0;
            y = 21;

        }

        dxx = dx;
        dyy = dy;
        v[0].px = dx;
        v[0].py = dy;
        if (c % 300 == 0) {
           
            dx += x ;
            dy += y ;

            for (int i = v.size() - 1; i > 0; i--)
            {
                v[i].px = v[i - 1].px;
                v[i].py = v[i - 1].py;
                rectangle3.setPosition(v[i].px, v[i].py);
            }
            rectangle.setPosition(dx, dy);         
        for (int i = 1; i < v.size() ; i++)
        {
            if (dx == v[i ].px && dy == v[i].py)
            {
                    end(dx, dy, score, v,state);
            }
        }
    }
        if (dx >= 405 or dy >= 405 or dx <= -5 or dy <= -5)
        {
            end(dx, dy,score,v,state );
        }
        if (dx==a && dy==a )
        {
            score++;
            v.push_back(Position{ dx, dy });
           
            a = rand() % 200 ;
            r(a);
            shape.setPosition(a, a);
        }
        window.clear();
        for (int i = 0; i < 21; i++)
            for (int j = 0; j < 21; j++)
            {
                rectangle2.setPosition(i * tx, j * ty);
                window.draw(rectangle2);
            }
            for (int i = 1; i < v.size(); i++)
            {
                window.draw(rectangle3);
                rectangle3.setPosition(v[i].px, v[i].py);
            }
            text.setString("Score: " + to_string(score));
            window.draw(text);
        window.draw(shape);
        window.draw(rectangle);
        window.display();
    }

    return 0;
}