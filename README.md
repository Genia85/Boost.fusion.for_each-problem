Task:
1. create vector from 10 elements of different types
2. fill it and print  it
3. select integer elements with boost::fusion::filter_view
4. calculate sum of these elements with function boost::fusion::for_each()
5. add sum in the end of the initial vector and print it

Problem is in p.4

In VS function 
for_each(vec_view, sum1); doesnt work the way epected. 
It will return sum1=0 (initial value) 
 so in std this function works properly 
for_each(vec_view, std::ref(sum1)); 
and sum1 will be changed.


full programm

#include <iostream>
#include <boost/fusion/tuple.hpp>
#include<boost/fusion/algorithm.hpp>
#include<boost/fusion/sequence.hpp>
#include <vector>
#include <boost/mpl/arg.hpp>
#include <boost/fusion/view.hpp>
#include <boost/integer.hpp>
#include <string>
#include<boost/fusion/container.hpp>
#include<boost/fusion/algorithm/transformation.hpp>
#include <boost/fusion/include/view.hpp>


using namespace boost::fusion;


struct print_v
{
    template <typename T>
    void operator()(const T&c)
    {
        std::cout << std::boolalpha << c << std::endl;
    }
};
class sum
{
public:
    int sum_;
    int  s=0;
    sum() :sum_(0) {  }


    
    
    void print()
    {
        std::cout << "sum= " << sum_ << std::endl;
    }
   void operator()(const int &c)
    {
        this->sum_ += c;

        std::cout << "process\n";// just for service issues to see that in both case during for_each implementation it works the same but end result of sum1 is different
        std::cout << sum_ << std::endl;
        s = sum_;
        
    };
   int getsum() const
    {
       return sum_;
    };
   
};



int main()


{
   
     sum sum1;

    using vector_type=vector<int,std::string,bool,double, float, char, unsigned int,bool,
        std::string,unsigned long long>;
        vector_type v{ 8, "abs",true,5.5,-5.50,'c',10,false,"KLM",3.33333 };
        std::vector<int> v1;

        filter_view<vector_type, std::is_integral<boost::mpl::arg<1>>>vec_view( v );
      
        for_each(vec_view, print_v{});
        for_each(vec_view, sum1);// wont work if you use vs . will return sum1=0!!!!!
       for_each(vec_view, std::ref(sum1));
       std::cout << sum1.sum_<<std::endl;
       auto new_v = push_back(v, sum1.sum_);
       for_each(new_v, print_v{});

       

       
        
}
