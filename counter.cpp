#include <iostream>
using namespace std;

class Tracer {
    int id;
public:
    Tracer(int i) : id(i) { cout << "Construct #" << id << endl; }
    ~Tracer() { cout << "Destruct #" << id << endl; }
};

int main() {
    for (int i = 1; i <= 3; ++i) {
        Tracer *t = new Tracer(i);
        delete t; // Try commenting this out and compile with: g++ -fsanitize=address
    }
}