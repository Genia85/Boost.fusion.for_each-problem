// Boost_dif_type_containers.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

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

        std::cout << "process\n";
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

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
