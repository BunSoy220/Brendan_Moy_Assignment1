// Brendan Moy 
// 2-16-2023
// a class that takes a sequence of 2D points
// you can add, input, and print all points
// includes overload Big Five

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

// class contains sequence_ a dynamically allocated array of 2d points
// you can add the sequences together, print them, and get user input
template<typename Object>
class Points2D {
  public:
    // Zero-parameter constructor.
    // Sets size to 0 with empty sequence.
    Points2D(){
        sequence_ = nullptr;
        size_ = 0;
    }

    // Copy-constructor.
    // makes a seperate copy of all elements in rhs's sequence_ including size_
    Points2D(const Points2D &rhs){
        size_ = rhs.size_;
        sequence_ = new std::array<Object, 2> [rhs.size_];
        for(size_t i = 0; i < rhs.size_; ++i){
            for(size_t j = 0; j < 2; ++j){
                sequence_[i][j] = rhs.sequence_[i][j];
           }
        }
    }
    // Copy-assignment. If you have already written
    // uses std::swap the current Points2D object with the rhs one, if they are not the same 
    Points2D& operator=(const Points2D &rhs){
        if(this != &rhs){
            Points2D copy_ = rhs;
            std::swap(*this, copy_);
        }
        return *this;
    }

    // Move-constructor.
    // moves rhs's varibales to this, sets rhs's to null 
    Points2D(Points2D &&rhs):sequence_{rhs.sequence_},size_{rhs.size_}{
        rhs.sequence_ = nullptr;
        rhs.size_ = 0;
    }

    // Move-assignment.
    // uses std::swap() for all variables.
    Points2D& operator=(Points2D &&rhs){
        std::swap(sequence_,rhs.sequence_); 
        std::swap(size_,rhs.size_); 
        return *this; 
    }

    ~Points2D(){
        delete[] sequence_; 
    }

    // End of big-five.

    // one parameter constructor 
    //makes all makes new sequence from array item using a one parameter constructor
    Points2D(const std::array<Object, 2>& item) {
        sequence_ = new std::array<Object,2>{item};
        size_t i = 0 ;
        if(item.empty()){
            size_ = 0;
        }else{
            size_ = 1;
        }
    }
    //returns the how many points are in the sequence and is unmutable
    size_t size() const {
        return size_;
    }
   
    // @location: an index to a location in the sequence.
    // @returns the point at @location.
    // const version.
    // abort() if out-of-range.
    const std::array<Object, 2>& operator[](size_t location) const {
        if(location >= size_){
            abort();
        }
        return sequence_[location];
    }
    
    //  @c1: A sequence.
    //  @c2: A second sequence.
    //  @return their sum. If the sequences are not of the same size, append the
    //   result with the remaining part of the larger sequence.
    friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
        Points2D biggest_ = (c1.size_>c2.size_)?c1:c2; //checks and sets the biggest and smallest
        Points2D smallest_ = (c1.size_<=c2.size_)?c1:c2;
        std::array<Object,2> *sum_ = new std::array<Object,2>[biggest_.size_];//array for sum with biggest size
         for(size_t i = 0; i < biggest_.size_; ++i){
            for(size_t j = 0; j < 2; ++j){
                if(smallest_.size_ > i)//if not out of the smaller's index add the two
                    sum_[i][j] = biggest_.sequence_[i][j] + smallest_.sequence_[i][j];
                else//append the rest
                    sum_[i][j] = biggest_.sequence_[i][j];
            }
         }
        Points2D result_ = Points2D();
        result_.size_ = biggest_.size_;
        result_.sequence_ = sum_;
       
        return result_;
    }
    
    // Overloading the << operator.
    // @some_points: Points2D Object to be printed
    //prints all points in sequence with format: "(x,y) ...(x(n),y(n))"
    //if there are no points in the sequence it prints: "()"
    friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) {
        if(some_points.size_ == 0){ //empty sequence
            out << "()" <<std::endl;
        }
        else{
            for(size_t i = 0; i < some_points.size_; ++i){
                out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1]  << ") ";
            }
             out << std::endl;
        }
        return out;
    }   
    
    // Overloading the >> operator.
    // @some_points: Points2D Object to be overriden
    //takes in a sequence in the format: # of points(n) x1 y1 ... x(n) y(n)
    //aborts with error if there are less inputs then stated in (n)
    friend std::istream &operator>>(std::istream &in, Points2D &some_points) {
        in >> some_points.size_;
        std::array<Object, 2> *temp_ = some_points.sequence_;
        some_points.sequence_ = new std::array<Object, 2>[some_points.size_];
        delete[] temp_; 
        for(size_t i = 0; i <some_points.size_; ++i){
            for(size_t j = 0; j < 2; ++j){//goes through all points 
                while(std::cin.peek() == ' ') std::getchar();//get the char if its is space
                if(std::cin.peek() == EOF){//if cin is at the end of file there is an error(not enough inputs)
                    std::cerr << "ERROR";
                    std::abort();
                }else //if nothing is wrong
                    in >> some_points.sequence_[i][j]; //take input into sequence
            }
        }
        if(some_points.sequence_->empty()){ 
            some_points.size_ = 0;
        }
        std::cout << std::endl;
        return in;
    }
    
  private:
    // Sequence of points.
    std::array<Object, 2> *sequence_;
    // Size of sequence.
    size_t size_;
};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_Points2D_H_
