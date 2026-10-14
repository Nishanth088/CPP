#include <iostream>
using namespace std;

// std:: now optional for cout, cin, endl

// Swap using REFERENCES (clean, no & at call site)
void swapRef (int &a, int &b) { int t = a; a = b; b = t; }

// Swap using POINTERS (the C way) - shown for contrast
void swapPtr(int *a, int *b) { int t = *a; *a = *b; *b = t; }

int main() {
    int x = 10, y = 20;
    
    swapRef(x, y); // no & needed
    cout << "After swapRef: x=" << x << " y=" << y << endl;
    
    swapPtr(&x, &y); // must pass addresses
    cout << "After swapPtr: x=" << x << " y=" << y << endl;
    
    int &alias = x; // alias is another name for x
    alias = 99;     // changes x too
    cout << "x via alias= " << x << endl;
    
    return 0;
}
```[cite: 5, 6]

#### 1.2 std::string essentials: palindrome & frequency
```cpp
#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a word: ";
    cin >> s;
    
    cout << "Length: " << s.length() << endl;
    cout << "Upper: ";
    for (char c : s) cout << (char) toupper(c); // range-based for
    cout << endl;
    
    // Palindrome check using two indices
    bool pal = true;
    for (size_t i = 0, j = s.size() - 1; i < j; ++i, --j)
        if (s[i] != s[j]) { pal = false; break; }
        
    cout << s << (pal ? " IS" : " is NOT") << " a palindrome\n";
    
    // Find a substring
    size_t pos = s.find("an");
    if (pos != string::npos) 
        cout << "'an' found at index " << pos << endl;
    else 
        cout << "'an' not found\n";
        
    return 0;
}
```[cite: 6]

#### 1.3 More std::string: substr, compare & frequency
```cpp
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s = "verification";
    
    cout << "First 4: " << s.substr(0, 4) << endl;     // substr(pos, len)
    cout << "From 4: " << s.substr(4) << endl;         // to end
    
    int c = s.compare("verify");                       // <0, 0, >0 like strcmp
    cout << "compare vs 'verify': " << (c < 0 ? "<" : c > 0 ? ">" : "=") << endl;
    
    int freq[26] = {0};
    for (char ch : s) 
        if (isalpha((unsigned char)ch))
            freq[tolower(ch) - 'a']++;
            
    cout << "Letter counts: ";
    for (int i = 0; i < 26; ++i) 
        if (freq[i]) 
            cout << char('a' + i) << ":" << freq[i] << " ";
            
    cout << endl;
    return 0;
}
```[cite: 6, 7]

---

### Week 2: Functions: Overloading, Default & Inline

#### 2.1 Overloading + inline
```cpp
#include <iostream>
using namespace std;

inline int square (int x) { return x * x; }                 // tiny inline
double area (double r) { return 3.14159 * r * r; }           // circle
int area(int l, int b) { return l * b; }                     // rectangle
double area (double b, double h) { return 0.5 * b * h; }     // triangle

int main() {
    cout << "Square (6) = " << square(6) << endl;
    cout << "Circle r=2 = " << area(2.0) << endl;
    cout << "Rectangle 4x5 = " << area(4, 5) << endl;
    cout << "Triangle b=3, h=8 = " << area(3.0, 8.0) << endl;
    return 0;
}
```[cite: 8]

#### 2.2 Default arguments (rightmost-first rule)
```cpp
#include <iostream>
#include <string>
using namespace std;

// level defaults to 1 (INFO); only the message is mandatory
void logMsg(const string &msg, int level = 1) {
    const string tag[] = {"", "INFO", "WARN", "ERROR"};
    cout << "[" << tag[level] << "] " << msg << endl;
}

// Simple interest with a default rate of 7.5%
double interest (double principal, double years, double rate = 7.5) {
    return (principal * years * rate) / 100.0;
}

int main() {
    logMsg("System started");                 // uses default level
    logMsg("Low memory", 2);                  // overrides default
    
    cout << "Interest = " << interest (10000, 2) << endl;         // default rate
    cout << "Interest = " << interest (10000, 2, 9.0) << endl;  // custom rate
    return 0;
}
```[cite: 8, 9]

#### 2.3 Call-by-reference vs call-by-pointer (two results at once)
```cpp
#include <iostream>
using namespace std;

void minMax (const int a[], int n, int &mn, int &mx) {
    mn = mx = a[0]; // out via references
    for (int i = 1; i < n; ++i) { 
        if (a[i] < mn) mn = a[i]; 
        if (a[i] > mx) mx = a[i]; 
    }
}

void minMaxPtr(const int a[], int n, int *mn, int *mx) {
    *mn = *mx = a[0]; // out via pointers
    for (int i = 1; i < n; ++i) { 
        if (a[i] < *mn) *mn = a[i]; 
        if (a[i] > *mx) *mx = a[i]; 
    }
}

int main() {
    int data[] = {7, 2, 9, 4, 1};
    int lo, hi;
    
    minMax(data, 5, lo, hi);
    cout << "ref -> min=" << lo << " max=" << hi << endl;
    
    minMaxPtr(data, 5, &lo, &hi); 
    cout << "ptr -> min=" << lo << " max=" << hi << endl;
    
    return 0;
}
```[cite: 9, 10]

---

### Week 3: Classes, Objects & Encapsulation

#### 3.1 Encapsulation: a safe BankAccount
```cpp
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance; // cannot go negative
    
public:
    void open(const string &name, double initial) {
        owner = name;
        balance = (initial > 0) ? initial : 0; // enforced below
    }
    
    void deposit (double amt) { if (amt > 0) balance += amt; }
    
    bool withdraw (double amt) { // returns success
        if (amt > 0 && amt < balance) { 
            balance -= amt; 
            return true; 
        }
        return false; // protects the invariant
    }
    
    double getBalance() const { return balance; } // const: read-only
    string getOwner() const { return owner; }
};

int main() {
    BankAccount a;
    a.open("Asha", 1000);
    a.deposit(500);
    
    if (!a.withdraw (2000)) cout << "Withdraw denied (insufficient)\n";
    a.withdraw (300);
    
    cout << a.getOwner() << " balance = " << a.getBalance() << endl;
    return 0;
}
```[cite: 11, 12]

#### 3.2 Array of objects: an 8-bit register file
```cpp
#include <iostream>
using namespace std;

class Register {
private:
    unsigned char value; // models one 8-bit hardware register (0..255)
public:
    void write(unsigned char v) { value = v; }
    unsigned char read() const { return value; }
    void reset() { value = 0; }
};

int main() {
    Register file[4]; // array of 4 objects
    
    for (int i = 0; i < 4; ++i)
        file[i].reset();
        
    file[0].write(0xAB);
    file[3].write(0x10);
    
    for (int i = 0; i < 4; ++i)
        cout << "R" << i << "=" << (int)file[i].read() << endl;
        
    return 0;
}
```[cite: 12]

#### 3.3 Passing & returning objects; the this pointer
```cpp
#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    
    // takes an object BY REFERENCE, RETURNS a new object by value
    Point add(const Point &p) const { return Point(x + p.x, y + p.y); }
    
    // 'this' points to the calling object; returning this enables chaining
    Point& setX(int v) { this->x = v; return *this; }
    Point& setY(int v) { this->y = v; return *this; }
    
    void show() const { cout << "(" << x << "," << y << ")\n"; }
};

void shift (Point &p) { p.setX(99); }       // by reference: changes original
void tryShift (Point p) { p.setX(-1); }     // by value: works on a copy

int main() {
    Point a(1, 2), b(3, 4);
    Point c = a.add(b);                      // returning an object -> (4,6)
    c.show();
    
    Point d; d.setX(7).setY(8);             // chaining through 'this' -> (7,8)
    d.show();
    
    shift(a); a.show();                      // (99,2) original changed
    tryShift(b); b.show();                   // (3,4) original unchanged
    
    return 0;
}
```[cite: 13]

---

### Week 4: Constructors, Destructors & Dynamic Memory

#### 4.1 Constructor / destructor call order
```cpp
#include <iostream>
using namespace std;

class Tracer {
    int id;
public:
    Tracer(int i) : id(i) { cout << " Construct #" << id << endl; } // init list
    ~Tracer() { cout << " Destruct #" << id << endl; }
};

int main() {
    cout << "Enter block\n";
    { 
        Tracer a(1), b(2); 
        cout << " ...working...\n"; 
    } // b dies first (LIFO)
    cout << "Left block\n";
    return 0;
}
```[cite: 14]

#### 4.2 Deep copy vs shallow copy (the interview classic)
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class MyString {
    char *data;
public:
    MyString(const char *s) { // parameterized ctor
        data = new char[strlen(s) + 1];
        strcpy(data, s);
    }
    
    MyString(const MyString &o) { // DEEP copy ctor
        data = new char[strlen(o.data) + 1]; // own fresh memory
        strcpy(data, o.data);
    }
    
    ~MyString() { delete[] data; } // each object frees its own
    
    void print() const { cout << data << endl; }
};

int main() {
    MyString a("hardware");
    MyString b = a; // copy ctor runs deep copy
    
    a.print();
    b.print();
    return 0;
}
```[cite: 15]

#### 4.3 Constructor overloading & delegating constructors
```cpp
#include <iostream>
using namespace std;

class Box {
    int w, h, d;
public:
    Box(int w, int h, int d) : w(w), h(h), d(d) {} // the "real" ctor
    Box() : Box(1, 1, 1) {}                         // delegates
    Box(int s) : Box(s, s, s) {}                     // cube, delegates
    
    int volume() const { return w * h * d; }
};

int main() {
    Box a; 
    Box b(3); 
    Box c(2, 3, 4);
    
    cout << a.volume() << " " << b.volume() << " " << c.volume() << endl;
    return 0;
}
```[cite: 15, 16]

---

### Week 5: Static Members & Friend Functions

#### 5.1 Static members: counting live objects
```cpp
#include <iostream>
using namespace std;

class Widget {
    int id;
    static int count; // declaration: shared by all objects
public:
    Widget() { 
        id = ++count; 
        cout << "Created W" << id << endl; 
    }
    
    ~Widget() { 
        --count; 
        cout << "Destroyed W" << id << endl; 
    }
    
    static int alive() { return count; } // no 'this'
};

int Widget::count = 0; // definition (exactly once)

int main() {
    Widget a, b;
    cout << "Alive = " << Widget::alive() << endl; // called on class
    
    { 
        Widget c; 
        cout << "Alive = " << Widget::alive() << endl; 
    }
    
    cout << "Alive = " << Widget::alive() << endl;
    return 0;
}
```[cite: 17, 18]

#### 5.2 Friend function across two objects
```cpp
#include <iostream>
using namespace std;

class Distance {
    int feet, inch;
public:
    Distance(int f = 0, int i = 0) : feet(f), inch(i) {}
    
    // friend can read private feet/inch of BOTH arguments
    friend Distance add(const Distance &a, const Distance &b);
    
    void show() const { cout << feet << "ft" << inch << "in\n"; }
};

Distance add(const Distance &a, const Distance &b) {
    int totalInch = (a.feet + b.feet) * 12 + a.inch + b.inch;
    return Distance(totalInch / 12, totalInch % 12);
}

int main() {
    Distance d1(5, 8), d2(3, 7);
    Distance d3 = add(d1, d2);
    d3.show(); // 9ft 3in
    return 0;
}
```[cite: 18]

#### 5.3 Friend class
```cpp
#include <iostream>
using namespace std;

class Car {
    int speed = 0;
    friend class Dashboard; // Dashboard may read Car's private data
public:
    void accelerate() { speed += 10; }
};

class Dashboard {
public:
    void display(const Car &c) { cout << "Speed = " << c.speed << " km/h\n"; }
};

int main() {
    Car c; 
    c.accelerate(); 
    c.accelerate();
    Dashboard().display(c); // 20 km/h
    return 0;
}
```[cite: 18]
