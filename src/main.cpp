#include <SFML/Graphics.hpp>
#include "../src/physics.cpp"

float WJ_ = 500.0; 
float HJ_ = 500.0;

int main() {
  sf::RenderWindow window(sf::VideoMode(WJ_,HJ_), "cmd com cor e forma bonita (quase)");

  Particle * p = 
    new Particle(
        WJ_/2.0, 
        HJ_/2.0,
        WJ_/2.0 - 20.0,
        WJ_/2.0 - 20.0,
        10.0,
        0.1
      );

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    p->Update();
    p->Draw(&window);
    window.display();
  }


  return 0;
}
