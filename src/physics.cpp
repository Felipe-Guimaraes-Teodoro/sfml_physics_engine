#include <cstdlib>
float WJ_2 = 500.0; 
float HJ_2 = 500.0;

float g = .0001; // c mais mais e mt rapido (c puls pus ..)
float bounce = 0.85;

class Particle {
  public:
    Particle(
        float x, 
        float y,
        float ox,
        float oy,
        float r,
        float frictio,
        float time
      ) {
      this->x = x;
      this->y = y;

      this->time = time;

      this->radius = r;

      this->ox = ox; // esse não é o delta 😁 (◁)
      this->oy = oy; // this is not delta 

      this->vx = x-ox; // esse é :)
      this->vy = y-oy; // (is ...)

      this->frictio = frictio;

      this->shape.setRadius(this->radius);
      this->shape.setFillColor(this->color);
      this->shape.setPosition(this->x,this->y);
    }

    void Update() {
      // agora vem a fisica
      // now phisic come
      //

      this->shape.setPosition(this->x,this->y);

      this->vx = this->x - this->ox;
      this->vy = this->y - this->oy;
      
      this->ox = this->x;
      this->oy = this->y;

      this->vy += g;

      this->x += vx;
      this->y += vy;

      this->Constrain();

      this->color.r = abs(this->x - 500.0)/5;
      this->color.g = this->y/5;
      this->color.b = int(this->time / 50.0) % 256;

      this->shape.setFillColor(this->color);

      this->time++;
    }

    void Constrain() {
      if (this->x < this->radius) {
        this->x = this->radius;
        this->ox = this->x + this->vx * bounce;
      }

      if (this->x > WJ_2 - this->radius * 2.0) {
        this->x = WJ_2-this->radius * 2.0;
        this->ox = this->x + this->vx * bounce;
      }

      if (this->y < this->radius) {
        this->y = this->radius;
        this->oy = this->y + this->vy * bounce;
      }

      if (this->y > HJ_2 - this->radius * 2.0) {
        this->y = HJ_2 - this->radius * 2.0;
        this->oy = this->y + this->vy * bounce;
        this->vx *= frictio;
      }

    }

    void Draw(sf::RenderWindow * window) {
      // shape.setPosition(this->x,this->y);
      window->draw(this->shape);
    }

    float x,y;
    float time;
  private:
    float radius;
    float frictio; // this is frictioN
    float ox,oy;
    float vx,vy;

    sf::Color color;
    sf::CircleShape shape;
};

class Stick {
  public:
    Stick(
      Particle * p1,
      Particle * p2,
      sf::Color color
    ) {
      this->color = color; // colocar a cor da classe como a cor que foi passada como argumento

      this->p1 = p1;
      this->p2 = p2;

      this->l = sqrt(
        (p1->x - p2->x) * (p1->x - p2->x) + 
        (p2->y - p2->y) * (p2->y - p2->y)
      ); // oi aqui eu to pegando a distancia entre os ponto do palito blz brow
         // hi here i am .. brown red purple yellow magenta black
         // foreword: the editor que eu estou usandp deixa as cores com as cores respectivas 
         // (brow red purple yellow magenta black);
      this->dist = l;
    }

    void Draw(sf::RenderWindow * window) {
    }
    
  private: 
    sf::RenderWindow window;
    Particle * p1;
    Particle * p2;
    sf::Color color;

    float l;
    float dist;
};
