// --> YOUR NAME here
// Few comments describing the class Points2D

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2D {
  public:
    // Default "big five" -- you have to alter them for your assignment.
    // That means that you will remove the "= default" statement.
    //  and you will provide an implementation.

    // Zero-parameter constructor.
    // Set size to 0.
    Points2D(){
        sequence_ = nullptr;
        size_ = 0;
    }

    // Copy-constructor.
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
    // the copy-constructor and the move-constructor
    // you can just use:



    Points2D& operator=(const Points2D &rhs){
        if(this != &rhs){
            Points2D copy_ = rhs;
            std::swap(*this, copy_);
        }

        return *this;
    }

    // Move-constructor.
    Points2D(Points2D &&rhs):sequence_{rhs.sequence_},size_{rhs.size_}{
        rhs.sequence_ = nullptr;
        rhs.size_ = 0;
    }

    // Move-assignment.
    // Just use std::swap() for all variables.
    Points2D& operator=(Points2D &&rhs){
        std::swap(sequence_,rhs.sequence_); 
        std::swap(size_,rhs.size_); 
        return *this; 
    }

    ~Points2D(){
        delete[] sequence_; 
    }

    // End of big-five.

    // One parameter constructor.
    Points2D(const std::array<Object, 2>& item) {
        sequence_ = new std::array<Object,2>{item};
        size_t i = 0 ;
        while((&(sequence_[i][1]) != &(sequence_->back()))) {
            ++i;
        }
        size_ = i+1;
    }

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
    //    result with the remaining part of the larger sequence.
    friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
        Points2D biggest_ = (c1.size_>c2.size_)?c1:c2;
        Points2D smallest_ = (c1.size_<=c2.size_)?c1:c2;
        std::array<Object,2> *sum_ = new std::array<Object,2>[biggest_.size_];
         for(size_t i = 0; i < biggest_.size_; ++i){
            for(size_t j = 0; j < 2; ++j){
                if(smallest_.size_ > i)
                    sum_[i][j] = biggest_.sequence_[i][j] + smallest_.sequence_[i][j];
                else
                    sum_[i][j] = biggest_.sequence_[i][j];
            }
         }
        Points2D result_ = Points2D();
        result_.size_ = biggest_.size_;
        result_.sequence_ = sum_;
       
        return result_;
    }
    
    // Overloading the << operator.
    friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points) {
        if(some_points.size_ == 0){
            out << "()\n";
        }
        else{
            for(size_t i = 0; i < some_points.size_; ++i){
                out << "(" << some_points.sequence_[i][0] << ", " << some_points.sequence_[i][1]  << ")";
            }
             out << "\n";
        }
        return out;
    }   
    
    // Overloading the >> operator.
    // Read a chain from an input stream (e.g., standard input).
    friend std::istream &operator>>(std::istream &in, Points2D &some_points) {
        in >> some_points.size_;
        std::array<Object, 2> *temp_ = some_points.sequence_;
        some_points.sequence_ = new std::array<Object, 2>[some_points.size_];
        delete[] temp_; 
        for(size_t i = 0; i <some_points.size_; ++i){
            for(size_t j = 0; j < 2; ++j){
                while(std::cin.peek() == ' ') std::getchar();
                if(std::cin.peek() == '\n'){
                    some_points.size_ = i+1;
                    break;  
                }else
                  in >> some_points.sequence_[i][j];
                /**
                 *        
                if(std::cin.peek() == 13){
                    if(j == 1) some_points.size_ = i;
                    else some_points.size_ = i+1;  
                    break;  
                }
                */
                
            }
        }
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
