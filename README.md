## Brendan_Moy_Assignment1

#### Points2D()
zero parameter constructor 
makes an empty sequence_ with size_ 0

#### Points2D(const Points2d &rhs) 
copy constructor
makes a seperate copy of all elements in rhs's sequence_ including size_

#### Points2D operator=(const Points2D &rhs)
copy assignment 
std::swaps the current Points2D object with the rhs one, if they are not the same 

#### Points2D& operator=(Points2D &&rhs)
move assignment 
swaps all variables in current object with rhs's variables

#### Points2D(const std::array<Object, 2>& item)
one parameter constructor 
makes all makes new sequence from array item using a one parameter constructor
makes use of std::array<> function back() using it's address to find the size

#### size_t size() const
returns the how many points are in the sequence and is unmutable

#### const std::array<Object, 2>& operator[](size_t location) const
returns the two points int the sequence at index location
aborts if there location is out of bounds

#### friend Points2D operator+(const Points2D &c1, const Points2D &c2)
overloads + operator
adds the points together(x1+x2,y1+y2)
appends extra points to sequence if there is more points
returns a new Points2D object

#### friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points)
overloads std::cin << 
takes in a sequence in the format: # of points(n) x1 y1 ... x(n) y(n)
aborts with error if there are less inputs then stated in (N)
 
#### friend std::istream &operator>>(std::istream &in, Points2D &some_points) 
overloads std::cout >> 
prints all points in sequence with format: "(x,y) ...(x(n),y(n))"
if there are no points in the sequence it prints: "()"

