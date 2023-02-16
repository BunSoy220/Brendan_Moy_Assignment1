## Brendan_Moy_Assignment1

## Information about the repository

This repository contains the following:
- Starter code: `points2d.h`, `test_points2d.cc`,`test_input_file.txt`, `expected_output.txt`, `Makefile` and `README.md`
- Assignment specification: `Spring23-Assignment1.pdf`

## Running the assignment

You will use this exact `Makefile` for your Assignment 1. Failure to do so will result in *deduction* of points.

To compile on terminal, type:

```bash
make clean
make all
```

To delete executables and object files, type:

```bash
make clean
```

To run, type:


## Providing Input from Standard Input

To run with a given file that is redirected to standard input:

```bash
./test_points2d < test_input_file.txt
```

## Completed assignments: 
 
## Big Five: 
### troubles: 
dynamically allocating arrays
#### Points2D()
zero parameter constructor  <br />
makes an empty sequence_ with size_ 0 <br />

#### Points2D(const Points2d &rhs) 
copy constructor <br />
makes a seperate copy of all elements in rhs's sequence_ including size_ <br />

#### Points2D operator=(const Points2D &rhs)
copy assignment <br />
std::swaps the current Points2D object with the rhs one, if they are not the same <br />

#### Points2D& operator=(Points2D &&rhs)
move assignment  <br />
swaps all variables in current object with rhs's variables <br />

#### Points2D(const std::array<Object, 2>& item)
one parameter constructor <br />
makes all makes new sequence from array item using a one parameter constructor <br />
makes use of std::array<> function back() using it's address to find the size <br />

#### size_t size() const
returns the how many points are in the sequence and is unmutable <br />

#### const std::array<Object, 2>& operator[](size_t location) const
returns the two points int the sequence at index location <br />
aborts if there location is out of bounds <br />

## Operation Overloads

#### friend Points2D operator+(const Points2D &c1, const Points2D &c2)
overloads + operator <br />
adds the points together(x1+x2,y1+y2) <br />
appends extra points to sequence if there is more points <br />
returns a new Points2D object <br />

#### friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points)
overloads std::cin << <br />
takes in a sequence in the format: # of points(n) x1 y1 ... x(n) y(n) <br />
aborts with error if there are less inputs then stated in (N) <br />
 
#### friend std::istream &operator>>(std::istream &in, Points2D &some_points) 
overloads std::cout >>  <br />
prints all points in sequence with format: "(x,y) ...(x(n),y(n))" <br />
if there are no points in the sequence it prints: "()" <br />

#### Bugs:
Bug:  did not get correct output for sequences that had size > points.  <br /> 
fix: impliemented std::cin.peek() and std::getchar() to determine if there are any more valid inputs <br />
Bug: << overload had references to c1 and c2 that did not work <br />
fix: used copy assigment instead. <br />
Bug: had size_ error for move contructor <br />
fix: assigned size_ to 0 <br />
