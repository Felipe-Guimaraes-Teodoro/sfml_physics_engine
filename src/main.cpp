#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "../src/physics.cpp"

float WJ_ = 500.0; 
float HJ_ = 500.0;

int TIME = 0;

int main() {
  //TODO: delta time na simulacao de fisica
  sf::RenderWindow window(sf::VideoMode(WJ_,HJ_), "cmd com cor e forma bonita (quase)");

  Particle** particles = new Particle*[1000];

  for (int i = 0; i<1000; i++) {
    particles[i] = new Particle(
      WJ_ / 2.0,
      HJ_ / 2.0,
      WJ_ / 2.0 - 1.0 + float(i) * 0.1,
      WJ_ / 2.0 - 1.0 + float(i) * 0.1,
      1.0,
      0.1,
      i
    );
  }

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    // window.clear();
    for (int i = 0; i<1000; i++) {
      particles[i]->Update();
      particles[i]->Draw(&window);
    }
    window.display();
    TIME++;
  }


  return 0;
}
